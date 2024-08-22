//
// Created by varev on 8/22/24.
//

#ifndef DATA_H
#define DATA_H

#include <Arduino.h>
#include <DataType.h>

#include <LiquidCrystalDisplay.h>

constexpr DataType DEFAULT_DATA_TYPE = FLOATING;

class Data : public Printable {
protected:
    std::string data;
    DataType type;

public:
    Data();
    ~Data() override;

    explicit Data(const std::string&, const DataType& type = DEFAULT_DATA_TYPE);

    void setData(const std::string&);
    void setType(const DataType& type);

    [[nodiscard]] std::string getData() const;
    [[nodiscard]] DataType getType() const;

    void print(LiquidCrystalDisplay& lcd) const override;
};

#endif //DATA_H
