#include "mbed.h"

DigitalOut myLed(LED1);
DigitalIn myKey(USER_BUTTON);

int main() {
    int mode = 1;
    int count = 0;
    myLed = 0;
    while(1) {
        if (myKey == 0) {
            wait_ms(10);
            if(myKey == 0)
                mode = mode >= 4?1:mode << 1;
        }
        else
            wait_ms(10);
        if(count >= mode * 250) {
            count = 0;
            myLed = !myLed;
        }
        count ++;
    }
}
