const int trigPin = 11;
const int echoPin = 10;
const int buzzPin = 6;
long duration;
float distance;
int b=1;
int c=1;
unsigned int on=0;
unsigned int on1=0;
unsigned int on2=0;
void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzPin, OUTPUT);
Serial.begin(9600);
}
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = 0.034*(duration/2);
on=millis();//100
if (distance <= 5)
{
digitalWrite(buzzPin,HIGH);
}
else if (distance <= 15 && distance > 5)
{
if(b==1)
{
on1=on;
on2=on1+50;
b=0;
}
if(on<(on1+50))
{
digitalWrite(buzzPin,HIGH);
}
else if((on<(on2+50)) && (on>=(on1+50)))
{
digitalWrite(buzzPin,LOW);
}
else
{
     b=1;
    }
    c=1;
  }


   else if (distance <= 25 && distance > 15)
    {
     if(c==1)
     {
      on1=on;
      on2=on1+300;
      c=0;
     }
     if(on<(on1+300))
     {
       digitalWrite(buzzPin,HIGH);
     }
     else if((on<(on2+300)) && (on>=(on1+300)))
     {
       digitalWrite(buzzPin,LOW);
     }
     else
     {
      c=1;
     }
     b=1;
   }
  
    
  else
  {
     digitalWrite(buzzPin,LOW);
     b=1;
     c=1;
     on=on1=on2=0;
  }
  Serial.println(distance);
 
}
