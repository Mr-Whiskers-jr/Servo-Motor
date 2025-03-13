// This code is intended to control a servo motor 
// Servo Motor connections
int enA = 9;
int in1 = 8;
int in2 = 7;
int deadBand = 25 ;
int angle  = 0 ;


void setup() {
	// Set all the motor control pins to outputs
  serial.begin(9600)
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);

  // Set Speed of the servo 
  analogWrite(enA, 5);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void loop() {
	directionCheck();
	delay(1000);
}

// This function checks the direction of motor and sets it to 0 angle 
void directionCheck() {
angle = analogRead(1) ;
angle = map(angle, 0, 1023, -180, 180) ;

if (angle < 0) {
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);

}
if (angle > 0) {
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);

}
if (angle > -deadBand && angle < deadBand) {
  Serial.Println("The motor has been set to zero angle")
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}
}
void angleInput() {
  Serial.Println("Kindly enter the angle you'd like the motor to be moved to (between 180 and -180)") ;
  while (Serial.available() == 0) {
}
  angle = Serial.parseint() ;
}
void Servo() {
  if (angle == 0) {
    Serial.Println("We have arrived at your required destination") ;
  }
  if (angle < 0) {
    digitalWrite(in1,HIGH) ;
    digitalWrite(in2,LOW) ;
    if (angle == angle + deadBand || angle == angle - deadBand){
      digitalWrite(in1,LOW) ;
      digitalWrite(in2,LOW) ;
    }
  }
  else {
    digitalWrite(in1,LOW) ;
    digitalWrite(in2,HIGH) ;
    if (angle == angle + deadBand || angle == angle - deadBand){
      digitalWrite(in1,LOW) ;
      digitalWrite(in2,LOW) ;
    }
  }
  Serial.Println("We have arrived at your required destination") ;
}