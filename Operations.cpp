#include "Operations.h"

Operations::Operations(Base* p_head_object, std::string name_object):Base(p_head_object, name_object){}

void Operations::sig(std::string& input){
    std::cout << "\nSignal from " << getAbsolute();
    input += " (class: 5)";
}

void Operations::hand(std::string input){
    std::cout << "\nSignal to " << getAbsolute() << " Text: " << input;
}

void Operations::operationsRead(std::string oper){
    short int num2 = std::stoi(num);
    if(oper == "+") result += num2;
    else if(oper == "-") result -= num2;
    else if(oper == "*") result *= num2;
    else if(oper == "/"){
        if(num2 == 0){
            result = 0;
            num = "    Division by zero";
        } else result /= num2;
    } else if(oper == "%"){
        if(num2 == 0){
            result = 0;
            num = "    Division by zero";
        } else result %= num2;
    }
    std::basic_string<char> s = std::to_string(result);
    emit_signal(SIGNAL_D(Operations::operSig), s);
}

int Operations::getNum(){return 5;}

void Operations::operSig(std::string& m){}