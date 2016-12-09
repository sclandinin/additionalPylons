
const int pylon =  2;      // the number of the LED pin
byte response = 0;     //reply from voice recognition

void setup() 
{
  Serial.begin(9600);
  pinMode(pylon, OUTPUT);
  
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x37);
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x21);
  delay(1000);
}

void loop() 
{
  while(Serial.available())
  {
    response = Serial.read();

    //"You must construct additional pylons."
    if (response == 0x11) 
    {
      delay(750);
      digitalWrite(pylon, HIGH);
    }

    //"My life for Aiur!"
    if (response == 0x12) 
    {
      delay(500);
      digitalWrite(pylon, LOW);
    }
    
  }
}


