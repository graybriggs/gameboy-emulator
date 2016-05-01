
#ifndef GPU_H
#define GPU_H

#include "types.h"

//

//#define VRAM 0x8000

constexpr WORD LCD_CR_ADDR = 0xFF40;
constexpr WORD LCD_SR_ADDR = 0xFF41;
constexpr WORD SCROLL_Y_ADDR = 0xFF42;
constexpr WORD SCROLL_X_ADDR = 0xFF43;
constexpr WORD Y_COORDIATE_ADDR = 0xFF44;

constexpr WORD WINDOW_X = 0xFF4A;
constexpr WORD WINDOW_Y = 0xFF4B;
//

constexpr WORD VRAM_TILE_DATA_0 = 0x8000;
constexpr WORD VRAM_TILE_DATA_1 = 0x8800;

#define TILE_MAP_0_START 0x9800

#define TILE_MAP_1_START 0x9C00
#define TILE_MAP_1_END 0x9FFF

//#define TILE SET

#define TILE_COLOR_PALETTE 0xFF47  // [11, 10, 01, 00] - 0xE4
#define SPRITE_COLOR_PALETTE 0xFF48 //  11 10 01 00


class MMU;

class GPU {
public:
	GPU(MMU* m);

	void updateLCDStatusRegister();

	int pixelPosition(const BYTE x, const BYTE y);
	void modeStep();
	void scanlineFramebuffer();
	void renderFrame();

	void renderTiles();
	bool isBitSet(BYTE byte, const BYTE bit);

public:

	MMU* mmu;

	static constexpr BYTE screen_w = 160;
	static constexpr BYTE screen_h = 144;
	static constexpr BYTE rgba = 4;

	BYTE screenBuffer[screen_w * screen_h * rgba];  // screen width * screen height * RGBA value4

	BYTE gpu_mode; // 0, 1, 2, 3
	BYTE current_scanline;


	BYTE scroll_x;
	BYTE scroll_y;
	BYTE window_x;
	BYTE window_y;
	
	BYTE LCD_CR; // LCD control register (R/W)
	BYTE LCD_SR; // LCD status register (R/W)

	WORD tile_ram[384]; 
};

#endif