//
// Created by varev on 8/22/24.
//

#ifndef DATA_H
#define DATA_H

#include <string>

#include "DataType.h"
#include "LiquidCrystalDisplay.h"
#include "Renderable.h"
#include "Scrollable.h"
#include "Axis.h"
#include "Position.h"

constexpr auto DEFAULT_SCROLL = true;
constexpr auto DEFAULT_POSITION = Position(0, 0);
constexpr auto DEFAULT_DATA_TYPE = DataType::FLOATING;
constexpr auto DEFAULT_AXIS = Axis::UNDEFINED;

class Data final : public Renderable, public Scrollable {
protected:
    std::string data;
    DataType type;

    Position position;
    Axis scroll_axis;
    bool scrollable_;

public:
    Data();
    ~Data() override;

    explicit Data(std::string  data, DataType type = DEFAULT_DATA_TYPE, const Position& position = DEFAULT_POSITION,
                  bool scrollable = DEFAULT_SCROLL, Axis scroll_axis = DEFAULT_AXIS);

    void setData(const std::string& data);
    void setType(const DataType& type);

    [[nodiscard]] std::string getData() const;
    [[nodiscard]] DataType getType() const;

    void render(LiquidCrystalDisplay& lcd) const override;
    void scroll(int8_t shift) override;
    [[nodiscard]] bool isScrollable() const override;
};

#endif //DATA_H
