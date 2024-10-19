#include <iostream>
#include <memory>

class DriveStrategy{
    public:
    virtual void drive() = 0;
};

class NormalDriveStrategy : public DriveStrategy{
    public:
    void drive() override {
        std::cout << "Normal Drive Stratergy\n";
    }
};

class SpecialDriveStrategy : public DriveStrategy{
    public:
    void drive() override {
        std::cout << "Special Drive Stratergy\n";
    }
};