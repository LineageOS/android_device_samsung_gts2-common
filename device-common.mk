DEVICE_PACKAGE_OVERLAYS += device/samsung/gts2-common/overlay
LOCAL_PATH := device/samsung/gts2-common

PRODUCT_CHARACTERISTICS := tablet

# ANT+
PRODUCT_PACKAGES += \
    AntHalService \
    com.dsi.ant.antradio_library \
    libantradio

# Audio
PRODUCT_PACKAGES += \
    audio.a2dp.default \
    audio.usb.default \
    audio.r_submix.default \
    audio.primary.universal5433 \
    libtinycompress

#PRODUCT_PACKAGES += \
#	libseirenhw

PRODUCT_PACKAGES += \
    android.hardware.audio@2.0-impl \
    android.hardware.audio.effect@2.0-impl
	
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/audio/audio_effects.conf:$(TARGET_COPY_OUT_VENDOR)/etc/audio_effects.conf \
    $(LOCAL_PATH)/configs/audio/audio_policy.conf:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy.conf \
    $(LOCAL_PATH)/configs/audio/mixer_paths_0.xml:$(TARGET_COPY_OUT_VENDOR)/etc/mixer_paths_0.xml

# Bluetooth
PRODUCT_PACKAGES += \
    libbt-vendor

PRODUCT_PACKAGES += \
    android.hardware.bluetooth@1.0-impl \
    android.hardware.bluetooth@1.0-service

# Camera
PRODUCT_PACKAGES += \
    camera.universal5433 \
    libexynoscamera_shim \
    Snap

PRODUCT_PACKAGES += \
    android.hardware.camera.provider@2.4-impl-legacy \
    camera.device@1.0-impl-legacy

# Charger
PRODUCT_PACKAGES += \
    charger_res_images \
    lineage_charger_res_images

# Codecs
PRODUCT_PACKAGES += \
    libstagefrighthw \
    libExynosOMX_Core

#PRODUCT_PACKAGES += \
#   libOMX.Exynos.AAC.Decoder \
#   libOMX.Exynos.AVC.Decoder \
#   libOMX.Exynos.AVC.Encoder \
#   libOMX.Exynos.HEVC.Decoder \
#   libOMX.Exynos.MP3.Decoder \
#   libOMX.Exynos.MPEG4.Decoder \
#   libOMX.Exynos.MPEG4.Encoder \
#   libOMX.Exynos.VP8.Decoder \
#   libOMX.Exynos.VP8.Encoder \
#   libOMX.Exynos.WMA.Encoder

LOCAL_PATH := device/samsung/gts2-common

# Flat device tree for boot image
PRODUCT_PACKAGES += \
    dtbhtoolExynos

# Ramdisk
PRODUCT_PACKAGES += \
    fstab.universal5433 \
    init.power.rc \
    init.samsung.rc \
    init.wifi.rc \
    init.universal5433.rc \
    init.universal5433.usb.rc \
    ueventd.universal5433.rc

# Permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.ethernet.xml:system/etc/permissions/android.hardware.ethernet.xml \
    frameworks/native/data/etc/android.hardware.fingerprint.xml:system/etc/permissions/android.hardware.fingerprint.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:system/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:system/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.software.freeform_window_management.xml:system/etc/permissions/android.software.freeform_window_management.xml \
    frameworks/native/data/etc/tablet_core_hardware.xml:system/etc/permissions/tablet_core_hardware.xml

# Graphics
PRODUCT_AAPT_CONFIG := xlarge
PRODUCT_AAPT_PREF_CONFIG := xhdpi
# A list of dpis to select prebuilt apk, in precedence order.
PRODUCT_AAPT_PREBUILT_DPI := hdpi mdpi

# hardware/samsung/AdvancedDisplay (MDNIE)
PRODUCT_PACKAGES += \
    AdvancedDisplay

# Radio
PRODUCT_PACKAGES += \
    libxml2 \
    libprotobuf-cpp-full

PRODUCT_PACKAGES += \
    libsecril-client \
    libsecril-client-sap \
    modemloader

PRODUCT_PACKAGES += \
    SamsungServiceMode

# Fingerprint
PRODUCT_PACKAGES += \
    fingerprintd \
    libbauthtzcommon_shim

# Offmode charger
# Use cm images if available, aosp ones otherwise
PRODUCT_PACKAGES += \
    charger_res_images \
    cm_charger_res_images

PRODUCT_CHARACTERISTICS := tablet

# Inherit board specific artifacts
include $(LOCAL_PATH)/board_artifacts/*.mk

# System properties
-include $(LOCAL_PATH)/system_prop.mk

# call the proprietary setup
$(call inherit-product, vendor/samsung/gts2-common/gts2-common-vendor.mk)
