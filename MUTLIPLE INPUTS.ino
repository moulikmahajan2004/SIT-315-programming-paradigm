void setup()
{
  //mentioning th pin of motion and RGB
  pinMode(2,INPUT);	//2 PIN FOR THE MOTION SENSOR 1
  pinMode(3,INPUT); //3 PIN FOR THE MOTION SENSOR 2
  //MENTI0NG THE RGB 
  pinMode(7,OUTPUT);  //MENTIONG THE BLUE COLOUR FOR  MOTION IN 1 SENSOR
  pinMode(4,OUTPUT);  //MENTIONG THE BLUE COLOUR FOR  MOTION IN 2 SENSOR
  pinMode(5,OUTPUT);  //RED IS ALWAYS ON TO SHOW NOTHING DETCTECTED
  //USING THE CHANGE INTYERRUPT 
  //THIS WILL HELP IN MANAGING WHEN STATE IS LOW IT IS SET TO HIGH 
  //AND VICE VERSA
  attachInterrupt(digitalPinToInterrupt(2),MOTIONDETECTED1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),MOTIONDETECTED2, CHANGE);
  //giving the baudrate for easy communication
  Serial.begin(9600);
}

void loop()
{
  // MAKING THE LOOP EMPTY TO  IMPLEMENT INTERRUPT AND THIS WILL 
  //HELP IN MANAGING THE LOAD WHEN THE STATE CHANGES THEN IT IS CALLED 
  
}
 
void MOTIONDETECTED1()
{
  if(digitalRead(2)==HIGH)
  {
    digitalWrite(7,HIGH);
    digitalWrite(5,LOW);
    Serial.println("----MOTION IN SENSOR 1  HIGH COLOUR GREEN ----");
  }
  else
  {
    digitalWrite(5,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(4,LOW);
    Serial.println("----NO MOTION RGB IS SET TO RED-------");
  }
}

 void MOTIONDETECTED2()
 {
    if(digitalRead(3)==HIGH)
  {
    
   	digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    Serial.println("----MOTION IN SENSOR 2  HIGH COLOUR BLUE  ----");
  }
  else
  {
    digitalWrite(5,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(4,LOW);
    Serial.println("----NO MOTION RGV IS SET TO RED-------");
  }
 }