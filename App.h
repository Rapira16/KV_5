#ifndef __APP__H
#define __APP__H
#include "Base.h"

class App : public Base{
    std::string cm = "";
public:
    App(Base* p_head_object);
    void makeTree();
    int startApp();
    void hand(std::string);
    void appSig(std::string&);
    int getNum();
};

#endif
