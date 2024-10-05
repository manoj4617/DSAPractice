#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <memory>


class Client{
    public:
    Client();
    ~Client();
    void connect(const std::string& address, int port);
    void send(const std::string& message);
    std::string receive();
    void close();

    private:
    class ClientImpl;
    std::unique_ptr<ClientImpl> clientImpl;
};

#endif