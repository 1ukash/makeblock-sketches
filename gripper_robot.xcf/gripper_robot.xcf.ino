#include <Makeblock.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);

MeDCMotor MotorG(PORT_1);
MeDCMotor MotorM(PORT_2);

MeInfraredReceiver infraredReceiverDecode(PORT_6);
int moveSpeed = 190;
boolean leftflag,rightflag;
int minSpeed = 55;
int factor = 23;

void setup()
{
    infraredReceiverDecode.begin();
}

void loop()
{
 if(infraredReceiverDecode.available()||infraredReceiverDecode.buttonState())
    {
        switch(infraredReceiverDecode.read())
        {
          case IR_BUTTON_PLUS:
               Forward();
               break;
          case IR_BUTTON_MINUS:
               Backward();
               break;
          case IR_BUTTON_NEXT:
               TurnRight();
               break;
          case IR_BUTTON_PREVIOUS:
               TurnLeft();
               break;
          case IR_BUTTON_9:
               ChangeSpeed(factor*9+minSpeed);
               break;
          case IR_BUTTON_8:
               ChangeSpeed(factor*8+minSpeed);
               break;
          case IR_BUTTON_7:
               ChangeSpeed(factor*7+minSpeed);
               break;
          case IR_BUTTON_6:
               ChangeSpeed(factor*6+minSpeed);
               break;
          case IR_BUTTON_5:
               ChangeSpeed(factor*5+minSpeed);
               break;
          case IR_BUTTON_4:
               ChangeSpeed(factor*4+minSpeed);
               break;
         case IR_BUTTON_3:
               ChangeSpeed(factor*3+minSpeed);
               break;
         case IR_BUTTON_2:
               ChangeSpeed(factor*2+minSpeed);
               break;
         case IR_BUTTON_1:
               ChangeSpeed(factor*1+minSpeed);
               break;
         case IR_BUTTON_A:
               MotorG.run(moveSpeed);
               break;
         case IR_BUTTON_C:
               MotorG.run(-moveSpeed);
               break;
         case IR_BUTTON_D:
               MotorM.run(moveSpeed);
               break;
         case IR_BUTTON_E:
               MotorM.run(moveSpeed);
               break;
        }
    }
    else
    {
      Stop();
    }
}


void Forward()
{
  MotorL.run(moveSpeed);
  MotorR.run(moveSpeed);
}
void Backward()
{
  MotorL.run(-moveSpeed);
  MotorR.run(-moveSpeed);
}
void TurnLeft()
{
  MotorL.run(-moveSpeed);
  MotorR.run(moveSpeed);
}
void TurnRight()
{
  MotorL.run(moveSpeed);
  MotorR.run(-moveSpeed);
}
void Stop()
{
  MotorL.run(0);
  MotorR.run(0);
}
void ChangeSpeed(int spd)
{
  moveSpeed = spd;
}
