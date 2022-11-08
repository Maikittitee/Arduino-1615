const int a = 4;
const int b = 5;
const int c = 8;
const int d = 7;
const int e = 6;
const int f = 3;
const int g = 2;
const int dp = 9;

void setup() {
  // Defining Pin Modes
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
}

void loop() {
  // Turn on all the segment one by one
  digitalWrite(a, HIGH);
  delay(5000);
  digitalWrite(b, HIGH);
  delay(5000);
  digitalWrite(c, HIGH);
  delay(5000);
  digitalWrite(d, HIGH);
  delay(5000);
  digitalWrite(e, HIGH);
  delay(5000);
  digitalWrite(f, HIGH);
  delay(5000);
  digitalWrite(g, HIGH);
  delay(5000);
  digitalWrite(dp, HIGH);
  delay(5000);
  // Turn off all the segment at once
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
  delay(5000);
}
