#include <Wire.h> 
#include <Adafruit_MCP4725.h>


Adafruit_MCP4725 dac; 
 
float DAC_ADU_per_v = 4095.0 / 5.0;         //conversion from volts to ADU 
int V_DAC_ADU;                              // the value in ADU to output on the DAC 
 
void setup() { 
  Serial.begin(115200); 
  dac.begin(0x60);           // address is either 0x60, 0x61, 0x62,0x63, 0x64 or 0x65 
  dac.setVoltage(0, false);  //sets the output current to 0 initially 
} 
 
void loop() { 
  V_DAC_ADU = 0 * DAC_ADU_per_v; 
  dac.setVoltage(V_DAC_ADU, false);  //sets the output current to 0 initially 
 
  V_DAC_ADU = 3.0 * DAC_ADU_per_v; 
  dac.setVoltage(V_DAC_ADU, false);  //sets the output current to 0 initially 
} 
