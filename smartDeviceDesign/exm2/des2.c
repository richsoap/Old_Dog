#include "mbed.h"

PwmOut my_led(LED1);
AnalogIn analog_in(A0);


int main() {
    float meas;
    while(1) {
        meas = analog_in.read();
        my_led.period_us(1000);
        my_led.pulsewidth_us(meas*1000);
        wait_ms(10);
    }
}
