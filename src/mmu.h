
#ifndef MMU_H
#define MMU_H

#include "types.h"


constexpr WORD VRAM = 0x8000;
constexpr WORD BG_MAP_REGION_0 = 0x9800;
constexpr WORD BG_MAP_REGION_1 = 0x9C00;


class MMU {
public:
	MMU();

	BYTE readByte(WORD addr);
	void writeByte(WORD addr, BYTE val);
	WORD readWord(WORD addr);
	void writeWord(WORD addr, WORD val);

	
	BYTE memory[65535];

	bool inBIOS;

};

#endif
