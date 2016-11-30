# Packages
PRODUCT_PACKAGES += \
    gralloc.exynos5 \
    libion \
    libfimg

# Properties
PRODUCT_PROPERTY_OVERRIDES += \
    ro.bq.gpu_to_cpu_unsupported=1 \
    ro.opengles.version=196609 \
    ro.sf.lcd_density=320

# Hwc - not used on cm/aosp
PRODUCT_PROPERTY_OVERRIDES += \
    debug.hwc.winupdate=1 \
    debug.hwc.otf=1
