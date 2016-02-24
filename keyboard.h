/*
	YAPE - Yet Another Plus/4 Emulator

	The program emulates the Commodore 264 family of 8 bit microcomputers

	This program is free software, you are welcome to distribute it,
	and/or modify it under certain conditions. For more information,
	read 'Copying'.

	(c) 2000, 2001, 2015 Attila Gr�sz
*/
#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "types.h"

class KEYS {
	protected:
		unsigned char joybuffer[256];
		unsigned char joy_trans(unsigned char r);
		//
		static unsigned int nrOfJoys;
		static SDL_Joystick *sdlJoys[2];
		static unsigned int joystickScanCodes[5];
		unsigned char getPcJoyState(unsigned int joyNr, unsigned int activeJoy);
		unsigned char latched;
		unsigned char keyReadMatrixRow(unsigned int r);
		unsigned char blockMask;
		virtual unsigned int fireButtonIndex(unsigned int a) const { return 6 + a; };

	public:
		KEYS();
		virtual ~KEYS();
		static void initPcJoys();
		static void closePcJoys();
		void latch(unsigned int keyrow, unsigned int joyrow);
		unsigned char feedkey(unsigned char latch);
		unsigned char feedjoy(unsigned char latch);
		unsigned int swapjoy();
		void empty(void);
		static unsigned int activejoy;
		unsigned char readLatch() { return latched | blockMask; };
		void block(bool isBlocked) { blockMask = isBlocked ? 0xFF : 0x00; };
};

#endif // _KEYBOARD_H
