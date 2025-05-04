#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");
    if (!inputFile) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        stringstream stream(line);
        string type, id, name, yearStr, extraData, cert;
        getline(stream, type, ',');
        getline(stream, id, ',');
        getline(stream, name, ',');
        getline(stream, yearStr, ',');
        getline(stream, extraData, ',');
        getline(stream, cert);

        if (type == "HybridTruck") {
            size_t colonPosition = extraData.find(':');
            size_t pipePosition = extraData.find('|');

            if (colonPosition != string::npos && pipePosition != string::npos) {
                string cargoStr = extraData.substr(colonPosition + 1, pipePosition - colonPosition - 1);
                string batteryStr = extraData.substr(pipePosition + 8);

                int cargo = stoi(cargoStr);
                int battery = stoi(batteryStr);

                cout << "ID: " << id << ", Cargo: " << cargo << ", Battery: " << battery << endl;
            }
        }
    }

    inputFile.close();
    return 0;
}
