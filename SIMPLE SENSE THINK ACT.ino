// C++ code
//
void setup()
{
  //mentioning th pin of motion and led
  pinMode(4, OUTPUT);
  pinMode(7,INPUT);
  //giving the baudrate for easy communication
  Serial.begin(9600);
}

void loop()
{
  //making the loop high if sensro read motion
  if(digitalRead(7)==HIGH)
  {
    //led reamin high 
    digitalWrite(4,HIGH);
    Serial.println("LED ON");
  }
  else
  {
    //else if there is not motion then led will remain off
    digitalWrite(4,LOW);
    Serial.println("LED OFF");
  }
}