//
// Created by varev on 8/22/24.
//

#ifndef LIQUIDCRYSTALDISPLAY_H
#define LIQUIDCRYSTALDISPLAY_H

#include <chrono>
#include <LiquidCrystal_I2C.h>
#include <list>

#include "Data.h"

class Data;

constexpr auto DEFAULT_LCD_I2C_ADDRESS = 0x27;

class LiquidCrystalDisplay final : LiquidCrystal_I2C {
private:
    std::list<Data> data;
    std::chrono::milliseconds shift_delay;
    std::chrono::steady_clock::time_point last_shift;

public:
    LiquidCrystalDisplay(uint8_t address, uint8_t columns, uint8_t rows);
    ~LiquidCrystalDisplay() override;

    void displayData();
    void update();

    Data getData(uint64_t id);
    void addData(const Data& data);
    void removeData(const Data& data);
    void removeData(uint64_t id);
    void clearData();
};

#endif //LIQUIDCRYSTALDISPLAY_H
