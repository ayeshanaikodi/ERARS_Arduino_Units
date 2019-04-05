#include <VirtualWire.h>

//Assigning controller buttons to Digital Pins
int a = 8;
int b = 9;
int c = 10;
int d = 11;
int e = 12;
//int remotePins[]= {8,9,10,11,12};//array to store pin nos

void setup()
{
  Serial.begin(9600);	  // Debugging only
  Serial.println("setup");
  // Initialise the IO and ISR
  vw_setup(2000);	 // Bits per sec
  vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3


  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

}//close setup

void loop()
{
  char *msg2;

  if (digitalRead(a) == HIGH) //if the first button is pressed
  {
    char *msg2 = "a";//send a to the receiver
    // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2)); //send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone

  }

  if (digitalRead(b) == HIGH) //if the second button is pressed
  {
    char *msg2 = "b";///send b to the receiver
    // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone

  }

  if (digitalRead(c) == HIGH) //if the third button is pressed
  {
    char *msg2 = "c";//send c to the receiver
    // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone

  }

  if (digitalRead(d) == HIGH) //if the fourth button is pressed
  {
    char *msg2 = "d";//send d to the receiver
    // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the message to the receiver
    vw_wait_tx(); // Wait until the whole message is gone

  }
  if (digitalRead(e) == HIGH) //if the fifth button is pressed
  {
    char *msg2 = "e";//send e to the receiver
    // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the message to the receiver
    vw_wait_tx(); // Wait until the whole message is gone

  }

}//close loop