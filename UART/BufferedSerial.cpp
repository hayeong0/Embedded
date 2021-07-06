#include "mbed.h"

#define MAXIMUM_BUFFER_SIZE 80
char buf[MAXIMUM_BUFFER_SIZE];

static DigitalOut led(LED2);
static BufferedSerial pc(USBTX, USBRX, 115200);

int main () {
    sprintf(buf, "Hello New Serial function in mbed-os v.%1f\r\n", 6.0);
    pc.write(buf, strlen(buf));
    
    sprintf(buf, "Enter characters... \r\n");
    pc.write(buf, strlen(buf));
    
//    while(1) {
//        led = !led;
//        // 문자 입력될 때까지 기다림
//        int num = pc.read(buf, sizeof(buf));
//        // 문자 출력
//        pc.write(buf, num);
//        // ennter 입력 시, line 변경
//        if (buf[0] == '\r') pc.write("\n", 1);
//    }
    while(1) {
        if (pc.readable()) {
            led = !led;
            
            int num = pc.read(buf, sizeof(buf));
            pc.write(buf, num);
            if (buf[0] == '\r'){
                pc.write("\n", 1);
            }
        }
    } // end of while
}

