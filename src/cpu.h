
#ifndef CPU_H
#define CPU_H

#include <functional>
//#include <vector>
#include <map>

#include "types.h"

//

constexpr WORD INTERRUPT_REQUEST_REGISTER = 0xFF0F;
constexpr WORD INTERRUPT_ENABLED_REGISTER = 0xFFFF;

// Interrput identifiers
// Interrupt priority is in descending bit order. 0 - highest, 4 lowest

constexpr BYTE V_BLANK_INTERRUPT = 0x40;
constexpr BYTE LCD_INTERRPUT = 0x48;
constexpr BYTE TIMER_INTERRPUT = 0x50;
constexpr BYTE JOYPAD_INTERRPUT = 0x60;
//

class MMU;

// DMG cpu

class CPU {
public:

	enum FLAGS { FLAG_Z = 0x08, FLAG_N = 0x04, FLAG_H = 0x02, FLAG_C = 0x01 };

	CPU(MMU*);
	~CPU();

	void resetCPU();

	void dispatcher(CPU& cpu);
	void dispatcherCB(CPU& cpu);

	// individual register access

	BYTE readRegisterA();
	void writeRegisterA(BYTE val);
	BYTE readRegisterF();
	void writeRegisterF(BYTE val);

	BYTE readRegisterB();
	void writeRegisterB(BYTE val);
	BYTE readRegisterC();
	void writeRegisterC(BYTE val);
	
	BYTE readRegisterD();
	void writeRegisterD(BYTE val);
	BYTE readRegisterE();
	void writeRegisterE(BYTE val);
	
	BYTE readRegisterH();
	void writeRegisterH(BYTE val);
	BYTE readRegisterL();
	void writeRegisterL(BYTE val);
	
	// Full register access
	
	WORD readRegisterAF();
	void writeRegisterAF(WORD val);

	WORD readRegisterBC();
	void writeRegisterBC(WORD val);
	
	WORD readRegisterDE();
	void writeRegisterDE(WORD val);
	
	WORD readRegisterHL();
	void writeRegisterHL(WORD val);
	
	// Register F flag setting methods
	
	
	

	// Stack pointer access
	
	WORD readStackPointer();
	void writeStackPointer(WORD val);

	void pushStack(WORD val);
	WORD popStack();
	
	// program counter access
	WORD readProgramCounter();
	void writeProgramCounter(WORD val);
	
	// MMU accessor
	
	MMU* getMMU();

	void setupOpcodes();
	void setupCBOpcodes();

	// bit setting / checking

	void setBit(BYTE byte, const BYTE bit);
	void unsetBit(BYTE, const BYTE bit);
	bool isBitSet(BYTE byte, const BYTE bit);
	// flag manipulation functions

	void clearFlags();
	//void clearFlags(BYTE flags);
	void clearFlagZ();
	void clearFlagH();
	void clearFlagN();
	void clearFlagC();
	void setFlag(enum FLAGS);
	bool isFlagSet(enum FLAGS);
	///

	void enableMasterInterrupt();
	void disableMasterInterrupt();
	void requestInterrupt(BYTE id);
	void serviceInterrupt(BYTE id);
	void processInterrupts();

	int cycles;

public:
	MMU* mmu;

	//std::vector<std::function<void(CPU&)>> opcodes;
	std::map<BYTE, std::function<void(CPU&)>> opcodes;
	std::map<BYTE, std::function<void(CPU&)>> cb_opcodes;

	WORD AF;
	WORD BC;
	WORD DE;
	WORD HL;
	
	WORD program_counter;
	WORD stack_pointer;

	bool masterInterruptEnable;
};


#endif
