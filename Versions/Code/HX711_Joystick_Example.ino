#include "HX711.h"

//Mux control pins
#define S0 18
#define S1 19
#define S2 20
#define S3 21

#define TOP_SIG 17
#define THUMB_SIG 22

void setMux(int pin);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN1 = 3;
const int LOADCELL_SCK_PIN1= 2;
HX711 scale1;
const int LOADCELL_DOUT_PIN2 = 5;
const int LOADCELL_SCK_PIN2= 4;
HX711 scale2;

void setup() {
  Serial.begin(57600);
  scale1.begin(LOADCELL_DOUT_PIN1, LOADCELL_SCK_PIN1);
  scale2.begin(LOADCELL_DOUT_PIN2, LOADCELL_SCK_PIN2);

  pinMode(S0, OUTPUT); 
  pinMode(S1, OUTPUT); 
  pinMode(S2, OUTPUT); 
  pinMode(S3, OUTPUT); 

  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  pinMode(TOP_SIG, INPUT_PULLUP);
  pinMode(THUMB_SIG, INPUT_PULLUP);
  //Joystick.begin();
}

void loop() {
//read axis inputs
  if (scale1.is_ready()) {
    long reading = scale1.read();
    Serial.print("HX711 X Axis: ");
    
    Serial.print(scale1.get_units() * .0017 + 844);
    Joystick.X(scale1.get_units() * .0017 + 844);
  }
  if (scale2.is_ready()) {
    long reading = scale2.read();
    Serial.print("   HX711 Y Axis: ");
    Serial.println(-scale2.get_units() * .0017 + 52);
    Joystick.Y(-scale2.get_units() * .0017 + 52);
  }
//end read axis inputs

  //read button inputs
  for (int i=0; i<16; i++) {
    setMuxs(i);
    //Serial.print(digitalRead(TOP_SIG));
    //Serial.print(digitalRead(THUMB_SIG));
    //Serial.println();
    //read the value at the SIG pin and send to joystick
    if (i == 0) {
      Joystick.button(26, !digitalRead(TOP_SIG));
    } else {
      Joystick.button(i,!digitalRead(TOP_SIG));
    }
    // There are only 5 inputs for the thumb joystick board so dont try to send any buttons to computer
    if (i<=5) {
      Joystick.button(i+16, !digitalRead(THUMB_SIG));
    }
  }
  //Serial.println();
  //end of read button inputs
  
  //delay(1);
  
}

void setMuxs(int channel){
  int controlPin[] = {S0, S1, S2, S3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }
  delay(1);
}
