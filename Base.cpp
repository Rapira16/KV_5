#include "Base.h"

Base::Base(Base* p_head_object, std::string name_object) : p_head_object(p_head_object), name_object(name_object){
    if (p_head_object != nullptr){
        p_head_object -> subordinate_objects.push_back(this);
    }
}

bool Base::changeName(std::string new_name){
    if(getParent() != nullptr && getParent()->getChild(new_name) != nullptr) return false;
    name_object = new_name;
    return true;
}

std::string Base::getName() const {return name_object;}

Base* Base::getParent() const {return p_head_object;}

Base* Base::getChild(std::string child_name){
    for (auto subordinate : subordinate_objects){
        if (subordinate -> name_object == child_name) return subordinate;
    }
    return nullptr;
}

Base::~Base(){
    for(auto subordinate : subordinate_objects){
        delete subordinate;
    }
}

Base* Base::searchOnBranch(std::string name_object){
    Base* found = nullptr;
    std::vector<Base*> elements;
    elements.push_back(this);
    while(!elements.empty()){
        Base* elem = elements[0];
        elements.erase(elements.begin());
        if(elem -> name_object == name_object){
            if (found != nullptr) return nullptr;
            else found = elem;
        }
        for(int i = 0; i < elem->subordinate_objects.size(); i++){
            elements.push_back(elem->subordinate_objects[i]);
        }
    }
    return found;
}

Base* Base::searchOnTree(std::string name_object){
    if (p_head_object != nullptr) return p_head_object->searchOnTree(name_object);
    else return searchOnBranch(name_object);
}

void Base::printTree(){
    static int level = 0;
    std::cout << std::endl;
    for (int i = 0; i < level; i++){
        std::cout << "    ";
    }
    std::cout << name_object;
    level++;
    for (auto subordinate : subordinate_objects){
        subordinate->printTree();
    }
    level--;
}

void Base::printStatesOfTree(){
    Base* object = getParent();
    while(object != nullptr){
        std::cout << "    ";
        object = object->getParent();
    }
    std::cout << name_object << std::endl;
    if (state) std::cout << " is ready\n";
    else std::cout << " is not ready\n";
    for(auto subordinate : subordinate_objects){
        subordinate->printStatesOfTree();
    }
}

void Base::setState(int state){
    if(p_head_object == nullptr || p_head_object -> state != 0) this -> state = state;
    if(state == 0){
        this -> state = state;
        for(int i = 0; i < subordinate_objects.size(); i++){
            subordinate_objects[i] -> setState(state);
        }
    }
}

bool Base::changeHead(Base* head_new){
    if(this -> getParent() == head_new) return true;
    if(this -> getParent() == nullptr) return false;
    if(head_new == nullptr) return false;
    if(head_new -> getChild(this -> getName()) != nullptr) return false;

    std::vector<Base*> elements;
    elements.push_back(this);

    while(!elements.empty()){
        Base* current = elements.back();
        elements.pop_back();
        if(current == head_new) return false;
        for(auto subordinate : current -> subordinate_objects){
            elements.push_back(subordinate);
        }
    }
    std::vector<Base*> & elem = this -> getParent() -> subordinate_objects;
    for(int i = 0; i < elem.size(); i++){
        if(elem[i] -> getName() == this -> getName()){
            elem.erase(elem.begin() + i);
            head_new -> subordinate_objects.push_back(this);
            return true;
        }
    }
    return false;
}

void Base::killChild(std::string name_child){
    std::vector<Base*> & elem = this -> subordinate_objects;
    for(int i = 0; i < elem.size(); i++){
        if(elem[i] -> getName() == name_child){
            delete elem[i];
            elem.erase(elem.begin()+i);
            return;
        }
    }
}

Base* Base::getByPath(std::string path){
    if(path.empty()) return nullptr;
    if(path == ".") return this;
    if(path[0] == '.') return searchOnBranch(path.substr(1));
    if(path.substr(0, 2) == "//") return this -> searchOnTree(path.substr(2));
    if(path[0] != '/'){
        int slash = path.find('/');
        Base* child = this -> getChild(path.substr(0, slash));
        if(child == nullptr || slash == -1) return child;
        return child -> getByPath(path.substr(slash + 1));
    }
    Base* object = this;
    while(object -> getParent() != nullptr){
        object = object -> getParent();
    }
    if(path == "/") return object;
    return object -> getByPath(path.substr(1));
}

void Base::set_connect(TYPE_SIGNAL p_signal, Base * p_object, TYPE_HANDLER p_ob_hendler){
    o_sh* p_value;
    for (unsigned int i = 0; i < connects.size(); i ++ )   {
        if (connects [i] -> p_signal == p_signal &&
            connects [i] -> p_cl_base == p_object &&
            connects [i] -> p_hendler == p_ob_hendler) return;
    }

    p_value =  new o_sh();
    p_value -> p_signal  = p_signal;
    p_value -> p_cl_base = p_object;
    p_value -> p_hendler = p_ob_hendler;
    connects.push_back (p_value);
}

void Base::emit_signal(TYPE_SIGNAL p_signal, std::basic_string<char> s_command){
    if(this -> state == 0) return;
    TYPE_HANDLER p_handler;
    Base* p_object;
    (this ->* p_signal)(s_command);
    for ( unsigned int i = 0; i < connects.size(); i++ ){
        if (connects [i] -> p_signal == p_signal){
            p_handler = connects[i] -> p_hendler;
            p_object  = connects[i] -> p_cl_base;
            if(p_object -> state != 0) (p_object ->* p_handler)(s_command);
        }
    }
}

void Base::disconnect(TYPE_SIGNAL p_signal, Base * p_object, TYPE_HANDLER p_ob_hendler){
    for ( unsigned int i = 0; i < connects.size(); i++ ){
        if (connects [i] -> p_signal == p_signal &&
            connects [i] -> p_cl_base == p_object &&
            connects [i] -> p_hendler == p_ob_hendler){
            delete connects[i];
            connects.erase(connects.begin() + i);
            return;
        }
    }
}

void Base::setBranch(int state){
    if(getParent() && !(getParent() -> state)) return;
    setState(state);
    for(auto subordinate : subordinate_objects){
        subordinate -> setBranch(state);
    }
}

int Base::getNum() {return 0;}

std::string Base::getAbsolute(){
    std::string out;
    std::vector<std::string> elem;
    Base* object = this;
    while(object -> getParent()){
        elem.push_back(object -> getName());
        object = object -> getParent();
    }
    while(!elem.empty()){
        out += "/" + elem.back();
        elem.pop_back();
    }
    if(!out.size()){
        return "/";
    }
    return out;
}
