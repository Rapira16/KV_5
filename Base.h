#ifndef __BASE__H
#define __BASE__H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f)
#define HENDLER_D(hendler_f)(TYPE_HANDLER)(&hendler_f)

class Base;
typedef void (Base::*TYPE_SIGNAL)(std::string&);
typedef void (Base::*TYPE_HANDLER)(std::string);

class Base{
    struct o_sh{
        TYPE_SIGNAL p_signal;
        Base* p_cl_base;
        TYPE_HANDLER p_hendler;
    };
private:
    std::string name_object;
    Base* p_head_object;
    std::vector<Base*> subordinate_objects;
    int state = 0;
    std::vector <o_sh*> connects;
public:
    int b = 0;
    int result = 0;
    std::string num = "";
    std::string out = "";
    std::string expr = "";
    Base(Base* p_head_objects, std::string name_object = "default");
    bool changeName(std::string new_name);
    std::string getName() const;
    Base* getParent() const;
    Base* getChild(std::string child_name);
    Base* searchOnBranch(std::string name_object);
    Base* searchOnTree(std::string name_object);
    void printTree();
    void printStatesOfTree();
    void setState(int);
    bool changeHead(Base* p_head_object);
    void killChild(std::string name_object);
    Base* getByPath(std::string path);

    void set_connect(TYPE_SIGNAL p_signal, Base* p_cl_base, TYPE_HANDLER p_hendler);
    void emit_signal(TYPE_SIGNAL p_signal, std::basic_string<char> s_command);
    void disconnect(TYPE_SIGNAL p_signal, Base* p_cl_base, TYPE_HANDLER p_hendler);
    void setBranch(int state);
    std::string getAbsolute();
    virtual int getNum();
    typedef void (Base::*TYPE_SIGNAL)(std::string&);
    typedef void (Base::*TYPE_HANDLER)(std::string);
    ~Base();
};

#endif

