// C++ code
//

#define MOTOR_1_PIN  13
#define MOTOR_2_PIN  7
#define ENABLE_MOTOR_1 6
#define ENABLE_MOTOR_2 11
#define TRIG_PIN 5
#define ECHO_PIN 3
#define COLOR_PIN 2
#define BLACK_COLOR_VOLTAGE 2

long duration, cm;

void setup()
{
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(MOTOR_1_PIN, OUTPUT);
  pinMode(MOTOR_2_PIN, OUTPUT);
  pinMode(ENABLE_MOTOR_1, OUTPUT);
  pinMode(ENABLE_MOTOR_2, OUTPUT);
  pinMode(1, OUTPUT);
  
  pinMode(COLOR_PIN, INPUT);

  digitalWrite(ENABLE_MOTOR_1, LOW);
  digitalWrite(ENABLE_MOTOR_2, LOW);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  // attachInterrupt(digitalPinToInterrupt(ECHO_PIN), ultrassoundInterrupt, )
  attachInterrupt(digitalPinToInterrupt(COLOR_PIN), blink, HIGH);
}

void blink(){
  // enableMotors();
  Serial.println("\n\n\n\n ACHOOOOU \n\n\n\n");
}

void loop()
{
  Serial.println(digitalRead(COLOR_PIN));
  digitalWrite(1, LOW);
  // readUltrasound();
  // disableMotors();
  // float color_voltage = readColor();
  // delay(1000);
  // if(color_voltage >= BLACK_COLOR_VOLTAGE){  
  //   enableMotors();
  // }else{
  //   disableMotors();
  // }

}

float readColor(){
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1024.0);
  Serial.println(voltage);
  // the lower the voltage, the brighter it is
  if ((voltage >= 0) && (voltage <= 0.4)) {
    // Serial.print ("it is light - ");
  } else if ((voltage > 0.4) && (voltage <= 2)) {
    // Serial.print ("it is bright - ");
  } else {
    // Serial.print ("it is dark - ");
  }
  // print out the value you read:
  // Serial.println(voltage);
  return voltage;
}

void enableMotors(){
  digitalWrite(ENABLE_MOTOR_1, HIGH);
  digitalWrite(ENABLE_MOTOR_2, HIGH);
}

void disableMotors(){
  digitalWrite(ENABLE_MOTOR_1, LOW);
  digitalWrite(ENABLE_MOTOR_2, LOW);
}

int readUltrasound(){
  // defines variables
long duration;
int distance;
  // Clears the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Sets the TRIG_PIN on HIGH state for 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 58;
}

bool handleDetection(){
  duration = pulseIn(ECHO_PIN, HIGH);
  cm = microsecondsToCentimeters(duration);
  if(cm < 100){
    Serial.print("DETECTOU EM cm: ");
    Serial.print(cm);
    Serial.print("\n");
    digitalWrite(ENABLE_MOTOR_1, LOW);
    digitalWrite(ENABLE_MOTOR_2, LOW); // sets the digital pin 13 on
  }
}