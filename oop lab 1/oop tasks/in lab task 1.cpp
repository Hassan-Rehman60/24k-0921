#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Event {
private:
    string name;
    vector<string> participants;
    const int maxParticipants = 5;

public:
    Event(string eventName) : name(eventName) {}

    void registerParticipant(const string& participantName) {
        if (participants.size() < maxParticipants) {
            participants.push_back(participantName);
        } else {
            cout << "Event " << name << " is full. Cannot add more participants.\n";
        }
    }

    bool isParticipantRegistered(const string& participantName) {
        return find(participants.begin(), participants.end(), participantName) != participants.end();
    }

    void displayParticipantsReverse() {
        cout << "Participants for " << name << " (in reverse order):\n";
        for (auto it = participants.rbegin(); it != participants.rend(); ++it) {
            cout << *it << endl;
        }
    }

    int getTotalDonations() {
        return participants.size() * 10; // $10 per participant
    }

    int getParticipantCount() {
        return participants.size();
    }

    string getName() {
        return name;
    }
};

class EventManager {
private:
    Event event1, event2;

public:
    EventManager(string name1, string name2) : event1(name1), event2(name2) {}

    void registerParticipants() {
        string name;
        cout << "Registering for " << event1.getName() << ":\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Enter participant name (or 'done' to stop): ";
            cin >> name;
            if (name == "done") break;
            event1.registerParticipant(name);
        }

        cout << "Registering for " << event2.getName() << ":\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Enter participant name (or 'done' to stop): ";
            cin >> name;
            if (name == "done") break;
            event2.registerParticipant(name);
        }
    }

    void checkAttendance() {
        string name;
        cout << "Enter participant name to check attendance: ";
        cin >> name;
        if (event1.isParticipantRegistered(name) || event2.isParticipantRegistered(name)) {
            cout << name << " is registered in one of the events.\n";
        } else {
            cout << name << " is NOT registered in any event.\n";
        }
    }

    void displayTotalDonations() {
        int total = event1.getTotalDonations() + event2.getTotalDonations();
        cout << "Total donations collected: $" << total << endl;
    }

    void displayParticipantsInReverse() {
        event1.displayParticipantsReverse();
        event2.displayParticipantsReverse();
    }

    void displayEventPopularity() {
        cout << "\nEvent Popularity:\n";
        cout << event1.getName() << ": ";
        for (int i = 0; i < event1.getParticipantCount(); i++) cout << "*";
        cout << endl;

        cout << event2.getName() << ": ";
        for (int i = 0; i < event2.getParticipantCount(); i++) cout << "*";
        cout << endl;
    }
};

int main() {
    EventManager manager("Music Festival", "Art Exhibition");

    manager.registerParticipants();
    manager.checkAttendance();
    manager.displayTotalDonations();
    manager.displayParticipantsInReverse();
    manager.displayEventPopularity();

    return 0;
}
