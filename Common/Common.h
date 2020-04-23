//
// Created by Joaquin Bejar Garcia on 08/04/2020.
//

#ifndef BABIECA_COMMON_H
#define BABIECA_COMMON_H

#include <ostream>


struct Order {
public:
    std::string id;
    int type;
    bool direction;
    std::string marketname;
    std::string userid;

    Order(int type, bool direction, std::string m, std::string u);

    Order();

    std::string Serialize() const;

    void Deserialize(std::string s);

    void PrintOrder() const;

private:
    static std::string __to_rand();

    static std::string __id_generator();

    std::string __subString(std::string &s, char d[1]);
};


namespace Color {


    enum Code {
        FG_RED = 31,
        FG_GREEN = 32,
        FG_YELLOW = 33,
        FG_BLUE = 34,
        FG_PURPLE = 35,
        FG_CYAN = 36,
        FG_WHITE = 37,
        FG_DEFAULT = 39,
    };
    enum Bright {
        DARK = 0,
        LIGHT = 1
    };
    class Modifier {
        Code code;
        Bright bright;
    public:
        Modifier(Code pCode, Bright pBright);

        friend std::ostream &operator<<(std::ostream &os, const Modifier &mod);

    };
    static Color::Modifier red(Color::FG_RED, Color::LIGHT);
    static Color::Modifier white(Color::FG_WHITE, Color::LIGHT);
    static Color::Modifier green(Color::FG_GREEN, Color::LIGHT);
    static Color::Modifier yellow(Color::FG_YELLOW, Color::LIGHT);
    static Color::Modifier def(Color::FG_DEFAULT, Color::LIGHT);
}

#endif //BABIECA_COMMON_H


