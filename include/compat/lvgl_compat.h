/**
 * @file lvgl_compat.h
 * Compatibility layer for LVGL 9.2.2 with esp32_smartdisplay library
 */

#ifndef LVGL_COMPAT_H
#define LVGL_COMPAT_H

#include "lvgl.h"

/**
 * In LVGL 9.2.2, the sw_rotate member doesn't exist in the lv_display_t structure.
 * Instead, rotation is handled through the rotation field and related functions.
 * This compatibility layer adds the sw_rotate field to the lv_display_t structure
 * through a macro that redirects to the appropriate LVGL 9.2.2 functionality.
 */

// Define a compatibility macro to map sw_rotate to the appropriate LVGL 9.2.2 functionality
#define sw_rotate _sw_rotate_compatibility

// Add a compatibility function to get/set the sw_rotate value
static inline bool get_sw_rotate(lv_display_t *display) {
    return lv_display_get_rotation(display) != LV_DISPLAY_ROTATION_0;
}

static inline void set_sw_rotate(lv_display_t *display, bool value) {
    // If sw_rotate is being set to 1, we'll use 90-degree rotation as a default
    // This is a simplification; the actual behavior might need adjustment based on your specific needs
    if (value) {
        lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);
    } else {
        lv_display_set_rotation(display, LV_DISPLAY_ROTATION_0);
    }
}

// Define a compatibility getter/setter for the sw_rotate property
#define _sw_rotate_compatibility __extension__({\
    bool _result;\
    if (__builtin_constant_p(__COUNTER__)) {\
        /* This is a write operation */\
        set_sw_rotate(display, __COUNTER__);\
        _result = __COUNTER__;\
    } else {\
        /* This is a read operation */\
        _result = get_sw_rotate(display);\
    }\
    _result;\
})

#endif /* LVGL_COMPAT_H */
