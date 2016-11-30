DEVICE_PATH := device/samsung/gts2-common

# AOSP Exynos 5 BSP
ifeq ($(TARGET_SLSI_VARIANT),)

    $(call inherit-product, hardware/samsung_slsi/exynos5/exynos5.mk)

# Samsung LSI BSP
else ifeq ($(TARGET_SLSI_VARIANT),cm)

    $(call inherit-product, hardware/samsung_slsi-cm/exynos5/exynos5.mk)
    $(call inherit-product, hardware/samsung_slsi-cm/exynos5433/exynos5433.mk)

else

    $(error TARGET_SLSI_VARIANT not set!)

endif
