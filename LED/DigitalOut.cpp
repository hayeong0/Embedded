/*
Red LED를 1초 간격 (500ms on/ 500ms off)으로, Yellow LED를 2초 간격으로, Green LED를 4초 간격으로 점멸하기
*/

// Version 1: DigitalOut
#include "mbed.h"
#define BLINKING_RATE     500ms
DigitalOut redLed(D3);
DigitalOut yellowLed(D4);
DigitalOut greenLed(D5);

int main(){
    int color = 0;
    while(true) {
        redLed = color & 0x01;
        yellowLed = color & 0x02;
        greenLed = color & 0x04;
        ThisThread::sleep_for(BLINKING_RATE);
         
        color = (color + 1)%8;
    }
}
