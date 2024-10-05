#include <exception>
#include <stdexcept>

class NetworkingException : public std::runtime_error{
    public:
    explicit NetworkingException(const std::string& message) :
        std::runtime_error(message)
        {}
};


class ConnectionFailed : public NetworkingException {
    public:
    explicit ConnectionFailed(const std::string& message) :
        NetworkingException(message){}
};

class SendFailed : public NetworkingException {
    public:
    explicit SendFailed(const std::string& message) :
        NetworkingException(message){}
};

class ReceiveFailed : public NetworkingException {
    public:
    explicit ReceiveFailed(const std::string& message) :
        NetworkingException(message){}
};

class ServerStartFailed : public NetworkingException {
    public:
    explicit ServerStartFailed(const std::string& message) :
        NetworkingException(message){}
};