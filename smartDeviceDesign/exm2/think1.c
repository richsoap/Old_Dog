#include "mbed.h"

AnalogIn analog_in(A0);

int main() {
    float meas;
    float record = analog_in.read();
    while(1) {
        meas = analog_in.read();
        printf("Delta V = %f V/S \n", mead - record);
        mead = record;
        wait_ms(1000);
    }
}
