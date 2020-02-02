//n attempt to calculate the yaw angle right from servo write
#include <Servo.h> // include Servo library 
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
float ANGLEX;
float ANGLEY;
float ANGLEZ;

float SETANGLEX;
float SETANGLEY;
float SETANGLEZ;
// 180 horizontal MAX
Servo horizontal; // horizontal servo
int servoh = 95;   // 95;     // stand horizontal servo

int servohLimitHigh = 180;
int servohLimitLow = 1;

// 180 degrees MAX
Servo vertical;   // vertical servo 
int servov = 100;    //   110;     // stand vertical servo

int servovLimitHigh = 155;
int servovLimitLow = 25;

float yaw;
// LDR pin connections
//  name  = analogpin;
int ldrlt =A0; //LDR top left - BOTTOM LEFT    <--- BDG
int ldrrt =A1; //LDR top right - BOTTOM RIGHT 
int ldrld =A2; //LDR down left - TOP LEFT
int ldrrd =A3; //ldr down right - TOP RIGHT
void SET(){

SETANGLEX=mpu6050.getAngleX();
SETANGLEY=mpu6050.getAngleY(); 
 SETANGLEZ=mpu6050.getAngleZ();
}
void setup()
{
  Serial.begin(9600);
   Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
   mpu6050.update();
 
 SET();
// servo connections
// name.attacht(pin);
  horizontal.attach(5); 
  vertical.attach(6);
  horizontal.write(95);
  vertical.write(100);
   horizontal.write(servoh);
  delay(3000);
}

void loop() 
{
  mpu6050.update();mpu6050.update();
  ANGLEX=((mpu6050.getAngleX()-SETANGLEX));
ANGLEY=((mpu6050.getAngleY()-SETANGLEY));
ANGLEZ=((mpu6050.getAngleZ()-SETANGLEZ));

  
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  
  // int dtime = analogRead(4)/20; // read potentiometers  
  // int tol = analogRead(5)/4;
  int dtime = 6;
  int tol = 35;
  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt
  
  
 //  Serial.print(lt);
 // Serial.print(" ");
 // Serial.print(rt);
 //Serial.print(" ");
 // Serial.print(ld);
 // Serial.print(" ");
 // Serial.println(rd);
 yaw=map(servoh,1,180,-70,71);

  Serial.print("angleX : ");
  Serial.print(yaw);
 // Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(ANGLEY);
  Serial.print("\tangleZ : ");
  Serial.println(ANGLEZ);
 // Serial.print("   ");
 // Serial.print(avt);
 // Serial.print("   ");
 // Serial.print(avd);
 // Serial.println(" ");
 // Serial.print(avt);
 // Serial.print("   ");
  //Serial.print(avd);
  //Serial.println(" ");
  
    
  if (-1*tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical angle
  {
  if (avt > avd)
  {
    servov = ++servov;
     if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
  }
  else if (avt < avd)
  {
    servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  }
  vertical.write(servov);
 // horizontal.write(servoh);
  }
  
  if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
  {
  if (avr > avl)
  {
    servoh = --servoh;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
  }
  else if (avr < avl)
  {
    servoh = ++servoh;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }
  else if (avl = avr)
  {
    // nothing
  }
  horizontal.write(servoh);
  }
   delay(dtime);

}
