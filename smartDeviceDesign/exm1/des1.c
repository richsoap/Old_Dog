#include "mbed.h"

DigitalOut myLed(LED1);

int main() {
    while(1) {
        wait_ms(500);
        myLed = 1;
        wait_ms(500);
        myLed = 0;
    }
}
