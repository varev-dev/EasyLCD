//
// Created by varev on 8/22/24.
//

#ifndef LIQUIDCRYSTALDISPLAY_H
#define LIQUIDCRYSTALDISPLAY_H

#include <chrono>
#include <LiquidCrystal_I2C.h>
#include <list>

#include "Data.h"
#include "View.h"

class Data;

constexpr auto DEFAULT_LCD_I2C_ADDRESS = 0x27;
constexpr auto DEFAULT_LCD_COLS = 20;
constexpr auto DEFAULT_LCD_ROWS = 4;

class LiquidCrystalDisplay final : LiquidCrystal_I2C {
private:
    std::list<View> views;
    std::chrono::milliseconds shift_delay;
    std::chrono::steady_clock::time_point last_shift;

public:
    LiquidCrystalDisplay(uint8_t address, uint8_t columns, uint8_t rows);
    ~LiquidCrystalDisplay() override;

    void displayData();
    void update();

    View getView(uint64_t id);
    void addView(const Data& data);
    void removeView(const Data& data);
    void removeView(uint64_t id);
    void clearViews();
};

#endif //LIQUIDCRYSTALDISPLAY_H
