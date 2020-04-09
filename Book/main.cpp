//
// Created by Joaquin Bejar Garcia on 08/04/2020.
//

#include <iostream>
#include <Common.h>


int main() {
    Order order1(1, true, "CL", "Joaquin");

    std::cout << "ID: " << order1.id << std::endl;
    std::cout << "type: " << order1.type << std::endl;
    std::cout << "direction: " << order1.direction << std::endl;
    std::cout << "marketid: " << order1.marketid << std::endl;
    std::cout << "userid: " << order1.userid << std::endl;

    return 0;
}