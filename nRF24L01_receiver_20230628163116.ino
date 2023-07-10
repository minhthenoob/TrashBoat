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
//   while (!Serial);
//     Serial.begin(9600);

//   radio.begin();

//   //set the address
//   radio.openReadingPipe(0, address);

//   //Set module as receiver
//   radio.startListening();
// }

// void loop()
// {
//   //Read the data if available in buffer
//   if (radio.available())
//   {
//     char text[32] = {0};
//     radio.read(&text, sizeof(text));
//     Serial.println(text);
//   }
//   delay(1000);
// }


//Receiver Code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>

RF24 radio(9,8);  // CE, CSN
const uint64_t address = 0xf0f0f0f066;

int text[2];
void setup() {
  Serial.begin(9600);
  Wire.begin();
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop() {
  Serial.println("begin");
  if (radio.available()) {
    radio.read(text, sizeof(text));
    Serial.println(text[1]);
    Serial.println(text[0]);
    Serial.println("end");
  }
  delay(1000);
}
