#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        stringstream stream(line);
        string type, id, name, year, extraData, cert;

        getline(stream, type, ',');
        getline(stream, id, ',');
        getline(stream, name, ',');
        getline(stream, year, ',');
        getline(stream, extraData, ',');
        getline(stream, cert);

        cout << "Parsed: " << type << ", " << id << ", " << name
             << ", " << year << ", " << extraData << ", " << cert << endl;
    }

    inputFile.close();
    return 0;
}
