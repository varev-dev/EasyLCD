cmake_minimum_required(VERSION 3.29)
project(EasyLCD)

set(CMAKE_CXX_STANDARD 20)

if (UNIX)
    set(ARDUINO_CORE_PATH "path/to/directory/with/Arduino.h/file")
    set(LCD_I2C_PATH "path/to/directory/with/LiquidCrystal_I2C.h/file")
endif ()

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${ARDUINO_CORE_PATH}
        ${LCD_I2C_PATH}
)

file(GLOB SOURCES "src/*.cpp")

add_library(EasyLCD STATIC ${SOURCES})

target_include_directories(EasyLCD PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${ARDUINO_CORE_PATH}
        ${LCD_I2C_PATH}
)