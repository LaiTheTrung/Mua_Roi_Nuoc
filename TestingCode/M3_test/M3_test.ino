//// khai bao cac chan
#define M1_D1 5
#define M1_D0 4

#define M2_D1 3 
#define M2_D0 2 

#define M3_D1 6
#define M3_D0 7

#define M4_D1 9
#define M4_D0 8

#define M5_D1 10
#define M5_D0 11

char state = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(M1_D1, OUTPUT);
  pinMode(M1_D0, OUTPUT);
  
  pinMode(M2_D1, OUTPUT);
  pinMode(M2_D0, OUTPUT);
//  
  pinMode(M3_D1, OUTPUT);
  pinMode(M3_D0, OUTPUT);
  
  pinMode(M4_D1, OUTPUT);
  pinMode(M4_D0, OUTPUT);
  
  pinMode(M5_D1, OUTPUT);
  pinMode(M5_D0, OUTPUT);


    // Timer 1
    cli();                                  // tắt ngắt toàn cục
    
    /* Reset Timer/Counter1 */
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;
    
    /* Setup Timer/Counter1 */
    TCCR1B |= (1 << CS11) | (1 << CS10);    // prescale = 64
    TCNT1 = 53035;
    TIMSK1 = (1 << TOIE1);                  // Overflow interrupt enable 
    sei();     

}

void loop() {
  // put your main code here, to run repeatedly:

  if(state == 0){
        digitalWrite(M3_D0,HIGH);
    analogWrite(M3_D1, (255-100));
//
//    analogWrite(M3_D1, 200);
//    digitalWrite(M3_D0, LOW);
    
  }

//  if(state == 1){
//
//    digitalWrite(M3_D0,HIGH);
//    analogWrite(M3_D1, (255-150));
//  }

}

ISR (TIMER1_OVF_vect) 
{
    TCNT1 = 53035;
    count += 1;
    if(count>50){

      state = 1-state; 
      count = 0;
    
    }
}
