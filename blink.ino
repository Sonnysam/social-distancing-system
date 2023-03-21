int trigPin = 7;
int echoPin = 12;
int ledPin = 13;
int ledPin2 = 8;
long duration;
int distance;

void setup() {
 	pinMode(trigPin, OUTPUT);
  	pinMode(echoPin, INPUT);
  	pinMode(ledPin, OUTPUT);
  	pinMode(ledPin2, OUTPUT);
   	Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);
  // This line calculates the distance in centimeters. 
  //Speed of sound (in air) = 340 m/s, which is ~~ 0.034 cm/microsecond. 


  // conditional to test and turn on LED if the distance is than 20cm
   if(distance < 20){ 
    // turn on red LED and turn off green LED
    digitalWrite(LED_BUILTIN, HIGH);  
   	digitalWrite(ledPin2, LOW);
   }
  else {
    // turn on green LED and turn off red LED
  	digitalWrite(ledPin2, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.print("Distance is  ");
  Serial.print(distance);
  Serial.println(" cm ");
  delay(1000);
}