const int GREEN_PIN = 10;
const int YELLOW_PIN = 9;
const int RED_PIN = 8;

int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (state == 0) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    delay(5000);
  } else if (state == 1) {
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    delay(3000);
  } else if (state == 2) {
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    delay(7000);
  }
  state = (state + 1) % 3;
}
