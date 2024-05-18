#ifndef __OPERATIONS__H
#define __OPERATIONS__H
#include "Base.h"
class Operations : public Base{
public:
    Operations(Base*, std::string);
    void sig(std::string&);
    void hand(std::string);
    void operationsRead(std::string);
    void operSig(std::string&);
    int getNum();
};

#endif
