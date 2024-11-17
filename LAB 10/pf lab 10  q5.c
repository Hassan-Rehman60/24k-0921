#include <stdio.h>

void checkTemperature(float temp, float limit) {
    static int exceedCount = 0;
    if (temp > limit)
        exceedCount++;

    printf("Times temperature exceeded the limit: %d\n", exceedCount);
}

int main() {
    float limit = 30.0;

    checkTemperature(32.5, limit);
    checkTemperature(29.0, limit);
    checkTemperature(35.0, limit);

    return 0;
}