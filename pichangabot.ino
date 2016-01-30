int ENA=5;//connected to Arduino's port 5(output pwm)
int IN1=2;//connected to Arduino's port 2
int IN2=3;//connected to Arduino's port 3
int ENB=6;//connected to Arduino's port 6(output pwm)
int IN3=4;//connected to Arduino's port 4
int IN4=7;//connected to Arduino's port 7

void setup()
{
 Serial.begin(9600);
 pinMode(ENA, OUTPUT);    //output
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

void loop()
{

  if (Serial.available()) {
    char c = Serial.read();
    Serial.println(c);
    switch(c) {
      case 'l':
        left();
      break;
      case 'r':
        right();
      break;
      case 'f':
        forward();
      break;
      case 'b':
        backward();
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
