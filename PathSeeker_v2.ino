#define leftMotor_B1 7 //left part of car 
#define leftMotor_F1 10   //ok 
#define rightMotor_F2 9  //right side of car front 
#define rightMotor_B2 8  
#define enB 5  
#define enA 6  
#define Left 3 //sensors 
#define Right 2 

const int speed = 180; 

void setup() { 

    Serial.begin(9600);
    TCCR0B = TCCR0B & B11111000 | B00000010;  //a trebuit sa schimb frecventa de la PWM pentru ca la
//la viteza mica motoarele nu se rotesc, iar la viteza prea mare nu pot controla masina si aceasta iese de
//pe linie
    pinMode(leftMotor_F1, OUTPUT);
    pinMode(leftMotor_B1, OUTPUT);
    pinMode(rightMotor_F2, OUTPUT);
    pinMode(rightMotor_B2, OUTPUT);
    pinMode(Left, INPUT);
    pinMode(Right, INPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    analogWrite(enA, 0);
    analogWrite(enB, 0); 
} 

void loop() { 
//citire valori senzori 
  int LeftSensor = digitalRead(Left),  
  RightSensor = digitalRead(Right); 

  if(LeftSensor == 0 && RightSensor == 0) 
  { 
   //inainte 
      rotateMotor(speed,speed);  
  } 
  else if(LeftSensor == 1 && RightSensor == 0) 
  {  
    rotateMotor(-speed,speed);//rotire cu spatele la motorul din dreapta      
  } 
  else if(LeftSensor == 0 && RightSensor == 1) 
  { 
    //dreapta 
      rotateMotor(speed,-speed); //rotire cu spatele la motorul din stanga 
  } 
  else  
  { 
    rotateMotor(0,0);      
  } 
} 
 
void rotateMotor(int rightMotorSpeed,int leftMotorSpeed ) 
{ 
    if (rightMotorSpeed <0) 
    { 
       
      digitalWrite(rightMotor_F2,LOW); 
      digitalWrite(rightMotor_B2,HIGH); 
 
    } 
    else  if (rightMotorSpeed >0) 
    { 
       
      digitalWrite(rightMotor_F2,HIGH); 
      digitalWrite(rightMotor_B2,LOW); 
 
    } 
    else{ 
      digitalWrite(rightMotor_F2,LOW); 
      digitalWrite(rightMotor_B2,LOW); 
 
    } 
 
    if (leftMotorSpeed <0) 
    { digitalWrite(leftMotor_F1,LOW); 
      digitalWrite(leftMotor_B1,HIGH); 
 
    } 
    else   if (leftMotorSpeed >0) 
    { 
       
      digitalWrite(leftMotor_F1,HIGH); 
      digitalWrite(leftMotor_B1,LOW); 
 
    } 
    else{ 
      digitalWrite(leftMotor_F1,LOW); 
      digitalWrite(leftMotor_B1,LOW); 
 
    } 
 
  analogWrite(enB, abs(rightMotorSpeed));  
  analogWrite(enA, abs(leftMotorSpeed));  
}
/
