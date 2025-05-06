const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(sensorPin);
  Serial.println(lightLevel);
  delay(50);
}
