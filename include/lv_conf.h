/**
 * @file lv_conf.h
 * Configuration file for LVGL v9.0.0
 */

#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

/* Color depth: 1 (1 byte per pixel), 8 (RGB332), 16 (RGB565), 32 (ARGB8888) */
#define LV_COLOR_DEPTH 32

/* Default display refresh period. */
#define LV_DISP_DEF_REFR_PERIOD 30

/* Enable logging */
#define LV_USE_LOG 1
#define LV_LOG_LEVEL LV_LOG_LEVEL_WARN

/* For performance monitoring */
#define LV_USE_PERF_MONITOR 0
#define LV_USE_MEM_MONITOR 0

/* Input device settings */
#define LV_INDEV_DEF_READ_PERIOD 30

/* Use SDL renderer for PC simulator */
#define LV_USE_SDL 0

/* Asserts */
#define LV_USE_ASSERT_NULL 1
#define LV_USE_ASSERT_MALLOC 1

/* Completely disable all assembly optimizations */
#define LV_USE_DRAW_SW_ASM 0
#define LV_USE_DRAW_SW_HELIUM 0
#define LV_USE_DRAW_SW_NEON 0

/* Disable any vector graphics support */
#define LV_USE_VECTOR_GRAPHIC 0

/* Disable any problematic drawing features */
#define LV_USE_DRAW_SW 1
#define LV_USE_DRAW_HW 0

/* Enable built-in fonts */
#define LV_FONT_MONTSERRAT_8  0
#define LV_FONT_MONTSERRAT_10 0
#define LV_FONT_MONTSERRAT_12 1
#define LV_FONT_MONTSERRAT_14 1
#define LV_FONT_MONTSERRAT_16 1
#define LV_FONT_MONTSERRAT_18 0
#define LV_FONT_MONTSERRAT_20 0
#define LV_FONT_MONTSERRAT_22 0
#define LV_FONT_MONTSERRAT_24 0
#define LV_FONT_MONTSERRAT_26 0
#define LV_FONT_MONTSERRAT_28 0
#define LV_FONT_MONTSERRAT_30 0
#define LV_FONT_MONTSERRAT_32 0
#define LV_FONT_MONTSERRAT_34 0
#define LV_FONT_MONTSERRAT_36 0
#define LV_FONT_MONTSERRAT_38 0
#define LV_FONT_MONTSERRAT_40 0
#define LV_FONT_MONTSERRAT_42 0
#define LV_FONT_MONTSERRAT_44 0
#define LV_FONT_MONTSERRAT_46 0
#define LV_FONT_MONTSERRAT_48 0

/* Enable image decoder */
#define LV_USE_LODEPNG 0
#define LV_USE_LIBPNG 0
#define LV_USE_BMP 0
#define LV_USE_TJPGD 0
#define LV_USE_LIBJPEG_TURBO 0
#define LV_USE_GIF 0

/* Enable QR code */
#define LV_USE_QRCODE 0

/* Enable FreeType for fonts */
#define LV_USE_FREETYPE 0

/* Enable animations */
#define LV_USE_ANIMATION 1

/* Enable GPU */
#define LV_USE_GPU_ARM2D 0
#define LV_USE_GPU_STM32_DMA2D 0
#define LV_USE_GPU_SWM341_DMA2D 0
#define LV_USE_GPU_NXP_PXP 0
#define LV_USE_GPU_NXP_VG_LITE 0

#endif /* LV_CONF_H */
