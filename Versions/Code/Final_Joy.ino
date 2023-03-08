#include "HX711.h"
#include <EEPROM.h>
#define calibration_factor1 outputValue 
#define calibration_factor2 outputValue
#define S0 6
#define S1 7
#define S2 8
#define S3 9
#define TOP_SIG 11
#define THUMB_SIG 10 
int sensorValue;
int outputValue;

void setMux(int pin);
// Set these pins to correspond to the wiring on the hx711
const int LC_DATA1 = 4; // Data Pin 1
const int LC_DATA2 = 2; //Data Pin 2
const int LC_CLK1= 5; // Clock Pin 1
const int LC_CLK2= 3; // Clock Pin 2
int angle = -1; //hat switch angle
HX711 scale1; 
HX711 scale2;

void setup() {
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
scale1.tare();
scale2.tare();
Serial.begin(9600);
}

void loop() {
  // Pot range mapping
  int sensorValue = analogRead(A9);
  outputValue = map(sensorValue, 0, 1023, 200, 800);

  //HX711 to joystick conversion
  if (scale1.is_ready()) {
    long reading = scale1.read();
    Joystick.X(scale1.get_units() / calibration_factor1 + 512);
  }
  if (scale2.is_ready()) {
    long reading = scale2.read();
    Joystick.Y(scale2.get_units() / calibration_factor2 + 512);
  }

  angle = -1;

  // Buttons to Joystick conversion
  for (int i=0; i<16; i++) {
    setMuxs(i);
    if (i == 0) {
      Joystick.button(26, !digitalRead(TOP_SIG));
    } else {
      Joystick.button(i,!digitalRead(TOP_SIG));


    if ((i == 9) && (!digitalRead(TOP_SIG)) == 1) {
      angle = 0;

    } 

    else if ((i == 8) && (!digitalRead(TOP_SIG)) == 1) {
      angle = 90;

    }

    else if ((i == 11) && (!digitalRead(TOP_SIG)) == 1) {
      angle = 180;

    } 

    else if ((i == 10) && (!digitalRead(TOP_SIG)) == 1) {
      angle = 270;

    } 

  }
  // There are only 5 inputs for the thumb joystick board so dont try to send any buttons to computer
  if (i<=5) {
  Joystick.button(i+16, !digitalRead(THUMB_SIG));
  }
  // Serial Prints
  //    Serial.print(digitalRead(THUMB_SIG)); // Prints Mux Readings for Thumb stick
  //    Serial.print(digitalRead(TOP_SIG)); // Prints Mux Readings for top pcb
  //    Serial.print("HX711 X Axis: "); // Prints X Axis
  //    Serial.print(scale1.get_units() / calibration_factor1 + 512); // Prints X Axis
  //    Serial.print("HX711 Y Axis: "); // Prints Y Axis
  //    Serial.println(scale2.get_units() / calibration_factor2 + 512); // Prints Y Axis
  //    Serial.println(outputValue); // Prints Pot for adjusting the force required
  //    Serial.println(calibration_factor1); Prints the Calibration factor
      //Serial.println(digitalRead(S0));
    }
    //Serial.println();

  Joystick.hat(angle);
  
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
    
//Serial.print(controlPin[i]);
    
  }

  //Serial.println();
  delay(1);
}
