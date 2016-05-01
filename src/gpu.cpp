
#include "cpu.h"
#include "gpu.h"
#include "mmu.h"

#include <cmath>

GPU::GPU(MMU* m) :
	mmu(m),
	current_scanline(0),
	scroll_x(0),
	scroll_y(0)
{

}

void updateLCDStatusRegister() {
	//LCD_SR = mmu->memory[LCD_SR_ADDR];	
}

int GPU::pixelPosition(const BYTE x, const BYTE y) {
	return screen_w * y + x;
}

void GPU::modeStep() {

	enum GPU_MODES { H_BLANK, V_BLANK, OAM_SCANLINE, VRAM_SCANLINE };

	unsigned int gpu_mode_clock = 0;

	switch(gpu_mode) {
	case OAM_SCANLINE:

		if (gpu_mode_clock >= 80) {
			gpu_mode_clock = 0;
			gpu_mode = VRAM_SCANLINE;
		}

	case VRAM_SCANLINE:

		if (gpu_mode_clock >= 172) {
			gpu_mode_clock = 0;
			gpu_mode = H_BLANK;

			scanlineFramebuffer();
		}
		break;

	case H_BLANK:

		if (gpu_mode_clock >= 204) {
			gpu_mode_clock = 0;

			++current_scanline;

			// if all screen_h lines have been completed enter V_BLANK period.
			// otherwise get the next scanline
			if (current_scanline == screen_h - 1) {
				gpu_mode = V_BLANK;

				renderFrame();
			}
			else {
				gpu_mode = OAM_SCANLINE;
			}
		}
		break;

	case V_BLANK:

		if (gpu_mode_clock >= 456) {
			gpu_mode_clock = 0;

			++current_scanline;

			if (current_scanline >= (screen_h + 10) - 1) {
				current_scanline = 0;
				gpu_mode = OAM_SCANLINE;
			}
		}

		break;

	default:
		break;

	}

}

void GPU::scanlineFramebuffer() {

}

void GPU::renderFrame() {

	LCD_CR = mmu->readByte(LCD_CR_ADDR);
	bool signedMemAccess = false;
	bool usingWindow = false;
	WORD bgTileMapSelect;
	WORD tileData = 0;

	scroll_y = mmu->readByte(SCROLL_Y_ADDR);
	scroll_x = mmu->readByte(SCROLL_X_ADDR);

	if (isBitSet(LCD_CR, 4))
		tileData = VRAM_TILE_DATA_0;
	else {
		tileData = VRAM_TILE_DATA_1;
		signedMemAccess = true;
	}

	if (!usingWindow) {
		if (isBitSet(LCD_CR, 3))
			bgTileMapSelect = 0x8000;
		else 
			bgTileMapSelect = 0x9C00;
	}
	else  {
		if (isBitSet(LCD_CR, 6))
			bgTileMapSelect = 0x8000;
		else
			bgTileMapSelect = 0x9C00;
	}

	if (signedMemAccess) {
		// do signed value stff in VRAM_TILE_DATA_1
	}
	else {

	}

}

void GPU::renderTiles() {

}


bool GPU::isBitSet(BYTE byte, const BYTE bit) {
	return byte & static_cast<BYTE>(exp2(bit));
}
