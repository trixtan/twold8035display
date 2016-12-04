#include <TwoLD8035Display.h>

TwoLD8035Display vfds(8,9,0,1,2,3,4,5,6,7);
int timer1_counter;

volatile Vfd activeV;
Character v1c;
Character v2c;

void setup() {
	//Disable all interrupts
	noInterrupts();
	TCCR1A = 0;
	TCCR1B = 0;	


	// Set timer1_counter to the correct value for our interrupt interval
	//timer1_counter = 0;	    // preload timer for 1Hz
	timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
	//timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
	//timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz
  
	TCNT1 = timer1_counter;   // preload timer
	TCCR1B |= (1 << CS12);    // 256 prescaler 
	TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
	interrupts();             // enable all interrupts
	
	vfds.clear();
}

void loop() {
/*
	v1c = FIVE, v2c = TWO;
	delay(1000);
	v1c = NONE, v2c = NONE;
	delay(1000);
*/

	v1c = ZERO, v2c = ONE;
	delay(1000);
	v1c = NINE, v2c = NONE;
	delay(1000);
	v1c = EIGHT, v2c = NONE;
	delay(1000);
	v1c = SEVEN, v2c = NONE;
	delay(1000);
	v1c = SIX, v2c = NONE;
	delay(1000);
	v1c = FIVE, v2c = NONE;
	delay(1000);
	v1c = FOUR, v2c = NONE;
	delay(1000);
	v1c = THREE, v2c = NONE;
	delay(1000);
	v1c = TWO, v2c = NONE;
	delay(1000);
	v1c = ONE, v2c = NONE;
	delay(1000);
	v1c = ZERO, v2c = NONE;
	delay(1000);

/*
	//current test
	v1c = NONE, v2c = EIGHT;
*/
}

ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
	TCNT1 = timer1_counter;   // preload timer
	//Swap tube
	switch(activeV) {
	case V1:
		vfds.printCharacter(V2, v2c);
		activeV = V2;
		break;
	case V2:
	default:
		vfds.printCharacter(V1, v1c);
		activeV = V1;
		break;
	}
}
