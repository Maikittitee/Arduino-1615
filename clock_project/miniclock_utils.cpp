#include "miniclock.h"

timer	clock;
timer alarm;

String timerStr = "00 : 00 : 00";

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

void  check_alarm()
{
  if (clock == alarm)
  {
    //ALARM !!
  }
}
