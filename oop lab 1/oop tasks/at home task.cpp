//SHEIKH HASSAN REHMAN
// 24k-0921
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class AQITracker {
private:
    vector<vector<int>> data;
    vector<string> cities = {"City A", "City B", "City C", "City D"};
    const int daysInWeek = 7;
    const int daysInMonth = 28;

public:
    AQITracker() {
        data.resize(4, vector<int>(daysInMonth, 0));
    }

    void inputWeeklyData() {
        cout << "Enter AQI values for 4 cities over 7 days:\n";
        for (int i = 0; i < 4; ++i) {
            cout << cities[i] << ":\n";
            for (int j = 0; j < daysInWeek; ++j) {
                cout << "  Day " << j + 1 << ": ";
                cin >> data[i][j];
            }
        }
    }

    void displayWeeklyAverages() {
        vector<double> averages(4, 0);
        int worstCityIndex = 0;

        cout << "\nWeekly AQI Averages:\n";
        for (int i = 0; i < 4; ++i) {
            int sum = 0;
            for (int j = 0; j < daysInWeek; ++j) {
                sum += data[i][j];
            }
            averages[i] = sum / (double)daysInWeek;
            if (averages[i] > averages[worstCityIndex]) {
                worstCityIndex = i;
            }
            cout << cities[i] << ": " << fixed << setprecision(2) << averages[i] << endl;
        }

        cout << "City with worst air quality: " << cities[worstCityIndex] << " (Highest AQI: " 
             << averages[worstCityIndex] << ")\n";
    }

    void identifyCriticalDays() {
        cout << "\nCritical Pollution Days (AQI > 150):\n";
        for (int i = 0; i < 4; ++i) {
            cout << cities[i] << ": ";
            bool found = false;
            for (int j = 0; j < daysInWeek; ++j) {
                if (data[i][j] > 150) {
                    cout << "Day " << j + 1 << " ";
                    found = true;
                }
            }
            if (!found) cout << "None";
            cout << endl;
        }
    }

    void visualizeData() {
        cout << "\nAQI Visualization:\n";
        for (int i = 0; i < 4; ++i) {
            cout << cities[i] << ":\n";
            for (int j = 0; j < daysInWeek; ++j) {
                cout << "  Day " << j + 1 << ": ";
                int symbols = data[i][j] / 50;
                for (int k = 0; k < symbols; ++k) cout << "*";
                cout << " (" << data[i][j] << ")\n";
            }
        }
    }

    void inputMonthlyData() {
        cout << "\nEnter AQI values for 4 cities over 28 days:\n";
        for (int i = 0; i < 4; ++i) {
            cout << cities[i] << ":\n";
            for (int j = 0; j < daysInMonth; ++j) {
                cout << "  Day " << j + 1 << ": ";
                cin >> data[i][j];
            }
        }
    }

    void displayMonthlyComparison() {
        vector<double> monthlyAverages(4, 0);
        int bestImprovedCity = 0;
        double maxImprovement = 0;

        cout << "\nMonthly AQI Averages:\n";
        for (int i = 0; i < 4; ++i) {
            int sum = 0;
            for (int j = 0; j < daysInMonth; ++j) {
                sum += data[i][j];
            }
            monthlyAverages[i] = sum / (double)daysInMonth;
            cout << cities[i] << ": " << fixed << setprecision(2) << monthlyAverages[i] << endl;

            double firstWeekAvg = 0, lastWeekAvg = 0;
            for (int j = 0; j < 7; ++j) firstWeekAvg += data[i][j];
            for (int j = 21; j < 28; ++j) lastWeekAvg += data[i][j];

            firstWeekAvg /= 7;
            lastWeekAvg /= 7;
            double improvement = firstWeekAvg - lastWeekAvg;

            if (improvement > maxImprovement) {
                maxImprovement = improvement;
                bestImprovedCity = i;
            }
        }

        cout << "City with most improved air quality: " << cities[bestImprovedCity] 
             << " (Drop in AQI: " << maxImprovement << ")\n";
    }

    void generateReport() {
        cout << "\n--- AQI REPORT ---\n";
        displayWeeklyAverages();
        identifyCriticalDays();
        displayMonthlyComparison();
    }
};

int main() {
    AQITracker tracker;
    
    tracker.inputWeeklyData();
    tracker.displayWeeklyAverages();
    tracker.identifyCriticalDays();
    tracker.visualizeData();

    tracker.inputMonthlyData();
    tracker.displayMonthlyComparison();
    tracker.generateReport();

    return 0;
}
