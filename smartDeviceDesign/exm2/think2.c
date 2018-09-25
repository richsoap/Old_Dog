#include "mbed.h"

PwmOut my_led(LED1);
int beat = 750;
int table[] = {0,523,554,587,622,659,698,740,784,831,880,932,988};

struct note{
    float fre;
    int dur;
    note* next;
    note(float _fre = 0, int _dur = 0):fre(_fre), dur(_dur), next(NULL) {}
    note* add(float _fre, int _dur) {
        next = new note(_fre, _dur);
        return next;
    }
}

void playNode(node* select) {
    my_led.period(select->fre*2);
    my_led.pulsewidth_ms(1);
    wait_ms(beat*select->dur);
}


int main() {
    note* head = new note(0,1); 
    note* select;
    head->add(0,3)->add(8,1)->add(8,1)->add(9,1)->add(13,1)->add(15,1)->add(17,2)->add(22,1)
        ->add(20,1)->add(0,1)->add(17,1)->add(15,1)->add(13,3)->add(0,1)->add(13,1)->add(15,1)
        ->add(13,1)->add(12,1)->add(13,1)->add(18,2)->add(10,1)->add(13,1)->add(0,1)->add(17,1)
        ->add(0,1)->add(15,1)->add(0,6);
    while(1) {
        for(select = head; select != NULL; select = select->next)
            playNote(select);
    }
}
