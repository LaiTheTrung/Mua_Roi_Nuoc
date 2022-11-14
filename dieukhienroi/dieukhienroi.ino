int leftDolla=3;
int rightDolla=5;
int leftDollSpeed=2;
int rightDollSpeed=5;
int roundTurna=6;
int lengthena=9;
int roundTurnSpeed=6;
int lengthenSpeed=9;

int leftDollb=2;
int rightDollb= 4;
int roundTurnb=7;
int lengthenb=8;
int count=0;
int pre=1;

int midPos=42;

#define A A1
bool cw=true;
bool ccw=false;
unsigned long time;

void setup()
{
  pinMode(A,INPUT_PULLUP);  
  pinMode(leftDolla,OUTPUT);  
  pinMode(rightDolla,OUTPUT);
  pinMode(leftDollb,OUTPUT);  
  pinMode(rightDollb,OUTPUT);
  pinMode(leftDollSpeed,OUTPUT);  
  pinMode(rightDollSpeed,OUTPUT);
  pinMode(roundTurna,OUTPUT);  
  pinMode(lengthena,OUTPUT);
  pinMode(roundTurnb,OUTPUT);  
  pinMode(lengthenb,OUTPUT);
  pinMode(roundTurnSpeed,OUTPUT);  
  pinMode(lengthenSpeed,OUTPUT);
    time=millis();
    Serial.begin(9600);
    
//takeplace2(70);
}


void loop()
{
  delay(1000);
//  takeplace(midPos);
  
  delay(1000);
//takeplace2(70);
style1();
//style2();
//allLeft(50,255);
//    int readA=digitalRead(A);
//    if (pre!=readA){count++;pre=readA;Serial.println(count);}
//    
////takeplace(midPos);
//axis(ccw,200);

}
//........................................
void late(int tg){
  time=millis();
  while ( ((unsigned long) (millis() - time) < tg)){
  }
  }
//.........................................
void style1(){
  int timeF=1000;
  int speed=50;
  Serial.println("style1");
  allLeft(timeF,speed);
  late(timeF);
  stop();
  
  allRight(timeF,speed);
  late(timeF);
  stop();
  
  allRight(timeF,speed);
  late(timeF);
  stop();
  
  len(cw,speed);
  late(timeF);
  stop();
  
  allOut(timeF,speed);
  late(timeF);
  stop();
  
  allIn(timeF,speed);
  len(ccw,speed);
  late(timeF);
  stop();
  }
//........................................
void style2(){
  Serial.println("style2");
  int timeF=1000;
  int speed=125;
  allRight(timeF,speed);
  late(timeF);
  stop();
  
  len(cw,speed);
  late(timeF);
  stop();
  
  allLeft(timeF,speed);
  late(timeF);
  stop();
  
  allLeft(timeF,speed);
  late(timeF);
  stop();
  
  allRight(timeF,speed);
  len(ccw,speed);
  late(timeF);
  stop();
  
  allLeft(timeF,speed);
  late(timeF);
  stop();

  allRight(timeF,speed);
  late(timeF);
  stop();
  }
//........................................
void allRight(int timeF,int speed){
    leftD(cw,speed);
    rightD(cw,speed);
    Serial.println("phai");
  }
void allLeft(int timeF,int speed){
  leftD(ccw,speed);
  rightD(ccw,speed);
  Serial.println("trai");
}

void allIn(int timeF,int speed){
  leftD(cw,speed);
  rightD(ccw,speed);
  Serial.println("trong");
}

void allOut(int timeF,int speed){
  leftD(ccw,speed);
  rightD(cw,speed);
  Serial.println("ngoai");
}
void clockwise(int a,int b){
  analogWrite(a,180);
  digitalWrite(b,0);
  }
  
void counter_clockwise(int a,int b){
  digitalWrite(a,1);
  analogWrite(a,255-180);
  }
  
void leftD(bool dir, int speed){
  if (dir==cw){
    clockwise(leftDolla,leftDollb);
    analogWrite(leftDollSpeed,speed);
    }
    else{
    counter_clockwise(leftDolla,leftDollb);
    analogWrite(leftDollSpeed,speed);

      }
  }
  
void rightD(bool dir, int speed){
  if (dir==cw){
    clockwise(rightDolla,rightDollb);
    analogWrite(rightDollSpeed,speed);
    }
    else{
    counter_clockwise(rightDolla,rightDollb);
    analogWrite(rightDollSpeed,speed);
      }}
      
void axis(bool dir, int speed){
  if (dir==cw){
    clockwise(roundTurna,roundTurnb);
    analogWrite(roundTurnSpeed,speed);
    }
    else{
    counter_clockwise(roundTurna,roundTurnb);
    analogWrite(roundTurnSpeed,speed);
      }
  }  
void len(bool dir, int speed){
  if (dir==cw){
    clockwise(lengthena,lengthenb);
    analogWrite(lengthenSpeed,speed);
      Serial.println("xuong");
    }
    else{
    counter_clockwise(lengthena,lengthenb);
    analogWrite(lengthenSpeed,speed);
      Serial.println("len");
    }
  }
void takeplace(int pulseNum){
  int count=0;
  axis(cw,200);
  while (abs(count)<100){
    Serial.println("dang chay can");
  int readA=digitalRead(A);
  if (readA==0){count-=1;}else {count+=1;}
  }
  stop();
  axis(ccw,200);
  count=0;
  int readA=digitalRead(A);
  int preA=readA;
  while(count<=round(pulseNum)){
        Serial.println(count);
    readA=digitalRead(A);
    if (preA!=readA){count++;preA=readA;}
    }
      stop();
}
void takeplace2(int pulseNum){
  int count=0;
  axis(ccw,200);
  while (abs(count)<100){
    Serial.println("dang chay can");
  int readA=digitalRead(A);
  if (readA==0){count-=1;}else {count+=1;}
  }
  stop();
  axis(cw,200);
  count=0;
  int readA=digitalRead(A);
  int preA=readA;
  while(count<=round(pulseNum)){
        Serial.println(count);
    readA=digitalRead(A);
    if (preA!=readA){count++;preA=readA;}
    }
      stop();
}
void stop(){
  Serial.println("dung");
  digitalWrite(leftDolla,0);
  digitalWrite(leftDollb,0); 
  digitalWrite(rightDolla,0);
  digitalWrite(rightDollb,0);
  digitalWrite(lengthena,0);
  digitalWrite(lengthenb,0); 
  digitalWrite(roundTurna,0);
  digitalWrite(roundTurnb,0);
  }
