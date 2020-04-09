//
// Created by Joaquin Bejar Garcia on 08/04/2020.
//
# pragma once
#ifndef BABIECA_COMMON_H
#define BABIECA_COMMON_H

struct Order {
    std::string id;
    int type;
    bool direction;
    std::string marketid;
    std::string userid;
    Order(int type, bool direction, std::string m, std::string u);

private:
    static std::string __to_rand();
    static std::string __id_generator();
};
#endif //BABIECA_COMMON_H


