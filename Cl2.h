#ifndef __CL2__H
#define __CL2__H
#include "Base.h"

class Cl2 : public Base{
public:
    Cl2(Base* p_head_object, std::string name_object);
    void sig(std::string&);
    void hand(std::string);
    int getNum();
};

#endif
