BOARD_KERNEL_BASE := 0x10000000
BOARD_KERNEL_PAGESIZE := 2048
#BOARD_KERNEL_CMDLINE := The bootloader ignores the cmdline from the boot.img

# Kernel
TARGET_KERNEL_SOURCE := kernel/samsung/gts2
KERNEL_TOOLCHAIN_PREFIX := arm-linux-androideabi-

# Extended filesystem support
TARGET_KERNEL_HAVE_EXFAT := true
TARGET_KERNEL_HAVE_NTFS := true
