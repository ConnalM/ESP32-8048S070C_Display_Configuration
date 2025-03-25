# ESP32 Smart Display Project

This project demonstrates how to use the ESP32 Smart Display (Sunton Smart Display / CYD - Cheap Yellow Display) with LVGL for creating graphical user interfaces.

## Hardware Requirements

- ESP32 Smart Display board (e.g., ESP32-2432S024R)
- USB cable for programming

## Software Requirements

- PlatformIO IDE
- ESP32 Arduino framework
- LVGL library (automatically installed as a dependency)

## Project Structure

- `platformio.ini`: PlatformIO project configuration
- `boards/`: Board definitions for Sunton Smart Display boards (git submodule)
- `include/lv_conf.h`: LVGL configuration file
- `src/main.cpp`: Main application code

## Installation

1. Clone this repository with submodules:
   ```
   git clone --recurse-submodules https://github.com/yourusername/ESP32_SmartDisplay_Project.git
   ```

2. Open the project in PlatformIO IDE

3. Build and upload to your ESP32 Smart Display board

## Usage

The example code displays a simple "Hello ESP32 Smart Display!" message in the center of the screen. You can modify the code in `src/main.cpp` to create your own user interface using LVGL.

## Customization

- Change the display rotation in `src/main.cpp` by uncommenting one of the rotation lines
- Modify LVGL settings in `include/lv_conf.h`
- Choose a different board by changing the board name in `platformio.ini`

## Supported Boards

This project supports various Sunton Smart Display boards, including:
- ESP32-2432S024R/C/N
- ESP32-2432S028R/C
- ESP32-3248S035R/C
- ESP32-8048S070N/C

And many more as defined in the board definitions submodule.

## License

This project is open source and available under the MIT License.
