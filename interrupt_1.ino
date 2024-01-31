
void setup()
{
  //mentioning th pin of motion and led
  pinMode(4, OUTPUT);
  pinMode(3,INPUT);
  //USING THE CHANGE INTYERRUPT 
  //THIS WILL HELP IN MANAGING WHEN STATE IS LOW IT IS SET TO HIGH 
  //AND VICE VERSA
  attachInterrupt(digitalPinToInterrupt(3), DigitalMotion, CHANGE);
  //giving the baudrate for easy communication
  Serial.begin(9600);
}

void loop()
{
  // MAKING THE LOOP EMPTY TO  IMPLEMENT INTERRUPT AND THIS WILL 
  //HELP IN MANAGING THE LOAD WHEN THE STATE CHANGES THEN IT IS CALLED 
  
}
 
 void DigitalMotion()
 {
   if(digitalRead(3)==HIGH)
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