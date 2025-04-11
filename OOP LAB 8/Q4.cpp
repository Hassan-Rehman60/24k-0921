#include <iostream>
#include <string>
using namespace std;

class Car;

class InventoryManager {
public:
    void setNewPrice(Car& car, double price);
    void showCarInfo(const Car& car);
};

class Car {
private:
    string modelName;
    double cost;

public:
    Car(string name, double price) : modelName(name), cost(price) {}

    friend class InventoryManager;
    friend void comparePrices(const Car& car1, const Car& car2);
};

void InventoryManager::setNewPrice(Car& car, double price) {
    car.cost = price;
}

void InventoryManager::showCarInfo(const Car& car) {
    cout << "Model: " << car.modelName << " | Price: $" << car.cost << endl;
}

void comparePrices(const Car& car1, const Car& car2) {
    if (car1.cost > car2.cost) {
        cout << car1.modelName << " is more expensive." << endl;
    } else if (car1.cost < car2.cost) {
        cout << car2.modelName << " is more expensive." << endl;
    } else {
        cout << "Both cars have the same price." << endl;
    }
}

int main() {
    Car carA("BMW", 24534);
    Car carB("Civic", 54532);

    InventoryManager invManager;

    cout << "Initial Car Details:\n";
    invManager.showCarInfo(carA);
    invManager.showCarInfo(carB);

    invManager.setNewPrice(carA, 32000);
    cout << "\nUpdated Car A's Price:\n";
    invManager.showCarInfo(carA);

    cout << "\nPrice Comparison:\n";
    comparePrices(carA, carB);

    return 0;
}
