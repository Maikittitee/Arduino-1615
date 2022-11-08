#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

void setup() {
  u8g2.begin();
  Serial.begin(9600);
}

void loop() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_logisoso28_tr);
  u8g2.drawStr(8,29,"Hello");
  u8g2.sendBuffer();
  delay(3000);
}
