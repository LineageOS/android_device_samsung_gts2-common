LOCAL_PATH := $(call my-dir)

MKDTBHBOOTIMG := $(HOST_OUT_EXECUTABLES)/mkdtbhbootimg$(HOST_EXECUTABLE_SUFFIX)

$(INSTALLED_BOOTIMAGE_TARGET): $(MKDTBHBOOTIMG) $(INTERNAL_BOOTIMAGE_FILES) $(BOOTIMAGE_EXTRA_DEPS) TARGET_KERNEL_BINARIES
	$(call pretty,"Target boot image: $@")
	$(hide) $(MKDTBHBOOTIMG) $(INTERNAL_BOOTIMAGE_ARGS) $(BOARD_MKBOOTIMG_ARGS) --dt_dir $(KERNEL_OUT)/arch/arm/boot/dts/ --output $@
	$(hide) $(call assert-max-image-size,$@,$(BOARD_BOOTIMAGE_PARTITION_SIZE),raw)
	@echo -e ${CL_CYN}"Made boot image: $@"${CL_RST}

$(INSTALLED_RECOVERYIMAGE_TARGET): $(MKDTBHBOOTIMG) \
		$(recovery_ramdisk) \
		$(recovery_kernel)
	@echo -e ${CL_CYN}"----- Making recovery image ------"${CL_RST}
	$(hide) $(MKDTBHBOOTIMG) $(INTERNAL_RECOVERYIMAGE_ARGS) $(BOARD_MKBOOTIMG_ARGS) --dt_dir $(KERNEL_OUT)/arch/arm/boot/dts/ --output $@
	$(hide) $(call assert-max-image-size,$@,$(BOARD_RECOVERYIMAGE_PARTITION_SIZE),raw)
	@echo -e ${CL_CYN}"Made recovery image: $@"${CL_RST}
