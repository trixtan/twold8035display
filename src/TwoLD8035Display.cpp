#include "TwoLD8035Display.h"

TwoLD8035Display::TwoLD8035Display(byte grid_v1, byte grid_v2, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h) {

	pin_[0] = a;
	pin_[1] = b;
	pin_[2] = c;
	pin_[3] = d;
	pin_[4] = e;
	pin_[5] = f;
	pin_[6] = g;
	pin_[7] = h;
	pin_[8] = grid_v1;
	pin_[9] = grid_v2;

	for(byte i=0; i<10; i++){
		pinMode(pin_[i], OUTPUT);
	}

	clear();
}

void TwoLD8035Display::clear() {
	for(byte i=0; i<10; i++){
		//switch all off
		digitalWrite(pin_[i], LOW);
	}
}

void TwoLD8035Display::swapVfd(Vfd mustBeOn){
	Vfd other = V1 == mustBeOn ? V2:V1;
	digitalWrite(pin_[other], LOW);
	digitalWrite(pin_[mustBeOn], HIGH);
}

void TwoLD8035Display::printCharacter(Vfd v, Character c){
	swapVfd(v); //Filament on
	byte m = c;
	for (byte i = 0; i < 8; i++) {
		digitalWrite(pin_[i], m & 0x01);
		m >>= 1;
	}
}

