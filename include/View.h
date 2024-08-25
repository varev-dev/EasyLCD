//
// Created by varev on 8/25/24.
//

#ifndef VIEW_H
#define VIEW_H

#include <list>

class LiquidCrystalDisplay;
class Data;

class View {
private:
    bool** board;
    std::list<Data> data;

public:
    View();
    ~View();
    void addData(const Data& data);
    void removeData(const Data& data);
    void clearData();
    void print(LiquidCrystalDisplay& lcd) const;
};

#endif //VIEW_H
