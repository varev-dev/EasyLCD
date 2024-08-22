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

constexpr bool      DEFAULT_SCROLL = true;
constexpr uint64_t  DEFAULT_POSITION = 0;
constexpr DataType  DEFAULT_DATA_TYPE = FLOATING;

class Data final : public Renderable, public Scrollable {
protected:
    std::string data;
    DataType type;

    uint64_t position;
    Axis scroll_axis;
    bool scrollable_;

public:
    Data();
    ~Data() override;

    explicit Data(const std::string& data, DataType type = DEFAULT_DATA_TYPE, uint64_t position = DEFAULT_POSITION,
                  bool scrollable = DEFAULT_SCROLL, Axis scroll_axis = UNDEFINED);

    void setData(const std::string&);
    void setType(const DataType& type);

    [[nodiscard]] std::string getData() const;
    [[nodiscard]] DataType getType() const;

    void render(LiquidCrystalDisplay& lcd) const override;
    void scroll(int8_t shift) override;
    [[nodiscard]] bool isScrollable() const override;
};

#endif //DATA_H
