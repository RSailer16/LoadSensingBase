//Mux control pins
#define s0 18
#define s1 19
#define s2 20
#define s3 21

#define TOP_MUX_SIG 17
#define BOT_MUX_SIG 22


void setMux(int pin);

void setup(){
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  pinMode(TOP_MUX_SIG, INPUT_PULLUP);
  pinMode(BOT_MUX_SIG, INPUT_PULLUP);

  Serial.begin(9600);
}


void loop(){

  //Loop through and read all 16 values
  //Reports back Value at channel 6 is: 346
  for(int i = 0; i < 16; i ++){
    setMux(i);
    Serial.print(digitalRead(TOP_MUX_SIG));
    Serial.print(digitalRead(BOT_MUX_SIG));
  }
  Serial.println();
  
}


void setMux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0 H1
    {1,0,0,0}, //channel 1 H1
    {0,1,0,0}, //channel 2 H1
    {1,1,0,0}, //channel 3 H1
    {0,0,1,0}, //channel 4 H2
    {1,0,1,0}, //channel 5 H2
    {0,1,1,0}, //channel 6 H2
    {1,1,1,0}, //channel 7 H2
    {0,0,0,1}, //channel 8 H3
    {1,0,0,1}, //channel 9 H3
    {0,1,0,1}, //channel 10 H3
    {1,1,0,1}, //channel 11 H3
    {0,0,1,1}, //channel 12 H4
    {1,0,1,1}, //channel 13 H4
    {0,1,1,1}, //channel 14 H4
    {1,1,1,1}  //channel 15 H4
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }
  delay(1);
}
