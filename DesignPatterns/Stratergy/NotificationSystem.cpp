#include <iostream>
#include <memory>

using namespace std;

class NotificationStrategy{
    public:
    virtual void notify(const string& message) = 0;
};

class EmailNotification : public NotificationStrategy {
    public:
    void notify(const string& message){
        cout << "Email Notification: " << message << endl;
    }
};

class SMSNotification : public NotificationStrategy {
    public:
    void notify(const string& message){
        cout << "SMS Notification: " << message << endl;
    }
};

class PushNotification : public NotificationStrategy {
    public:
    void notify(const string& message){
        cout << "Push Notification: " << message << endl;
    }
};

class NotificationSystem {
    private:
    unique_ptr<NotificationStrategy> notificationStrategy;

    public:
    explicit NotificationSystem(unique_ptr<NotificationStrategy> strategy){
        this->notificationStrategy = std::move(strategy);
    }

    void setStrategy(unique_ptr<NotificationStrategy> newStrategy){
        this->notificationStrategy = std::move(newStrategy);
    }

    void notify(const string& message){
        notificationStrategy->notify(message);
    }
};

class User : public NotificationSystem {
    private:
    string name;
    
    public:
    User(const string& name, unique_ptr<NotificationStrategy> strategy) :
        name(name), NotificationSystem(std::move(strategy)){}

    void setUserName(const string& name){
        this->name = name;
    }

    string getUserName(){
        return this->name;
    }
};

int main(){
   
    User user("Manoj", make_unique<EmailNotification>());
    user.notify("Hello, " + user.getUserName());

    unique_ptr<NotificationStrategy> sms = make_unique<SMSNotification>();
    user.setStrategy(std::move(sms));
    user.notify("SMS: Hello, " + user.getUserName());
    return 0;
}