int IR_PIN = 2;      // IR sensor output pin
int RELAY_PIN = 7;   // Relay control pin
int LED_PIN = 3;     // LED input pin
int objectDetected = 0;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Ensure the relay is initially off
  pinMode(IR_PIN, INPUT);
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  objectDetected = digitalRead(IR_PIN);
  
  if (objectDetected == HIGH) {
    digitalWrite(RELAY_PIN, LOW); // Turn OFF the relay
    digitalWrite(LED_PIN, LOW);   // Turn OFF the led
    
  }else {
    digitalWrite(RELAY_PIN, HIGH); // Turn ON the relay
    Serial.println("No object detected. Relay OFF.");
    digitalWrite(LED_PIN, HIGH);   // Turn ON the led
    delay(950);
  }
  
}