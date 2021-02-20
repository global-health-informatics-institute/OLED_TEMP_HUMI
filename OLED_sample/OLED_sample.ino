// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit Graphics & OLED libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
// Include DHT Temp Humid Library
#include "DHT.h"   
 
// Reset pin not used but needed for library
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
 
// Define object DHT
#define DHTTYPE DHT11
#define DHTPIN 2           //Pin number of the signal
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  // Start Wire library for I2C
  Wire.begin();
  // initialize OLED with I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //Start DHT Sensor
    dht.begin();
}

void displayTempHumid(){
  // Delay to allow sensor to stabalize
  delay(2000);
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humi = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temp = dht.readTemperature();
  
  // Clear the display
  display.clearDisplay();
  //Set the color - always use white despite actual display color
  display.setTextColor(WHITE);
  //Set the font size
  display.setTextSize(1);
  
  // Check if any reads failed and exit early (to try again).
  if(isnan(humi) || isnan(temp)){
   display.setCursor(0,10); 
   display.print("DHT sensor Failure");
   return;
  }
  //Set the cursor coordinates
  display.setCursor(0,0);
  display.print("Mtheto's Bedroom");
  display.setCursor(0,10); 
  display.print("Humidity:    "); 
  display.print(humi);
  display.print(" %");
  display.setCursor(0,20);
  display.print("Temperature: "); 
  display.print(temp);
  display.print(" C");
}
void loop() {
  displayTempHumid();
  display.display();
}
