//intializing the pin 
const byte LED_PIN = 13;
const byte METER_PIN = A4;
void setup()
{
  //LED PIN AND THE METERE PIN
  pinMode(LED_PIN, OUTPUT);
  pinMode(METER_PIN, INPUT);
  //SETTING THE BAUDRATE
  Serial.begin(9600);
  //START TIMER FUNCTION
  startTimer();
}
void loop()
{ 
  //TO CHECK THE VALUE FROM THE POT AND CONTINOUSLY MAPPING 
  int potentiometere = analogRead(METER_PIN);
  double map_frequescy = map(potentiometere,0,1023,1,10);
  //in the above we are taking the anlog read value from the 0 to 1023 
  //also taking the heartz frequencey from 1 to 10HZ
  Serial.print("TIMER FREQUENCY IS ->");
  Serial.print(map_frequescy);
  //F_CPU this is used to tell the frequency of the board
  //dividing with 256 is used due to the timer 1
  //mapfrequecy is calculate abve and sub tratced by 1to calaculate exact value
  unsigned long value = F_CPU / 256 / map_frequescy - 1; // Added semicolon at the end
  //by default ocr1a is working with 2hz frequency 
  //byt the mapping value generate new due to which coparison mut also change
  //here the user can confugure the frequency 
  OCR1A = value; 
  //ading the 1scond delay
  delay(1000);
}
void startTimer(){
  noInterrupts();
  //setting the timer counter 1 
  TCCR1A =0;
  TCCR1B =0;
  //SETTING THE COMPARER VALUE 
  OCR1A = 15624; 
  //15624 IS 2HZ AS 16/(256*2)-1
  //This will also make the led blink every 2 second
  // ENABLING CTC MODE
  TCCR1B |= (1 << WGM12);
  //SETTING THE PRESCALER OF 256 
  TCCR1B |= (1 << CS12); 
  TCCR1B &= ~(1 << CS11); 
  TCCR1B &= ~(1 << CS10);  
  //SETTING THE COMPARER 
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}
ISR(TIMER1_COMPA_vect){
   digitalWrite(LED_PIN, digitalRead(LED_PIN) ^ 1);
}
