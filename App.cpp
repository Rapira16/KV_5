#include "App.h"
#include "Base.h"
#include "BitShift.h"
#include "CCom.h"
#include "Cl2.h"
#include "Operations.h"
#include "Print.h"
#include "ReadCom.h"

App::App(Base* p_head_object) : Base(p_head_object){}

void App::makeTree(){
    Base* object = this;

    object = new ReadCom(this, "ReadCom");
    object = new Operations(this, "Operations");
    object = new BitShift(this, "BitShift");
    object = new CCom(this, "CCom");
    object = new Print(this, "Print");

    this->set_connect(SIGNAL_D(App::appSig), getChild("ReadCom"), HENDLER_D(ReadCom::read));
    getChild("ReadCom")->set_connect(SIGNAL_D(ReadCom::readSig), this, HENDLER_D(App::hand));
    getChild("ReadCom")->set_connect(SIGNAL_D(ReadCom::readSig), getChild("CCom"), HENDLER_D(CCom::CCommand));
    getChild("ReadCom")->set_connect(SIGNAL_D(ReadCom::readSig), getChild("BitShift"), HENDLER_D(BitShift::shiftFunc));
    getChild("ReadCom")->set_connect(SIGNAL_D(ReadCom::readSig), getChild("Operations"), HENDLER_D(Operations::operationsRead));
    getChild("ReadCom")->set_connect(SIGNAL_D(Operations::operSig), getChild("Print"), HENDLER_D(Print::print));
}

int App::startApp(){
    std::string com;
    this->setBranch(1);
    while(cm != "Off") {
        std::basic_string<char> s = com;
        emit_signal(SIGNAL_D(App::appSig), s);
    }
    return 0;
}

void App::hand(std::string com){
    if(com == "Off"){
        cm = "Off";
        num = "Off";
    }
}

void App::appSig(std::string& m){}

int App::getNum(){return 1;}