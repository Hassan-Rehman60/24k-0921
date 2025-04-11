#include <iostream>
#include <string>

using namespace std;

class Device {
public:
    int id;
    string name;
    bool isOn;
    string location;

    Device(int id, const string& name, bool isOn)
        : id(id), name(name), isOn(isOn), location("") {}

    virtual void turnOn() {
        isOn = true;
    }

    virtual void turnOff() {
        isOn = false;
    }

    virtual bool isActive() const {
        return isOn;
    }

    virtual void showDetails() const {
        cout << "ID: " << id
             << "\tName: " << name
             << "\tStatus: " << (isOn ? "On" : "Off");
        if (!location.empty())
            cout << "\tLocation: " << location;
        cout << endl;
    }

    virtual ~Device() {}
};

class Light : public Device {
public:
    double brightness;
    string color;

    Light(int id, const string& name, bool isOn, double brightness, const string& color)
        : Device(id, name, isOn), brightness(brightness), color(color) {}

    void showDetails() const override {
        Device::showDetails();
        cout << "Brightness: " << brightness
             << "\tColor Mode: " << color << endl;
    }
};

class Thermostat : public Device {
public:
    double temperature;
    bool tempControlOn;

    Thermostat(int id, const string& name, bool isOn, double temperature, bool tempControlOn)
        : Device(id, name, isOn), temperature(temperature), tempControlOn(tempControlOn) {}

    bool isActive() const override {
        return tempControlOn;
    }
};

class SecurityCamera : public Device {
public:
    string resolution;
    bool isRecording;
    bool nightVision;

    SecurityCamera(int id, const string& name, bool isOn, const string& resolution, bool isRecording, bool nightVision)
        : Device(id, name, isOn), resolution(resolution), isRecording(isRecording), nightVision(nightVision) {}

    void turnOn() override {
        isOn = true;
        isRecording = true;
    }
};

class SmartPlug : public Device {
public:
    double powerUsage;
    int timer;

    SmartPlug(int id, const string& name, bool isOn, double powerUsage, int timer)
        : Device(id, name, isOn), powerUsage(powerUsage), timer(timer) {}

    void turnOff() override {
        isOn = false;
        powerUsage = 0;
    }
};

int main() {
    Light livingRoomLight(1, "Living Room Light", true, 75.0, "Warm White");
    Thermostat hallwayThermostat(2, "Hallway Thermostat", false, 22.5, true);
    SecurityCamera frontDoorCam(3, "Front Door Camera", true, "1080p", true, true);
    SmartPlug socket(4, "Smart Socket", true, 150.0, 30);

    livingRoomLight.turnOn();
    livingRoomLight.showDetails();
    cout << endl;

    hallwayThermostat.isActive();  
    cout << endl;

    frontDoorCam.turnOn();
    frontDoorCam.isActive();
    cout << endl;

    socket.turnOff();
}
