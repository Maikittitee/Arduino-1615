#define Button_1 12
#define Button_2 11
#define Button_3 10
#define Output_1 4
#define Output_2 3
#define Output_3 2
void setup() {
  // put your setup code here, to run once:
  pinMode(Button_1, INPUT);
  pinMode(Button_2, INPUT);
  pinMode(Button_3, INPUT_PULLUP);
  pinMode(Output_1, OUTPUT);
  pinMode(Output_2, OUTPUT);
  pinMode(Output_3, OUTPUT);

  digitalWrite(Output_1, 0);
  digitalWrite(Output_2, 0);
  digitalWrite(Output_3,0);
}\

void loop() {
  
  int reader_1 = digitalRead(Button_1);
  int reader_2 = digitalRead(Button_2);
  int reader_3 = digitalRead(Button_3);
  
  if(reader_1 == 1)
  {
   digitalWrite(Output_1,!digitalRead(Output_1)); 
  }
  if(reader_2 == 0)
  {
   digitalWrite(Output_2,!digitalRead(Output_2)); 
  }
  if(reader_3 == 0)
  {
   digitalWrite(Output_3,!digitalRead(Output_3)); 
  }
}
