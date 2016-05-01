
#include "debug.h"

#include "cpu.h"
#include "mmu.h"

void dumpCPUInfo(CPU& cpu, ...) {
	
}

void dumpCpuRegisters(CPU& cpu) {
	
	printf("--- CPU Register Dump ---\n");

	printf("AF - %X\n", cpu.AF);
	printf("BC - %X\n", cpu.BC);
	printf("DE - %X\n", cpu.DE);
	printf("HL - %X\n\n", cpu.HL);

	printf("SP - %X\n", cpu.stack_pointer);
	printf("PC - %X\n", cpu.program_counter);

	printf("-------------------------\n");

}

void dumpMainMemory(MMU& mmu) {

	for (int addr = 0; addr < 65535; ++addr) {
		printf("%X ", (unsigned char)mmu.readByte(addr));
		//printf("%d %X", addr, (unsigned char)mmu.readByte(addr));
	}

}