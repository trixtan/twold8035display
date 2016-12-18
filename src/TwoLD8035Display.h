#ifndef TWOLD8035DISPLAY_H
#define TWOLD8035DISPLAY_H

#include "Arduino.h"

#define DIGIT_DEF(a, b, c, d, e, f, g) \
	(a + (b << 1) + (c << 2) + (d << 3) + (e << 4) + (f << 5) + (g << 6))

enum Character:byte {
	NONE 	= DIGIT_DEF(0,0,0,0,0,0,0), 
	ZERO 	= DIGIT_DEF(1,1,1,1,1,1,0),
	ONE 	= DIGIT_DEF(0,1,1,0,0,0,0), 
	TWO 	= DIGIT_DEF(1,1,0,1,1,0,1), 
	THREE 	= DIGIT_DEF(1,1,1,1,0,0,1), 
	FOUR 	= DIGIT_DEF(0,1,1,0,0,1,1),
	FIVE 	= DIGIT_DEF(1,0,1,1,0,1,1),
	SIX 	= DIGIT_DEF(1,0,1,1,1,1,1),
	SEVEN 	= DIGIT_DEF(1,1,1,0,0,0,0),
	EIGHT 	= DIGIT_DEF(1,1,1,1,1,1,1),
	NINE 	= DIGIT_DEF(1,1,1,1,0,1,1),
	A 	= DIGIT_DEF(1,1,1,0,1,1,1),
	C 	= DIGIT_DEF(1,1,1,1,0,0,0),
	F 	= DIGIT_DEF(1,0,0,0,1,1,1),
	E 	= DIGIT_DEF(1,0,0,1,1,1,1),
	U 	= DIGIT_DEF(0,1,1,1,1,1,0),
	L 	= DIGIT_DEF(0,0,0,1,1,1,0),
	P 	= DIGIT_DEF(1,1,0,0,1,1,1)
};

enum Vfd:byte {V1 = 8, V2 = 9};

class TwoLD8035Display {
public:
	TwoLD8035Display(byte grid_v1, byte grid_v2, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h);
	void printCharacter(Vfd v, Character c);
	void clear();
	
protected:
	void swapVfd(Vfd mustBeOn);
	byte pin_[10];
};

#endif /* TWOLD8035DISPLAY_H*/
