//
// Created by Joaquin Bejar Garcia on 08/04/2020.
//

#include <iostream>
#include <Common.h>
#include <Book.h>
#include "rpc/server.h"

void foo() {
    std::cout << "foo was called!" << std::endl;

}

int main() {

    static Color::Modifier red(Color::FG_RED, Color::LIGHT);
    static Color::Modifier white(Color::FG_WHITE, Color::LIGHT);
    static Color::Modifier green(Color::FG_GREEN, Color::LIGHT);
    static Color::Modifier yellow(Color::FG_YELLOW, Color::LIGHT);
    static Color::Modifier def(Color::FG_DEFAULT, Color::LIGHT);

    Book book = Book(1,"CL");
    //t = book.InsertOrder(order1);
    rpc::server srv(8080);


    srv.bind("InsertOrder", [&book](std::string s) {

        Order order1;
        std::cout << green << "InsertOrder: "<< def;

        order1.Deserialize(s);
        book.InsertOrder(order1);
        return s;
    });

    // Binding a lambda function to the name "add".
    srv.bind("GetBook", [&book](std::string& s){
        //book.GetBook();
        return book.Serialize();
    });



    // Run the server loop.
    //srv.run();
    constexpr size_t thread_count = 8;
    srv.async_run(thread_count); // non-blocking call, handlers execute on one of the workers
    std::cin.ignore();
    return 0;

}