#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;
// Enum for gearbox type.
enum class gearbox{
    Manual,
    Semi_Automatic,
    Automatic
};
// Convert gearbox enum to string
string gearboxToString(gearbox gb){
    switch (gb) {
        case gearbox::Manual: return "Manual";
        case gearbox::Semi_Automatic: return "Semi-Automatic";
        case gearbox::Automatic: return "Automatic";
        default: return "Unknown";
    }
}
class Cars{
protected:
    string ChassisNumber;
    string EngineSize;
    string Fuel;
    gearbox GearBox;
    string Tires;
    int HorsePower;
    int Seat;
public:
    // Constructor with initialization list
    Cars(string chassis_number, string engine_size, string fuel, gearbox gear_box, string tires, int horse_power, int seat)
    : ChassisNumber(std::move(chassis_number)), EngineSize(std::move(engine_size)), Fuel(std::move(fuel)), GearBox(gear_box), Tires(std::move(tires)), HorsePower(horse_power), Seat(seat){
    }

    void setEngineSize(string engine_size){
        EngineSize = std::move(engine_size);
    }
    string getEngineSize(){
        return EngineSize;
    }

    void setFuel(string fuel){
        Fuel = std::move(fuel);
    }
    string getFuel(){
        return Fuel;
    }

    void setGearBox(gearbox gear_box){
        GearBox = gear_box;
    }
    gearbox getGearBox(){
        return GearBox;
    }

    void setTires(string tires){
        Tires = std::move(tires);
    }
    string getTires(){
        return Tires;
    }

    void setHorsePower(int horse_power){
        HorsePower = horse_power;
    }
    int getHorsePower(){
        HorsePower;
    }

    void setSeat(int seat){
        Seat = seat;
    }
    int getSeat(){
        return Seat;
    }
    void Print(){
        cout << "Chassis Number: " << ChassisNumber << "\nEngine Size: " << EngineSize << "\nFuel Type: " << Fuel << "\nGearBox Type: " << static_cast<int>(GearBox) << "\nTires Size: " << Tires << "\nHorsepower: " << HorsePower << "\nNumber of Seats: " << Seat << endl;
    }
};
 // Created ElectricCars class for specific electric car features.
// Inherited from main Cars class.
class ElectricCars : public Cars{
public:
    string BatteryCapacity;
    int Range;
    ElectricCars(string chassis_number, string engine_size, string fuel, gearbox gear_box, string tires, int horse_power, int seat, int range, string battery_capacity)
    : Cars(std::move(chassis_number), std::move(engine_size), std::move(fuel), gear_box, std::move(tires), horse_power, seat){
        BatteryCapacity = std::move(battery_capacity);
        Range = range;
    }
    void Print(){
        Cars::Print();
        cout << "Range: " << Range << " km" << "\nBattery Capacity: " << BatteryCapacity << endl;
    }
};

int main() {
    map<string, Cars*> carsDatabase;
    // Menu for users to choose what he/she want.
    while (true){
        cout << "\nMenu:\n";
        cout << "1- Add a new car\n";
        cout << "2- Show the information about a car\n";
        cout << "3- Delete a car\n";
        cout << "4- Exit\n";
        cout << "Enter your choice (1-4): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "Enter Chassis Number: ";
                string chassisNumber;
                cin >> chassisNumber;
                if(carsDatabase.find(chassisNumber)) != carsDatabase.end()){
                    cout << "Car with chassis number " << chassisNumber << " already exists. Enter a different chassis number.\n";
                    break;
                }

            }
            
        }
    }
    //ElectricCars T10F = ElectricCars("160kW", "Electric", gearbox::Automatic, "21 inch", 217, 4,530 , "88kWh");
    //T10F.Print();
    return 0;
}
