#include "mbed.h"

DigitalOut myLed(LED1);
struct note{
    int val;
    int len;
    node(int _val = 0, int _len = 0):val(_val),len(_len) ()
};
int beat = 50;

int main() {
    note sentence[11];
    int i,j,cache;
    sentence[0] = note(0,4);
    sentence[1] = note(0,1);
    sentence[2] = note(2,4);
    sentence[3] = note(2,4);
    sentence[4] = note(7,3);
    sentence[5] = note(0,0);
    sentence[6] = note(2,2);
    sentence[7] = note(2,3);
    sentence[8] = note(3,2);
    sentence[9] = note(12,5);
    sentence[10] = note(0,0);
    while(1) {
        for(i = 0;i < 11;i ++) {
            if(sentence[i].len == 0)
                wait_ms(beat*4);
            else {
                cache = sentence[i].val;
                for(j = 0;j < sentence[i].len;j ++) {
                    myLed = 1;
                    if(cache & 1 == 1)
                        wait_ms(3*beat);
                    else
                        wait_ms(beat);
                    cache = cache >> 1;
                    myLed = 0;
                    wait_ms(beat);
                }
            }
        }
    }
}
