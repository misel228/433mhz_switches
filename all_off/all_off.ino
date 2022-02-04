/*
  from rc switch examples
  
  https://github.com/sui77/rc-switch/
  
*/

#include <RCSwitch.h>
#define LED_PIN 13
#define TX_PIN 5


RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  mySwitch.enableTransmit(TX_PIN);
  
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(2);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
  
  // Optional set number of transmission repetitions.
  mySwitch.setRepeatTransmit(15);

  pinMode(LED_PIN, OUTPUT);
  
}

void loop() {

  digitalWrite(LED_PIN, LOW);
  mySwitch.send(13976913, 24);
  mySwitch.send(13979985, 24);
  mySwitch.send(4436, 24);
  mySwitch.send(1364, 24);
  delay(1000);  

  digitalWrite(LED_PIN, HIGH);
  delay(150);
}
