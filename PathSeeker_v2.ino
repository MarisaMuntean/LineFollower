#define leftMotor_B1 7 //left part of car
#define leftMotor_F1 10   //ok
#define rightMotor_F2 9  //right side of car front
#define rightMotor_B2 8 

#define enB 5 
#define enA 6 

#define Left 3
#define Right 2

#define Yellow 11
#define Green 12
#define Blue 13
#define Yellow2 4
const int speed = 180;

void Forward();
void TurnLeft();
void TurnRight();
void Stop();

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  TCCR0B = TCCR0B & B11111000 | B00000010;
  
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

  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Yellow2, OUTPUT);

  //delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int LeftSensor = digitalRead(Left), 
  RightSensor = digitalRead(Right);


 /* Serial.print("Left IR sensor:");
  Serial.println(LeftSensor);
  Serial.print("Right IR sensor: ");
  Serial.println(RightSensor);
*/

  if(LeftSensor == 0 && RightSensor == 0)
  {
    //Forward();
    rotateMotor(speed,speed);
    digitalWrite(Yellow, HIGH);
    digitalWrite(Green, LOW);
    digitalWrite(Blue, LOW);
    digitalWrite(Yellow2, LOW);
  }
  else if(LeftSensor == 1 && RightSensor == 0)
  {
    //TurnLeft();
    rotateMotor(-speed,speed);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, HIGH);
    digitalWrite(Blue, LOW);
    digitalWrite(Yellow2, LOW);
  }
  else if(LeftSensor == 0 && RightSensor == 1)
  {
    //TurnRight();
    rotateMotor(speed,-speed);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
    digitalWrite(Blue, HIGH);
    digitalWrite(Yellow2, LOW);
  }
  else  //(LeftSensor == 1 && RightSensor == 1)
  {
    //Stop();
    rotateMotor(0,0);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
    digitalWrite(Blue, LOW);
    digitalWrite(Yellow2, HIGH);
  }
}

void Forward()
{
  
  digitalWrite(leftMotor_F1,HIGH);
  digitalWrite(leftMotor_B1,LOW);
  digitalWrite(rightMotor_F2,HIGH);
  digitalWrite(rightMotor_B2,LOW);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  delay(100);

  // digitalWrite(leftMotor_F1,HIGH);
  // digitalWrite(leftMotor_B1,LOW);
  // digitalWrite(rightMotor_F2,HIGH);
  // digitalWrite(rightMotor_B2,LOW);
}
void TurnLeft()
{
  
  digitalWrite(leftMotor_F1,HIGH);
  digitalWrite(leftMotor_B1,LOW);
  digitalWrite(rightMotor_F2,LOW);
  digitalWrite(rightMotor_B2,HIGH);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  delay(200);
  
}
void TurnRight()
{
  
  digitalWrite(leftMotor_F1,LOW);
  digitalWrite(leftMotor_B1,HIGH);
  digitalWrite(rightMotor_F2,HIGH);
  digitalWrite(rightMotor_B2,LOW);
  analogWrite(enA, speed);
  analogWrite(enB,speed);
  delay(200);
  
}
void Stop()
{
  
  digitalWrite(leftMotor_F1,LOW);
  digitalWrite(leftMotor_B1,LOW);
  digitalWrite(rightMotor_F2,LOW);
  digitalWrite(rightMotor_B2,LOW);
  
  
  analogWrite(enA, 0);
  analogWrite(enB, 0);

  delay(400);
}

void rotateMotor(int rightMotorSpeed,int leftMotorSpeed )
{
    if (rightMotorSpeed <0)
    {
      
      digitalWrite(rightMotor_F2,LOW);
      digitalWrite(rightMotor_B2,HIGH);

    }
    else   if (rightMotorSpeed >0)
    {
      
      digitalWrite(rightMotor_F2,HIGH);
      digitalWrite(rightMotor_B2,LOW);

    }
    else{
      digitalWrite(rightMotor_F2,LOW);
      digitalWrite(rightMotor_B2,LOW);

    }


    if (leftMotorSpeed <0)
    {
      
      digitalWrite(leftMotor_F1,LOW);
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
