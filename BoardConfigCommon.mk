LOCAL_PATH := device/samsung/gts2-common

# Platform
TARGET_SLSI_VARIANT := cm

TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true

# Extracted with libbootimg
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x01000000 --tags_offset 0x00000100
BOARD_CUSTOM_BOOTIMG_MK := $(LOCAL_PATH)/mkdtbhbootimg.mk

# Include path
TARGET_SPECIFIC_HEADER_PATH += $(LOCAL_PATH)/include

# Boot animation
TARGET_BOOTANIMATION_PRELOAD := true
TARGET_BOOTANIMATION_TEXTURE_CACHE := true
TARGET_BOOTANIMATION_MULTITHREAD_DECODE := true

# Recovery
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/ramdisk/fstab.universal5433

# SELinux
BOARD_SEPOLICY_DIRS += device/samsung/gts2-common/sepolicy

# Seccomp filters
BOARD_SECCOMP_POLICY += device/samsung/gts2-common/seccomp

# Inherit board specific defines
include $(LOCAL_PATH)/board_defines/*.mk
