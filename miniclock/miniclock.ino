#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
#include <stdlib.h>

#define startButton 2
#define stopButton 3
#define resetButton 4


#define OLED_RESET -1

int	startButtonState;
int	stopButtonState;
int	resetButtonState;
int	lastStartButtonState = 0;
int	lastStopButtonState = 0;
int	lastResetButtonState = 0;
int	initDebouceTime = 0;
int debouceDelay = 50;

typedef struct timer{
	int hr;
  int min;
  int sec;
} timer;

int	timer1_counter;

int t1 = 0;

Adafruit_SSD1306 OLED(OLED_RESET);

timer clock;
timer alarm;

String timerStr = "00 : 00 : 00";
String clockStr = "00 : 00 : 00";

//----------------Define Used Function------------------


//give Start value of clock
void	init_clock()
{
  clock.hr = 0;
  clock.min = 0;
  clock.sec = 0;
}

//count the clock up, timer up

void	run_up()
{
  clock.sec += 1;
  clock.min += (clock.sec/60);
  clock.sec %= 60;
  clock.hr += (clock.min/60);
  clock.min %= 60;
  clock.hr %= 24;
}

//show clock;

void	print_clock()
{
  timerStr[0] = (clock.hr / 10) + '0';
  timerStr[1] = (clock.hr % 10) + '0';

  timerStr[5] = (clock.min / 10) + '0';
  timerStr[6] = (clock.min % 10) + '0';

  timerStr[10] = (clock.sec / 10) + '0';
  timerStr[11] = (clock.sec % 10) + '0';

  Serial.println(timerStr);

}

// For setting Alarm Time, setting clock

void  plus_sec(timer obj)
{
  obj.sec += 1;
  obj.min += (clock.sec/60);
  obj.sec %= 60;
  obj.hr += (clock.min/60);
  obj.min %= 60;
  obj.hr %= 24;  
}

void  plus_min(timer obj)
{
  obj.min += 1;
  obj.sec %= 60;
  obj.hr += (clock.min/60);
  obj.min %= 60;
  obj.hr %= 24;   
}

void  plus_hr(timer obj)
{
  obj.hr += 1;
  obj.min %= 60;
  obj.hr %= 24;  
}

// Debouce

void  isStopButton()
{
  int read_1 = digitalRead(startButton);
  
  if (read_1 != lastStartButtonState)
  	initDebouceTime = millis();
  
  if (millis() - initDebouceTime >= debouceDelay)
  {
    if (read_1 != startButtonState)
    {
    	startButtonState = read_1;
    }
  }
  lastStartButtonState = read_1;
}

void  check_alarm()
{
  if (clock.hr == alarm.hr && clock.min == alarm.min)
  {
    //ALARM !!
  }
}

//--------------------------------------------------------------------------//

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
    // Serial.print(clock.hr);
    // Serial.print(" : ");
    // Serial.print(clock.min);
    // Serial.print(" : ");
    // Serial.println(clock.sec);
  	
}

void loop() {


  static char message[11]; // should be "{a/t} 12:34:56"
  static unsigned int message_pos = 0;
  int input = 0;
  
  while (Serial.available() > 0)
  {
    char inByte = Serial.read();
    if ( inByte != '\n' && (message_pos < 10) ) 
    {
    message[message_pos] = inByte;
    message_pos++;
    }
    else
    {
      message[10] = '\0';
      input = 1;
      Serial.print("Recieve massage : ");
      Serial.println(message);
      message_pos = 0;
    } 
  }

  if ((message[0] == 'A' || message[0] == 'a') && input)
  {
    alarm.hr = atoi(&message[2]);
    alarm.min = atoi(&message[5]);
    alarm.sec = atoi(&message[8]);
  }
  else if (input)
  {
    clock.hr = atoi(&message[2]);
    clock.min = atoi(&message[5]);
    clock.sec = atoi(&message[8]) - 1;
  }


  //show
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(10, 0);
  OLED.setTextSize(2);
  OLED.println(timerStr);
  OLED.display();

  

}
