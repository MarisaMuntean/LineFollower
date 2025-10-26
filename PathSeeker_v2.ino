#define leftMotor_B1 7 //left part of car
#define leftMotor_F1 10   //ok
#define rightMotor_F2 9  //right side of car front
#define rightMotor_B2 8 

#define enB 5 
#define enA 6 

#define Left 3
#define Right 2

const int speed = 180;

void Forward();
void TurnLeft();
void TurnRight();
void Stop();

void setup() {

  Serial.begin(9600);
  
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

}

void loop() {
  // put your main code here, to run repeatedly:
  int LeftSensor = digitalRead(Left), 
  RightSensor = digitalRead(Right);

  if(LeftSensor == 0 && RightSensor == 0)
  {
    Forward();
  }
  else if(LeftSensor == 1 && RightSensor == 0)
  {
    TurnLeft();
    rotateMotor(-speed,speed);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, HIGH);
    digitalWrite(Blue, LOW);
    digitalWrite(Yellow2, LOW);
  }
  else if(LeftSensor == 0 && RightSensor == 1)
  {
    TurnRight();
  }
  else 
  {
    Stop();
    rotateMotor(0,0);
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
