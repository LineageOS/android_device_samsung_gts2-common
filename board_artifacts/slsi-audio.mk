DEVICE_PATH := device/samsung/gts2-common

# Configs
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/audio/audio_effects.conf:system/etc/audio_effects.conf \
    $(DEVICE_PATH)/configs/audio/audio_policy.conf:system/etc/audio_policy.conf

# Packages
PRODUCT_PACKAGES += \
    audio.a2dp.default \
    audio.usb.default \
    audio.r_submix.default \
    audio.primary.universal5433 \
    libtinycompress

# Permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.audio.low_latency.xml:system/etc/permissions/android.hardware.audio.low_latency.xml
