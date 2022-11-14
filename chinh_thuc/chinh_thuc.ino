
//// khai bao cac chan
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

int count=0;
int pre=1;
int speedDoll=128; // speed for left doll
int speedDollR =140; // speed for right doll
int timeRoundDoll = 100; // time for left doll rotate 1 round


// bool command:

bool clockwise=true; // clock wise
bool counterClockwise=false; // counter clock wise
int timeRoundTurn = 1000;

bool GoOut=true; 
bool GoIn=false;
int timeGoOut=1000;

bool Up = true;
bool Down = false;
unsigned long time;
unsigned long starttime;
unsigned long endtime;
//________________________________________________________________________________________
// cac ham co ban gồm :
void setup() 
{
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

Serial.println("Start");
count=0;

}
void late(int delayTime){ // hàm giống với delay
  time=millis();
  while ( ((unsigned long) (millis() - time) < delayTime)){
    
  }
  Serial.println("break");
}
void stop(){ // stop all motor
  
  digitalWrite(leftDoll_a,0);
  digitalWrite(leftDoll_b,0); 
  digitalWrite(rightDoll_a,0);
  digitalWrite(rightDoll_b,0);
  digitalWrite(roundTurn_a,0);
  digitalWrite(roundTurn_b,0); 
  digitalWrite(inOut_a,0);
  digitalWrite(inOut_b,0);
  digitalWrite(upDown_a,0);
  digitalWrite(upDown_b,0);

  }
//________________________________________________________________________________________
//PHAN SUA SO TOC DO CUA CAC DONG CO
void Run_RoundTurn(){ // DONG CO LAC QUA LAC LAI
     analogWrite(roundTurn_a,(255-100)); 
    digitalWrite(roundTurn_b,HIGH);
}
void UpDown(){ // DONG CO LEN XUONG
       analogWrite(upDown_a,170);
      digitalWrite(upDown_b,1);
}
void InOut(){ // DONG CO RA VAO
 analogWrite(inOut_a,150);
    digitalWrite(inOut_b,HIGH);
}
void DollDance(bool trai){ // DONG CO 2 CON LAN ( rotate in oposite direction
  if (trai==1){ // yellow Rotates clockwiswe, red Rotates counter clockwise
    analogWrite(leftDoll_a,50); // leftDoll is the yellow one
    digitalWrite(leftDoll_b,0);
    
    analogWrite(rightDoll_a,(255-70)); // rightDoll is the red one
    digitalWrite(rightDoll_b,1);
  }
  else { //yellow Rotates counter clockwiswe, red Rotates clockwise
    analogWrite(leftDoll_a,(255-60));
    digitalWrite(leftDoll_b,1);
    
    analogWrite(rightDoll_a,62);
    digitalWrite(rightDoll_b,0);
  }
}
void DiepKhuc1(int time,int lan){ 
  DollDance(1);
  delay(time/2);
  stop();
  delay(600);
  for (int i=0; i<lan; i++){
    DollDance(0);
    delay(time);
    stop();
    delay(500);
    DollDance(1);
    delay(time);
    stop();
    delay(500);
    
  }
  DollDance(0);
  delay(time/2);
  stop();
}
void DiepKhuc2(){ // combine up down and dolldance
  UpDown();
  delay(500);
  stop();
  delay(1000);
  DollDance(0);
  delay(1000);
  stop();
  delay(1000);
  UpDown();
  delay(500);
  stop();
  delay(1000);
  DollDance(1);
  delay(1000);
  stop();
  delay(500);
  DollDance(0);
  delay(2000);
  stop();
  delay(500);
  DollDance(1);
  delay(2000);
  stop();
}
void DiepKhuc3(){ // combine all in one
  UpDown();
  delay(500);
  stop();
  Run_RoundTurn();
  InOut();
  delay(2000);
  stop();
  DollDance(0);
  delay(2000);
  stop();
  
  UpDown();
  delay(500);
  stop();
  InOut();
  Run_RoundTurn();
  DollDance(1);
  delay(2000);
  stop();
  DiepKhuc1(500,2);
  delay(1000);
  DollDance(0);
  delay(2000);
  stop();
  DollDance(1);
  delay(2000);
  stop();
}
void DiepKhuc4(){ // compine dolldance and inout
  for (int i=0; i<2; i++){
    InOut();
    delay(2000);
   DiepKhuc1(350,4);
    stop();
    delay(1000);
    
   DollDance(1);
   delay(1000);
   stop();

   InOut();
   delay(2000);
   DiepKhuc1(350,4);
   stop();
   delay(1000);

    DollDance(1);
   delay(200);
   stop();
   delay(500);
   DiepKhuc1(400,2);
   DollDance(0);
   delay(1200);
   InOut();
   delay(4000);
   stop();
   delay(1000);

  }
}
void DiepKhuc5(){ // combine dolldance and roundturn
  for (int i=0; i<2; i++){
      Run_RoundTurn();
     delay(500);
     stop();
     DollDance(1);
     delay(200);
     stop();
     delay(1000);
     DiepKhuc1(300,2);
     stop();
     delay(500);
     DollDance(i);
     delay(2000);
     
     
   
  }
}
void DiepKhuc6 () {// upgrade Diepkhuc1
   DollDance(0);
   delay(500);
   stop();
   delay(700);
   DiepKhuc1(500,1);
   delay(300);
    
   DollDance(0);
   delay(250);
   stop();
   delay(700);
   DiepKhuc1(500,1);
   delay(300);
   
   DollDance(0);
   delay(500);
   stop();
   delay(500);
   DiepKhuc1(500,1);
   
   DollDance(0);
   delay(1200);
   stop();
   DiepKhuc1(500,2);
  
}

void DiepKhuc7() { // upgrade All in one 
  
}
void loop(){
  DiepKhuc1(500,2);
  stop();
  delay(1000);
   DiepKhuc2();
  delay(1000);
  DiepKhuc6();
  delay(1000);
  DiepKhuc5();
  delay(1000);
  DiepKhuc1(500,2);
  delay(1000);
  DiepKhuc4();
  delay(1000);
  DiepKhuc1(500,2);
  delay(1000);
  DiepKhuc6();
  delay(1000);
  DiepKhuc3();
  delay(1000);
  DiepKhuc1(500,2);
  delay(1000);
  DiepKhuc5();
  delay(1000);
  DiepKhuc3();
  delay(1000);
  DiepKhuc1(500,2);
  delay(1000);
  DiepKhuc2();
  delay(1000);
  DiepKhuc6();
  delay(1000);
  DiepKhuc1(500,2);
  delay(1000);
  DiepKhuc2();
  delay(1000);
  DiepKhuc5();
  delay(1000);
  DiepKhuc2();
  delay(1000);
  DiepKhuc1(500,2);
  delay(1000);
  DiepKhuc6();
  delay(1000);
  DiepKhuc1(500,2);
  delay(1000);
  DiepKhuc2();
  delay(1000);
    DiepKhuc3();
  delay(1000);
  DiepKhuc6();
  delay(1000);
  DiepKhuc5();
  delay(1000);
  DiepKhuc1(500,2);
  delay(1000);
  DiepKhuc4();
  delay(1000);
  DiepKhuc6();
  delay(1000);
   DiepKhuc2();
  delay(1000);
}
