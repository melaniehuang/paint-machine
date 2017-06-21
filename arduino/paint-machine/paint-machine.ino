#include <Keyboard.h>

int ledPin =  13;  
int switchPinB = 3; 
const int switchPinA = 2; 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(switchPinA, INPUT);
  pinMode(switchPinB, INPUT);
  Keyboard.begin();
}

void loop() {
  int sensorValue = analogRead(A1);
  int sensorValueB = analogRead(A2);
  int buttonState = digitalRead(switchPinA);
  int buttonState2 = digitalRead(switchPinB);

  int rotaryvalA = int(sensorValue/142);
  int rotaryvalB = int(sensorValueB/142);

  Serial.println(buttonState);
  Serial.println(buttonState2);
  Serial.println(rotaryvalA);
  Serial.println(rotaryvalB);

  if (rotaryvalA == 7){
    Keyboard.write(89);
    Keyboard.write(49);
    Serial.println("ja");
  }

  if (rotaryvalB == 7){
    Keyboard.write(80);
    Keyboard.write(66);
    Keyboard.write(72);
    Keyboard.write(70);
    Serial.println("howzat");
  }
  
  delay(200);       
}
