#define ENABLE_MOTOR_1 6
#define ENABLE_MOTOR_2 11
#define COLOR_PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Starting Serial Terminal
  // pinMode(1, OUTPUT);
  
  pinMode(ENABLE_MOTOR_1, OUTPUT);
  pinMode(ENABLE_MOTOR_2, OUTPUT);
  disableMotors();
  // pinMode(COLOR_PIN, INPUT_PULLUP);
  
  // attachInterrupt(digitalPinToInterrupt(COLOR_PIN), blink, HIGH);
}

void blink(){
  // digitalWrite(1, HIGH);
  // delay(2000);
  
  // put your main code here, to run repeatedly:

}

void disableMotors(){
  digitalWrite(ENABLE_MOTOR_1, LOW);
  digitalWrite(ENABLE_MOTOR_2, LOW);
}

void loop() {
  digitalWrite(1, HIGH);

  Serial.println(digitalRead(1));
  // put your main code here, to run repeatedly:

}
