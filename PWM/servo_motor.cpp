#include "mbed.h"
#define PWM_MIN 550
#define PWM_MAX 2150

PwmOut servoMotor(D6);      //PB_10, D6
UnbufferedSerial pc(PA_2, PA_3, 115200);

char rx_buffer[10];
char tx_buffer[80];
int index = 0;
volatile int flag;

void rx_ISR(void) {
    char ch;
    pc.read(&ch, 1);                // read 1byte
    pc.write(&ch, 1);               // echo 1byte
    rx_buffer[index++] = ch;        // rx_buffer에 index부터 저장
    
    if (ch == '\r') {                   // recevied buf(ch) == CR
        pc.write("\n", 1);              // write LF  (1 line recevied)
        rx_buffer[--index] = '\0';      // change CR to 0
        index = 0;
        flag = 1;                       // 1 line recevied
    }
} 

void control_servo() {
    int num = atoi((const char *) rx_buffer);
    int on = PWM_MIN + (PWM_MAX-PWM_MIN)*num/180;
    
    sprintf(tx_buffer, "Pulse on time = %d(%d)\r\n", on, num);
    pc.write(tx_buffer, strlen(tx_buffer));
    
    if (on < PWM_MIN) on = PWM_MIN;
    if (on > PWM_MAX) on = PWM_MAX;
    
    servoMotor.pulsewidth_us(on);
}

int main() {
    sprintf(tx_buffer, "PWM Test Program (Servo motor)! \r\n");
    pc.write(tx_buffer, strlen(tx_buffer));
    pc.attach(rx_ISR);
    
    servoMotor.period_ms(20);           // PWM period = 20ms
    servoMotor.pulsewidth_us(PWM_MIN);  // for 0 degree
    
    while(1) {
        flag = 0;
        sprintf(tx_buffer, "Enter the rotation degree [0-180]: ");
        pc.write(tx_buffer, strlen(tx_buffer));
        while(flag != 1);           // 한 라인 다 받을 때 까지 while()
        
        control_servo();            // rotation!
    }
}
