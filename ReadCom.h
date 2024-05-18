#ifndef __READCOM__H
#define __READCOM__H
#include "Base.h"

class ReadCom : public Base{
public:
    ReadCom(Base*, std::string);
    void sig(std::string&);
    void hand(std::string);
    void read();
    void readSig(std::string&);
    int getNum();
};


#endif
