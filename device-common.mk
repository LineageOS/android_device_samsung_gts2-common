DEVICE_PACKAGE_OVERLAYS += device/samsung/gts2-common/overlay

LOCAL_PATH := device/samsung/gts2-common

# Flat device tree for boot image
PRODUCT_PACKAGES += \
    mkdtbhbootimg

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
