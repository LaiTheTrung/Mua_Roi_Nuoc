#define leftDoll_a 3  // a means analog
#define leftDoll_b 2  // b is a digital pin
#define encoderLD A1

#define rightDoll_a 5
#define rightDoll_b 4
#define encoderRD A2

#define roundTurn_a 6
#define roundTurn_b 7

#define inOut_a 9
#define inOut_b 8

#define upDown_a 10
#define upDown_b 11
#define encoderUD A3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(leftDoll_a,OUTPUT);
pinMode(leftDoll_b,OUTPUT);

pinMode(rightDoll_a,OUTPUT);
pinMode(rightDoll_b,OUTPUT);

pinMode(roundTurn_a,OUTPUT);
pinMode(roundTurn_b,OUTPUT);

pinMode(inOut_a,OUTPUT);
pinMode(inOut_b,OUTPUT);

pinMode(upDown_a,OUTPUT);
pinMode(upDown_b,OUTPUT);

pinMode(encoderRD,INPUT_PULLUP);
pinMode(encoderLD,INPUT_PULLUP);
pinMode(encoderUD,INPUT_PULLUP);

}
void stop() // just stop 2 doll
{
  digitalWrite(leftDoll_a,0);
  digitalWrite(leftDoll_b,0); 
  digitalWrite(rightDoll_a,0);
  digitalWrite(rightDoll_b,0);
    digitalWrite(roundTurn_a,0);
  digitalWrite(roundTurn_b,0); 
  digitalWrite(inOut_a,0);
  digitalWrite(inOut_b,0);
}
void loop() {
  // put your main code here, to run repeatedly:
   analogWrite(roundTurn_a,100);
    digitalWrite(roundTurn_b,0);
    
     analogWrite(upDown_a,165);
    digitalWrite(upDown_b,1);

    analogWrite(inOut_a,155);
    digitalWrite(inOut_b,0);


   
}
