#include <Keyboard.h>

int newValA0;
int newValCountA0 = 0;

int newValA1;
int newValCountA1 = 0;

int newValA2;
int newValCountA2 = 0;

int newValA3;
int newValCountA3 = 0;

int newValA4;
int newValCountA4 = 0;

int newValA5;
int newValCountA5 = 0;

int newValB0;
int newValCountB0 = 0;

int newValB1;
int newValCountB1 = 0;

int newValB2;
int newValCountB2 = 0;

int newValB3;
int newValCountB3 = 0;

int newValB4;
int newValCountB4 = 0;

int newValB5;
int newValCountB5 = 0;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  int rotaryValA0 = int(analogRead(A0)/142);
  int rotaryValA1 = int(analogRead(A1)/142);
  int rotaryValA2 = int(analogRead(A2)/142);
  int rotaryValA3 = int(analogRead(A3)/142);
  int rotaryValA4 = int(analogRead(A4)/142);
  int rotaryValA5 = int(analogRead(A5)/142);
  int rotaryValB0 = int(analogRead(A6)/142);
  int rotaryValB1 = int(analogRead(A7)/142);
  int rotaryValB2 = int(analogRead(A8)/142);
  int rotaryValB3 = int(analogRead(A9)/142);
  int rotaryValB4 = int(analogRead(A10)/142);
  int rotaryValB5 = int(analogRead(A11)/142);
  
  if (rotaryValA0 != newValA0 && newValCountA0 > 3){
    switchStatement(rotaryValA0, 82);
    newValA0 = rotaryValA0;
    newValCountA0 = 0;
  } else {
    newValCountA0++;
  }
  
  if (rotaryValA1 != newValA1 && newValCountA1 > 3){
    switchStatement(rotaryValA1, 84);
    newValA1 = rotaryValA1;
    newValCountA1 = 0;
  } else {
    newValCountA1++;
  }

  if (rotaryValA2 != newValA2 && newValCountA2 > 3){
    switchStatement(rotaryValA2, 89);
    newValA2 = rotaryValA2;
    newValCountA2 = 0;
  } else {
    newValCountA2++;
  }
  
  if (rotaryValA3 != newValA3 && newValCountA3 > 3){
    switchStatement(rotaryValA3, 85);
    newValA3 = rotaryValA3;
    newValCountA3 = 0;
  } else {
    newValCountA3++;
  }

  if (rotaryValA4 != newValA4 && newValCountA4 > 3){
    switchStatement(rotaryValA4, 73);
    newValA4 = rotaryValA4;
    newValCountA4 = 0;
  } else {
    newValCountA4++;
  }

  if (rotaryValA5 != newValA5 && newValCountA5 > 3){
    switchStatement(rotaryValA5, 79);
    newValA5 = rotaryValA5;
    newValCountA5 = 0;
  } else {
    newValCountA5++;
  }

  if (rotaryValB0 != newValB0 && newValCountB0 > 3){
    switchStatement(rotaryValB0, 80);
    newValB0 = rotaryValB0;
    newValCountB0 = 0;
  } else {
    newValCountB0++;
  }
  
  if (rotaryValB1 != newValB1 && newValCountB1 > 3){
    switchStatement(rotaryValB1, 71);
    newValB1 = rotaryValB1;
    newValCountB1 = 0;
  } else {
    newValCountB1++;
  }

  if (rotaryValB2 != newValB2 && newValCountB2 > 3){
    switchStatement(rotaryValB2, 72);
    newValB2 = rotaryValB2;
    newValCountB2 = 0;
  } else {
    newValCountB2++;
  }
  
  if (rotaryValB3 != newValB3 && newValCountB3 > 3){
    switchStatement(rotaryValB3, 74);
    newValB3 = rotaryValB3;
    newValCountB3 = 0;
  } else {
    newValCountB3++;
  }

  if (rotaryValB4 != newValB4 && newValCountB4 > 3){
    switchStatement(rotaryValB4, 75);
    newValB4 = rotaryValB4;
    newValCountB4 = 0;
  } else {
    newValCountB4++;
  }

  if (rotaryValB5 != newValB5 && newValCountB5 > 3){
    switchStatement(rotaryValB5, 76);
    newValB5 = rotaryValB5;
    newValCountB5 = 0;
  } else {
    newValCountB5++;
  }

  delay(140);
}  

void switchStatement(int selectBox, int keyCodeNum){
    Serial.println(selectBox);
    switch (selectBox) {
      case 0:
        Keyboard.write(keyCodeNum);
        Keyboard.write(48); 
        break;
      case 1:
        Keyboard.write(keyCodeNum);
        Keyboard.write(49); 
        break;
      case 2:
        Keyboard.write(keyCodeNum);
        Keyboard.write(50); 
        break; 
      case 3:
        Keyboard.write(keyCodeNum);
        Keyboard.write(51); 
        break;
      case 4:
        Keyboard.write(keyCodeNum);
        Keyboard.write(52); 
        break;
      case 5:
        Keyboard.write(keyCodeNum);
        Keyboard.write(53); 
        break;
      case 6:
        Keyboard.write(keyCodeNum);
        Keyboard.write(54); 
        break;
      case 7:
        Keyboard.write(keyCodeNum);
        Keyboard.write(55); 
        break;
    }    
}


