//
// Created by Joaquin Bejar Garcia on 08/04/2020.
//
#include <set>

#include <iostream>
#include <random>
#include "Common.h"
#include <chrono>
#include <ostream>


Order::Order(int t, bool d, std::string m, std::string u) : id(__id_generator()), type(t), direction(d), marketname(m),
                                                            userid(u) {
    std::cout << id << type << direction << std::endl;
}
Order::Order() {

}

std::string Order::Serialize() const{
    std::string ss;
    ss += id + ";";
    ss += std::to_string(direction) + ";";
    ss += std::to_string(type) + ";";
    ss += marketname + ";";
    ss += userid;

    return ss;
}

void Order::Deserialize(std::string s){

    std::string target;
    id = __subString(s, ";");
    direction = std::stoi(__subString(s, ";"));
    type = std::stoi(__subString(s, ";"));
    marketname = __subString(s, ";");
    userid = __subString(s, ";");

}

void Order::PrintOrder() const{
    static Color::Modifier red(Color::FG_RED, Color::LIGHT);
    static Color::Modifier yellow(Color::FG_YELLOW, Color::LIGHT);
    static Color::Modifier def(Color::FG_DEFAULT, Color::LIGHT);
    static Color::Modifier cyan(Color::FG_CYAN, Color::LIGHT);

    std::cout << cyan << "{";
    std::cout << yellow << " id: " << red << id << "," ;
    std::cout << yellow << " type: " << red << type << ",";
    std::cout << yellow << " direction: " << red << direction << ",";
    std::cout << yellow << " marketname: " << red << marketname << "," ;
    std::cout << yellow << " userid: " << red << userid;
    std::cout << cyan << " }";
    std::cout << def << std::endl;
}

std::string Order::__subString(std::string& s, char d[1]){
    int i = s.find(d);
    std::string target = s.substr(0,i);
    s.erase(0, i+1);

    return target;
}

std::string Order::__to_rand() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1000, 9999);

    return std::to_string(dist(mt));
}

std::string Order::__id_generator() {
    unsigned long int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return std::to_string(now) + "-" + __to_rand() + "-" + __to_rand() + "-" + __to_rand() + "-" + __to_rand() + "-" +
           __to_rand();
}


namespace Color {

        Modifier::Modifier(Code pCode, Bright pBright) : code(pCode), bright(pBright) {}
        std::ostream &operator<<(std::ostream &os, const Modifier &mod) {
            return os << "\033[" << mod.bright << ";" << mod.code << "m";
        };

}

