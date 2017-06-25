#include <Keyboard.h>

int newValA;
int newValCountA = 0;

int newValB;
int newValCountB = 0;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  int rotaryValA = int(analogRead(A1)/142);
  int rotaryValB = int(analogRead(A2)/142);  
  
  if (rotaryValA != newValA && newValCountA > 3){
    switchStatement(rotaryValA, 82);
    newValA = rotaryValA;
    newValCountA = 0;
  } else {
    newValCountA++;
  }

  if (rotaryValB != newValB && newValCountB > 3){
    switchStatement(rotaryValB, 72);
    newValB = rotaryValB;
    newValCountB = 0;
  } else {
    newValCountB++;
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


