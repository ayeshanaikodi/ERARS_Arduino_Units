#include <VirtualWire.h>
int r = A0;
int y1 = 3;
int g1 = 4;
int r2 = 5;
int y2 = 6;
int g2 = 7;
int r3 = 8;
int y3 = 9;
int g3 = 10;
int r4 = 11;
int y = A1;
int g4 = 13;
int r1;
int y4;
void setup()
{
  Serial.begin(9600);	// Debugging only
  Serial.println("setup");

  // Initialise the IO and ISR
  vw_setup(2000);	 // Bits per sec
  vw_set_rx_pin(2);    //Rx Data pin to Digital  Pin 2
  vw_rx_start();       // Start the receiver PLL running


  pinMode (r1, OUTPUT);
  pinMode (y1, OUTPUT);
  pinMode (g1, OUTPUT);

  pinMode (r2, OUTPUT);
  pinMode (y2, OUTPUT);
  pinMode (g2, OUTPUT);

  pinMode (r3, OUTPUT);
  pinMode (y3, OUTPUT);
  pinMode (g3, OUTPUT);

  pinMode (r4, OUTPUT);
  pinMode (y4, OUTPUT);
  pinMode (g4, OUTPUT);

  digitalWrite(r1, LOW);
  digitalWrite(y1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(y2, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(r3, LOW);
  digitalWrite(y3, LOW);
  digitalWrite(g3, LOW);
  digitalWrite(r4, LOW);
  digitalWrite(y4, LOW);
  digitalWrite(g4, LOW);





}//close setup

void loop()
{

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  vw_wait_rx();
  traffic();
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {

    int i;

    // Flash a light to show received good message
    // Message with a good checksum received, dump it.
    for (i = 0; i < buflen; i++)
    {


      if (buf[i] == 97) //if button 1 is pressed.... i.e.forward buton
      {
        Serial.println("a");
        digitalWrite(g1, HIGH);
        digitalWrite(r2, HIGH);
        digitalWrite(r3, HIGH);
        digitalWrite(r4, HIGH);

        delay(10000);
      }
      if (buf[i] == 98) //if button 2 is pressed.... i.e.back buton
      {
        laneb();
        Serial.println(" b");
        delay(10000);
      }
      if (buf[i] == 99) //if button 3 is pressed.... i.e.left buton
      {
        lanec();
        Serial.println("c");
        delay(10000) ;
      }

      if (buf[i] == 100) //if button 4 is pressed.... i.e.right buton
      {
        laned();
        Serial.println("d");
        delay(10000);
      }
      if (buf[i] == 101) //if button 4 is pressed.... i.e.right buton
      {
        traffic();
        Serial.println("e");
        delay(10000);
      }
      Serial.println("");
    }
  }

  //End Of Code

}

void traffic()
{
  r1 = analogRead(r);
  y4 = analogRead(y);

  digitalWrite(g1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  delay(9000);
  digitalWrite(g1, LOW);
  digitalWrite(r2, LOW);

  digitalWrite(y1, HIGH);
  digitalWrite(y2, HIGH);
  delay(3000);
  digitalWrite(y1, LOW);
  digitalWrite(y2, LOW);

  digitalWrite(r1, HIGH);
  digitalWrite(g2, HIGH);
  delay(9000);

  digitalWrite(g2, LOW);
  digitalWrite(r3, LOW);


  digitalWrite(y2, HIGH);
  digitalWrite(y3, HIGH);
  delay(3000);

  digitalWrite(y2, LOW);
  digitalWrite(y3, LOW);


  digitalWrite(r2, HIGH);
  digitalWrite(g3, HIGH);
  digitalWrite(r4, HIGH);
  delay(9000);

  digitalWrite(g3, LOW);
  digitalWrite(r4, LOW);
  

  digitalWrite(y3, HIGH);
  digitalWrite(y4, HIGH);
  delay(3000);

  digitalWrite(y3, LOW);
  digitalWrite(y4, LOW);

  digitalWrite(r3, HIGH);
  digitalWrite(g4, HIGH);
  delay(9000);

  digitalWrite(r3, LOW);
  digitalWrite(g4, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(y1, HIGH);
  digitalWrite(y4, HIGH);
  delay(3000);

  digitalWrite(y1, LOW);
  digitalWrite(y4, LOW);
}
void lanea()
{

}
void laneb()
{
  r1 = analogRead(r);
  y4 = analogRead(y);
  digitalWrite(r1, HIGH);
  digitalWrite(y1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(y2, LOW);
  digitalWrite(g2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(y3, LOW);
  digitalWrite(g3, LOW);
  digitalWrite(r4, HIGH);
  digitalWrite(y4, LOW);
  digitalWrite(g4, LOW);
}
void lanec()
{
  r1 = analogRead(r);
  y4 = analogRead(y);
  digitalWrite(r1, HIGH);
  digitalWrite(y1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(y2, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(r3, LOW);
  digitalWrite(y3, LOW);
  digitalWrite(g3, HIGH);
  digitalWrite(r4, HIGH);
  digitalWrite(y4, LOW);
  digitalWrite(g4, LOW);
  Serial.println(" c");
}
void laned()
{
  r1 = analogRead(r);
  y4 = analogRead(y);
  digitalWrite(r1, HIGH);
  digitalWrite(y1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(y2, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(r3, HIGH);
  digitalWrite(y3, LOW);
  digitalWrite(g3, HIGH);
  digitalWrite(r4, LOW);
  digitalWrite(y4, LOW);
  digitalWrite(g4, HIGH);
}