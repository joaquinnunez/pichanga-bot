/*
* Drives a differential drive robot composed by:
* - Arduino Nano
* - L298N Dual H-bridge DC Motor Driver Shield
* - HC-06 Bluetooth
*   HC-06 Connections:
*   BT       Arduino
*   RX ----> TX
*   TX ----> RX
* Tested with an android device and this app https://play.google.com/store/apps/details?id=appinventor.ai_test.BluetoothRC&hl=es_419
*/

// H Bridge ports
int ENA = 5; // port 5 (output pwm)
int IN1 = 2;
int IN2 = 3;
int ENB = 6; // port 6 (output pwm)
int IN3 = 4;
int IN4 = 7;

void setup() {
 Serial.begin(9600);
 pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);  // stop driving
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH); // setting motorA's directon
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);  // setting motorB's directon
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.println(c);
    switch(c) {
      case 'L':
        left();
      break;
      case 'R':
        right();
      break;
      case 'F':
        forward();
      break;
      case 'B':
        backward();
      break;
      case 'X':
        stop();
      break;
    }
  }
}

void forward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); //setting motorA's directon
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); //setting motorB's directon
  analogWrite(ENA, 255);   //start driving motorA
  analogWrite(ENB, 255);   //start driving motorB
}

void backward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); //setting motorA's directon
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); //setting motorB's directon
  analogWrite(ENA, 255);  //start driving motorA
  analogWrite(ENB, 255);  //start driving motorB
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); //setting motorA's directon
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); //setting motorB's directon
  analogWrite(ENA, 255);  //start driving motorA
  analogWrite(ENB, 255);  //start driving motorB
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); //setting motorA's directon
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); //setting motorB's directon
  analogWrite(ENA, 255);  //start driving motorA
  analogWrite(ENB, 255);  //start driving motorB
}

void stop() {
  analogWrite(ENA, 0);  //stop driving motorA
  analogWrite(ENB, 0);  //stop driving motorB
}
