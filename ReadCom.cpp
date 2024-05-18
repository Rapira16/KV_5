#include "ReadCom.h"

ReadCom::ReadCom(Base* p_head_object, std::string name_object):Base(p_head_object, name_object){}

void ReadCom::sig(std::string& input){
    std::cout << "\nSignal from " << getAbsolute();
    input += " (class: 7)";
}

void ReadCom::hand(std::string input){
    std::cout << "\nSignal to " << getAbsolute() << " Text: ";
}

void ReadCom::read(){
    std::string com;
    std::cin >> com;
    if(com == "C" || com == "Off") {
        std::basic_string<char> s = com;
        emit_signal(SIGNAL_D(ReadCom::readSig), s);
    }
    else if(com == "+" || com == "-" || com == "*" || com == "/" || com == "%" || com == "<<" || com == ">>"){
        expr += " " + com;
        std::cin >> num;
        expr += " " + num;
        std::basic_string<char> s = com;
        emit_signal(SIGNAL_D(ReadCom::readSig), s);
    } else {
        expr = com;
        result = stoi(expr);
    }
}

int ReadCom::getNum(){return 7;}

void ReadCom::readSig(std::string& m){}