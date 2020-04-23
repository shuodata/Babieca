//
// Created by Joaquin Bejar Garcia on 08/04/2020.
//

#include <iostream>
#include <Common.h>
#include <Book.h>
#include "rpc/server.h"
#define KXVER 4
//#include <k.h>
#include <kdb.h>


void foo() {
    std::cout << "foo was called!" << std::endl;

}
#define HOST_ADDR "127.0.0.1"
#define HOST_PORT 5000

int main() {


    kdb::Connector kcon;
    if (!kcon.connect(HOST_ADDR, HOST_PORT))
        return -1;

    kdb::Result res = kcon.sync("2+2");
    std::cout << Color::green << res << Color::def << std::endl;
    //int c=khp("localhost",5000);
    //std::cout << green << c << k(c,"2+2",(K)0) << def;

    Book book = Book(1,"CL");
    //t = book.InsertOrder(order1);
    rpc::server srv(8080);


    srv.bind("InsertOrder", [&book](std::string s) {

        Order order1;
        std::cout << Color::green << "InsertOrder: "<< Color::def;

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