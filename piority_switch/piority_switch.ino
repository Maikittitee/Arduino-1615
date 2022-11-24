#define redButton 2
#define greenButton 3
#define yellowButton 4

#define redLed 5
#define greenLed 5
#define yellowLed 5

//-----<-Debouce->------//

#define debouceDalay 50
long initTime = 0;

// RedButton
int redLastButtonState;
int redButtonState = 0;
// greenButton
int greenLastButtonState;
int greenButtonState = 0;
// yellowButton
int yellowLastButtonState;
int yellowButtonState = 0;

int redLedState = 0;
int greenLedState = 0;
int yellowL edState = 0;




void setup() {
  // put your setup code here, to run once:
  pinMode(redButton, INPUT_PULLDOWN);
  pinMode(greenButton, INPUT_PULLDOWN);
  pinMode(yellowButton, INPUT_PULLDOWN);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  
  // Interrupt Red Button
  attachInterrupt(redButton, runRed, RISING);
  attachInterrupt(greenButton, runGreen, RISING);
  // Interrupt Green Button

}

void  redButton()
{
  redLedState = 1;
  digitalWrite(redLed,digialRead(redButton));
  delay(1000);
    
}

void loop() {}
