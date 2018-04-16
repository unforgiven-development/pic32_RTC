// pic32_RTC
//
// © http://sites.google.com/site/vilorei
// CC = BY NC SA
//
// Jun 19, 2011 - Library
//
// based on Paul_L chipKITRTCC library
//

#include "pic32_RTC.h"

#define SERIAL_BAUD_RATE 115200


pic32_RTC myRTC;

void setup() {
	Serial.begin(SERIAL_BAUD_RATE);
	Serial.print("\n\n\n***\n");

	myRTC.begin();

	Serial.print(myRTC.WhoAmI());
	Serial.print("\n");

	myRTC.set(11, 10, 19, 17, 44, 30);
}


void loop() {
	/* Get the time from the RTCC */
	myRTC.get();

	/* Print the time */
	Serial.print(myRTC.date());
	Serial.print("\t");
	Serial.print(myRTC.time());
	Serial.print("\t");
	Serial.print(RTCDATE, HEX);
	Serial.print("\t");
	Serial.print(RTCTIME, HEX);
	Serial.print("\n");

	/* Wait... */
	delay(1500);

	uint32_t t0;
	uint32_t t1;

	t0 = millis();

	for (uint16_t i = 0; i < 32000; i++) {
		if (i % 1000 == 0) {
			Serial.print(i, DEC);
			Serial.print("\n");
		}
	}

	Serial.print(uint32_t(t1 - t0));
	Serial.print(" ms\n");
}
