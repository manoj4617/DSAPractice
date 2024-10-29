#include <iostream>
#include <memory>

using namespace std;

class Handler{
    public:
    ~Handler() = default;
    void setNext(shared_ptr<Handler> nextHandler){
        next = nextHandler;
    }

    void handleRequest(const string& request){
        if(canHandle(request)){
            process(request);
        }
        else if(next){
            next->handleRequest(request);
        }
        else{
            cout << "No suitable handler available to process the request\n";
        }
    }

    private:
    shared_ptr<Handler> next;
    
    protected:
    virtual bool canHandle(const string& request) = 0;
    virtual void process(const string& request) = 0;
};

class L1Support : public Handler{
    protected:
    bool canHandle(const string& request) override {
        return request == "Simple issue\n";
    }

    void process(const string& request) override {
        cout << "Level 1 support: Handling " << request << "\n";
    }
};

class L2Support : public Handler{
    protected:
    bool canHandle(const string& request) override {
        return request == "Complex issue\n";
    }

    void process(const string& request) override {
        cout << "Level 2 support: Handling " << request << "\n";
    }
};

class Manager : public Handler{
    protected:
    bool canHandle(const string& request) override {
        return request == "Excalating issue\n";
    }

    void process(const string& request) override {
        cout << "Manager: Handling " << request << "\n";
    }
};

int main(){

    auto level1 = make_shared<L1Support>();
    auto level2 = make_shared<L2Support>();
    auto manager = make_shared<Manager>();

    level1->setNext(level2);
    level2->setNext(manager);

    string str = "Complex issue\n";
    level1->handleRequest(str);
    str = "Excalating issue\n";
    level1->handleRequest(str);
    return 0;

}