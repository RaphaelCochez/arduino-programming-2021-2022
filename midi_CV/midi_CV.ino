// (*) All in the spirit of open-source and open-hardware 
// Janost 2019 Sweden  
// DIY USB MIDI to CV
// http://blog.dspsynth.eu/cheap-diy-usb-midi-to-cv-interface/
// Copyright 2019 DSP Synthesizers Sweden. 
// 
// Author: Jan Ostman 
// 
// This program is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version. 
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
// GNU General Public License for more details.
  
#include <DigiMIDI.h>
DigiMIDIDevice midi;
void setup() {
  pinMode(1,OUTPUT); //Pitch is output
  pinMode(5, OUTPUT); //Gate is output
  //Setup Timer1 to do PWM DAC for Pitch
  TCCR1 = _BV(PWM1A) | _BV(COM1A1) | _BV(CS10);
  GTCCR = 0;
  OCR1C = 239; //Set CV PWM range to 240
  OCR1A = 0; //Set initial Pitch to C2
  digitalWrite(5,LOW); //Set initial Gate to LOW;
}
void loop() {
  midi.update(); //Check if any MIDI data is received
}
