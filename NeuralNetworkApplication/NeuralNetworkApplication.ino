//C Neural Network Application
//8-Bit Arduino IR Scanner / ANN Classifier
//By Kenneth Vorseth, 4/8/18
#include "NeuralNetwork.h"
#include <Servo.h>
#define servoPin 3
#define sharpPin A0
#define avgNum 100

Servo scanServo;
void setup() 
{
  Serial.begin(9600);
  scanServo.attach(servoPin);
}

void loop() 
{
  //Perform an Entire Sweep Scan (Right -> Left)
  int pt = 0;
  for (int deg = 55; deg < 75; deg += 1)
  {
    //Move Servo to Degree Offset and Wait
    scanServo.write(deg);
    delay(500);
    //Average Samples to Get Good Distance Reading
    float avgTotal = 0;
    for (int a = 0; a < avgNum; a++)
    {
      //Retrieve Reading, Convert to 3.3V Data
      float scanValue = analogRead(sharpPin) * (3.3 / 1023);
      avgTotal += scanValue;
    }
    //Compute Final Average
    float average = avgTotal / avgNum;
    //Filter Out Out-Of-Range Results (Set to Zero)
    average = (average <= 0.8f) ? 0.0f : average;
    //Display Results to Serial Monitor
    Serial.print("Point: "); Serial.print(pt); Serial.print(" | Val:"); Serial.println(average);
    //Increment Pt Counter
    pt++;
  }

  //NEURAL NETWORK TO BE CONNECTED/ADDED HERE...

  //Reset Servo
  scanServo.write(65);
  delay(1000);
}
