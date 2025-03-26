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

## Usage Examples

The documentation includes several example projects demonstrating how to use the display with different configurations and UI frameworks.

## Troubleshooting

A comprehensive troubleshooting guide is included to help resolve common issues with display output, compilation, and performance.

## Contributing

Contributions to improve the documentation or add more examples are welcome. Please feel free to submit pull requests or open issues for any problems or suggestions.

## License

This documentation is provided under the MIT License.
