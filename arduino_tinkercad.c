// WRITE A PROGRAM USING OPEN SOURCE PROTOTYPE PLATFORM ARDUINO FOR DIGITAL READ/WRITE USING LED AND 
// SWITCH ANALOG READ/WRITE USING SENSOR AND ACTUATORS.

const int LED = 12;              // Digital LED pin
const int PWM_LED = 9;           // PWM LED pin (analog output)
int button = 2;                  // Button pin
int buttonState = 0;
int buttonPressCount = 0;        // To track button presses

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PWM_LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // Digital read
  buttonState = digitalRead(button);
  static int lastButtonState = LOW;
  
  // Detect button press
  if (buttonState == HIGH && lastButtonState == LOW) {
    buttonPressCount = (buttonPressCount + 1) % 5;  // Count 0-4 and repeat
    
    // Digital write
    digitalWrite(LED, HIGH);
    
    // Analog write - brightness based on press count
    int brightness = buttonPressCount * 60;  // Values: 0, 60, 120, 180, 240
    analogWrite(PWM_LED, brightness);
    
    Serial.print("Button press count: ");
    Serial.print(buttonPressCount);
    Serial.print(" Brightness: ");
    Serial.println(brightness);
    
    delay(50);  // Debounce
  } else if (buttonState == LOW) {
    digitalWrite(LED, LOW);  // Original LED turns off when button released
  }
  
  lastButtonState = buttonState;
  delay(10);
}

/*

const int LED = 12; 
const int PWM_LED = 9;
const int button = 2;
const int buzzer = 6;

int buttonState = 0;
int buttonPressCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PWM_LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);
  static int lastButtonState = LOW;

  if (buttonState == HIGH && lastButtonState == LOW) {
    buttonPressCount = (buttonPressCount + 1) % 5;  // 0-4 cycle

    // Digital write: turn ON LED
    digitalWrite(LED, HIGH);

    // Analog write: adjust LED brightness
    int brightness = buttonPressCount * 60;  // 0, 60, 120, 180, 240
    analogWrite(PWM_LED, brightness);

    // Analog write: control buzzer frequency
    int buzzerFrequency = 200 + (buttonPressCount * 200);  // 200, 400, 600, 800, 1000 Hz
    tone(buzzer, buzzerFrequency);  // Play sound on buzzer

    Serial.print("Button press count: ");
    Serial.print(buttonPressCount);
    Serial.print(" Brightness: ");
    Serial.print(brightness);
    Serial.print(" Buzzer frequency: ");
    Serial.println(buzzerFrequency);

    delay(50);  // Debounce
  } 
  else if (buttonState == LOW) {
    digitalWrite(LED, LOW);  // LED OFF
    noTone(buzzer);          // Stop buzzer sound
  }

  lastButtonState = buttonState;
  delay(10);
}*/

