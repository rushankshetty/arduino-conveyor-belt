
int LED = 13;             // On-board led pin 13
int motor1Pin1 = 8;       // Positive terminal of motor 1
int motor2Pin2 = 9;       // Positive terminal of motor 2
int sensor = A0;          // Obstacle sensor at A0 since it's analog
int distance;
int sensitivity = 700;    // Setting a threshold value

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
    // If an object is not sensed, keep the conveyor belt in motion
    digitalWrite(LED, HIGH);
    digitalWrite(motor1Pin1, HIGH);
  }
  else
  {
    // If an object is sensed, stop the conveyor belt for 5 seconds
    // so that required action(s) can be performed
    digitalWrite(LED,LOW);
    digitalWrite(motor1Pin1, LOW);
    delay(5000);
  }

  // Print the distance between the object and the sensor to the serial output
  // for debugging purposes
  Serial.println(distance);

}
