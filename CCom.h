#ifndef __CCOM__H
#define __CCOM__H
#include "Base.h"

class CCom : public Base{
public:
    CCom(Base*, std::string);
    void sig(std::string&);
    void hand(std::string);
    void CCommand(std::string);
    int getNum();
};


#endif
