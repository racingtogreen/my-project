// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "7cf0b131-673f-4607-8270-cce86afd5b57";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onThresholdChange();
void onPanelDownChange();
void onPanelStopChange();
void onPanelUpChange();
void onUseSensorChange();

int sensorValue1;
int sensorValue2;
int threshDiff;
int threshDiff_PM;
int threshold;
bool panel_Down;
bool panel_Stop;
bool panel_Up;
bool useSensor;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(sensorValue1, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(sensorValue2, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(threshDiff, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(threshDiff_PM, READ, 10 * SECONDS, NULL);
  ArduinoCloud.addProperty(threshold, READWRITE, ON_CHANGE, onThresholdChange);
  ArduinoCloud.addProperty(panel_Down, READWRITE, ON_CHANGE, onPanelDownChange);
  ArduinoCloud.addProperty(panel_Stop, READWRITE, ON_CHANGE, onPanelStopChange);
  ArduinoCloud.addProperty(panel_Up, READWRITE, ON_CHANGE, onPanelUpChange);
  ArduinoCloud.addProperty(useSensor, READWRITE, ON_CHANGE, onUseSensorChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
