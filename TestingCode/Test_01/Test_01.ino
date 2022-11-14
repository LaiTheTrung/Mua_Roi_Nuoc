#define leftDoll_a 3  // a means analog
#define leftDoll_b 2  // b is a digital pin
#define encoderLD A1

#define rightDoll_a 5
#define rightDoll_b 4

int state = 0;
int count = 0;

void setup() {

  // put your setup code here, to run once:
  pinMode(leftDoll_a,OUTPUT);
pinMode(leftDoll_b,OUTPUT);

pinMode(rightDoll_a,OUTPUT);
pinMode(rightDoll_b,OUTPUT);

pinMode(encoderLD,INPUT_PULLUP);

}
void stop(){
    digitalWrite(leftDoll_a,0);
  digitalWrite(leftDoll_b,0); 
  digitalWrite(rightDoll_a,0);
  digitalWrite(rightDoll_b,0);
}
void loop() {
  // put your main code here, to run repeatedly:


    analogWrite(leftDoll_a,100);
    digitalWrite(leftDoll_b,0);
    
    analogWrite(rightDoll_a,(255-150));
    digitalWrite(rightDoll_b,1);

    delay(1000);
  
    analogWrite(leftDoll_a,(255-100));
    digitalWrite(leftDoll_b,1);
    
    analogWrite(rightDoll_a,150);
    digitalWrite(rightDoll_b,0);
    delay(1000);

    
.

  
}
