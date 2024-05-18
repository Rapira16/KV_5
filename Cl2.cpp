#include "Cl2.h"

Cl2::Cl2(Base* p_head_object, std::string name_object) : Base(p_head_object, name_object){}

void Cl2::sig(std::string& input){
    std::cout << "\nSignal from "  << getAbsolute();
    input += " (class: 2)";
}

void Cl2::hand(std::string input){
    std::cout << "\nSignal to " << getAbsolute() << " Text: " << input;
}

int Cl2::getNum() { return 2;}