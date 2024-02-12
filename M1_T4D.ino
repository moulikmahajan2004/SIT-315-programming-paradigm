//PB4 IS THE PORT NUMBER OF THE PIN 12
const int speaker_pin = PB4; //PIN 12 FOR TIME COUNTER 1
bool speaker_status = false;
bool led_state1 =false;  //LED STATE
bool led_state2 =false; //LED STATE  2
//DECLARING THE MOTION1 AND MOTION2
volatile byte motion1,motion2;
void setup()
{//DECLARING THE NORMAL INTERRUPT
  pinMode(5,INPUT_PULLUP); //SENSOR 1 INPUT
  pinMode(4,INPUT_PULLUP); //SENSOR 2 INPUT
  pinMode(12,OUTPUT); //SPEAKER (DDRB = (1<<speaker_pin))// IT CAN ALSO BE DECLARED IN DDRB WAY
  pinMode(6,OUTPUT); //GRREN LIGHT INDICATING SENSOR1 MOTION
  pinMode(7,OUTPUT); //BLUE INDICATING SENSOR 2 TRIGGERE
  //////////////////////////////////////////////////////////////
  PCICR |= B00000100; //enable PCMSK2 this belongs to group 2 pcint16 to pcint23
  PCMSK2 |= B00110000;//USING THE PIN D4 AND D5
  //PCMSK2 |= B00100000;
  motion1 = digitalRead(5);
  motion2 = digitalRead(4);
  //setting initial state 
  //SEETING UP THE DATADIRECTION REGISTER IS IST OUTPUT OR INUPUT
  //HERE 1 MEANS OUTPUT 
  //HERE 0 MEANS INPUT
  //DATADIRECTION REGISTER INDICATING IT AS AN OUTPUT
 // DDRB = (1<<speaker_pin); //SEETING THE OUTPUT
  //RESET TIMER1 TO 0 VALUE
  TCCR1A =0; 
  TCCR1B =0;
  //SETTING TH COMPARSISION VALUE NEED TO BE TARGATED
  TCNT1 =375;
  //SETTING  THE PRESACLER OF 256 //CS10,11,12ARE USED TO SET
  TCCR1B |=  (1<<CS12);  //initail setting 0
  TIMSK1 = (1<< OCIE1A);  
  //ENABLING GLOBAL INTERRUPT
  sei();
  //SETTING UPT THE BAUDRATE 
  Serial.begin(9600);
  
}

ISR(PCINT2_vect)
{  
  
   if(( motion1 = (PIND & B00100000) ? 1 : 0)=1)
   {
     led_state1 = !led_state1;
     Serial.println("MOTION1 INTERRUPT OCCURED ---> M1");
     digitalWrite(6,led_state1);
   } 
  
  
   if(( motion2 = (PIND & B00010000) ? 1 : 0)=1)
   {
     led_state2 = !led_state2;
     Serial.println("MOTION2 INTERRUPT OCCURED ---> M2");
     digitalWrite(7,led_state2);
   } 

}



void loop()
{
 
}

//DECLARRING THE ISR OR  INPUT SERVICE ROUTINE
//TIMER1_COMPA_vect REFFRING TO MULTIPLE COMPARISON VALUE
ISR(TIMER1_COMPA_vect)
{
  //WHEN TCN1 = 375 TRIGGER LED BLINKS 
  TCNT1 = 375;   // DELAY ABOURT 6SECOND (6000*16)/256 = 375
  //SPEAKER STATUS
  speaker_status = !speaker_status;
  //SPEAKER IS ON
 	if(!speaker_status)
    {
      PORTB |=(1<<speaker_pin); 
      digitalWrite(12,digitalRead(12)^1); //THIS IS MAKING THE LED ON AND OFF
      Serial.println("SPEAKER ON TIMER OCCURED"); //PRINTING THE TIMER OCCURED
    }
}