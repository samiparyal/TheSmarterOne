float echo = A0;
float trig = A1;
long duration;
float distance;
int wheel1 = 6;
int wheel2 = 7;
int wheel3 = 8;
int wheel4 = 9;
int ENA = 10;
int ENB = 5;

void stop(){
    digitalWrite(wheel1, LOW);
    digitalWrite(wheel2, LOW);
    digitalWrite(wheel3, LOW);
    digitalWrite(wheel4, LOW);
  }

void setup()
{ 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(wheel1, OUTPUT);
  pinMode(wheel2, OUTPUT);
  pinMode(wheel3, OUTPUT);
  pinMode(wheel4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 

  analogWrite(ENA, 50);
  analogWrite(ENB, 50);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  
  if(distance>20)
  {
   digitalWrite(wheel1, HIGH);
   digitalWrite(wheel3, LOW);
   digitalWrite(wheel2, LOW);
   digitalWrite(wheel4, HIGH);
        
  }
  else
  {
     
   digitalWrite(wheel1, LOW);
   digitalWrite(wheel2, LOW);
   digitalWrite(wheel3, HIGH);
   digitalWrite(wheel4, LOW);  
  }
}
