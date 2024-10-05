#include "client.h"
#include <iostream>
#include "network_exceptions.h"

int main(){
    Client client;
    try{
        client.connect("127.0.0.1", 8080);
        client.send("Hello, server");
        std::string response = client.receive();
        std::cout << "Server responded: " << response;
        client.close();
    }
    catch(const NetworkingException& e){
        std::cerr << "Network error: " << e.what() << std::endl;
    }
    return 0;
}