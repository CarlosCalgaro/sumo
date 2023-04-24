#define INFRA_PIN 2
#define LED_PIN 4
void handleInterrupt();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(INFRA_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(INFRA_PIN), handleInterrupt, FALLING);
}

void handleInterrupt(){
  digitalWrite(LED_PIN, HIGH);
};

int readColor(){
  int sensorValue = digitalRead(INFRA_PIN);
  Serial.println(sensorValue);
  return sensorValue;
};

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, LOW);
  delay(100);
}

