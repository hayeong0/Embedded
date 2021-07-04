#include "mbed.h"
#define BLINKING_RATE     500ms
PortOut LedCtl(PortB, 0x0038);

int main() {
    int color = 0;
    while(true) {
        for (int i=0; i<8; i++) {
            color =0;
            if (i%2==1)
                color += 8;
            if (i>=4)
                color += 16;
            if (i==2 | i==3 | i==6 | i==7)
                color += 32;
            LedCtl = color; 
            
            ThisThread::sleep_for(BLINKING_RATE);
        }
    }
}
