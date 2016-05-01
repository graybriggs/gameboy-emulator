
#include "mmu.h"

MMU::MMU() :
	inBIOS(false)
{
	for (int i = 0; i < 65535; ++i)
		memory[i] = 0x00;
}

BYTE MMU::readByte(WORD addr) {
	return memory[addr];
	
	/*
	switch (addr & 0xF000) {
	
	// read up on spec of this area of code - writing to BIOS seems completely wrong!!
	case 0x0000: // BIOS
		if (inBIOS) {
			if (addr < 0x100)
				memory[addr] = memory[addr];
				//return bios[addr];
	
			else if (*(cpu->program_counter) == 0x0100)
					inBIOS = false;
		
			//return cart_rom[addr];
			return memory[addr];
		}
	case 0x1000:
	case 0x2000:
	case 0x3000:
		//return cart_rom[addr]; // ROM 0
		return memory[addr];
		
	case 0x4000:
	case 0x5000:
	case 0x6000:
	case 0x7000:
		//return cart_rom[addr]; // ROM 1 (16k)
		return memory[addr];
		
	case 0x8000:
	case 0x9000:
		//return vram[addr]; // VRAM (8k)
		return memory[addr];

	case 0xA000:
	case 0xB000:
		//return external_ram[addr];
		return memory[addr];

	case 0xC000:
	case 0xD000:
		//return work_ram[addr];
		return memory[addr];

	case 0xE000:
		return memory[addr];

	case 0xF000:
		switch (addr & 0x0F00) {
			  // ram mirror
		    case 0x000: case 0x100: case 0x200: case 0x300:
		    case 0x400: case 0x500: case 0x600: case 0x700:
		    case 0x800: case 0x900: case 0xA00: case 0xB00:
		    case 0xC00: case 0xD00:
		    	//return work_ram[addr]; // mirror of 0xC000 - 0xDDFF
		    	return memory[addr];

			case 0xE00:
				if (addr < 0xFEA0)
					return 0;
					//return gpu.oam[addr]; // ???
				else
					return 0; // if address is >= 0xFEA0 then the bytes are always read as 0


			case 0xF00:
				if (addr >= 0xFF80)
					memory[addr] = memory[addr];
					//return zram[addr];
				else
					return 0; // i/o control not handled
		}
	}
	*/
}

void MMU::writeByte(WORD addr, BYTE val) {
	memory[addr] = val;
	/*
	switch (addr & 0xF000) {
		
	case 0x0000: // BIOS
		if (inBIOS) {
			if (addr < 0x100)
				memory[addr] = memory[addr];
				//return bios[addr];
			
			else if (*(cpu->program_counter) == 0x0100)
					inBIOS = false;
				
			//return cart_rom[addr];
			memory[addr] = val;
		}
	case 0x1000:
	case 0x2000:
	case 0x3000:
		//return cart_rom[addr]; // ROM 0
		memory[addr] = val;
		
	case 0x4000:
	case 0x5000:
	case 0x6000:
	case 0x7000:
		//return cart_rom[addr]; // ROM 1 (16k)
		memory[addr] = val;
		
	case 0x8000:
	case 0x9000:
		//return vram[addr]; // VRAM (8k)
		memory[addr] = val;

	case 0xA000:
	case 0xB000:
		//return external_ram[addr];
		memory[addr] = val;

	case 0xC000:
	case 0xD000:
		//return work_ram[addr];
		memory[addr] = val;

	case 0xE000:
		memory[addr] = val;

	case 0xF000:
		switch (addr & 0x0F00) {
			  // ram mirror
		    case 0x000: case 0x100: case 0x200: case 0x300:
		    case 0x400: case 0x500: case 0x600: case 0x700:
		    case 0x800: case 0x900: case 0xA00: case 0xB00:
		    case 0xC00: case 0xD00:
		    	//return work_ram[addr]; // mirror of 0xC000 - 0xDDFF
		    	memory[addr] = val;

			case 0xE00:
				if (addr < 0xFEA0)
					memory[addr] = memory[addr];
					//return gpu.oam[addr]; // ???
				else
					memory[addr] = memory[addr]; // if address is >= 0xFEA0 then the bytes are always read as 0


			case 0xF00:
				if (addr >= 0xFF80)
					memory[addr] = val;
					//return zram[addr];
				else
					memory[addr] = memory[addr]; // i/o control not handled
		}

	}
	*/	
}


WORD MMU::readWord(WORD addr) {
	return readByte(addr) + (readByte(addr + 1) << 8);
}

void MMU::writeWord(WORD addr, WORD val) {
	writeByte(addr, val); // lsB
	writeByte(addr + 1, (val >> 8));  // msB
}


