#include <iostream>
#include <exception>
using namespace std;

class BelowZeroStock : public exception {};
class CapacityExceeded : public exception {};

template<typename T>
class WarehouseItem {
    T quantity;
    T limit;

public:
    WarehouseItem(T cap) : quantity(0), limit(cap) {}

    void updateStock(T value) {
        if (value < 0) {
            throw BelowZeroStock();
        }
        if (value > limit) {
            throw CapacityExceeded();
        }
        quantity = value;
        cout << "Current stock: " << quantity << endl;
    }

    T fetchStock() {
        return quantity;
    }
};

int main() {
    WarehouseItem<int> unit(100);

    try {
        cout << "Setting stock to -5\n";
        unit.updateStock(-5);
    } catch (BelowZeroStock ex) {
        cout << "Error: Negative stock value.\n";
        cout << "Details: " << ex.what() << endl;
    }

    try {
        cout << "Setting stock to 120\n";
        unit.updateStock(120);
    } catch (CapacityExceeded ex) {
        cout << "Error: Stock exceeds limit.\n";
        cout << "Details: " << ex.what() << endl;
    }

    return 0;
}
