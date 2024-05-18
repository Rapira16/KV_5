#ifndef __BITSHIFT__H
#define __BITSHIFT__H
#include "Base.h"

class BitShift : public Base{
public:
    BitShift(Base*, std::string);
    void sig(std::string&);
    void hand(std::string);
    void shiftFunc(std::string);
    void shiftSig(std::string&);
    int getNum();
};


#endif
