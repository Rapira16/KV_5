#include "CCom.h"

CCom::CCom(Base* p_head_object, std::string name_object):Base(p_head_object, name_object){}

void CCom::sig(std::string& input){
    std::cout << "\nSignal from " << getAbsolute();
    input += " (class: 4)";
}

void CCom::hand(std::string input){
    std::cout << "\nSignal to " << getAbsolute() << " Text: " << input;
}

void CCom::CCommand(std::string c){
    if(c == "C"){
        expr = "0";
        result = 0;
        num = "C";
    }
}

int CCom::getNum(){return 4;}