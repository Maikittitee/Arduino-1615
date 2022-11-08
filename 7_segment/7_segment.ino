int a = 2;
int b = 3;
int c = 4;
int d = 6;
int e = 7;
int f = 9;
int g = 8;
int sA = 11;
int sB = 12;
int i;

int ans_array[10] = {0,1,2,3,4,5,6,7,8,9};
int led_array[10][7] = {{1,0,0,0,0,0,0},{1,1,1,1,0,0,1},{0,1,0,0,1,0,0},{0,1,1,0,0,0,0},{0,0,1,1,0,0,1},{0,0,1,0,0,1,0},{0,0,0,0,0,1,0},{1,1,1,1,0,0,0},{0,0,0,0,0,0,0},{0,0,1,0,0,0,0}};

int buttonStateA;
int lastButtonStateA = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
int buttonStateB;
int lastButtonStateB = LOW;

void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(sA,INPUT);
  pinMode(sB,INPUT);
  Serial.begin(9600);
}

void loop() {

  int read_A = digitalRead(sA);
  if (read_A == HIGH && lastButtonStateA = LOW)
  {
    Serial.println("A");
  }
  lastButtonStateA = read_A;
 /*
  int R_ans;
  int U_ans;
  int read_A = digitalRead(sA);
  int read_B = digitalRead(sB);
  bool isChange[2] = {false, false};
  
//-------------------------reset debounce-------------------
  if (read_A != lastButtonStateA || read_B != lastButtonStateB)
  {
    lastDebounceTime = millis();
  }
//----------------------------------------------
  if (millis() - lastDebounceTime > debounceDelay)
  {
    if (read_A != buttonStateA) // if A is Presses
    {
      buttonStateA = read_A;
      isChange[0] = true;
    }
    if (read_B != buttonStateB) // if B is Presses
    {
      buttonStateB = read_B;
      isChange[1] = true;
    }

    //---logic---
    if (buttonStateA == HIGH && isChange[0])
    {
      Serial.println("A");
      digitalWrite(g,0);
      digitalWrite(f,0);
      digitalWrite(e,0);
      digitalWrite(d,1);
      digitalWrite(c,0);
      digitalWrite(b,0);
      digitalWrite(a,1);
    }
    if (buttonStateB == HIGH && isChange[1])
    {
      digitalWrite(g,1);
      digitalWrite(f,0);
      digitalWrite(e,0);
      digitalWrite(d,0);
      digitalWrite(c,1);
      digitalWrite(b,1);
      digitalWrite(a,1);
    }
  }
  lastButtonStateB = read_B;
  lastButtonStateA = read_A;
  */
}
