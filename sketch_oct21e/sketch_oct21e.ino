const int white_pin = 3;
const int red_pin = 5;
const int blue_pin = 6;
const int green_pin = 9;
const int yellow_pin = 10;

int pins [5] = {3, 5, 6, 9, 10};

void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<5;i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0;i<5;i++) {
    analogWrite(pins[i], 255);
    delay(1000);
  }
  int count = 200;
  for (int i=0;i<5;i++) {
    analogWrite(pins[i], count);
    count = count / 2;
    delay(1000);
  }
}
