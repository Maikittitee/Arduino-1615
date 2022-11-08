
#define R 8
#define Y 9
#define G 10
#define buzzer 11
void setup()
{
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  digitalWrite(R, 0);
  digitalWrite(Y, 0);
  digitalWrite(G, 0);
  //digitalWrite(buzzer, LOW);
  delay(1000);
}
