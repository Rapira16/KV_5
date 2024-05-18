#ifndef __PRINT__H
#define __PRINT__H
#include "Base.h"

class Print : public Base{
public:
    Print(Base*, std::string);
    void sig(std::string&);
    void hand(std::string);
    void print();
    int getNum();
};

#endif
