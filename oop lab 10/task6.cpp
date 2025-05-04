#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem itemToSave = {101, "Wrench"};
    ofstream outputFile("inventory.dat", ios::binary);
    outputFile.write(reinterpret_cast<char*>(&itemToSave), sizeof(itemToSave));
    outputFile.close();

    InventoryItem itemLoaded;
    ifstream inputFile("inventory.dat", ios::binary);
    inputFile.read(reinterpret_cast<char*>(&itemLoaded), sizeof(itemLoaded));
    inputFile.close();

    cout << "Loaded Item ID: " << itemLoaded.itemID << ", Name: " << itemLoaded.itemName << endl;

    return 0;
}
