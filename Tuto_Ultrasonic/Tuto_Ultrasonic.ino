const int led = 13;
const int trigPin = 2;
const int echoPin = 3;

long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
}
void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < 20){
    digitalWrite(led, 1);
  } else {
    digitalWrite(led, 0);
  }
}