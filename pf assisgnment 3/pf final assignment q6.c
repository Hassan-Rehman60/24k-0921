#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cropType[20];
    char growthStage[20];
    float expectedYield;
} Crop;

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;

typedef struct {
    char equipmentType[20];
    float fuelLevel;
    char status[20];
} Equipment;

typedef struct {
    float soilNutrients;
    float pHLevel;
    char pestActivity[20];
} Sensor;

typedef struct {
    Crop crops[10];
    WeatherForecast weather;
    Equipment equipment[5];
    Sensor sensors[5];
} Field;

typedef struct {
    Field fields[5];
    char hubName[20];
} RegionalHub;

int main() {
    RegionalHub hub;
    strcpy(hub.hubName, "Central Hub");

    strcpy(hub.fields[0].crops[0].cropType, "Wheat");
    strcpy(hub.fields[0].crops[0].growthStage, "Mature");
    hub.fields[0].crops[0].expectedYield = 1200.5;

    hub.fields[0].weather.temperature = 28.5;
    hub.fields[0].weather.rainfall = 15.2;
    hub.fields[0].weather.windSpeed = 12.3;

    strcpy(hub.fields[0].equipment[0].equipmentType, "Tractor");
    hub.fields[0].equipment[0].fuelLevel = 75.0;
    strcpy(hub.fields[0].equipment[0].status, "Active");

    hub.fields[0].sensors[0].soilNutrients = 7.5;
    hub.fields[0].sensors[0].pHLevel = 6.8;
    strcpy(hub.fields[0].sensors[0].pestActivity, "Low");

    printf("Hub Name: %s\n", hub.hubName);
    printf("Field 1 Crop Type: %s\n", hub.fields[0].crops[0].cropType);
    printf("Growth Stage: %s\n", hub.fields[0].crops[0].growthStage);
    printf("Expected Yield: %.2f\n", hub.fields[0].crops[0].expectedYield);

    printf("Weather - Temperature: %.2f, Rainfall: %.2f, Wind Speed: %.2f\n",
           hub.fields[0].weather.temperature, 
           hub.fields[0].weather.rainfall, 
           hub.fields[0].weather.windSpeed);

    printf("Equipment Type: %s, Fuel Level: %.2f, Status: %s\n",
           hub.fields[0].equipment[0].equipmentType, 
           hub.fields[0].equipment[0].fuelLevel, 
           hub.fields[0].equipment[0].status);

    printf("Sensor Data - Soil Nutrients: %.2f, pH Level: %.2f, Pest Activity: %s\n",
           hub.fields[0].sensors[0].soilNutrients, 
           hub.fields[0].sensors[0].pHLevel, 
           hub.fields[0].sensors[0].pestActivity);

    return 0;
}
