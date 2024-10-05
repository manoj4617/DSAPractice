#include "server.h"
#include "network_exceptions.h"


int main(){
    Server server;
    try{
        while(true){
            server.start(8080);
            std::string message = server.receive();
            std::cout << "Message received: " << message << "\n";
            server.send("Message Recieved:" + message + "Thank you!!\n");
        }
        server.close();
    } catch(const NetworkingException& e){
        std::cerr << "Network error: " << e.what() << std::endl;
    }
    return 0;
}