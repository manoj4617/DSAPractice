#include <iostream>
#include <memory>
#include <vector>


class Observer {
    public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};

class NewsSubject {
    public:
    virtual void add(std::shared_ptr<Observer>) = 0;
    virtual void remove(std::shared_ptr<Observer>) = 0;
    virtual void notifyAll(const std::string& message) = 0;
    virtual void publishNews(const std::string& news) = 0;
};