/*
 * Copyright (C) 2016 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef EXYNOS_GRALLOC_H_
#define EXYNOS_GRALLOC_H_

/*
 * Static data
 */
enum {
                                                           /* HAL_PIXEL_FORMAT_YCbCr_422_P = 0x100, */
    HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P_M       = 0x101,   /* HAL_PIXEL_FORMAT_YCbCr_420_P */
                                                           /* HAL_PIXEL_FORMAT_YCbCr_420_I = 0x102, */
    HAL_PIXEL_FORMAT_EXYNOS_CbYCrY_422_I        = 0x103,   /* HAL_PIXEL_FORMAT_CbYCrY_422_I */
                                                           /* HAL_PIXEL_FORMAT_CbYCrY_420_I = 0x104, */
    HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M      = 0x105,   /* HAL_PIXEL_FORMAT_YCbCr_420_SP */
    HAL_PIXEL_FORMAT_EXYNOS_YCrCb_422_SP        = 0x106,   /* HAL_PIXEL_FORMAT_YCrCb_422_SP */
    HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_TILED= 0x107,   /* HAL_PIXEL_FORMAT_YCbCr_420_SP_TILED */
    HAL_PIXEL_FORMAT_EXYNOS_ARGB_8888           = 0x108,   /* HAL_PIXEL_FORMAT_CUSTOM_ARGB_8888 */
    // support custom format for zero copy
                                                           /* HAL_PIXEL_FORMAT_CUSTOM_YCbCr_420_SP = 0x110 */
                                                           /* HAL_PIXEL_FORMAT_CUSTOM_YCrCb_420_SP = 0x111, */
                                                           /* HAL_PIXEL_FORMAT_CUSTOM_YCbCr_420_SP_TILED  = 0x112, */
                                                           /* HAL_PIXEL_FORMAT_CUSTOM_YCbCr_422_SP = 0x113, */
                                                           /* HAL_PIXEL_FORMAT_CUSTOM_YCrCb_422_SP = 0x114, */
                                                           /* HAL_PIXEL_FORMAT_CUSTOM_YCbCr_422_I  = 0x115, */
    HAL_PIXEL_FORMAT_EXYNOS_YCrCb_422_I         = 0x116,   /* HAL_PIXEL_FORMAT_CUSTOM_YCrCb_422_I */
                                                           /* HAL_PIXEL_FORMAT_CUSTOM_CbYCrY_422_I = 0x117, */
    HAL_PIXEL_FORMAT_EXYNOS_CrYCbY_422_I        = 0x118,   /* HAL_PIXEL_FORMAT_CUSTOM_CrYCbY_422_I */
                                                           /* HAL_PIXEL_FORMAT_CUSTOM_CbYCr_422_I = 0x11B, */

    HAL_PIXEL_FORMAT_EXYNOS_YV12_M              = 0x11C,   /* HAL_PIXEL_FORMAT_EXYNOS_YV12 */
    HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M      = 0x11D,   /* HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP */
    HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M_FULL = 0x11E,   /* HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_FULL */

    /* newly added formats */
    HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P         = 0x11F,
    HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP        = 0x120,

    HAL_PIXEL_FORMAT_EXYNOS_MAX
};

static const size_t ext_size = 256;

static const int HAL_PIXEL_FORMAT_sRGB_A_8888 = 12;
static const int HAL_PIXEL_FORMAT_sRGB_X_8888 = 13;

/*
 * Prototypes
 */
static int gralloc_alloc_framework_yuv(int ionfd, int w, int h, int format,
                                       int usage, unsigned int ion_flags,
                                       private_handle_t **hnd, int *stride);

/*
 * Board specific implementations
 */
static int handle_rgb_format(const int &w, const int &h, const int &format, const int &usage,
                             int *stride, size_t *size, size_t *bpr, int *bpp, int *vstride)
{
    switch (format) {
        case HAL_PIXEL_FORMAT_CUSTOM_ARGB_8888:
        case HAL_PIXEL_FORMAT_RGBA_8888:
        case HAL_PIXEL_FORMAT_RGBX_8888:
        case HAL_PIXEL_FORMAT_BGRA_8888:
        case HAL_PIXEL_FORMAT_sRGB_A_8888:
        case HAL_PIXEL_FORMAT_sRGB_X_8888:
            *bpp = 4;
            break;
        case HAL_PIXEL_FORMAT_RGB_888:
            *bpp = 3;
            break;
        case HAL_PIXEL_FORMAT_RGB_565:
        case HAL_PIXEL_FORMAT_RAW16:
            *bpp = 2;
            break;
        case HAL_PIXEL_FORMAT_BLOB:
            *stride = w;
            *vstride = h;
            *size = w * h;
            break;
        default:
            return -EINVAL;
    }

    if (format != HAL_PIXEL_FORMAT_BLOB) {
        *bpr = ALIGN(w* *bpp, 64);
        *vstride = ALIGN(h, 16);
        if (*vstride < h + 2)
            *size = *bpr * (h + 2);
        else
            *size = *bpr * *vstride;
        *stride = *bpr / *bpp;
        *size = ALIGN(*size, PAGE_SIZE) + ext_size;
    }

    return 0;
}

static int handle_framework_yuv_format(const int &w, const int &h, const int &format, int *stride,
                                       size_t *size)
{
    switch (format) {
        case HAL_PIXEL_FORMAT_YV12:
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P:
            *stride = ALIGN(w, 16);
            *size = (*stride * h) + (ALIGN(*stride / 2, 16) * h) + ext_size;
            break;
        case HAL_PIXEL_FORMAT_YCrCb_420_SP:
            *stride = w;
            *size = *stride * ALIGN(h, 16) * 3 / 2 + ext_size;
            break;
        default:
            ALOGE("invalid yuv format %d\n", format);
            return -EINVAL;
    }

    return 0;
}

static int handle_yuv_format(const int &ionfd, const int &w, const int &h, const int &format,
                             const int &usage, unsigned int &ion_flags, private_handle_t **hnd,
                             int *stride, size_t *luma_vstride, size_t *luma_size,
                             size_t *chroma_size, int *planes)
{
    switch (format) {
        case HAL_PIXEL_FORMAT_EXYNOS_YV12:
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P_M:
            {
                *stride = ALIGN(w, 32);
                *luma_vstride = ALIGN(h, 16);
                *luma_size = *luma_vstride * *stride + ext_size;
                *chroma_size = (*luma_vstride / 2) * ALIGN(*stride / 2, 16) + ext_size;
                *planes = 3;
                break;
            }
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_TILED:
            {
                size_t chroma_vstride = ALIGN(h / 2, 32);
                *luma_vstride = ALIGN(h, 32);
                *luma_size = *luma_vstride * *stride + ext_size;
                *chroma_size = chroma_vstride * *stride + ext_size;
                *planes = 2;
                break;
            }
        case HAL_PIXEL_FORMAT_YV12:
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P:
        case HAL_PIXEL_FORMAT_YCrCb_420_SP:
            return gralloc_alloc_framework_yuv(ionfd, w, h, format, usage,
                                               ion_flags, hnd, stride);
        case HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M:
        case HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M_FULL:
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M:
            {
                *luma_vstride = ALIGN(h, 16);
                *luma_size = *stride * *luma_vstride + ext_size;
                *chroma_size = *stride * ALIGN(*luma_vstride / 2, 8) + ext_size;
                *planes = 2;
                break;
            }
        case HAL_PIXEL_FORMAT_YCbCr_422_I:
            {
                *luma_vstride = h;
                *luma_size = *luma_vstride * *stride * 2;
                *chroma_size = 0;
                *planes = 1;
                break;
            }
        default:
            ALOGE("invalid yuv format %d\n", format);
            return -EINVAL;
    }

    return 0;
}

#endif /* EXYNOS_GRALLOC_H_ */
