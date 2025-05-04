#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("config.txt");
    outFile << "AAAAABBBBBCCCCC";
    outFile.close();

    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    file.seekp(5);
    file << "XXXXX";
    file.close();

    return 0;
}
