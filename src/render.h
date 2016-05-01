
#ifndef RENDER_H
#define RENDER_H

#include "SDL/SDL.h"

#include "types.h"

constexpr short SCREEN_W = 144;
constexpr short SCREEN_H = 160;

class Render {
public:

	Render();

	void clearBuffer();
	void drawPixel(BYTE x, BYTE y, BYTE color);
	void drawScreen();

private:
	BYTE buffer[SCREEN_W * SCREEN_H];
	SDL_Surface* scr;

};


#endif