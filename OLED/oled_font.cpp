#include "mbed.h"
#include "Adafruit_SSD1306.h"

Adafruit_SSD1306_Spi gOLED(ARDUINO_UNO_D11, ARDUINO_UNO_D13, 
                            ARDUINO_UNO_D10, ARDUINO_UNO_D4, ARDUINO_UNO_D7);

int main() {
  int tmp;
  ThisThread::sleep_for(5000ms);
  gOLED.clearDisplay();

  gOLED.setTextSize(2); 
  gOLED.printf("Hayeong\r\n\n");
  gOLED.setTextSize(1); 
  gOLED.printf("Temperature: \r\n\n");
  gOLED.printf("Humidity:");
  
  while(1) {
      gOLED.setTextCursor(13*6, 4*8);
      tmp = rand()%1000;
      gOLED.printf("%4.1f C", tmp/10.0);
      
      gOLED.setTextCursor(13*6, 6*8);
      tmp = rand()%1000;
      gOLED.printf("%4.1f C", tmp/10.0);
      
      gOLED.display();
      ThisThread::sleep_for(1000ms);
    }
}
