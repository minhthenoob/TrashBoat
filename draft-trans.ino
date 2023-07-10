// Include the nRF24L01 library
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>

// Create an nRF24L01 object
RF24 radio(9, 8);

// Create the payload variable
const uint64_t address = 0xf0f0f0f066;

// Create send button and confirm variables
const int btn_sendId = 10;
int move;
void setup() {
  // Set the radio and buttons
  Wire.begin();
  radio.begin();
  radio.openWritingPipe(address);
  pinMode(btn_sendId, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), send, RISING);
}

void send() {
  radio.write(move, sizeof(move));
  Serial.println("sent");
  Serial.println(move);
}
void loop() {
  Serial.println(digitalRead(btn_sendId));
}