#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseIssue : public exception {
public:
    const char* what() const noexcept override {
        return "Database error encountered.";
    }
};

class ConnectFailure : public DatabaseIssue {};
class TimeoutError : public DatabaseIssue {};

template<typename T>
class DatabaseHandler {
    T dbName;

public:
    DatabaseHandler(T db) : dbName(db) {}

    void establish() {
        if (dbName == "invalid_db") {
            throw ConnectFailure();
        }
        cout << "Connected to " << dbName << endl;
    }

    void execute(const string& statement) {
        if (dbName == "laggy_db") {
            throw TimeoutError();
        }
        cout << "Executing: " << statement << endl;
    }
};

int main() {
    try {
        cout << "Attempting connection to unknown database...\n";
        DatabaseHandler<string> handler1("invalid_db");
        handler1.establish();
    } catch (ConnectFailure& ex) {
        cout << "Connection failed.\n";
        cout << "Message: " << ex.what() << endl;
    }

    try {
        cout << "Connecting to delayed response database...\n";
        DatabaseHandler<string> handler2("laggy_db");
        handler2.establish();
        handler2.execute("SELECT * FROM users;");
    } catch (TimeoutError& ex) {
        cout << "Query execution timeout.\n";
        cout << "Message: " << ex.what() << endl;
    }

    return 0;
}
