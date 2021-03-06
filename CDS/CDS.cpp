#include "mbed.h"

#define MAXIMUM_BUFFER_SIZE 80
char buf[MAXIMUM_BUFFER_SIZE];

AnalogIn ain0(A0); // A0(PA_0), ADC1_IN0; analog 생성
BufferedSerial pc(USBTX, USBRX, 115200);

int main() {
    float meas;
    
    sprintf(buf, "\r\n Welcome to Analog In Lab. \r\n");
    pc.write(buf, strlen(buf));
    
    while(1) {
        meas = ain0.read(); // ain0을 통한 input alaog를 [0.0, 1.0]으로 읽어와서 meas에 저장
        meas = meas*3300;   // 0~1 * 3.3v (mv이므로 *3300)
        sprintf(buf, "A0 input voltage = %.2f mV\r\n", meas);
        pc.write(buf, strlen(buf));
        
        ThisThread::sleep_for(chrono::milliseconds(1000));
    }
}
