
#ifndef DEBUG_H
#define DEBUG_H

class CPU;
class MMU;

void dumpCPUInfo(CPU& cpu, ...);

void dumpCpuRegisters(CPU& cpu);
void dumpMainMemory(MMU& mmu);

#endif