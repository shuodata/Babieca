//
// Created by Joaquin Bejar Garcia on 08/04/2020.
//

#include <iostream>
#include "rpc/client.h"
#include <Common.h>
#include <Book.h>

int main() {
    static Color::Modifier red(Color::FG_RED, Color::LIGHT);
    static Color::Modifier white(Color::FG_WHITE, Color::LIGHT);
    static Color::Modifier green(Color::FG_GREEN, Color::LIGHT);
    static Color::Modifier yellow(Color::FG_YELLOW, Color::LIGHT);
    static Color::Modifier def(Color::FG_DEFAULT, Color::LIGHT);

    std::string m_name = std::string("CL1");
    int id = 2;
    Book book = Book(id, m_name);
    // Creating a client that connects to the localhost on port 8080
    rpc::client client("127.0.0.1", 8080);

    Order order1(1, true, "CL", "Joaquin");

    std::string ss = order1.Serialize();


    auto result = client.call("InsertOrder", ss).as<std::string>();
    std::cout << "The result is: " << result << std::endl;

    std::vector<std::string> s_book = client.call("GetBook", "CL").as<std::vector<std::string>>();
    for (std::string b : s_book)
        std::cout << "Order: " << b << std::endl;

    book.Deserialize(s_book);

    book.Print();
    return 0;
}