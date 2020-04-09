//
// Created by Joaquin Bejar Garcia on 08/04/2020.
//

#include <iostream>
#include <random>
#include "Common.h"


Order::Order(int t, bool d, std::string m, std::string u ) : id(__id_generator()), type(t), direction(d), marketid(m), userid(u) {

        std::cout << id << type << direction << std::endl;
    }
    
std::string Order::__to_rand() {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<> dist(1000, 9999);

        return std::to_string(dist(mt));
    }

std::string Order::__id_generator() {
        return __to_rand() + "-" + __to_rand() + "-" + __to_rand() + "-" + __to_rand() + "-" + __to_rand() + "-" +
               __to_rand();
    }
