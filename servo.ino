const int ser1_pwm_pin = 9;
float echoPin=A0;
float trigPin=A1;
long duration;
float distance;
void servo_pwm_con(int deg, int pin)
{
  int val = (deg*10.25)+500; // i.e. 500 ms means 0 degree rotation whereas val = 2345 ms means high pulse for 2345 microsecs resulting 150 degree rotation at servo motor   
  digitalWrite(pin,HIGH);
  delayMicroseconds(val);
  digitalWrite(pin,LOW);
  delay(7);
}
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
  Serial.println(distance);
    if (distance<27)
  {
    servo_pwm_con(140,ser1_pwm_pin);              
   }
    else{
    servo_pwm_con(0,ser1_pwm_pin);              
    }
   
}
