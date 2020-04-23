//
// Created by Joaquin Bejar Garcia on 17/04/2020.
//

#ifndef BABIECA_BOOK_H
#define BABIECA_BOOK_H

#include <Common.h>
#include <Market.h>
#include <vector>

struct ListOrders {
    int marketid;
    std::string marketname;
    std::vector<Order> orders;

    ListOrders(int &id, std::string &name);
    void Print() const ;

};

class Book {
    int __marketid;
    std::string __marketname;
    ListOrders orders = ListOrders(__marketid, __marketname);

public:
    Book(int id, std::string name);
    ListOrders GetBook();
    std::vector<std::string> Serialize();
    void Deserialize(const std::vector<std::string>& vs);
    void Print();
    bool InsertOrder(const Order& order);
    bool RemoveOrder(Order order);
    bool WipeMarket(Market market);
    bool CloseMarket(Market market);
    bool OpenMarket(Market market);


};





#endif //BABIECA_BOOK_H
