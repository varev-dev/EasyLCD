//
// Created by varev on 8/23/24.
//

#ifndef POSITION_H
#define POSITION_H

#include <cstdint>

class Position {
protected:
    uint64_t x;
    uint64_t y;

public:
    Position(uint64_t x, uint64_t y);
    ~Position();

    void setX(uint64_t x);
    void setY(uint64_t y);

    [[nodiscard]] uint64_t getX() const;
    [[nodiscard]] uint64_t getY() const;
};

#endif //POSITION_H
