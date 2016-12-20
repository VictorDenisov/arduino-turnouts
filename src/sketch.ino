int pinout[] = {8, 9, 10, 11};

const int pin_count = sizeof(pinout) / sizeof(pinout[0]);

const int state_count = pin_count / 2;
int state[state_count];

void apply_state() {
	for (int i = 0; i < state_count; ++i) {
		digitalWrite(pinout[state[i]], HIGH);
		delay(200);
		digitalWrite(pinout[state[i]], LOW);
		delay(500);
	}
}

void report_state() {
	char *st = "-----a---c-----";
	if (state[0] == 0) {
		st[2] = '-';
	}
	if (state[0] == 1) {
		st[2] = '/';
	}
	if (state[1] == 2) {
		st[12] = '-';
	}
	if (state[1] == 3) {
		st[12] = '\\';
	}
	Serial.println("    -b---d-    ");
	Serial.println("   /       \\   ");
	Serial.println(st);
}

void setup()
{
	state[0] = 0;
	state[1] = 2;
	for (int i = 0; i < pin_count; ++i) {
		pinMode(pinout[i], OUTPUT);
	}

	apply_state();

	Serial.begin(9600);
	report_state();
}

void serialEvent() {
	int incomingByte = Serial.read();
	if (incomingByte == 'l') {
		report_state();
	} else {
		int pinNum = incomingByte - 'a';
		if (pinNum >= 0 && pinNum < pin_count) {
			state[pinNum >> 1] = pinNum;
			apply_state();
			report_state();
		}
	}
}

void loop()
{
}

// vim: ai cin
