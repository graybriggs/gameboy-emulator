
#include "render.h"

#include <cstring>

Render::Render() {
    scr = SDL_GetVideoSurface();

    clearBuffer();
}


void Render::clearBuffer() {
    std::memset(buffer, 0, SCREEN_H * SCREEN_W);
}

void Render::drawPixel(BYTE x, BYTE y, BYTE color) {
    ((unsigned int*)scr->pixels)[y * (scr->pitch / 4) + x] = color;
}

void Render::drawScreen() {
    if (SDL_MUSTLOCK(scr)) {
        if (SDL_LockSurface(scr) < 0) {
            throw -1;
        }
    }

    for (int y = 0; y < SCREEN_H;  ++y) {
        for (int x = 0; x < SCREEN_W; ++x) {
            drawPixel(x, y, buffer[y * SCREEN_H + x]);
        }
    }

    if (SDL_MUSTLOCK(scr)) {
        SDL_UnlockSurface(scr);
    }
}
