DEVICE_PATH := device/samsung/gts2-common

# SELinux policy
# TODO: Split into sec/slsi policies
BOARD_SEPOLICY_DIRS += $(DEVICE_PATH)/sepolicy
