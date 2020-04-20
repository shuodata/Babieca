//
// Created by Joaquin Bejar Garcia on 17/04/2020.
//
#include <iostream>
#include "Book.h"
#include "Common.h"
#include <utility>
#include <vector>

static Color::Modifier red(Color::FG_RED, Color::LIGHT);
static Color::Modifier white(Color::FG_WHITE, Color::LIGHT);
static Color::Modifier green(Color::FG_GREEN, Color::LIGHT);
static Color::Modifier yellow(Color::FG_YELLOW, Color::LIGHT);
static Color::Modifier def(Color::FG_DEFAULT, Color::LIGHT);

ListOrders::ListOrders(int &id, std::string &name) : marketid(id), marketname(name){

}
void ListOrders::Print() const {
    for (Order o : orders)
        o.PrintOrder();
}

Book::Book(int id, std::string name) : __marketid(id), __marketname(std::move(name)) {
    std::cout << "soy un book" << std::endl;
}
ListOrders Book::GetBook(){
    std::cout << "Cojo el book" << std::endl;
    orders.Print();
    return orders;
}

std::vector<std::string> Book::Serialize(){
    std::vector<std::string> v;
    for (Order o : orders.orders)
        v.push_back(o.Serialize());
    return v;
}

void Book::Deserialize(const std::vector<std::string>& vs){
    //ListOrders t_orders = ListOrders(__marketid, __marketname);
    Order t_o;
    this->orders = ListOrders(__marketid, __marketname);
    for (std::string __or : vs) {
        t_o.Deserialize(__or);
        orders.orders.push_back(t_o);
    }
}

void Book::Print(){
    std::cout << yellow << "MarketId: " << red << __marketid << def << std::endl;
    std::cout << yellow << "MarketName: " << red  << __marketname << def << std::endl;
    orders.Print();
}

bool Book::InsertOrder(Order order){
    order.PrintOrder();
    orders.orders.push_back(order);
    return true;
}
bool Book::RemoveOrder(Order order){
    return true;
}
bool Book::WipeMarket(Market market){
    return true;
}
bool Book::CloseMarket(Market market){
    return true;
}
bool Book::OpenMarket(Market market) {
    return true;
}

