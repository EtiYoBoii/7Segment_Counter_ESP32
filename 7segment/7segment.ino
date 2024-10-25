#include <Arduino.h>


void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void Segments(){
  for(int i=0; i<16; i++){
    switch(i){
      case 0: digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW); break;
      case 1:  digitalWrite(1, HIGH); digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW); break;
      case 2: digitalWrite(1, LOW); digitalWrite(2, HIGH); digitalWrite(3, LOW); digitalWrite(4, LOW); break;
      case 3: digitalWrite(1, HIGH); digitalWrite(2, HIGH); digitalWrite(3, LOW); digitalWrite(4, LOW); break;
      case 4: digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(3, HIGH); digitalWrite(4, LOW); break;
      case 5: digitalWrite(1, HIGH); digitalWrite(2, LOW); digitalWrite(3, HIGH); digitalWrite(4, LOW); break;
      case 6: digitalWrite(1, LOW); digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, LOW); break;
      case 7: digitalWrite(1, HIGH); digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, LOW); break;
      case 8: digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, HIGH); break;
      case 9: digitalWrite(1, HIGH); digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, HIGH); break;
      case 10:  digitalWrite(1, LOW); digitalWrite(2, HIGH); digitalWrite(3, LOW); digitalWrite(4, HIGH); break;
      case 11:  digitalWrite(1, HIGH); digitalWrite(2, HIGH); digitalWrite(3, LOW); digitalWrite(4, HIGH); break;
      case 12:  digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(3, HIGH); digitalWrite(4, HIGH); break;
      case 13:  digitalWrite(1, HIGH); digitalWrite(2, LOW); digitalWrite(3, HIGH); digitalWrite(4, HIGH); break;
      case 14:  digitalWrite(1, LOW); digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH); break;
      case 15:  digitalWrite(1, HIGH); digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH); break;
      default: digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW); break;
    }
    delay(5000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
