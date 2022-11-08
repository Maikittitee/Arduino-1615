#ifndef MINICLOCK_H
#define MINICLOCK_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

#define OLED_RESET -1

typedef struct timer{
	int hr;
  	int min;
  	int sec
} timer;

void	init_clock();
void	run_up();
void	print_clock();
void	plus_sec(); 
void	plus_hr(); 
void	plus_min(); 
void	check_alarm(); 

#endif