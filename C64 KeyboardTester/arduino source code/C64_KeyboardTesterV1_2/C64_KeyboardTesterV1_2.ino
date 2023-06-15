// C64 Keyboard Tester V1.2 by Bjoern Buettner
// Arduino Sketch
// MCU = ATTiny85 @ 1MHz
// this small program measure the resistance of the C64 keyboard
// and turn by a resistance under 800 OHm the red led on
// so its possible to see if the key makes some trouble

const float key_R_tresh = 800.0; // 800 Ohm key treshhold
const float R1 = 1000.0; // 1kOhm R1 resistor
const float Vin = 5.0; // 5V power supply

// under 1000 Ohm the C64 see it as a keypress
 // if it under key treshhold turn on the red led

const int raw_tresh = ((Vin / ( key_R_tresh / R1 + 1)) * 1024.0) / Vin; // calculate AD treshhold value

int analogPin = A1; //Analog Input for measure the resistance
int LED_RD = 0 ;// Red LED Key pressed
int LED_GR = 1 ;// Run PRG LED
int raw = 0;

// setup outputs
void setup(){
 pinMode(LED_RD, OUTPUT);
 pinMode(LED_GR, OUTPUT);
 digitalWrite(LED_GR, LOW); // LED GR on
}

// the loop function runs over and over again forever
void loop(){
 raw = analogRead(analogPin);   // reading analog voltage 
 
 if (raw > raw_tresh) {
   digitalWrite(LED_RD, LOW); // LED RD on
  }
   else 
  {
   digitalWrite(LED_RD, HIGH); // LED RD off
  }
 
 delay(25); // short delay
}
