#include <Servo.h>
Servo lock;

void setup() 
{
 lock.attach(2);
 Serial.begin(9600);
 lock.write(0);
 delay(500);
 }
void loop() 
{
  int i;
  int s=1;
  start:
  int a;
  if(Serial.available()>0)
  {
    a=Serial.read();
    if(a==5&&(s==1))
    {
     for(i=0;i<=170;i++)
     {
       lock.write(i);
       delay(7);
     }
     Serial.print("OPEN");
     s=0;
    }
    if((s==0)&&(a==9))
    {
      for(i=170;i>=0;i--)
    {
       lock.write(i);
       delay(7);
    }
    Serial.print("LOCKED");
    s=1;
      }
  }
  goto start;
}

