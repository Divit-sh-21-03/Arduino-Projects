int sensorPin = A0;
int fanPin = 13;
int target = 0;

int raw = 0;
float volts = 0;
float tempC = 0;

unsigned long lastRead = 0;
unsigned long lastPrint = 0;

void setup() {
  pinMode(fanPin, OUTPUT);
  analogWrite(fanPin, 0);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();

  if (now - lastRead >= 300) {
    lastRead = now;
    raw = analogRead(sensorPin);
    volts = raw * (5.0 / 1023.0);
    tempC = (volts - 0.5) * 100.0;
    if (tempC < 25.0) target = 0;
    else if (tempC < 30.0) target = 50;
    else target = 100;
    int pwmVal = 0;
    if (target == 0) pwmVal = 0;
    else if (target == 50) pwmVal = 128;
    else pwmVal = 255;
    analogWrite(fanPin, pwmVal);
  }

  if (now - lastPrint >= 500) {
    lastPrint = now;
    Serial.print("Temp: ");
    Serial.print(tempC, 1);
    Serial.print(" C  Fan: ");
    if (target == 0) Serial.println("OFF");
    else if (target == 50) Serial.println("50%");
    else Serial.println("100%");
  }
}
