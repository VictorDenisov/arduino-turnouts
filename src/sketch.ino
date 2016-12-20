int pinout[] = {8, 9, 10, 11};

int pin_count = sizeof(pinout) / sizeof(pinout[0]);

void setup()
{
	for (int i = 0; i < pin_count; ++i) {
		pinMode(pinout[i], OUTPUT);
	}

	Serial.begin(9600);
}

void serialEvent() {
	int incomingByte = Serial.read();
	int pinNum = incomingByte - 'a';
	if (pinNum > 0 && pinNum < pin_count) {
		digitalWrite(pinout[pinNum], HIGH);
		delay(200);
		digitalWrite(pinout[pinNum], LOW);
	}
}

void loop()
{
}

// vim: ai cin
