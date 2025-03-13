// Servo Motor connections
int enA = 9;
int in1 = 8;
int in2 = 7;
int angle = 0 ;


void setup() {
	// Set all the motor control pins to outputs
  Serial.begin(9600) ;
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);

  // Set Speed of the servo 
  analogWrite(enA, 50);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
  angle = analogRead(1) ;
  angle = map(angle, 0, 1023, -180, 180) ;
  Serial.println(angle) ;
  delay(500) ;
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
  delay(500) ;
  angle = analogRead(1) ;
  angle = map(angle, 0, 1023, -180, 180) ;
  Serial.println(angle) ;
}
