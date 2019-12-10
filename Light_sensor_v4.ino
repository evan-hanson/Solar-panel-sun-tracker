#include<Servo.h>  //prior to setup, read servo library with changing servo speed
Servo John; //define your servo prior to setup
int LDR1 = A0;   //rename ports to LED1 and LDR1
int LED1 = 13;
int LDR2 = A1;   //rename ports to LED2 and LDR2
int LED2 = 12;
                            //average filter pre-setup
const int numReadings = 100;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 100;
void setup() 
{
  John.attach(10, 1, 255);  //pin 10 sends out signal to move servo
  Serial.begin(9600);   //Record vlaues in the serial table
  pinMode(LDR1, INPUT);   //See LDR1 as an imput  
  pinMode(LED1, OUTPUT); // See LED1 as an out put

  pinMode(LDR2, INPUT);   //See LDR2 as an imput  
  pinMode(LED2, OUTPUT);    //See LED2 as an output

  for(int thisReading = 0; thisReading < numReadings; thisReading++){     //average filter setup
    readings[thisReading] = 100;
   //Serial.println(thisReading);
   
   delay(2);
   total= total+(readings[thisReading]);
  
  }
  
//  
//  for(int thisReading = 0; thisReading < numReadings; thisReading++){     //average filter setup
//   readings[thisReading] =100;
//   total = readings thisReading
//  } 
// tak
}


void loop() 
{
    // recieving the signal from the light sensors
    int LDR1Value = analogRead(LDR1);  //recorded LDR1 vlaue is labled LDR1Value
    
    delay(0);
    if (LDR1Value <=600)     //If the light level of LDR1 is <600 then the LED1 will turn on,
    {
    digitalWrite(13, HIGH);
    }
    else                      //else the LED1 will be off
    {
      digitalWrite(13, LOW);
    }
    
    int LDR2Value = analogRead(LDR2);
    
    delay(0);
     if (LDR2Value <=600)     //If the light level of LDR1 is <600 then the LED2 will turn on,
    {
    digitalWrite(12, HIGH);
    }
    else                      //else the LED2 will be off
    {
      digitalWrite(12, LOW); 
    }
    // moving the servo
    
     int LDRdif;
     LDRdif = ((LDR2Value)-(LDR1Value));   //trying to get the difference of LDR1Value and LDR2Value
                   //use LDRdif to move servo if a difference is too high
    float angle = map(LDRdif,-100,100,40,140);
     
    // average filter
    total = total - readings[readIndex];
    readings[readIndex] = angle;           //difference from online code to apply to this senario
    total = total + readings[readIndex];
    readIndex = readIndex +1;

    if(readIndex >= numReadings) {
      readIndex = 0;
    }

    average = total / numReadings;
    //Serial.println(average);
    delay(0);
         
    
    John.write(average);
    Serial.println(average);
    delay(20);
   
     
 
}
