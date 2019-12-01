const int Button = 9;
const int relayModule1 = 6;
const int relayModule2 = 7;


int buttonState = 0;
int prevButtonState = 0;

int motorEnabled = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (relayModule1, OUTPUT);
  pinMode(relayModule2, OUTPUT);
  pinMode(Button, INPUT_PULLUP);
  digitalWrite (relayModule1, LOW);
  digitalWrite (relayModule2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(Button);
  delay (1);
  if (buttonState != prevButtonState){
    if (buttonState == HIGH) {
      motorEnabled = !motorEnabled;
    } 
  }

  if (motorEnabled == 1){
    digitalWrite (relayModule1, HIGH);
    digitalWrite (relayModule2, HIGH);
  }
  else {
    digitalWrite (relayModule1, LOW);
    digitalWrite (relayModule2, LOW);
  }

  prevButtonState = buttonState;
}
