
int LED = 13;
int motor1Pin1 = 8;
int motor2Pin2 = 9;
int sensor = A0;
int distance;
int sensitivity = 700;

void setup()
{
pinMode(LED, OUTPUT);
pinMode(sensor, INPUT);
digitalWrite(sensor, HIGH);
Serial.begin(9600);
}

void loop()
{
  distance = analogRead(sensor);
  if (distance < sensitivity)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(motor1Pin1, HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
    digitalWrite(motor1Pin1, LOW);
    delay(5000);
  }

  Serial.println(distance);

}
