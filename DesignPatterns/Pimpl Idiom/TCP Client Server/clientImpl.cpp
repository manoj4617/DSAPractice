#include "client.h"
#include "network_exceptions.h"
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


class Client::ClientImpl{
  
    int sockfd;
    ClientImpl() : sockfd(-1){}

    public:
    void connect(const std::string& address, int port){
        if (port <= 0 || port > 65535) {
            throw ConnectionFailed("Port number must be between 1 and 65535");
        }
        struct sockaddr_in addr;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0){
            throw ConnectionFailed("Unable to create a socket\n");
        }
        memset(&addr, 0 , sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        if(inet_pton(AF_INET, address.c_str(), &addr.sin_addr) <= 0){
            close();
            throw ConnectionFailed("Invalid Address\n");
        }
        if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) <= 0){
            close();
            throw ConnectionFailed("Connection failed\n");
        }
    }

};

Client::Client(){
    clientImpl = std::unique_ptr<ClientImpl>();
}

Client::~Client(){
    close();
}