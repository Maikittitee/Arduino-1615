 phint lastButtonState_A = LOW;
int lastButtonState_B = LOW;
long randomNo;
int num = 1;
const byte numPins= 7;
int whatbit;
const int segmentPins[7] = {8, 7, 6, 5, 4, 3, 2};
const int numberPins[12] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 123, 94, 14};

void shownumber(int a){
  for (int i = 0; i < 7; i++){
    whatbit = bitRead(numberPins[a],i);
    digitalWrite(segmentPins[i],!whatbit);
  }
}

void button_A() {
  int reading = digitalRead(10);
  if(reading == LOW && lastButtonState_A == HIGH){
    num++;
    if(num > 9){
      num = 1;
    }
  }
  lastButtonState_A = reading;
}

void button_B() {
  int reading = digitalRead(11);
  if(reading == LOW && lastButtonState_B == HIGH){
    if(num == randomNo){
      num = 0;
      randomNo = random(1,10);
    }
    else if(num > randomNo){
      num = 10;
    }
    else if(num < randomNo){
      num = 11;
    }
  }
  lastButtonState_B = reading;
}
void setup(){
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(A0,INPUT);
  randomSeed(analogRead(A0));
  randomNo = random(1,10); 
  Serial.begin(9600);
  for (int i = 0; i < numPins; i++){
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i],HIGH); 
    }
  }
void loop() 
{
  button_A();
  button_B();
  shownumber(num);
}
