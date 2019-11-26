
const int Button = 9;
const int relayModule = 6;


int buttonState = 0;
int prevButtonState = 0;

int motorEnabled = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (relayModule, OUTPUT);
  pinMode(Button, INPUT_PULLUP);
  digitalWrite (relayModule, LOW);
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
    digitalWrite (relayModule, HIGH);
  }
  else {
    digitalWrite (relayModule, LOW);
  }

  prevButtonState = buttonState;
}
