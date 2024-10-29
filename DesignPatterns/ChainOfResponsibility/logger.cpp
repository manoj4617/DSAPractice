#include <iostream>
#include <memory>

using namespace std;

enum LogLevel {
    INFO = 1,
    DEBUG,
    ERROR
};

class Logger {
    public:
    ~Logger() = default;

    void setNext(shared_ptr<Logger> nLogger){
        nextLogger = nLogger;
    }

    /**
     * This function logs a message at a certain level. It takes a LogLevel and
     * a string as arguments. If the LogLevel of the message is one that this
     * Logger can handle, it calls the writeMessage() method with the message
     * string. If the LogLevel is not one that this Logger can handle, but there
     * is a next Logger in the chain, then it calls logMessage() on the next
     * Logger in the chain. This allows the message to be handled by the first
     * Logger in the chain that can handle it.
     *
     * This allows the chain of Loggers to be traversed to find the first Logger
     * that can handle a message. If no Logger can handle the message, it is
     * silently ignored.
     *
     * @param level The LogLevel of the message to be logged.
     * @param log The message to be logged.
     */
    void logMessage(LogLevel level, const string& log){
        // If the LogLevel of the message is one that this Logger can handle,
        // then write the message to the console.
        if(canHandle(level)){
            writeMessage(log);
        }
        // If the LogLevel of the message is not one that this Logger can
        // handle, then check if there is a next Logger in the chain.
        else if(nextLogger){
            // If there is a next Logger in the chain, then call logMessage()
            // on it with the same LogLevel and message.
            nextLogger->logMessage(level, log);
        }
    }

    protected:
    virtual bool canHandle(LogLevel level) = 0;
    virtual void writeMessage(const string& message) = 0;

    private:
    shared_ptr<Logger> nextLogger;
};

class InfoLogger : public Logger {
    protected:
    bool canHandle(LogLevel level) override {
        return level == INFO;
    }

    void writeMessage(const string& message) override {
        cout << "[INFO]: " << message << "\n";
    }
};

class DebugLogger : public Logger {
    protected:
    bool canHandle(LogLevel level) override {
        return level == DEBUG;
    }

    void writeMessage(const string& message) override {
        cout << "[DEBUG]: " << message << "\n";
    }
};

class ErrorLogger : public Logger {
    protected:
    bool canHandle(LogLevel level) override {
        return level == ERROR;
    }

    void writeMessage(const string& message) override {
        cout << "[ERROR]: " << message << "\n";
    }
};


int main(){

    auto infoLogger = make_shared<InfoLogger>();
    auto debugLogger = make_shared<DebugLogger>();
    auto errorLogger = make_shared<ErrorLogger>();

    infoLogger->setNext(debugLogger);
    debugLogger->setNext(errorLogger);
    
    infoLogger->logMessage(INFO, "System if running smoothly..");
    infoLogger->logMessage(DEBUG, "Low memory warning");
    infoLogger->logMessage(ERROR, "System Failure!!");

    return 0;
}