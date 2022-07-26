const int ser1_pwm_pin = 9;
float echoPin=A0;
float trigPin=A1;
long duration;
float distance;

void setup()
{
  pinMode(ser1_pwm_pin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  
  duration= pulseIn(echoPin, HIGH);
  distance=duration*0.034/2;
  Serial.print(distance);

   if (distance<140)
  {
    for (int deg = 0; deg < 140; deg++) 
    { 
      servo_pwm_con(deg,ser1_pwm_pin);              
    }
  if (distance>140)  
//    delay(10000);
    for (int deg = 140; deg > 0; deg--)  
    { 
      servo_pwm_con(deg,ser1_pwm_pin);               
    }
  }
}
void servo_pwm_con(int deg, int pin)
{
  int val = (deg*10.25)+500; // i.e. 500 ms means 0 degree rotation whereas val = 2345 ms means high pulse for 2345 microsecs resulting 150 degree rotation at servo motor   
  digitalWrite(pin,HIGH);
  delayMicroseconds(val);
  digitalWrite(pin,LOW);
  delay(1);
}