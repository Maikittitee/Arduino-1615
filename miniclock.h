#ifndef MINICLOCK_H
#define MINICLOCK_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

#define startButton 2
#define stopButton 3
#define resetButton 4


#define OLED_RESET -1

typedef struct timer{
	int hr;
  int min;
  int sec;
} timer;


timer	clock;
timer alarm;

int	startButtonState;
int	stopButtonState;
int	startButtonState;
int	lastStartButtonState = 0;
int	lastStopButtonState = 0;
int	lastStartButtonState = 0;
int	initDebouceTime = 0;
int debouceDelay = 50;


String timerStr = "00 : 00 : 00";

void	init_clock();
void	run_up();
void	print_clock();
void	plus_sec(); 
void	plus_hr(); 
void	plus_min(); 
void	check_alarm(); 
void  isStopButton()

#endif