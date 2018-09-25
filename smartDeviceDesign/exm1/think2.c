#include "mbed.h"

DigitalOut myled(LED1);

int main() {
    char temp;
    while(1) {
        temp = getchar();
        printf("%c", temp);
        myled = 1;
        wait_ms(100);
        myled = 0;
    }
}
