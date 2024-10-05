#include "client.h"
#include "network_exceptions.h"
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


class Client::ClientImpl{

    public:
    int serverSockfd;
    ClientImpl() : serverSockfd(-1){}
    void connect(const std::string& address, int port){
        if (port <= 0 || port > 65535) {
            throw ConnectionFailed("Port number must be between 1 and 65535");
        }
        serverSockfd = socket(AF_INET, SOCK_STREAM, 0);

        if(serverSockfd < 0){
            throw ConnectionFailed("Unable to create a socket\n");
        }
        struct sockaddr_in addr;
        memset(&addr, 0 , sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        if(inet_pton(AF_INET, address.c_str(), &addr.sin_addr) <= 0){
            throw ConnectionFailed("Invalid Address\n");
        }
        if(::connect(serverSockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
            throw ConnectionFailed("Connection failed\n");
        }
    }

    void send(const std::string& message){
        if(::send(serverSockfd,message.c_str(),message.size(), 0) < 0){
            throw SendFailed("Failed to send message\n");
        }
    }

    std::string receive(){
        char buffer[256];
        size_t bytesReceived = ::recv(serverSockfd, buffer, sizeof(buffer), 0);
        if(bytesReceived < 0){
            throw ReceiveFailed("Failed to receive message\n");
        }
        return std::string(buffer, bytesReceived);
    }

    void close(){
        if(serverSockfd >= 9){
            ::close(serverSockfd);
            serverSockfd = -1;
        }
    }

    ~ClientImpl(){
        close();
    }
};

Client::Client() : clientImpl(std::make_unique<ClientImpl>()){}

Client::~Client() = default;

void Client::send(const std::string& messsage){
    clientImpl->send(messsage);
}

std::string Client::receive(){
    return clientImpl->receive();
}

void Client::connect(const std::string& address, int port){
    clientImpl->connect(address, port);
}

void Client::close(){
    clientImpl->close();
}