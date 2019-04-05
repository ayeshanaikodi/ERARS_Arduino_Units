#include <SoftwareSerial.h>
int xpin = A3 ;
int ypin = A2;
int zpin = A1;  // Use buzzer for alert
int FlamePin = 2;  // This is for input pin
int Flame = HIGH; // HIGH when FLAME Exposed
char str[70];
char *test = "$GPGGA";
char longitude[10];
char latitude[10];
int i, j, k;
int gps;


int temp = 0;
int mems = 0;
int x, y, z;
SoftwareSerial mySerial( 8, 7);

void setup()
{
  Serial.print("GPS Based Vehicle ");
  Serial.print("Tracking System");
  pinMode(FlamePin, INPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
  mySerial.write("AT+CMGF=1\r\n");
  delay(1000);
}

void loop()
{
  if (gps == 1)
  {
    for (i = 18; i < 27; i++)   //extract latitude from string
    {
      latitude[j] = str[i];
      j++;
    }
    for (i = 30; i < 40; i++)   //extract longitude from string
    {
      longitude[k] = str[i];
      k++;
    }
  }
  firesensor();
  memssensor();
  if (temp || mems)
  {
    SendTextMessage();
    Serial.println("Lat(N)");
    Serial.print(latitude);
    Serial.println("Lon(E)");
    Serial.print(longitude);
    delay(100);
    gps = 0;
    i = 0;
    j = 0;
    k = 0;
  }
}

void serialEvent()
{
  while (Serial.available())            //Serial incomming data from GPS
  {
    char inChar = (char)Serial.read();
    str[i] = inChar;                 //store incomming data from GPS to temparary string str[]
    i++;
    if (i < 7)
    {
      if (str[i - 1] != test[i - 1])    //check for right string
      {
        i = 0;
      }
    }
    if (i >= 60)
    {
      gps = 1;
    }
  }
}

void firesensor() {
  Flame = digitalRead(FlamePin);
  if (Flame == LOW)
  {
    Serial.println("HIGH FLAME");

    temp = 1;
  }
  else
  {
    Serial.println("No flame");

    temp = 0;
  }
}

void memssensor()
{
  x = analogRead(xpin);
  y = analogRead(ypin);
  z = analogRead(zpin);
  Serial.print(x);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(y);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(z);
  Serial.print("\t");

  if ( x <= 295 ||  x >= 360)
  {
    Serial.print("Accident detected");
    mems = 1;
  }
  else if (y <= 295 || y >= 360)
  {
    Serial.print("Accident detected");
    mems = 1;
  }
  else if (z >= 295)
  {
    Serial.print(" Accident detected");
    mems = 1;
  }
  else
  {
    Serial.print(" NO Accident");
    mems = 0;
  }
  Serial.print("\n");
  // delay before next reading:
  delay(2000);
}

///SendTextMessage()
///This function is to send a sms
void SendTextMessage()
{
  Serial.print("sending text message\n");
  mySerial.write("AT+CMGS=\"+919550697948\"\r\n");
  delay(100);
  Serial.print("Accident detected\n");
  mySerial.write("Accident detected\n");//the content of the message
  mySerial.write("Latitude(N): ");             //enter latitude in msg
  mySerial.write(latitude);                  //enter latitude value in msg
  mySerial.write("\nLongitude(E): ");            //enter Longitude in Msg
  mySerial.write(longitude);

  mySerial.write(0x1A);//the ASCII code of the ctrl+z is 26
  delay(100);
}
