
/*
  Analog Feedback Servo Calibration Demo
  feedback_servo_calib.ino
  Uses S1213 Analog Feedback Servo Motor
  Results displayed on Serial Monitor
 
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/
 
// Include Arduino Servo Library
#include <Servo.h>
 
// Control and feedback pins
int servoPin = 9;
int feedbackPin = A0;
 
// Value from feedback signal
int feedbackValue;
int altitude; 
// Create a servo object
Servo myservo;
 
void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600);
  
  // Attach myservo object to control pin
  myservo.attach(servoPin);
  
  // Home the servo motor
  myservo.write(0);
  
  // Step through servo positions
  // Increment by 5 degrees
  for (int servoPos = 0; servoPos <=155; servoPos = servoPos + 3){
    
    // Position servo motor
    myservo.write(servoPos);
    // Allow time to get there
    delay(2000);
    
    // Read value from feedback signal
    feedbackValue = analogRead(feedbackPin);
    altitude=map(feedbackValue,127,492,8,120);
    // Write value to serial monitor
    Serial.print("Position = ");
    Serial.print(servoPos);
    Serial.print("\t");
    Serial.print(" altitude = ");
    Serial.print(altitude);
    Serial.print("\t");
    Serial.println(feedbackValue);
  //micro analogservo 8moires ->127 , ,90MOIRES  392,120moires ->487
  }
 
  // Move back to home position
  myservo.write(0);
  
  // Print to serial monitor when done
  Serial.println("Finished!");
 
}  
 
void loop()
{ 
  delay(100);
   myservo.write(123);
  
}
