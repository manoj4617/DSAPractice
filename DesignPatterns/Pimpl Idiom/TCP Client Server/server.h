#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <memory>


class Server{
    public:
    Server();
    ~Server();
    void start(int port);
    void send(const std::string& message);
    std::string receive();
    void close();

    private:
    class ServerImpl;
    std::unique_ptr<ServerImpl> serverImpl;
};

#endif