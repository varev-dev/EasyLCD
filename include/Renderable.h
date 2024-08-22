//
// Created by varev on 8/22/24.
//

#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <LiquidCrystalDisplay.h>

class Renderable {
public:
    virtual ~Renderable();
    virtual void render(LiquidCrystalDisplay& lcd) const = 0;
};

#endif //PRINTABLE_H
