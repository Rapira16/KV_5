#include "BitShift.h"

BitShift::BitShift(Base* p_head_object, std::string name_object):Base(p_head_object, name_object){}

void BitShift::sig(std::string& input){
    std::cout << "\nSignal from " << getAbsolute();
    input += " (class: 3)";
}

void BitShift::hand(std::string input){
    std::cout << "\nSignal to " << getAbsolute() << " Text: " << input;
}

void BitShift::shiftFunc(std::string shift){
    short int cur = std::stoi(num);
    if(shift == "<<") result = result << cur;
    if(shift == ">>") result = result >> cur;
    std::basic_string<char> s = std::to_string(result);
    emit_signal(SIGNAL_D(BitShift::shiftSig), s);
}

void BitShift::shiftSig(std::string& input){}

int BitShift::getNum(){return 3;}
