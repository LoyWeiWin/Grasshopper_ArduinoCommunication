/* LDR → Arduino → Grasshopper
   Raw output only
   Format: <raw>
   Baud: 115200

   This just streams the raw ADC value (0–1023) from A0, nothing else.
*/

const int PIN_LDR = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int raw = analogRead(PIN_LDR);
  Serial.println(raw);   // just the raw value
  delay(10);             // ~100 Hz
}
