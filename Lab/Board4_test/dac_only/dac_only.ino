// vrm characterizer board 
#include <Wire.h> 
#include <Adafruit_MCP4725.h> 
Adafruit_MCP4725 dac; 
 
float DAC_ADU_per_v = 4095.0 / 5.0;         //conversion from volts to ADU 
int V_DAC_ADU;                              // the value in ADU to output on the DAC 

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        7 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 5 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
void setup() { 
  Serial.begin(115200); 
  dac.begin(0x60);           // address is either 0x60, 0x61, 0x62,0x63, 0x64 or 0x65 
  dac.setVoltage(0, false);  //sets the output current to 0 initially 

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
} 
 
void loop() { 
  V_DAC_ADU = 0 * DAC_ADU_per_v; 
  dac.setVoltage(V_DAC_ADU, false);  //sets the output current to 0 initially 
 
  V_DAC_ADU = 3 * DAC_ADU_per_v; 
  dac.setVoltage(V_DAC_ADU, false);  //sets the output current to 0 initially 
    pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(51, 0, 102));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop


  }
  
  for(int i=NUMPIXELS-1; i>=0; i--) { // For each pixel...

  // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
  // Here we're using a moderately bright green color:
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));

  pixels.show();   // Send the updated pixel colors to the hardware.

  delay(DELAYVAL); // Pause before next pass through loop
  }
} 
