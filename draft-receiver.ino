// Include the nRF24L01 library 
#include <SPI.h> 
#include <nRF24L01.h> 
#include <RF24.h> 
#include <Wire.h>
  
// Create an nRF24L01 object 
RF24 radio(9, 8);
int ena = 5;
int in1 = 6;
int in2 = 7;
  
// Create the payload variable 
const uint64_t address = 0xf0f0f0f066;
int move;
void setup() {
  Serial.begin(9600); 
  Wire.begin();
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.startListening(); 
}

// Program to receive button presses
void loop(){
  // while (radio.available()) {
  //   Serial.println("begin");
  //   delay(1000);
  //   radio.read(move, sizeof(move));
  //     if (move == 1) {
  //         Serial.println(move);
  //         digitalWrite(in1,HIGH);
  //         digitalWrite(in2,LOW);
  //         analogWrite(ena, 255);
  //       delay(10);
  //     } 
  //     else {
  //       Serial.println(move);
  //       digitalWrite(in1,LOW);
  //       digitalWrite(in2,LOW);
  //       delay(10);
  //     }
  //  }

}
