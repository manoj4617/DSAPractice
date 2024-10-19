#include <iostream>
#include <memory>
#include <functional>
#include <unordered_map>

class Vehicle {
    public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle{
    public:
    void drive() override {
        std::cout << "Driving car...\n";
    }
};

class Bike : public Vehicle {
    public:
    void drive() override {
        std::cout << "Driving bike....\n";
    }
};

class Truck : public Vehicle {
    public:
    void drive() override {
        std::cout << "Driving truck...\n";
    }
};

class VehicleFactory{
    public:
    using CreateVehicleFunc = std::function<std::shared_ptr<Vehicle>()>;

    void registerVehicle(const std::string& type, CreateVehicleFunc createFunc){
        registry[type] = createFunc;
    }

    std::shared_ptr<Vehicle> createVehicle(const std::string& type) const {
        auto it = registry.find(type);
        if(it != registry.end()){
            return it->second();
        }
        throw std::runtime_error("Vehicle type not registered\n");
    }

    private:
    std::unordered_map<std::string, CreateVehicleFunc> registry;
};

int main(){
    VehicleFactory factory;
    factory.registerVehicle("car", [] () -> std::shared_ptr<Vehicle> {
        return std::make_unique<Car>();
    });

    factory.registerVehicle("bike", [] () -> std::shared_ptr<Vehicle> {
        return std::make_unique<Bike>();
    });
    factory.registerVehicle("truck", [] () -> std::shared_ptr<Vehicle> {
        return std::make_unique<Truck>();
    });
    std::shared_ptr<Vehicle> myCar = factory.createVehicle("car");
    std::shared_ptr<Vehicle> myBike = factory.createVehicle("bike");
    std::shared_ptr<Vehicle> myTruck = factory.createVehicle("truck");
    myCar->drive();
    std::shared_ptr<Vehicle> mySecondCar = myCar;
    std::shared_ptr<Vehicle> myThirdCar = myCar;

    std::cout << "Reference count: " << myCar.use_count() << std::endl;
    myBike->drive();
    myTruck->drive();
    return 0;
}