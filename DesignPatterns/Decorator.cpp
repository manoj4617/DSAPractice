#include <functional>
#include <iostream>
#include <string>
#include <memory>

class Coffee {
    public:
    virtual ~Coffee() = default;
    virtual std::string description() const = 0;
    virtual double cost() const = 0;
};


/*
Base coffee classes
Base Coffee is-a Coffee
*/
class Espresso : public Coffee {
    public:
    std::string description() const override {
        return "Espresso";
    }
    double cost() const override {
        return 100.00;
    }
};

class Cappaccino : public Coffee {
    public:
    std::string description() const override {
        return "Cappaccino";
    }

    double cost() const override {
        return 150.00;
    }
};
/*
Base coffee
*/


/*
Coffee decorators
Decorator is-a Coffee
Decorator has-a coffee
*/
class CoffeeDecorator : public Coffee {
    public:
   explicit CoffeeDecorator(std::shared_ptr<Coffee> coffee) :
    wrappedCoffee(std::move(coffee)){}

    std::string description() const override {
        return wrappedCoffee->description();
    }

    double cost() const override {
        return wrappedCoffee->cost();
    }
    protected:
    std::shared_ptr<Coffee> wrappedCoffee;
};

class MilkDecorator : public CoffeeDecorator {
    public:
    using CoffeeDecorator::CoffeeDecorator;

    std::string description() const override {
        return wrappedCoffee->description() + ", Milk";
    }

    double cost() const override {
        return wrappedCoffee->cost() + 10.50;
    }
};

class SugarDecorator : public CoffeeDecorator {
    public:
    using CoffeeDecorator::CoffeeDecorator;

    std::string description() const override {
        return wrappedCoffee->description() + ", Sugar";
    }

    double cost() const override {
        return wrappedCoffee->cost() + 7.65;
    }
};

class CreamDecorator : public CoffeeDecorator {
    public:
    using CoffeeDecorator::CoffeeDecorator;

    std::string description() const override {
        return wrappedCoffee->description() + ", Cream";
    }

    double cost() const override {
        return wrappedCoffee->cost() + 17.65;
    }
};
/*
Coffee decorators
*/


int main() {
    std::shared_ptr<Coffee> coffee = std::make_shared<Espresso>();

    coffee = std::make_shared<MilkDecorator>(coffee);
    coffee = std::make_shared<SugarDecorator>(coffee);
    coffee = std::make_shared<CreamDecorator>(coffee);
    coffee = std::make_shared<MilkDecorator>(coffee);


    std::shared_ptr<Coffee> cap_coffee = std::make_shared<Cappaccino>();
    cap_coffee = std::make_shared<MilkDecorator>(cap_coffee);
    cap_coffee = std::make_shared<SugarDecorator>(cap_coffee);

    std::cout << "Order: " << coffee->description() << "\n";
    std::cout << "Cost: " << coffee->cost() << "\n";

    std::cout << "Order: " << cap_coffee->description() << "\n";
    std::cout << "Cost: " << cap_coffee->cost() << "\n";
}