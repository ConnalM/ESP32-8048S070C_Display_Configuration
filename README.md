# ESP32-8048S070C Display Configuration

Comprehensive documentation and configuration guide for the ESP32-8048S070C display module (part of the "Cheap Yellow Display" family) with PlatformIO and LVGL.

## About This Project

This repository provides detailed documentation for configuring and using the ESP32-8048S070C display module, a 7-inch 800x480 RGB LCD panel with an integrated ESP32-S3 microcontroller. The documentation covers hardware specifications, PlatformIO setup, pin configurations, and optimization tips.

## Hardware Specifications

- **Microcontroller**: ESP32-S3
- **Display**: 7-inch 800x480 RGB LCD panel
- **Display Controller**: ST7262 with 16-bit parallel interface
- **Touch Controller**: GT911 or XPT2046 (depending on variant)
- **Connectivity**: USB-C, TF card interface, I2C (JST1.0 4p), Power + Serial (JST1.25 4p)

## Documentation Contents

- **PlatformIO Board Configuration**: How to add and configure the ESP32-8048S070C in PlatformIO
- **Hardware Connection Information**: Pin mappings and physical setup details
- **Performance Optimization Tips**: Memory management and rendering performance advice
- **Example Projects**: Sample code for different use cases
- **Troubleshooting Guide**: Solutions for common display and compilation issues

## Getting Started

### PlatformIO Setup

This project uses a manual configuration approach for the ESP32-8048S070C board, which eliminates the need for external Git submodules and simplifies the setup process.

#### Manual Configuration

The project is configured directly in the `platformio.ini` file with all necessary settings for the ESP32-S3 board and display. This approach offers several advantages:

- **Simplified Setup**: No need to clone additional repositories
- **Better Portability**: All configuration is contained within the project
- **Easier Maintenance**: Direct control over all build parameters
- **Improved Compatibility**: Avoids potential conflicts with board package updates

The configuration includes:
- Board-specific settings for the ESP32-S3
- Memory configuration for optimal performance
- Build flags for display compatibility
- Custom build script to handle LVGL configuration

### Required Libraries

- Arduino_GFX Library: `https://github.com/moononournation/Arduino_GFX.git`
- LVGL: `lvgl/lvgl@^9.2.2`

## Setting Up This Project in VSCode

To use this ESP32 display configuration in a VSCode instance, follow these steps:

### Step 1: Clone the Repository
```bash
git clone https://github.com/ConnalM/ESP32-8048S070C_Display_Configuration.git
cd ESP32-8048S070C_Display_Configuration
```

### Step 2: Install PlatformIO Extension
1. Open VSCode
2. Go to Extensions (Ctrl+Shift+X)
3. Search for "PlatformIO IDE"
4. Install the extension
5. Restart VSCode when prompted

### Step 3: Open the Project
1. In VSCode, select "File > Open Folder"
2. Navigate to the cloned repository folder
3. Click "Select Folder"

### Step 4: Let PlatformIO Initialize
- PlatformIO will automatically detect the project
- Wait for it to initialize and install dependencies
- This may take a few minutes the first time

### Step 5: Verify Configuration
- Check that the `platformio.ini` file has all the correct settings
- Ensure the custom_build_script.py file is present
- Verify that the src/main.cpp file contains the display code

### Step 6: Connect Your ESP32 Display
1. Connect your ESP32-8048S070C display to your computer via USB
2. Windows should recognize it as a COM port device

### Step 7: Build and Upload
1. Click the PlatformIO icon in the sidebar
2. Under "PROJECT TASKS", expand the "esp32-8048S070C" environment
3. Click "Build" to compile the project
4. Click "Upload" to flash it to your ESP32 display

### Step 8: Monitor Serial Output (Optional)
- Click "Monitor" under the project tasks to view serial output
- This is useful for debugging

### Important Notes
- No Git submodule setup is required - everything is configured directly in the project files
- The manual configuration in platformio.ini handles all the board-specific settings
- If you encounter any compilation errors related to LVGL assembly files, check that the custom_build_script.py is being executed

### Customizing the Display Patterns
If you want to modify the display patterns:
1. Edit the pattern functions in src/main.cpp
2. Add new patterns by creating additional drawing functions
3. Update the switch statement in the loop() function to include your new patterns

## Usage Examples

The documentation includes several example projects demonstrating how to use the display with different configurations and UI frameworks.

## Troubleshooting

A comprehensive troubleshooting guide is included to help resolve common issues with display output, compilation, and performance.

## Contributing

Contributions to improve the documentation or add more examples are welcome. Please feel free to submit pull requests or open issues for any problems or suggestions.

## License

This documentation is provided under the MIT License.
