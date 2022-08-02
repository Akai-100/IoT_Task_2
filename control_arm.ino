#include <Servo.h>

Servo myservo;
double pos = 0;

void setup() {
 Serial.begin(9600);
 myservo.attach(9);
 
}

void loop() {
 String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  
  String command = getValue(computerText, ' ',0);

    if (command == "right." || command == "رايت." || command == "Right." || command == "يمين." || command == "رايت" || command == "Right" || command == "يمين" || command == "right") {
      myservo.write(pos += 180);
    }
    if (command == "left." || command == "Left." || command == "لفت." || command == "يسار." || command == "Left" || command == "لفت" || command == "يسار" || command == "left") {
      myservo.write(pos -= 180);
    }
  delay(1000);
}


String getValue(String data, char separator, int index){
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
