int A = 2;
int B = 3;
int C = 4;

void setup() {
 
}

void loop() {
    
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,INPUT);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    delay(500);

    pinMode(3,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(4,INPUT);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    delay(500);


    pinMode(3,OUTPUT);
    pinMode(2,INPUT);
    pinMode(4,OUTPUT);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    delay(500);

pinMode(3,OUTPUT);
    pinMode(2,INPUT);
    pinMode(4,OUTPUT);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    delay(500);

    pinMode(2,OUTPUT);
    pinMode(3,INPUT);
    pinMode(4,OUTPUT);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    delay(500);

    digitalWrite(4,LOW);
    digitalWrite(2,HIGH);
    delay(500);

    //--------------------------------

    pinMode(2,OUTPUT);
    pinMode(3,INPUT);
    pinMode(4,OUTPUT);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    delay(500);

    pinMode(3,OUTPUT);
    pinMode(2,INPUT);
    pinMode(4,OUTPUT);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    delay(500);

    pinMode(3,OUTPUT);
    pinMode(2,INPUT);
    pinMode(4,OUTPUT);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    delay(500);

    pinMode(3,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(4,INPUT);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    delay(500);

    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,INPUT);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    delay(500);

}
  
  
