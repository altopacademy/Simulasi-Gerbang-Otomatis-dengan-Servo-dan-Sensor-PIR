/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/
 
#include <Servo.h>

Servo myservo;

int sensor = 4;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;     
int pos = 0;             // variable to store the sensor status (value)

void setup() {
     // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  myservo.attach(7);
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  Serial.println(val);
  if (val == HIGH) {           // check if the sensor is HIGH

    delay(100); 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
          for(pos = 0; pos < 100; pos += 1)  //fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
      {
        myservo.write(pos); //prosedur penulisan data PWM ke motor servo
        delay(15); //waktu tunda 15 ms                 
      } 
      delay(2000);
      state = HIGH;       // update variable state to HIGH
      }
  } 
  else {
      // digitalWrite(led, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
            for(pos = 90; pos > 0; pos -= 1)  //fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
      {
        myservo.write(pos); //prosedur penulisan data PWM ke motor servo
        delay(15); //waktu tunda 15 ms                 
      } 
    delay(100); 
    }
  }
}
