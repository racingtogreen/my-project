/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/72fdc536-58ed-467c-82a3-170dbd1a36ee 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int sensorValue1;
  int sensorValue2;
  int threshDiff;
  int threshDiff_PM;
  int threshold;
  bool panel_Down;
  bool panel_Stop;
  bool panel_Up;
  bool useSensor;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
const int Extend = 6;
const int Retract = 5;

int sensorPin1 = A1;
int sensorPin2 = A2;



int counter = 0;
//int valAverage1 = 0;
//int valAverage2 = 0;
int numAverage = 10;


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here
  //valAverage1 =0;
  //valAverage2 =0;
  if (useSensor) {
    for (counter = 0; counter < numAverage; counter++) {
      sensorValue1 = analogRead(sensorPin1);
      sensorValue2 = analogRead(sensorPin2);
      threshDiff = (sensorValue2 - (sensorValue1 + threshold));
      threshDiff_PM = (sensorValue1 - (sensorValue2 + threshold));

      //valAverage1 = valAverage1 + sensorValue1;
      //valAverage2 = valAverage2 + sensorValue2;
    }

    //valAverage1 = valAverage1/numAverage;
    //valAverage2 = valAverage2/numAverage;

    //Serial.print(valAverage1, DEC);
    //Serial.print(", ");
    //Serial.println(valAverage2, DEC);

    if (sensorValue2 > sensorValue1)
    {
      digitalWrite(Extend, HIGH);
      digitalWrite(Retract, LOW);
      delay(1000);
      digitalWrite(Extend, LOW);
      digitalWrite(Retract, LOW);
      delay(500);

    }

    else if (sensorValue1 > sensorValue2)
    {
      digitalWrite(Retract, HIGH);
      digitalWrite(Extend, LOW);
      delay(1000);
      digitalWrite(Retract, LOW);
      digitalWrite(Extend, LOW);
      delay(500);
    }
  }
  // If useSensor is false, read the button state and turn on/off the relay based on it
  else {
    if(panel_Up == HIGH) {
      digitalWrite(Extend, HIGH);
      digitalWrite(Retract, LOW);
    }
    else if(panel_Down == HIGH) {
      digitalWrite(Retract, HIGH);
      digitalWrite(Extend, LOW);
    }
    else if(panel_Stop == HIGH) {
      digitalWrite(Retract, LOW);
      digitalWrite(Extend, LOW);
      
    }
  }  
      
      
  
  Serial.print("sens_1 ");
  Serial.print(analogRead(sensorPin1));
  Serial.println();
  Serial.print("sens_2 ");
  Serial.print(analogRead(sensorPin2));
  Serial.println();
  Serial.print("Threshold Difference ");
  Serial.print(threshDiff);
  Serial.println();
  delay(1000);
  
}


/*
  Since Threshold is READ_WRITE variable, onThresholdChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onThresholdChange()  {
  // Add your code here to act upon Threshold change
}








/*
  Since PanelUp is READ_WRITE variable, onPanelUpChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPanelUpChange()  {
  // Add your code here to act upon PanelUp change
     
   

}

/*
  Since PanelDown is READ_WRITE variable, onPanelDownChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPanelDownChange()  {
  // Add your code here to act upon PanelDown change
  
}

/*
  Since PanelStop is READ_WRITE variable, onPanelStopChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPanelStopChange()  {
  // Add your code here to act upon PanelStop change
  
}







/*
  Since UseSensor is READ_WRITE variable, onUseSensorChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onUseSensorChange()  {
  // Add your code here to act upon UseSensor change
}
