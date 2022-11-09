#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
#include <stdlib.h>

#define startButton 2
#define stopButton 3
#define resetButton 4

int reset = 0;
int start = 0;
int stop = 0;


#define OLED_RESET -1

int	startButtonState;
int	stopButtonState;
int	resetButtonState;
int	lastStartButtonState = 0;
int	lastStopButtonState = 0;
int	lastResetButtonState = 0;
int	initDebouceTime = 0;
int debouceDelay = 50;

int timerIsRun = 0;

typedef struct s_timer{
	int hr;
  int min;
  int sec;
} t_timer;

int	timer1_counter;

int t1 = 0;

Adafruit_SSD1306 OLED(OLED_RESET);

t_timer clock;
t_timer timer;
t_timer alarm;

String timerStr = "00 : 00 : 00";
String clockStr = "00 : 00 : 00";

//----------------Define Used Function------------------


//give Start value of clock
void	init_clock()
{
  if (EEPROM.read(0) || EEPROM.read(1) || EEPROM.read(2))
  {
    clock.hr = EEPROM.read(0);
    clock.min = EEPROM.read(1);
    clock.sec = EEPROM.read(2);
  }
  else
  {
    clock.hr = 0;
    clock.min = 0;
    clock.sec = 0;
  }
  
}

void	init_timer()
{
  timer.hr = 0;
  timer.min = 0;
  timer.sec = 0;
}

void  init_eeprom()
{
  EEPROM.write(0, clock.hr);
  EEPROM.write(1, clock.min);
  EEPROM.write(2, clock.sec);
}

void  update_eeprom()
{
  EEPROM.update(0, clock.hr);
  EEPROM.update(1, clock.min);
  EEPROM.update(2, clock.sec);
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

void	run_timer()
{
  timer.sec += 1;
  timer.min += (timer.sec/60);
  timer.sec %= 60;
  timer.hr += (timer.min/60);
  timer.min %= 60;
  timer.hr %= 24;
}

//show clock;

void	print_clock()
{
  clockStr[0] = (clock.hr / 10) + '0';
  clockStr[1] = (clock.hr % 10) + '0';

  clockStr[5] = (clock.min / 10) + '0';
  clockStr[6] = (clock.min % 10) + '0';

  clockStr[10] = (clock.sec / 10) + '0';
  clockStr[11] = (clock.sec % 10) + '0';

Serial.print("Clock :");
  Serial.println(clockStr);

}

void	print_timer()
{
  timerStr[0] = (timer.hr / 10) + '0';
  timerStr[1] = (timer.hr % 10) + '0';

  timerStr[5] = (timer.min / 10) + '0';
  timerStr[6] = (timer.min % 10) + '0';

  timerStr[10] = (timer.sec / 10) + '0';
  timerStr[11] = (timer.sec % 10) + '0';

  Serial.print("Timer :");
  Serial.print(timerStr);
  Serial.print(" | ");

}

// For setting Alarm Time, setting clock

// Debouce

void  isStartButton()
{
  int read = digitalRead(startButton);
  
  if (read != lastStartButtonState)
  	initDebouceTime = millis();
  
  if (millis() - initDebouceTime >= debouceDelay)
  {
    if (read != startButtonState)
    {
    	startButtonState = read;
    }
  }
  lastStartButtonState = read;
}

void  isStopButton()
{
  int read = digitalRead(stopButton);
  
  if (read != lastStopButtonState)
  	initDebouceTime = millis();
  
  if (millis() - initDebouceTime >= debouceDelay)
  {
    if (read != stopButtonState)
    {
    	stopButtonState = read;
    }
  }
  lastStopButtonState = read;
}

void  isResetButton()
{
  int read = digitalRead(resetButton);
  
  if (read != lastResetButtonState)
  	initDebouceTime = millis();
  
  if (millis() - initDebouceTime >= debouceDelay)
  {
    if (read != resetButtonState)
    {
    	resetButtonState = read;
    }
  }
  lastResetButtonState = read;
}

void  check_alarm()
{
  if (clock.hr == alarm.hr && clock.min == alarm.min && clock.sec == alarm.sec)
  {
    Serial.println("ALARMM!");
    tone(11,300,3000);
  }
}

//--------------------------------Arduino Function ---------------------------------//

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
  init_eeprom();

  Serial.println("-----Run kub------");
}

ISR(TIMER1_OVF_vect)
{
    TCNT1 = timer1_counter;
    t1++;
    run_up();
    print_clock();
    check_alarm();
    if (timerIsRun)
    {
      run_timer();
    }
    print_timer();
    update_eeprom();

  	
}

void loop() {

  int xaccel = analogRead(A0);
  int yaccel = analogRead(A1);
  int zaccel = analogRead(A2);
  unsigned long timevar = millis();

  int need_flip;

  static char message[11]; // should be "{a/t} 12:34:56"
  static unsigned int message_pos = 0;
  int input = 0;

  isStartButton();
  isStopButton();
  isResetButton();

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
  if (startButtonState)
    timerIsRun = 1;
  else if (stopButtonState)
    timerIsRun = 0;
  else if (resetButtonState)
  {
    init_timer();
  }

  if (xaccel < 300)
    OLED.setRotation(2);
  else
    OLED.setRotation(0);


  //show
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(10, 0);
  OLED.setTextSize(2);
  OLED.print(clockStr);
  OLED.setTextSize(1);
  OLED.print("    \n        ");
  OLED.println(timerStr);
  OLED.display();

  // Serial.print(timevar);
  // Serial.print(" ");
  // Serial.print(xaccel);
  // Serial.print(" ");
  // Serial.print(yaccel);
  // Serial.print(" ");
  // Serial.println(zaccel);

  

  

}
