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

        int year = stoi(yearStr);
        cout << "Vehicle ID: " << id << ", Year: " << year << endl;
    }

    inputFile.close();
    return 0;
}
