
void setup()
{

	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	Serial.begin(9600);
}

void serialEvent() {
	int incomingByte = Serial.read();
	if (incomingByte == 'a') {
		Serial.write('a');
		digitalWrite(8, HIGH);
		delay(200);
		digitalWrite(8, LOW);
	}
	if (incomingByte == 'b') {
		Serial.write('b');
		digitalWrite(9, HIGH);
		delay(200);
		digitalWrite(9, LOW);
	}
	if (incomingByte == 'c') {
		Serial.write('c');
		digitalWrite(10, HIGH);
		delay(200);
		digitalWrite(10, LOW);
	}
	if (incomingByte == 'd') {
		Serial.write('d');
		digitalWrite(11, HIGH);
		delay(200);
		digitalWrite(11, LOW);
	}
}

void loop()
{
}
