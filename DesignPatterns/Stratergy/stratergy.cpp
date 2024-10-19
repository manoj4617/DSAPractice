#include "DriveStratergy.h"
#include <memory>
#include <utility>

/**
 * The Strategy pattern is used in this code to allow the `Vehicle` class to
 * dynamically change its behavior at runtime. The `Vehicle` class delegates
 * the `drive` behavior to a `DriveStrategy` object. This allows different
 * driving strategies to be used interchangeably without modifying the `Vehicle`
 * class.
 */

class Vehicle {
public:
    Vehicle() = default;
    explicit Vehicle(std::unique_ptr<DriveStrategy>&& driveStrategy)
        : obj(std::move(driveStrategy)) {}

    void setDriveStrategy(std::unique_ptr<DriveStrategy>&& strategy) {
        obj = std::move(strategy);
    }

    void drive() {
        obj->drive();
    }

private:
    std::unique_ptr<DriveStrategy> obj;
};


class Car : public Vehicle {
    public:
    Car() : Vehicle(std::make_unique<NormalDriveStrategy>()){}
};

class OffRoader : public Vehicle {
    public:
    OffRoader() : Vehicle(std::make_unique<SpecialDriveStrategy>()){}
};

int main(){
    Vehicle* car = new Car();
    car->drive();
    car->setDriveStrategy(std::make_unique<SpecialDriveStrategy>());
    car->drive();   // Setting new strategy on runtime
    Vehicle* offroader = new OffRoader();
    offroader->drive();
    return 0;

}

