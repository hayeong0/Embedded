#include "mbed.h"

DigitalOut led2(LED2);
InterruptIn button(USER_BUTTON);
Ticker led2_ticker;

float interval = 0.5;

void button_onpressed(void);
void timeout_cb(void);

int main() {
    // button 누르면 h/w적으로 falling (ISR로 실행)
    button.fall(&button_onpressed);
    // 초기 interval로 timeout_cb에 attach
    led2_ticker.attach(&timeout_cb, interval);
    
    while (true) {}
}

void button_onpressed(void) {
    led2_ticker.detach();       // disable timer
    interval = interval * 2;    // equals >> 1
    if (interval > 4.0)
        interval = 0.125;
    
    led2 = 1;                   // turn on the LED2; 상태와 무관하게 항상 켜지게끔
    // 새로운 interval 간격으로 timeout_cb가 실행되도록 attach
    led2_ticker.attach(&timeout_cb, interval);
}

void timeout_cb(void) {
    led2 = !led2;
}
