#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outputFile("sensor_log.txt");
    if (!outputFile) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    outputFile << "Sensor 1: 25.5 C\n";
    cout << "Position after first write: " << outputFile.tellp() << endl;

    outputFile << "Sensor 2: 98.1 %RH\n";
    cout << "Position after second write: " << outputFile.tellp() << endl;

    outputFile.close();
    return 0;
}
