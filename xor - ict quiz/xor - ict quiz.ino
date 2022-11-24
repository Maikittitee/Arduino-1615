//Led check
//button
//button ip
//fuction 


#define debounceDelay 50
int initTime = 0;
int buttonState = 0;
int lastButtonState = 0;
int num[3] = {0,0,0};
int i = 0;
int buttonTimes = 0;

int rotate_cir(void)
{
  int times = num[1];
  int n = num[0]; //00000111;
  int temp;

  while(times)
  {
    temp = (n & B00001000) >> 3;  
    n = n << 1;
    n += temp;
    times--;
  }
  return (n);
}

void setup() {
  // put your setup code here, to run once:
  DDRB |= B00001111; //set led
  DDRD &= !B11110000;
  Serial.begin(9600);

}

void loop() {
  int reading = digitalRead(4);


  if (reading != lastButtonState) {
    initTime = millis();
  }

  if ((millis() - initTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        num[i] = (PIND & B11100000) >> 5;
        PORTB = (num[i]);
        i++;
        Serial.println("------");
        Serial.print("num1 = ");
        Serial.println(num[0]);
        Serial.print("num2 = ");
        Serial.println(num[1]);
        buttonTimes++;
      }
    }
  }

  lastButtonState = reading;
  if (buttonTimes == 3)
  {
    PORTB = rotate_cir();
  }
  if (buttonTimes == 4)
  {
    num[0]= 0;
    num[1] = 0;
    buttonTimes = 0;
    i = 0;
  }


  //if (digitalRead(4) == 1)
  //PORTB |= B00001111;
  //delay(1000);
  //PORTB &= !B00001111;
  // delay(1000);


}
