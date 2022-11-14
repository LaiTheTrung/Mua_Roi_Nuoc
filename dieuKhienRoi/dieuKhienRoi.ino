
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

//===========================================================================//

int count=0;
int pre=1;

//______________________________________________________________________
// khai bao cac gia tri de thay doi cho phù hợp với hệ cơ khí


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

void late(int delayTime){ // hàm giống với delay
  time=millis();
  while ( ((unsigned long) (millis() - time) < delayTime)){
    
  }
  Serial.println("break");
}




void lateCountEncoder(int countL, int countR, unsigned long delayTime) // count the encoder during delayTime
{
  time=millis();
 
  int stopRotate = 0;
  int  readAL=digitalRead(encoderLD);
  int  readAR=digitalRead(encoderRD);
  while ( ((unsigned long) (millis() - time) < delayTime)){
     if (readAL==1){
        readAL=digitalRead(encoderLD);
        if (readAL==0) countL++;
        }
      else if (readAL==0){
        readAL=digitalRead(encoderLD);
        if (readAL==1) countL++;
        }
      if (readAR==1){
        readAL=digitalRead(encoderRD);
        if (readAR==0) countR++;
        }
      else if (readAR==0){
        readAR=digitalRead(encoderLD);
        if (readAR==1) countR++;
        }
    }
   
}





int CommandWhileWait(int pin_a, int pin_b, bool dir ,int speedRate, int pinA,int changeRange, unsigned long delayTime) // not use
{
  int count =0;
  time=millis();
  if (dir == 1){ cwRotate(pin_a,pin_b,speedRate);}
  else {ccwRotate(pin_a,pin_b,speedRate);}
  
  int readA= digitalRead(pinA);
  while ( ((unsigned long) (millis() - time) < delayTime)){
    if (readA==1){
      readA= digitalRead(pinA);
      if (readA==0) count++;
    }
    else if (readA==0){
      readA= digitalRead(pinA);
      if (readA==1) count++;
    }
    if (count>=changeRange){
      if (dir == 1){ ccwRotate(pin_a,pin_b,speedRate);}
      else {cwRotate(pin_a,pin_b,speedRate);}
      count =0;
    }
    return count;
   }
}





int ReadEn(int pinA) // not use
{
  int output=0;
  for (int i; i<=30; i++)
  {
    int input=digitalRead(pinA);
    if (input ==1) output++;
    
  }
  if (output>=20) return 1;

  else return 0;
}
int CountingEncoder(int pinA) // not use
{
  Serial.println("Counting");

    int  readA=digitalRead(pinA);
   
    if (readA==1){
       while (readA==1)
      {
//        Serial.print("dang doc: ");
//        Serial.println(readA);
        readA=digitalRead(pinA);
   
      }
    }
    else if (readA==0){
       while (readA==0)
        {
//        Serial.print("dang doc: ");
//        Serial.println(readA);
        readA=digitalRead(pinA);
      
        }
      }
  return 1;
    
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
//  holdUpDown();
  }




void stopAllDoll() // just stop 2 doll
{
  digitalWrite(leftDoll_a,0);
  digitalWrite(leftDoll_b,0); 
  digitalWrite(rightDoll_a,0);
  digitalWrite(rightDoll_b,0);
}

void holdUpDown() // not use
{
  cwRotate(upDown_a,upDown_b,50);
}




void cwRotate(int a,int b,int speedRotate){ // clockwise rotation
  analogWrite(a,speedRotate);
  digitalWrite(b,0);
  
  }

  
void ccwRotate(int a,int b,int speedRotate){ // counter clockwise
  analogWrite(a,255-speedRotate);
  digitalWrite(b,1);
  }


void BothDollRotate( bool dirL,bool dirR ,int speedRotate,int angleL,int angleR) // rotate two doll, the parameters with L or R end means( L: left , R:right)
{
    if (dirL == 1){ 
      Serial.print("LD running cw");
//      cwRotate(leftDoll_a,leftDoll_b,speedRotate);
      }
    else if (dirL==0){
      Serial.print("LD running ccw");
//      ccwRotate(leftDoll_a,leftDoll_b,(speedRotate))  ;   
    }
     if (dirR == 1){ 
      Serial.print("RD running cq");
//      cwRotate(rightDoll_a,rightDoll_b,speedRotate+20);
      }
    else if (dirR==0){
      Serial.print("RD running ccw");
//      ccwRotate(rightDoll_a,rightDoll_b,(speedRotate+20));
    }
    int countL = 0;

    Serial.println("Rotating");

    while (true){
    Serial.println("true");
      if (digitalRead(encoderLD)==LOW){
         countL++;
        }


      Serial.print("countL: ");
      Serial.println(countL);
      if (countL>=angleL) // left doll stop
      {
        Serial.print("stopL");
        cwRotate(leftDoll_a,leftDoll_b,0);
        break;
      }
    }    
  
  stopAllDoll();
}

void axisRound(bool dir,int speedRotate) // rotate the center axis of 2 doll
{
  Serial.println("Rotating");
  if (dir == 1) {cwRotate(roundTurn_a,roundTurn_b, speedRotate);}
  else {ccwRotate(roundTurn_a,roundTurn_b, speedRotate);}
  
 
}



void takeplaceInOut(bool GoOut,int speedRotate) // the doll go in or out
{
  Serial.println("Moving");
  if (GoOut == 1) {cwRotate(inOut_a,inOut_b, speedRotate);}
  else {ccwRotate(inOut_a,inOut_b, speedRotate);}
  
}

void GoUpDown(bool Up,int speedRotate) // the doll go up or down
{
  Serial.println("Moving");
  if (Up == 1) {cwRotate(inOut_a,inOut_b, speedRotate);}
  else {ccwRotate(inOut_a,inOut_b, speedRotate);}
  
}

//______________________________________________________________________________
// BẮT ĐẦU VỚI CÁC ĐIỆP KHÚC 
void DiepKhuc0(){ // lân bắt đầu chạy ra 
  int count1=0; // biến là số encoderL đọc đc
  int count2=0;// biến là số encoderR đọc đc
  int countL =0; // góc lệch của lân Left so với vị trí ban đầu 
  int countR =0; //góc lệch của lân Right so với vị trí ban đầu 
  takeplaceInOut(GoOut,80);
  ccwRotate(leftDoll_a,leftDoll_b,speedDoll); 
  cwRotate(rightDoll_a,rightDoll_b,speedDollR);   
  lateCountEncoder(count1, count2, timeRoundDoll/4);
  countL-=count1; // xoay ngược chiều là dấu -
  countR+=count2; // xaoy thuận là dấu cộng
  count1=0;
  count2=0;
  stopAllDoll();
  
  late(100);
  // ddiepj khúc lặp lại n lần
  for (int i=0; i<=3; i+=1)
  {
 
    cwRotate(leftDoll_a,leftDoll_b,speedDoll);
    ccwRotate(rightDoll_a,rightDoll_b,speedDollR);   
     lateCountEncoder(count1, count2, timeRoundDoll/4);
    countL+=count1;
    countR-=count2;
    count1=0;
    count2=0;
    stopAllDoll();
    
    late(100);
    
    ccwRotate(leftDoll_a,leftDoll_b,speedDoll);
    cwRotate(rightDoll_a,rightDoll_b,speedDollR);   
    lateCountEncoder(count1, count2, timeRoundDoll/4);
    countL-=count1;
    countR+=count2;
    count1=0;
    count2=0;
    stopAllDoll();
  
    late(100);
  }
  stop();
  delay(500);
  // cehck xem nên xoay lân hướng nào
  int dirR;
  int dirL;
  int angleL;
  int angleR;
  if (countL>=0){
    dirL = counterClockwise;
    angleL =countL;
  }
  else if(countL<0){
    dirL = clockwise;
     angleL= -countL;
  }
   if (countR>=0){
    dirR = counterClockwise;
    angleR =countL;
  }
  else if (countR<0){
    dirR = clockwise;
     angleR= -countL;
  }
  // câu lệnh xoay lân theo góc
  BothDollRotate( dirL ,dirR ,90 ,angleL,angleR);
  stop();
  }





//
void DiepKhuc1(int lan) // lân lắc đầu với số lần = lan
{
  time = millis();
  int speedRotate = 100;
  BothDollRotate( counterClockwise, clockwise ,speedRotate,45, 45);
  delay(50);
  
  for (int i=0; i<=lan; i+=1)
  {
 
     BothDollRotate( clockwise, counterClockwise , speedRotate, 90, 90);
     stop();
     delay(100);
     BothDollRotate( counterClockwise, clockwise ,speedRotate, 90, 90);
     stop();
     delay(100);
  }
  BothDollRotate( clockwise, counterClockwise ,speedRotate,45, 45);  
  
  stopAllDoll();
  delay(50);
}






void DiepKhuc2() // đầu lân xoay 1 cách nghệ thuật
{
  int speedRotate = 100;
  
  BothDollRotate( counterClockwise, clockwise ,speedRotate, 90, 90);   

  stopAllDoll();
 
  delay(1000);
  
  BothDollRotate( counterClockwise, clockwise ,speedRotate, 90, 90); 
  stopAllDoll();
  delay(50);
  
  BothDollRotate( clockwise, counterClockwise ,speedRotate, 180, 180); 
  stopAllDoll();

  delay(500);
  BothDollRotate( counterClockwise, clockwise ,speedRotate, 360 , 360); 
  late(timeRoundDoll);
  stopAllDoll();
  
  delay(300);

  BothDollRotate( counterClockwise, clockwise ,speedRotate, 360, 360); 
  stopAllDoll();

  BothDollRotate( clockwise, clockwise ,speedRotate, 720, 720); 
  stopAllDoll();
  delay(50);
}



void DiepKhuc3() // vừa xoay đầu, vừa di chuyển // no use
{
  int speedRotate = 100;
  
  BothDollRotate( counterClockwise, clockwise ,speedRotate, 90, 90);   

  stopAllDoll();
  
  delay(1000);
  axisRound(clockwise,100);
  late(1000);
  stop();
  delay(1500);
  axisRound(counterClockwise,100);
  late(1000);
  stop();
  axisRound(clockwise,100);
  late(1000);
  stop();
  
  BothDollRotate( counterClockwise, clockwise ,speedRotate, 180, 180); 
  stopAllDoll();
  delay(50);
  
  BothDollRotate( clockwise, counterClockwise ,speedRotate, 180, 180); 
  stopAllDoll();

  delay(500);
  BothDollRotate( counterClockwise, clockwise ,(speedRotate+50), 360 , 360); 
  late(timeRoundDoll);
  stopAllDoll();
  
  delay(300);

  BothDollRotate( counterClockwise, clockwise ,(speedRotate+50), 360, 360); 
  stopAllDoll();
  
  BothDollRotate( clockwise, clockwise ,speedRotate, 720, 720); 
  stop();
  delay(50);
  
}



//void DiepKhuc5()// no use
//{
//    int count =0;
//  takeplaceInOut(GoIn,100);
//  ccwRotate(leftDoll_a,leftDoll_b,speedDoll);
//  cwRotate(rightDoll_a,rightDoll_b,speedDollR);   
//  lateCountEncoder(count,encoderIO,timeRoundDoll/8);
//  stopAllDoll();
//  
//  late(100);
//  
//  for (int i=0; i<=2; i+=1)
//  {
// 
//    ccwRotate(leftDoll_a,leftDoll_b,speedDoll);
//    cwRotate(rightDoll_a,rightDoll_b,speedDollR);   
//    lateCountEncoder(count,encoderIO,timeRoundDoll/4);
//    stopAllDoll();
//    late(100);
//    ccwRotate(leftDoll_a,leftDoll_b,speedDoll);
//    cwRotate(rightDoll_a,rightDoll_b,speedDollR);   
//    lateCountEncoder(count,encoderIO,timeRoundDoll/4);
//    stopAllDoll();
//    late(100);
//  }
//  
//  ccwRotate(leftDoll_a,leftDoll_b,speedDoll);
//  cwRotate(rightDoll_a,rightDoll_b,speedDollR);   
//  late(timeRoundDoll/8);
//  stop();
//  takeplaceInOut(GoOut,150);
//   while (count<=0)
// {
//  axisRound(clockwise,250);
//  count-=CountingEncoder(encoderIO);
// }
//  stop();
//  } 

//-------------------------------------------------------------------------------

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

pinMode(encoderRD,INPUT_PULLUP);
pinMode(encoderLD,INPUT_PULLUP);
pinMode(encoderUD,INPUT_PULLUP);
time = millis();
Serial.println("Start");
count=0;

}
int state = 0;
//--------------------------------------------------------------------------------
void loop() 
{
 
while(state==0){
  Serial.println("Start");
  BothDollRotate( clockwise, clockwise ,60,20, 20);
  stop();
  delay(1000);
  BothDollRotate( counterClockwise, counterClockwise ,60,20,20);
  stop();
  delay(1000);
  state=1;
}

}
