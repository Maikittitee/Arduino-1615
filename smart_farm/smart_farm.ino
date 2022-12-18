#include <SimpleDHT.h> 
#include <WiFi.h>
#include <TridentTD_LineNotify.h>

#define waterPotenSensorPin 34
#define waterSensorPin 35
#define LED1 14
#define LED2 26
#define LED3 33
#define Motor 15

#define SSID        "guest"   // ชื่อ Wifi
#define PASSWORD    "Guest42guest"   // รหัส Wifi
#define LINE_TOKEN  "As5aqolzulTo753s7LRjgCThxl8ntkYWhKWe8RZWSN2"

int waterPotenSensorValue;
int waterSensorValue;

SimpleDHT11 dht11;

int DHTSENSOR = 32;
byte humidity = 0;
byte temperature = 0;

int haveWater()
{
  waterPotenSensorValue = analogRead(waterPotenSensorPin);
  Serial.print("waterPotenSensorValue:");
  Serial.println(waterPotenSensorValue);
  if (waterPotenSensorValue < 1400)
    return (1);
  return (0);
}
int needWater()
{
  waterSensorValue = analogRead(waterSensorPin);
  Serial.print("waterSensorValue:");
  Serial.println(waterSensorValue);
  return (waterSensorValue > 3000);
}

int isRain()
{
  dht11.read(DHTSENSOR, &temperature, &humidity, NULL);
  Serial.print("humidity:");
  Serial.println(humidity);
  if (humidity > 80)
    return (1);
  return (0);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(Motor, OUTPUT);
  pinMode(waterSensorPin, INPUT);
  pinMode(waterPotenSensorPin, INPUT);
  WiFi.begin(SSID, PASSWORD);
  LINE.setToken(LINE_TOKEN);
  // ส่งข้อความ
  LINE.notify("เริ่มการใช้งานระบบตรวจจับคุณภาพอากาศ");
  LINE.notify("Smart Tong's Farm");

}

void loop() {
  digitalWrite(LED2 , haveWater() && 1);
  digitalWrite(LED1, isRain());

  if (needWater() && haveWater() && !isRain())
  {
    digitalWrite(LED3, 1);
    digitalWrite(Motor, 1);
  }
  else
  {
    digitalWrite(LED3, 0);
    digitalWrite(Motor, 0);
  }
  if (!haveWater())
  {
      LINE.notify("เติมน้ำไอ้เวนนนนน");
  }
  delay(100);
  //digitalWrite(Motor, 1);


 

  

}
