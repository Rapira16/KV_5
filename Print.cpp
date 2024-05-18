#include "Print.h"

Print::Print(Base* p_head_object, std::string name_object):Base(p_head_object, name_object){}

void Print::sig(std::string& input){
    std::cout << "\nSignal from " << getAbsolute();
    input += " (class: 6)";
}

void Print::hand(std::string input){
    std::cout << "\nSignal to " << getAbsolute() << " Text: " << input;
}

void Print::print(){
    if(num == "C" || num == "Off") num = "";
    else if(result > 32767 || result < -32768){
        std::cout << expr << "    Overflow";
        result = 0;
        expr = "";
    } else if(num == "    Division by zero"){
        std::cout << '\n' << expr << "    Division by zero";
        expr = "0";
    } else{
        if(b != 0) std::cout << '\n';
        std::cout << expr << "    HEX " << std::setw(4) << std::setfill('0') << std::uppercase << std::hex << result;
        std::cout << "  BIN" << result;
        std::bitset<16> binaryNumber(result);
        std::string binaryString = binaryNumber.to_string();
        for(int i = 4; i < binaryString.length(); i+=5) binaryString.insert(i, " ");
        b++;
    }
}

int Print::getNum(){return 6;}