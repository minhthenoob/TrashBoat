// //Include Libraries
// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// //create an RF24 object
// RF24 radio(9, 8);  // CE, CSN

// //address through which two modules communicate.
// const byte address[6] = "00001";

// void setup()
// {
//   radio.begin();

//   //set the address
//   radio.openWritingPipe(address);

//   //Set module as transmitter
//   radio.stopListening();
// }
// void loop()
// {
//   //Send message to receiver
//   const char text[] = "420";
//   radio.write(&text, sizeof(text));

//   delay(1000);
// }


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>

RF24 radio(9,8);  // CE, CSN
const uint64_t address = 0xf0f0f0f066;

int text[2];
void setup() {
  Wire.begin();
  radio.begin();
  radio.openWritingPipe(address);
  Serial.begin(9600);
}

void loop() {
  text[0] = 100;
  text[1] = 200;
  radio.write(text, sizeof(text));
  Serial.println("sent");
  delay(2000);
}
