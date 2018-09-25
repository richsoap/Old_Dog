#include "mbed.h"

PwmOut my_led(LED1);
AnalogIn analog_in(A0);
InterruptIn key_int(USER_BUTTON);
int led_on;

void led_turn() {
    led_on = led_on==1?0:1;
}

int main() {
    led_on = 1;
    float meas;
    while(1) {
        meas = analog_in.read();
        my_led.period_us(1000);
        my_led.pulsewidth_us(meas*1000*led_on);
        wait_ms(10);
    }
}
