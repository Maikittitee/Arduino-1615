#include "miniclock.h"

//debouce
// #define debouceDelay 50
// int	lastButtonState = 0;
// int	buttonState;
// int	initDebouceTime = 0;

int	timer1_counter;

int t1 = 0;

Adafruit_SSD1306 OLED(OLED_RESET);

void setup() {
  Serial.begin(9600);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  //initislize timer1
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  timer1_counter = 3036;
  init_clock();
  
  TCNT1 = timer1_counter;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 <<  TOIE1);
  interrupts();
  init_clock();
}

ISR(TIMER1_OVF_vect)
{
    TCNT1 = timer1_counter;
    t1++;
    run_up();
    print_clock();
  	
}

void loop() {

  // int read_1 = digitalRead(button1);
  
  // if (read_1 != lastButtonState)
  // 	initDebouceTime = millis();
  
  // if (millis() - initDebouceTime > debouceDelay)
  // {
  //   if (read_1 != buttonState)
  //   {
  //   	buttonState = read_1;
  //    	if (read_1 == 1)
  //        	thisState = state_list[1];
      	
  //   }
  // }
  // lastButtonState = read_1;
  
  //show
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(10, 0);
  OLED.setTextSize(2);
  OLED.println(timerStr);
  OLED.display();
  

}
