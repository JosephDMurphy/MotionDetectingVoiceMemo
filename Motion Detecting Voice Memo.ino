#define sensorPin A1 // select the input pin for LDR
#define PLAYE 2 //attach pin D2 Arduino to PLAY-E pin of HC-SR04
#define trigPin 3 //attach pin D4 Arduino to pin Trig of HC-SR04
#define echoPin 4 // attach pin D3 Arduino to pin Echo of HC-SR04
#define GLED 5 //attach for green activation LED

int lightValue = 0; // variable to store the value coming from the sensor
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(PLAYE, OUTPUT); // Sets PLAY-E pin as OUTPUT
  pinMode(GLED, OUTPUT); // Sets GLED pin as OUTPUT
  //Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
  lightValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println(lightValue);

  while (lightValue < 100)
  { delay(3600000);
    lightValue = analogRead(sensorPin); // read the value from the sensor
    //Serial.println(lightValue);
  }

  // Light detected so while loop escaped - Begins motion detection
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.println(distance);

  if (distance < 40) {
    digitalWrite(PLAYE, HIGH);
    digitalWrite(GLED, HIGH);
    delay(5000);
    digitalWrite(PLAYE, LOW);
    digitalWrite(GLED, LOW);
    delay(10000);
  }
  delay(2000);
}
