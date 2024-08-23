//
// Created by varev on 8/22/24.
//

#include "Data.h"

#include <utility>

Data::Data() {
}

Data::~Data() {
}

Data::Data(std::string data, const DataType type, const Position& position, const bool scrollable, const Axis scroll_axis)
    : data(std::move(data)), type(type), position(position), scroll_axis(scroll_axis), scrollable_(scrollable) {
}

void Data::setData(const std::string& data) {
    this->data = data;
}

void Data::setType(const DataType &type) {
    this->type = type;
}

std::string Data::getData() const {
    return this->data;
}

DataType Data::getType() const {
    return this->type;
}

// TODO: implement lcd and then create render there
void Data::render(LiquidCrystalDisplay &lcd) const {

}

void Data::scroll(const int8_t shift) {
    if (!isScrollable())
        return;

    const uint64_t current = this->scroll_axis == Axis::X_AXIS ? this->position.getX() : this->position.getY();
    const uint64_t updated = current + shift;

    this->scroll_axis == Axis::X_AXIS ? this->position.setX(updated) : this->position.setY(updated);
}

bool Data::isScrollable() const {
    return scrollable_ || this->scroll_axis == Axis::UNDEFINED;
}
