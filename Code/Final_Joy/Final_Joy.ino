#include "HX711.h"
#define calibration_factor1 550 // Changes the Force required for full deflection
#define calibration_factor2 600
#define S0 6
#define S1 7
#define S2 8
#define S3 9

#define TOP_SIG 11
#define THUMB_SIG 10 

void setMux(int pin);
// Set these pins to correspond to the wiring on the hx711
const int LC_DATA1 = 4; // Data Pin 1
const int LC_DATA2 = 2; //Data Pin 2
const int LC_CLK1= 5; // Clock Pin 1
const int LC_CLK2= 3; // Clock Pin 2
HX711 scale1; 
HX711 scale2;

void setup() {
  Serial.begin(57600);
  scale1.begin(LC_DATA1, LC_CLK1);
  scale2.begin(LC_DATA2, LC_CLK2);

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

  scale1.set_scale(calibration_factor1);
  scale2.set_scale(calibration_factor2);
  scale1.tare();
  scale2.tare();
}

void loop() {
//read axis inputs
  if (scale1.is_ready()) {
    long reading = scale1.read();
    Serial.print("HX711 X Axis: ");
    Serial.print(scale1.get_units() + 512);
    Joystick.X(scale1.get_units() + 512);
  }
  if (scale2.is_ready()) {
    long reading = scale2.read();
    Serial.print("HX711 Y Axis: ");
    Serial.println(scale2.get_units() + 512);
    Joystick.Y(scale2.get_units() + 512);
  }
//end read axis inputs

  //read button inputs
  for (int i=0; i<16; i++) {
    setMuxs(i);
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
