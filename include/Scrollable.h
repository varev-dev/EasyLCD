//
// Created by varev on 8/23/24.
//

#ifndef SCROLLABLE_H
#define SCROLLABLE_H

#include <cstdint>

class Scrollable {
public:
    virtual ~Scrollable();
    virtual void scroll(int8_t shift) = 0;
    [[nodiscard]] virtual bool isScrollable() const = 0;
};

#endif //SCROLLABLE_H
