#include "observer.h"

/**
 * This class uses the observer pattern to notify all registered observers of news
 * published by the news agency.
 *
 * The news agency is the subject in the observer pattern. Observers register
 * themselves with the news agency and it is responsible for notifying them of
 * any news that is published.
 *
 * The news agency is responsible for managing the list of observers and
 * notifying them of any news that is published. The observers are responsible
 * for their own implementation of how they want to be notified, this is done
 * through the update method.
 */
class NewAjency : public NewsSubject {
    public:
    NewAjency() = default;

    void add(std::shared_ptr<Observer> observer) override{
        _observers.push_back(observer);
    }
    void remove(std::shared_ptr<Observer> observer) override {
        for(auto it = _observers.begin(); it != _observers.end(); ++it){
            if(*it == observer){
                _observers.erase(it);
                break;
            }
        }
    }

    /**
     * Notify all registered observers of news.
     *
     * This method will iterate over all registered observers and call the
     * update method on each one, passing the message as an argument. This
     * allows each observer to handle the news in its own way.
     *
     * @param message The message that is being published.
     */
    void notifyAll(const std::string& message) override {
        std::cout << "Notifying all observers of news: " << message << "\n";
        for(const auto& obs : _observers){
            std::cout << "Notifying observer: " << obs.get() << "\n";
            obs->update(message);
        }
    }


    /**
     * Publish news to all observers.
     *
     * This method is used by the news agency to publish news to all of its
     * registered observers. It will print out a message indicating that news
     * has been published, and then call the notifyAll method to notify all
     * registered observers of the news.
     *
     * @param news The news that is being published.
     */
    void publishNews(const std::string& news) override {
        std::cout << "New Agency pubished: " << news << "\n";
        // Notify all registered observers of the news.
        notifyAll(news);
    }

    private:
    std::vector<std::shared_ptr<Observer>> _observers;
};

class Users : public Observer {
    public:
    explicit Users(const std::string& name) : _name(name){}

    void update(const std::string& message) override {
        std::cout << _name << " recieved update: " << message << "\n";
    }

    private:
    std::string _name;
};

int main(){
    NewAjency newAgency;

    auto user1 = std::make_shared<Users>("Manoj");
    auto user2 = std::make_shared<Users>("sumedha");
    auto user3 = std::make_shared<Users>("anuj");


    newAgency.add(user1);
    newAgency.add(user2);
    newAgency.add(user3);

    newAgency.publishNews("New version of C++ it out!!!");
    newAgency.publishNews("And it has even more colons!!!!");

    return 0;
}