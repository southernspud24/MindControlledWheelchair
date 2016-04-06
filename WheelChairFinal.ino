#include <Servo.h>

boolean a=true;
boolean b=true;
boolean c=false;
boolean d=false;
boolean e=true;
boolean f=true;
boolean g=false;
boolean h=false;
int pause = 1500;
boolean led=false;

char inByte=0;
Servo FB;
Servo LR;

#define LRCenter 80        // Servo angles
#define LRMin 72
#define LRMax 92
#define FBCenter 92
#define FBMin 82
#define FBMax 102

void setup() {                
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  // Put the servos on output pins 10 and 11
  FB.attach(10);
  LR.attach(11);
  
  Serial.begin(9600);
}

void loop() {

  if (!a && !f)                    //Stop
  {
    LR.write(LRCenter);
    FB.write(FBCenter);
  }
  else if (a && b && e && f && !d && !c) // Left
  {
    LR.write(LRMin);
    FB.write(FBCenter);
    delay(pause); 
    //LR.write(LRCenter);
  }
  else if (a && b && e && f && (c | d)) // Back
  {
    LR.write(LRCenter);
    FB.write(FBMax);
    delay(pause);
    //FB.write(FBCenter);
  }
  else if (f && e)                      // Forward
  {
    LR.write(LRCenter);
    FB.write(FBMin);
    delay(pause);
    //FB.write(FBCenter);
  }
  else if (a && b)                      // Right
  {
    LR.write(LRMax);
    FB.write(FBCenter);
    delay(pause);
    //LR.write(LRCenter);
  }
  
  while (Serial.available() == 0); // pause until a byte is received by serial Rx
  inByte = Serial.read();                     
  if (inByte == 'x') {
      while (Serial.available() == 0);
      inByte = Serial.read();
      h = (inByte =='1');
      while (Serial.available() == 0);
      inByte = Serial.read();
      g = (inByte =='1');
      while (Serial.available() == 0);
      inByte = Serial.read();
      f = (inByte =='1');
      while (Serial.available() == 0);
      inByte = Serial.read();
      e = (inByte =='1');
      while (Serial.available() == 0);
      inByte = Serial.read();
      d = (inByte =='1');
      while (Serial.available() == 0);
      inByte = Serial.read();
      c = (inByte =='1');
      while (Serial.available() == 0);
      inByte = Serial.read();
      b = (inByte =='1');
      while (Serial.available() == 0);
      inByte = Serial.read();
      a = (inByte =='1');
  }
}


