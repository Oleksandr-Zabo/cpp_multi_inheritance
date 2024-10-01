#include <iostream>
using namespace std;
#include <string>

class Component {
public:
    virtual void description() const = 0;
    virtual ~Component() = default;
};

enum class TransmissionType {
    Unknown,
    Manual,
    Automatic,
    SemiAutomatic
};

enum class FuelType {
    Unknown,
    Petrol,
    Diesel,
    Electric,
    Hybrid
};

class Wheels : virtual public Component {
protected:
    int number;
public:
    Wheels() {
        number = 0;
    }
    Wheels(int number){
        this->number = number;
    }

    void description() const override {
        cout << "Number of wheels: " << number << endl;
    }


};

class Engine : virtual public Component {
private:
    string fuelTypeToString(FuelType type) const {
        switch (type) {
        case FuelType::Petrol: return "Petrol";
        case FuelType::Diesel: return "Diesel";
        case FuelType::Electric: return "Electric";
        case FuelType::Hybrid: return "Hybrid";
        case FuelType::Unknown: return "Unknown";
        default: return "Unknown";
        }
    }

protected:
    FuelType type;

public:
    Engine() {
		this->type = FuelType::Unknown;
    }
    Engine(FuelType type){
		this->type = type;
    }

    void description() const override {
        cout << "Engine type: " << fuelTypeToString(type) << endl;
    }


};

class Doors : virtual public Component {
protected:
    int number;
public:

    Doors() {
		number = 0;
    }
    Doors(int number) {
		this->number = number;
    }

    void description() const override {
        cout << "Number of doors: " << number << endl;
    }


};

class Transmission : virtual public Component {
private:
    string transmissionTypeToString(TransmissionType type) const {
        switch (type) {
        case TransmissionType::Manual: return "Manual";
        case TransmissionType::Automatic: return "Automatic";
        case TransmissionType::SemiAutomatic: return "Semi-Automatic";
        case TransmissionType::Unknown: return "Unknown";
        default: return "Unknown";
        }
    }

protected:
    TransmissionType type;

public:
    Transmission() {
		type = TransmissionType::Unknown;
    }
    Transmission(TransmissionType type) {
		this->type = type;
    }

    void description() const override {
        cout << "Transmission type: " << transmissionTypeToString(type) << endl;
    }

};

class Car : public Wheels, public Engine, public Doors, public Transmission {
public:
    Car() : Wheels(), Engine(), Doors(), Transmission() {}
    Car(int wheels, FuelType engineType, int doors, TransmissionType transmissionType)
        : Wheels(wheels), Engine(engineType), Doors(doors), Transmission(transmissionType) {}

    void description() const override {
        cout << "Car with the following characteristics:" << endl;
        Wheels::description();
        Engine::description();
        Doors::description();
        Transmission::description();
    }
};

int main() {
    Car* myCar = new Car(4, FuelType::Petrol, 4, TransmissionType::Automatic);
    myCar->description();
	delete myCar;
    return 0;
}
