int buttonPin = 2;     
int counter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    counter++;
    Serial.print("Button pressed. Count = ");
    Serial.println(counter);
    delay(200); // debounce
  }

  lastButtonState = buttonState;
}
