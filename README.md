🧠 Arduino Push Button Counter Project
This project is a simple push button counter using an Arduino Uno and a tactile push button. Every time you press the button, the counter increases by one and prints the count to the Serial Monitor. It’s a great project for beginners to understand digital input, debouncing logic (manually), and basic serial communication.

🔧 Components Used:
Component	Quantity
Arduino Uno R3	1
Push Button (tactile)	1
10kΩ Resistor	1
Jumper Wires	As needed
Breadboard (optional)	1 (optional)

🔌 Circuit Connections:
Arduino Pin	Component Connection
Pin 2	One leg of the push button
GND	Connected to other leg of the button via 10kΩ pull-down resistor
5V	Connected to the same leg of the push button as Pin 2

Note: This is a typical pull-down resistor configuration. When the button is not pressed, the input pin reads LOW due to the resistor pulling it to GND. When pressed, the pin reads HIGH due to the 5V connection.

🧾 Code Explanation:
cpp
Copy
Edit
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
        delay(200); // Basic debounce delay
    }

    lastButtonState = buttonState;
}
🧠 Logic:
buttonPin: The pin connected to the push button (digital pin 2).

counter: Keeps track of the number of times the button is pressed.

lastButtonState: Used to detect the transition from LOW to HIGH (i.e., actual button press, not hold).

delay(200): A basic debounce mechanism to avoid multiple readings from one press.

📟 Output Example (on Serial Monitor):
mathematica
Copy
Edit
Button pressed. Count = 1
Button pressed. Count = 2
Button pressed. Count = 3
📂 Applications & Learning:
Great beginner project to learn input handling.

Understand digitalRead(), pinMode(), and Serial.print().

Can be extended to control LEDs, motors, or LCDs based on count.

