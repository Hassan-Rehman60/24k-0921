#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("data_records.txt");
    if (!inputFile) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    int offset = 2 * 9;
    inputFile.seekg(offset, ios::beg);

    string record;
    getline(inputFile, record);
    cout << "Third record: " << record << endl;

    inputFile.close();
    return 0;
}
