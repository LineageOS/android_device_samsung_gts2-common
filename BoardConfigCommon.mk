LOCAL_PATH := device/samsung/gts2-common

# Platform
TARGET_SLSI_VARIANT := cm

TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true

# Extracted with libbootimg
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_SEPARATED_DT := true
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x01000000 --tags_offset 0x00000100
TARGET_CUSTOM_DTBTOOL := dtbhtoolExynos

# Include path
TARGET_SPECIFIC_HEADER_PATH := $(LOCAL_PATH)/include

# Boot animation
TARGET_BOOTANIMATION_PRELOAD := true
TARGET_BOOTANIMATION_TEXTURE_CACHE := true
# Per LineageOS required...
TARGET_SCREEN_HEIGHT := 2048
TARGET_SCREEN_WIDTH := 1536

# Recovery
#RECOVERY_VARIANT := twrp
BOARD_HAS_DOWNLOAD_MODE := true
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/ramdisk/fstab.universal5433

# TWRP
ifeq ($(RECOVERY_VARIANT),twrp)
PRODUCT_COPY_FILES += $(LOCAL_PATH)/twrp/twrp.fstab:recovery/root/etc/twrp.fstab
RECOVERY_SDCARD_ON_DATA := true
BOARD_HAS_NO_REAL_SDCARD := true
TARGET_USE_CUSTOM_LUN_FILE_PATH := "/sys/devices/15400000.usb/15400000.dwc3/gadget/lun%d/file"
TW_BRIGHTNESS_PATH := /sys/class/backlight/panel/brightness
TW_MAX_BRIGHTNESS := 255
TW_DEFAULT_BRIGHTNESS := 162
TW_NO_REBOOT_BOOTLOADER := true
TW_INCLUDE_CRYPTO := true
TW_HAS_DOWNLOAD_MODE := true
TW_NO_EXFAT_FUSE := true
TW_EXCLUDE_SUPERSU := true
TW_USE_TOOLBOX := true
endif

# SELinux
BOARD_SEPOLICY_DIRS += device/samsung/gts2-common/sepolicy

# Seccomp filters
BOARD_SECCOMP_POLICY := device/samsung/gts2-common/seccomp

# Inherit board specific defines
include $(LOCAL_PATH)/board_defines/*.mk
