#include "server.h"
#include "network_exceptions.h"
#include <cstring>
#include <arpa/inet.h>
#include <memory>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class Server::ServerImpl{
    public:
    int sockfd;
    int clientfd;

    ServerImpl() : sockfd(-1), clientfd(-1) {}

    void start(int port){
        sockfd = socket(AF_INET, SOCK_STREAM,0);
        if(sockfd < 0){
            throw ServerStartFailed("Unable to create socket\n");
        }
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);

        if(bind(sockfd, (sockaddr*)&addr, sizeof(addr)) < 0){
            throw ServerStartFailed("Binding failed on port " + std::to_string(port));            
        }

        if(listen(sockfd, 10) < 0){
            ::close(sockfd);
            throw ServerStartFailed("Listening failed\n");
        }

        struct sockaddr_in clientAddr;
        socklen_t addrLen = sizeof(clientAddr);
        clientfd = accept(sockfd, (sockaddr*)&clientAddr, &addrLen);
        if(clientfd < 0){
            ::close(sockfd);
            ::close(clientfd);
            throw ServerStartFailed("Failed to accept client connections\n");
        }
        std::cout << "Client Connected\n";
    }

    std::string recieve(){
        char buffer[1024];
        size_t bytesReceived = ::recv(clientfd,buffer,sizeof(buffer),0);
        if(bytesReceived < 0){
            throw ReceiveFailed("Failed to receive message\n");
        }
        return std::string(buffer,bytesReceived);
    }

    void send(const std::string& message){
        if(::send(clientfd, message.c_str(),message.size(),0) < 0){
            throw SendFailed("Failed to send message");
        }
    }

    void close(){
        if(clientfd >= 0){
            ::close(clientfd);
            clientfd = -1;
        }
        if(sockfd >= 0){
            ::close(sockfd);
            sockfd = -1;
        }
    }
    ~ServerImpl(){
        close();
    }
};

Server::Server() : serverImpl(std::make_unique<ServerImpl>()){}

Server::~Server() = default;

void Server::send(const std::string& message){
    serverImpl->send(message);
}

std::string Server::receive(){
    return serverImpl->recieve();
}

void Server::start(int port){
    serverImpl->start(port);
}

void Server::close(){
    serverImpl->close();
}