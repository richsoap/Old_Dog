#include "mbed.h"

DigitalOut myled(LED1);
DigitalIn mykey(USER_BUTTON);

int main() {
    while(1) {
        if(mykey == 0) {
            wait_ms(10);
            if(mykey == 0) {
                myled = !myled;
                while(mykey == 0);
                printf("Hello Arm!\n");
            }
        }
    }
}
