#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

using namespace std;

/*
Parking Lot System Design

This design models a parking lot system with various components and their interactions. The main components include:

1. **Vehicle**: Represents different types of vehicles that can park in the parking lot. Each vehicle can be assigned a parking ticket.
    - Car
    - Van
    - Truck
    - MotorCycle

2. **ParkingSpot**: Represents different types of parking spots available in the parking lot. Each spot can be assigned a vehicle.
    - Handicapped
    - Compact
    - Large
    - MotorCycleSpot

3. **ParkingTicket**: Represents a parking ticket issued to a vehicle when it enters the parking lot. It contains details like ticket number, timestamp, and payment information.

4. **Payment**: Represents different payment methods for parking fees.
    - Card
    - Cash
    - UPI

5. **Account**: Represents user accounts in the system. There are two types of accounts:
    - Admin: Can add parking spots, display boards, entrances, and exits.
    - ParkingAgent: Can process parking tickets.

6. **ParkingLot**: The main class that manages the parking lot. It is a singleton class ensuring only one instance exists. It manages entrances, exits, and parking tickets.

7. **Entrance and Exit**: Represents the entry and exit points of the parking lot. Entrances issue parking tickets, and exits validate them.

8. **DisplayBoard**: Shows available parking spots in the parking lot.

9. **ParkingRate**: Calculates the parking fee based on the duration of the parking.

The design uses various design patterns:
- Singleton: Ensures only one instance of the ParkingLot class.
- Factory: For creating different types of vehicles and parking spots.
- Strategy: For different payment methods.

Relationships between classes:

- **ParkingLot**: Manages the entire parking lot, including entrances, exits, and parking tickets. It is a singleton class.
- **Entrance**: Issues parking tickets and is associated with the ParkingLot.
- **Exit**: Validates parking tickets and is associated with the ParkingLot.
- **ParkingTicket**: Issued by Entrance and validated by Exit. It contains references to Vehicle, Payment, Entrance, and Exit.
- **Vehicle**: Represents a vehicle that can park in the parking lot. It can be assigned a ParkingTicket.
- **ParkingSpot**: Represents a parking spot that can be assigned a Vehicle.
- **Payment**: Represents a payment method for parking fees. It is associated with ParkingTicket.
- **Account**: Represents user accounts in the system. Admin and ParkingAgent are derived from Account.
- **DisplayBoard**: Shows available parking spots in the parking lot.
- **ParkingRate**: Calculates the parking fee based on the duration of the parking.
*/

enum PaymentStatus{
    Completed = 0,
    Failed,
    Refunded,
    Pending,
    Unpaid
};

enum AccountStatus{
    Active = 0,
    Closed,
    Cancelled,
    BlackListed,
    None
};

class Person {
    public:
        string name;
        string address;
        string email;
        long long phone;
};

class Address{
    private:
        int zipCode;
        string address;
        string city;
        string state;
        string country;
};

class ParkingTicket;


/************* Vehicles ***************/
class Vehicle{
    private:
        string licenseNo;
    
    public:
        void virtual assignTicket(unique_ptr<ParkingTicket> ticket) = 0;
};

class Car : public Vehicle {
    public:
        void assignTicket(unique_ptr<ParkingTicket> ticket){}
};
class Van : public Vehicle {
    public:
        void assignTicket(unique_ptr<ParkingTicket> ticket){}
};
class Truck : public Vehicle {
    public:
        void assignTicket(unique_ptr<ParkingTicket> ticket){}
};
class MotorCycle : public Vehicle {
    public:
        void assignTicket(unique_ptr<ParkingTicket> ticket){}
};
/************* Vehicles ***************/


/************* Parking Spots ***************/
class ParkingSpot{
    private:
        int id;
        bool isFree;
        unique_ptr<Vehicle> vehicle;
    public:
        bool getIsFree();
        virtual bool assignVehicle(unique_ptr<Vehicle> vechile) = 0;
        bool removeVehicle(){  /*impl*/   }
};

class Handicaped : public ParkingSpot{
    public:
        bool assignVehicle(unique_ptr<Vehicle> vechile){
            /*impl*/
        }
};

class Compact : public ParkingSpot{
    public:
        bool assignVehicle(unique_ptr<Vehicle> vechile){
            /*impl*/
        }
};
class Large : public ParkingSpot{
    public:
        bool assignVehicle(unique_ptr<Vehicle> vechile){
            /*impl*/
        }
};
class MotorCycleSpot : public ParkingSpot{
    public:
        bool assignVehicle(unique_ptr<Vehicle> vechile){
            /*impl*/
        }
};

/************* Parking Spots ***************/


class DisplayBoard;
class Entrance;
class Exit;

/************* Account ***************/
class Account {
    private:
        string username;
        string password;
        Person person;
        AccountStatus status;

    public:
        virtual bool resetPassword() = 0; 
};

class Admin : public Account { 
    public:
        bool addParkingSpot(unique_ptr<ParkingSpot> parkingSpot);
        bool addDisplayBoard(unique_ptr<DisplayBoard> displayBoard);
        bool addEntrance(unique_ptr<Entrance> entrance);
        bool addExit(unique_ptr<Exit> exit);
        bool resetPassword(){}
};

class ParkingAgent : public Account{
    public:
        bool processTicket(string ticketNumber);
        bool resetPassword(){

        }
};
/************* Account ***************/


class DisplayBoard {
    private: 
        int id;
        vector<ParkingSpot*> parkingSpots;

    public:
        DisplayBoard(int id) : id(id){}
        void addParkingSpot(ParkingAgent* spot);
        void showFreeSpot();
};

class ParkingRate{
    private:
        double hours;
        double rate;
    public:
        void calculate();
};

class Entrance {
    private:
        int id;
    
    public:
        ParkingTicket getTicket();
};

class Exit{
    private:
        int id;
    
    public:
        void validateTicket(unique_ptr<ParkingTicket> ticket ){}
};


class Payment;

class ParkingTicket{
    private:
        int ticketNo;
        time_t timestamp;
        time_t exit;
        double amount;
        bool status;

        unique_ptr<Vehicle> vehicle;
        unique_ptr<Payment> paymnet;
        unique_ptr<Entrance> entrance;
        unique_ptr<Exit> exitspot;
};


/****************** Payment ********************/
class Payment{
    private:
        double amount;
        PaymentStatus status;
        time_t timestamp;
    public:
        virtual bool initiateTransaction() = 0;
};

class Card : public Payment{
    public:
        bool initiateTransaction(){}
};

class Cash : public Payment{
    public:
        bool initiateTransaction(){}
};

class UPI : public Payment{
    public:
        bool initiateTransaction(){}
};
/****************** Payment ********************/

class ParkingLot {
    private:
        int id;
        string name;
        Address address;
        ParkingRate parkingRate;

        unordered_map<string, Entrance> entrances;
        unordered_map<string, Exit> exits;
        // Create a hashmap that identifies all currently generated tickets using their ticket number
        unordered_map<string , ParkingTicket> tickets;

        // The ParkingLot is a singleton class that ensures it will have only one active instance at a time
        // Both the Entrance and Exit classes use this class to create and close parking tickets
        static ParkingLot *parkingLot;

        ParkingLot(){}
        
    public:
        static ParkingLot getInstance(){
            if(parkingLot == nullptr){
                parkingLot = new ParkingLot();
            }
            return *parkingLot;
        }

        bool addEntrance(unique_ptr<Entrance> entrance){}
        bool addExit(unique_ptr<Exit> exit){}

        // This function allows parking tickets to be available at multiple entrances
        ParkingTicket getParkingTicket(unique_ptr<Vehicle> vehicle){}
        bool isFull(unique_ptr<ParkingSpot> spot){}
};
