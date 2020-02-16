
#include <Servo.h> // include Servo library 

int allowance = 35;
int PHOTOLT=A0; //ΠΑΝΩ ΑΡΙΣΤΕΡΗ ΦΩΤΟΑΝΤΙΣΤΑΣΗ
int PHOTOLD=A2;
int PHOTORT=A1;
int PHOTORD=A3;


// 180 horizontal MAX
Servo horizontal; // horizontal servo
int servoh = 95;   // 95;     // stand horizontal servo

int servohHigh = 180;
int servohLow = 10;

// 180 degrees MAX
Servo vertical;   // vertical servo 
int servov = 90;    //   90;     // stand vertical servo

int servovHigh = 150;
int servovLow = 25;
int rest=10;
void setup()
{
  Serial.begin(9600);

  horizontal.attach(5); 
  vertical.attach(4);
  horizontal.write(95);
  vertical.write(90);
  delay(3000);
}



void loop ()
{
   int lt = analogRead(PHOTOLT); // top left
  int rt = analogRead(PHOTORT); // top right
  int ld = analogRead(PHOTOLD); // down left
  int rd = analogRead(PHOTORD); // down right
  int averagesumleft=(lt + ld)/2;
  int averagesumright=(rt + rd)/2;
  int averagesumtop=(lt + rt)/2;
  int averagesumdown=(rd + ld)/2;
  int difh=averagesumleft - averagesumright;
  int difv=averagesumtop - averagesumdown;
  
   Serial.print(lt);
  Serial.print(" ");
  Serial.print(rt);
  Serial.print(" ");
  Serial.print(ld);
  Serial.print(" ");
  Serial.println(rd);
  Serial.print(averagesumtop);
  Serial.println(averagesumdown);
if ( difh  > allowance ||  difh < -allowance ) {
       

if ( averagesumleft >averagesumright ) {
  servoh = ++servoh;


if (servoh > servohHigh) 
     { 
      servoh = servohHigh;
     }}

    

else if ( averagesumleft <averagesumright )  {
  servoh = --servoh; 

 if (servoh < servohLow) 
     { 
      servov = servohLow;
     }}
     horizontal.write(servoh);
}


if ( difv > allowance  || difv < -allowance ) {
      
if ( averagesumtop >averagesumdown ) {
  servov = ++servov;

if (servov > servovHigh) 
     { 
      servov = servovHigh;
     }
}   
else if (averagesumtop >averagesumdown) {
  servov = --servov; 

if (servov < servovLow) 
     { 
      servov = servovLow;
     }
}

 vertical.write(servov);
}

delay(rest);  
}
