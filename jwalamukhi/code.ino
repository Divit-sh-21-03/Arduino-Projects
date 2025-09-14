#include<LiquidCrystal.h>
int switchpin = 4;
const int tempSensor = A0;  
const int gasSensor = A1;    
const int motorPin = 9;          
const int buzzerPin = 8;     
const int ledPin = 7;        
const int pirSensor = 6;    
const int mintemp = 35;        
const int maxtemp = 85;        
const int minRPM = 350;        
const int maxRPM = 500;        
const int increment = 50;   
const int tempThreshold = 70; 
LiquidCrystal lcd(13, 12, 11, 10, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  pinMode(switchpin, INPUT); 
  pinMode(tempSensor, INPUT); 
  pinMode(gasSensor, INPUT);  
  pinMode(motorPin, OUTPUT);  
  pinMode(buzzerPin, OUTPUT); 
  pinMode(ledPin, OUTPUT);    
  pinMode(pirSensor, INPUT);  
}

void loop() {

  int tempSensorValue = analogRead(tempSensor);
  float voltage = tempSensorValue * (5.0 / 1023.0);
  float temp = (voltage - 0.5) * 100;
  Serial.print("Temperature: ");
  Serial.println(temp);

  int gasSensorValue = analogRead(gasSensor);
  Serial.print("Gas Sensor Input: ");
  Serial.println(gasSensorValue);
  
  lcd.setCursor(0,0);          
lcd.print("  Temperature");
lcd.setCursor(0,1);
lcd.print(temp);

  
  if (temp > tempThreshold) {
    analogWrite(motorPin, 0);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Temperature exceeds threshold! Buzzer ON.");

    
  int pirValue = digitalRead(pirSensor);
  if (pirValue == HIGH) {
    digitalWrite(ledPin, HIGH);    
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);      
    Serial.println("No motion detected. ");
  }
    
  } else {
   
    if (gasSensorValue > 250) {
      digitalWrite(buzzerPin, HIGH);
      Serial.println("smoke detected! Buzzer ON.");

    
  int pirValue = digitalRead(pirSensor);
  if (pirValue == HIGH) {
    
    digitalWrite(ledPin, HIGH);     
    Serial.println("Motion detected! ");
  } else {
    digitalWrite(ledPin, LOW);      
    Serial.println("No motion detected. ");
  }
      
    } else {
      digitalWrite(buzzerPin, LOW);
      
    }
  }
  
  if(digitalRead(switchpin)){
   digitalWrite(buzzerPin, HIGH);
  Serial.println("fire alarm turned on manually");
    int pirValue = digitalRead(pirSensor);
  if (pirValue == HIGH) {
    
    digitalWrite(ledPin, HIGH);     
    Serial.println("Motion detected! ");
  } else {
    digitalWrite(ledPin, LOW);      
    Serial.println("No motion detected. ");
  }
  
  
  
  }

  
  if (temp > mintemp && temp < tempThreshold) {
    int fanRPM = minRPM + ((int)(temp - mintemp) / 5) * increment;
    fanRPM = constrain(fanRPM, minRPM, maxRPM); 
    Serial.print("Calculated Fan RPM: ");
    Serial.println(fanRPM);

    int motorSpeedValue = map(fanRPM, 0, 5300, 0, 255);
    motorSpeedValue = constrain(motorSpeedValue, 0, 255);
    Serial.print("Motor Speed : ");
    Serial.println(motorSpeedValue);
    analogWrite(motorPin, motorSpeedValue);

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" °C, Fan RPM: ");
    Serial.println(fanRPM);
    
  } else {
    analogWrite(motorPin, 0);
    
  }

  

  delay(1000); 
}

