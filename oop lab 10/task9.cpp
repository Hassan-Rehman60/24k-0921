#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("large_log.txt");
    if (!inputFile) {
        cout<< "Failed to open file." << endl;
        return 1;
    }

    char buffer[11];
    inputFile.read(buffer, 10);
    buffer[10] = '\0';
    cout << "First 10 characters: " << buffer << endl;
    cout << "Position after first read: " << inputFile.tellg() << endl;

    inputFile.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Next 10 characters: " << buffer << endl;
    cout << "Position after second read: " << inputFile.tellg() << endl;

    inputFile.close();
    return 0;
}
