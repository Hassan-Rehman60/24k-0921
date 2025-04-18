#include <iostream>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int cr) : courseCode(code), credits(cr) {}
    virtual double calculateGrade() = 0;
    virtual void displayInfo() = 0;
};

class LectureCourse : public Course {
public:
    LectureCourse(string code, int cr) : Course(code, cr) {}

    double calculateGrade() override {
        return 85.0;
    }

    void displayInfo() override {
        cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(string code, int cr) : Course(code, cr) {}

    double calculateGrade() override {
        return 90.0;
    }

    void displayInfo() override {
        cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
    }
};

int main() {
    Course* c1 = new LectureCourse("CS101", 3);
    Course* c2 = new LabCourse("CS101L", 1);

    c1->displayInfo();
    cout << "Final Grade: " << c1->calculateGrade() << "\n\n";

    c2->displayInfo();
    cout << "Final Grade: " << c2->calculateGrade() << "\n";

    delete c1;
    delete c2;

    return 0;
}
