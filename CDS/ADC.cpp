#include "mbed.h"
BufferedSerial pc(USBTX, USBRX, 115200);
AnalogIn tempSensor(ADC_TEMP);
char buf[80];

int main() {
    float meas;
    
    sprintf(buf, ("\r\n *** ADC Example (Internal Temp Sensor) *** \r\n"));
    pc.write(buf, strlen(buf));
    
    while(true) {
        meas = tempSensor.read();
        meas = 25.0 + (3300.0 * meas - 760.0)/2.5; //convert to temp
        sprintf(buf, "Internal Temperature = %2.f[c] \r\n", meas);
        pc.write(buf, strlen(buf));
        
        ThisThread::sleep_for(chrono::milliseconds(1000));
    }
}
