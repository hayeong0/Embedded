#include "mbed.h"
#include "HTU21D.h"
#include "Adafruit_SSD1306.h"

HTU21D i2c(PB_9, PB_8);
Adafruit_SSD1306_Spi gOLED(ARDUINO_UNO_D11, ARDUINO_UNO_D13, ARDUINO_UNO_D10,
                            ARDUINO_UNO_D4, ARDUINO_UNO_D7);

int main() {
  ThisThread::sleep_for(5000ms);
  gOLED.clearDisplay();

  gOLED.setTextSize(2); 
  gOLED.printf("Hayeong\r\n\n");
  gOLED.setTextSize(1); 
  gOLED.printf("Temperature: \r\n\n");
  gOLED.printf("Humidity:");
  
  while(1) {
      gOLED.setTextCursor(13*6, 4*8);
      float temp = i2c.sample_ctemp();
      gOLED.printf("%.1f [c]", temp);
      
      gOLED.setTextCursor(13*6, 6*8);
      float hum = i2c.sample_humid();
      gOLED.printf("%.1f [%%]", hum);
      
      gOLED.display();
      ThisThread::sleep_for(3000ms);
    }
}
