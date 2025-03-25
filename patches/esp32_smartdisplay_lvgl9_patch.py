Import("env")

import os
import re

def patch_esp32_smartdisplay(env):
    print("Applying patch for esp32_smartdisplay to work with LVGL 9.2.2...")
    
    # Get the path to the esp32_smartdisplay library
    lib_path = os.path.join(env.get("PROJECT_LIBDEPS_DIR"), env.get("PIOENV"), "esp32_smartdisplay")
    src_path = os.path.join(lib_path, "src")
    
    if not os.path.exists(src_path):
        print(f"Error: Could not find esp32_smartdisplay library at {src_path}")
        return
    
    # List of files to patch
    files_to_patch = [
        os.path.join(src_path, "esp32_smartdisplay.c"),
        os.path.join(src_path, "lvgl_panel_ili9341_spi.c"),
        os.path.join(src_path, "lvgl_panel_st7789_spi.c"),
        os.path.join(src_path, "lvgl_panel_st7796_spi.c"),
        os.path.join(src_path, "lvgl_panel_st7701_par.c"),
        os.path.join(src_path, "lvgl_panel_st7789_i80.c"),
        os.path.join(src_path, "lvgl_panel_st7262_par.c"),
        os.path.join(src_path, "lvgl_panel_gc9a01_spi.c")
    ]
    
    # Patch pattern: replace 'display->sw_rotate' with appropriate LVGL 9.2.2 code
    for file_path in files_to_patch:
        if not os.path.exists(file_path):
            print(f"Warning: File {file_path} not found, skipping...")
            continue
        
        # Read the file content
        with open(file_path, "r") as f:
            content = f.read()
        
        # Replace 'display->sw_rotate = 0;' with 'lv_display_set_rotation(display, LV_DISPLAY_ROTATION_0);'
        content = re.sub(r'display->sw_rotate\s*=\s*0;', 'lv_display_set_rotation(display, LV_DISPLAY_ROTATION_0);', content)
        
        # Replace 'display->sw_rotate = 1;' with 'lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);'
        content = re.sub(r'display->sw_rotate\s*=\s*1;', 'lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);', content)
        
        # Replace 'if (!display->sw_rotate)' with 'if (lv_display_get_rotation(display) == LV_DISPLAY_ROTATION_0)'
        content = re.sub(r'if\s*\(!display->sw_rotate\)', 'if (lv_display_get_rotation(display) == LV_DISPLAY_ROTATION_0)', content)
        
        # Write the modified content back to the file
        with open(file_path, "w") as f:
            f.write(content)
        
        print(f"Patched {file_path}")
    
    print("Patch applied successfully.")

# Apply the patch
patch_esp32_smartdisplay(env)
