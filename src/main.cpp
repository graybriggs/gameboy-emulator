
#include <iostream>
#include <cstdio>
#include <string>

#include "cpu.h"
#include "mmu.h"
#include "debug.h"
#include "gpu.h"
#include "loader.h"
//#include "opcodes.h"

#include "SDL/SDL.h"

int main() {

	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(160, 144, 16, SDL_SWSURFACE);
	SDL_WM_SetCaption("GB_emu", nullptr);

	MMU* mmu = new MMU();
	CPU cpu(mmu);
	GPU gpu(mmu);

	std::string name = readRomName();
	std::cout << "Loading ROM: " << name << std::endl;
	std::vector<BYTE> v = readRom(name);

	WORD address = 0;
	for (auto it = v.begin(); it != v.begin() + 16384; it++) {
		mmu->memory[address] = *it;
		++address;
	}
	
	std::cout << "Executing instructions: " << std::endl;
	for (int i = 0; i < 50; ++i) {
		//printf("\n"); dumpCpuRegisters(cpu); printf("\n");
		printf("Tick %d - ", i);
		cpu.dispatcher(cpu);
	}

	dumpCpuRegisters(cpu);

	delete mmu;
}