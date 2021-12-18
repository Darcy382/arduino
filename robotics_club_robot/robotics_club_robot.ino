// 1 is left, 2 is right

const int MOTOR1_FORWARD = 9; 
const int MOTOR1_BACKWARD = 8;
const int MOTOR1_ENABLE = 10;
const int MOTOR2_FORWARD = 7;
const int MOTOR2_BACKWARD = 6;
const int MOTOR2_ENABLE = 5;

int IRSensor1 = 2; // connect ir sensor to arduino pin 2
int IRSensor2 = 3; // connect ir sensor to arduino pin 3

void setup() {
  // Enable both of the motors
  digitalWrite(MOTOR1_ENABLE, HIGH);
  digitalWrite(MOTOR2_ENABLE, HIGH);

  pinMode(IRSensor1, INPUT); // sensor pin is an input. Sends values to the Arduino
  pinMode(IRSensor2, INPUT); // sensor pin is an input. Sends values to the Arduino

  Serial.begin(9600);
}

void moveForward() {
  // Setting the forward pin to high and backward to low will make motors rotate forward.         
  digitalWrite(MOTOR1_FORWARD, HIGH);  
  digitalWrite(MOTOR1_BACKWARD, LOW);    

  // Do the same for the right motor
  digitalWrite(MOTOR2_FORWARD, HIGH);
  digitalWrite(MOTOR2_BACKWARD, LOW);
}

void moveBackward() {
  // Setting the forward pin to high and backward to low will make motors rotate forward.         
  digitalWrite(MOTOR1_FORWARD, LOW);  
  digitalWrite(MOTOR1_BACKWARD, HIGH);    

  // Do the same for the right motor
  digitalWrite(MOTOR2_FORWARD, LOW);
  digitalWrite(MOTOR2_BACKWARD, HIGH);
}

void stopMoving() {
  // Setting the forward pin to low and backward to low will make motors atop rotating.         
  digitalWrite(MOTOR1_FORWARD, LOW);  
  digitalWrite(MOTOR1_BACKWARD, LOW);    

  // Do the same for the right motor
  digitalWrite(MOTOR2_FORWARD, LOW);
  digitalWrite(MOTOR2_BACKWARD, LOW);
}

void moveLeft() {
  // Setting the forward pin to low and backward to low will make motors atop rotating.         
  digitalWrite(MOTOR1_FORWARD, LOW);  
  digitalWrite(MOTOR1_BACKWARD, LOW);    

  // Do the same for the right motor
  digitalWrite(MOTOR2_FORWARD, LOW);
  digitalWrite(MOTOR2_BACKWARD, LOW);
  
}


void moveRight() {
  
}

void loop() {

  
  // Enable both of the motors
  moveForward();
//  moveBackward();
//  delay(3000);
//  stopMoving();
//  delay(3000);

  if (digitalRead(IRSensor1) == LOW || digitalRead(IRSensor2) == LOW) {   
    moveBackward();
    delay(500);
    stopMoving();
    delay(2000);
  }

//  int irSensorL = digitalRead(IRSensor1); // Creates a variable that will constantly hold the value of IR sensor ( 1 or 0)
//  int irSensorR = digitalRead(IRSensor2);

//  if (irSensorL) {
//    moveLeft();
//  } else if (irSensorR) {
//    moveRight();
//  } else {
//    moveForward();
//  }

  
}
