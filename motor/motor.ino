// C++ code
//

#define MOTOR_1_PIN  13
#define MOTOR_2_PIN  7
#define ENABLE_MOTOR_1 9
#define ENABLE_MOTOR_2 11
#define PING_PIN 5
#define ECHO_PIN 3

long duration, cm;

void setup()
{
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(MOTOR_1_PIN, OUTPUT);
  pinMode(MOTOR_2_PIN, OUTPUT);
  pinMode(ENABLE_MOTOR_1, OUTPUT);
  pinMode(ENABLE_MOTOR_2, OUTPUT);
  pinMode(PING_PIN, OUTPUT);
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_PIN, HIGH);
  // attachInterrupt(digitalPinToInterrupt(ECHO_PIN), handleDetection, HIGH);
}

void loop()
{
  digitalWrite(MOTOR_1_PIN, HIGH);
  digitalWrite(MOTOR_2_PIN, HIGH);
  digitalWrite(ENABLE_MOTOR_1, HIGH);
  digitalWrite(ENABLE_MOTOR_2, HIGH); // sets the digital pin 13 on
}

// long microsecondsToCentimeters(long microseconds) {
//    return microseconds / 58;
// }

// bool handleDetection(){
//   duration = pulseIn(echoPin, HIGH);
//   cm = microsecondsToCentimeters(duration);
//   if(cm < 100){
//     Serial.print("DETECTOU EM %d cm", cm)
//     digitalWrite(ENABLE_MOTOR_1, LOW);
//     digitalWrite(ENABLE_MOTOR_2, LOW); // sets the digital pin 13 on
//     //detectou
//   }
// }