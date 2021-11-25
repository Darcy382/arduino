const int ON = 1;
const int OFF = 0;

const int BUTTON_PIN = 7;
const int FLICKER_DELAY = 100;
int LIGHT_PIN = 8;
int program_state = 0;
int flicker_timer = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN)) {
    Serial.println(program_state);
    if (program_state == 0) {
      digitalWrite(LIGHT_PIN, HIGH);
      program_state = 1;
    }
    else if (program_state == 1) {
      digitalWrite(LIGHT_PIN, LOW);
      program_state = 2;
    } 
    else if (program_state == 2) {
      program_state = 0;
    }
    while (digitalRead(BUTTON_PIN)) {
      delay(10);
    }
  }
  if (program_state == 0) {
    int current_led_state = digitalRead(LIGHT_PIN);
    digitalWrite(LIGHT_PIN, !current_led_state);
    delay(FLICKER_DELAY);
  }
}
