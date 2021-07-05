#include "mbed.h"

Ticker timer1;      // 반복
Timeout timeout;    // 1qjs

DigitalOut led1(D3);
DigitalOut led2(D4);

// 0.5초마다 실행
void blink_led1() {
    led1 = !led1;
}

// 10초 지난 후 실행되어 off
void off_led2() {
    led2 = 0;
}

int main() {
    led2 = 1;   // greenLED on
    
    timer1.attach(&blink_led1, 0.5f);    // 0.5 sec
    timeout.attach(&off_led2, 10.0f);   // 10 sec
    
    while(1) {}
}
