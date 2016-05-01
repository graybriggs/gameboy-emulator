
#include "cpu.h"
#include "mmu.h"
#include "opcodes.h"

#include <iostream>
#include <cmath>

CPU::CPU(MMU* m)
	: mmu(m) {

	resetCPU();

	setupOpcodes();
	setupCBOpcodes();
	resetCPU();
}

CPU::~CPU() {
}

//////////////////

void CPU::resetCPU() {

	AF = 0x01B0;
	BC = 0x0013;
	DE = 0x00D8;
	HL = 0x014D;
		
	program_counter = 0x0150;
	stack_pointer = 0xFFFE;	

	getMMU()->writeByte(0xFF05, 0x00);
	getMMU()->writeByte(0xFF06, 0x00);
	getMMU()->writeByte(0xFF07, 0x00);
	getMMU()->writeByte(0xFF10, 0x80);
	getMMU()->writeByte(0xFF11, 0xBF);
	getMMU()->writeByte(0xFF12, 0xF3);
	getMMU()->writeByte(0xFF14, 0xBF);
	getMMU()->writeByte(0xFF16, 0x3F);
	getMMU()->writeByte(0xFF17, 0x00);
	getMMU()->writeByte(0xFF19, 0xBF);
	getMMU()->writeByte(0xFF1A, 0x7F);
	getMMU()->writeByte(0xFF1B, 0xFF);
	getMMU()->writeByte(0xFF1C, 0x9F);
	getMMU()->writeByte(0xFF1E, 0xBF);

	getMMU()->writeByte(0xFF20, 0xFF);
	getMMU()->writeByte(0xFF21, 0x00);
	getMMU()->writeByte(0xFF22, 0x00);
	getMMU()->writeByte(0xFF23, 0xBF);
	getMMU()->writeByte(0xFF24, 0x77);
	getMMU()->writeByte(0xFF25, 0xF3);
	getMMU()->writeByte(0xFF26, 0xF1); // value F1 for gameboy, F0 for super gameboy 
	getMMU()->writeByte(0xFF40, 0x91);
	getMMU()->writeByte(0xFF42, 0x00); // scroll Y
	getMMU()->writeByte(0xFF44, 0x00); // scroll X
	getMMU()->writeByte(0xFF45, 0x00);
	getMMU()->writeByte(0xFF47, 0xFC);
	getMMU()->writeByte(0xFF48, 0xFF);
	getMMU()->writeByte(0xFF49, 0xFF);
	getMMU()->writeByte(0xFF4A, 0x00); // window Y
	getMMU()->writeByte(0xFF4B, 0x00); // window X
	getMMU()->writeByte(0xFFFF, 0x00); 

	disableMasterInterrupt();
}


///

void CPU::dispatcher(CPU& cpu) {

	printf("PC: %X, ", program_counter);
	BYTE instruction = getMMU()->readByte(program_counter);
	printf("INS: %X\n", instruction);
	opcodes[instruction](cpu);

	processInterrupts();
	// increment clock by instruction time?
}

void CPU::dispatcherCB(CPU& cpu) {

	printf("--> PC: %X, ", program_counter);
	BYTE instruction = getMMU()->readByte(program_counter);
	printf("CB%X \n", instruction);
	cb_opcodes[instruction](cpu);
}

//////////////////


// 8 bit read/write register AF

BYTE CPU::readRegisterA() {
	return ((AF & 0xFF00) >> 8);
}

void CPU::writeRegisterA(BYTE val) {
	AF &= 0x00FF; // clear A
	AF |= (val << 8);
}
BYTE CPU::readRegisterF() {
	return (AF & 0x00FF);
}

void CPU::writeRegisterF(BYTE val) {
	AF &= 0xFF00; // clear F
	AF |= val;
}

// 8 bit read/write register BC

BYTE CPU::readRegisterB() {
	return ((BC & 0xFF00) >> 8);
}

void CPU::writeRegisterB(BYTE val) {
	BC &= 0x00FF;
	BC |= (val << 8);
}
BYTE CPU::readRegisterC() {
	return (BC & 0x00FF);
}

void CPU::writeRegisterC(BYTE val) {
	BC &= 0xFF00;  // clear C
	BC |= val;
}

// 8 bit read/write register DE

BYTE CPU::readRegisterD() {
	return ((DE & 0xFF00) >> 8);
}

void CPU::writeRegisterD(BYTE val) {
	DE &= 0x00FF;
	DE |= (val << 8);
}
BYTE CPU::readRegisterE() {
	return (DE & 0x00FF);
}

void CPU::writeRegisterE(BYTE val) {
	DE &= 0xFF00; // clear E
	DE |= val;
}

// 8 bit read/write register HL

BYTE CPU::readRegisterH() {
	return ((HL & 0xFF00) >> 8);
}

void CPU::writeRegisterH(BYTE val) {
	HL &= 0x00FF; // clear H
	HL |= (val << 8);
}
BYTE CPU::readRegisterL() {
	return (HL & 0x00FF);
}

void CPU::writeRegisterL(BYTE val) {
	HL &= 0xFF00;
	HL |= val;
}

////////////

// 16 bit read/write register AF

WORD CPU::readRegisterAF() {
	return AF;
}

void CPU::writeRegisterAF(WORD val) {
	AF = val;
}

// 16 bit read/write register BC

WORD CPU::readRegisterBC() {
	return BC;
}

void CPU::writeRegisterBC(WORD val) {
	BC = val;
}

// 16 bit read/write register DE

WORD CPU::readRegisterDE() {
	return DE;
}

void CPU::writeRegisterDE(WORD val) {
	DE = val;
}

// 16 bit read/write register HL

WORD CPU::readRegisterHL() {
	return HL;
}

void CPU::writeRegisterHL(WORD val) {
	HL = val;
}


// read/write program counter

WORD CPU::readProgramCounter() {
	return program_counter;
}

void CPU::writeProgramCounter(WORD val) {
	program_counter = val;
}

// read/write stack pointer

WORD CPU::readStackPointer() {
	return stack_pointer;
}

void CPU::writeStackPointer(WORD val) {
	stack_pointer = val;
}

void CPU::pushStack(WORD val) {

	mmu->writeWord(stack_pointer, val);
	stack_pointer -= 2;
}

WORD CPU::popStack() {

	WORD val = mmu->readWord(stack_pointer);
	stack_pointer += 2;

	return val;
}

// MMU accessor

MMU* CPU::getMMU() {
	return mmu;
}

//////////////////
//////////////////

void CPU::setupOpcodes() {
	
	// map all opcode values to its function

	opcodes[0x06] = LD_Bn;
	opcodes[0x0E] = LD_Cn;
	opcodes[0x16] = LD_Dn;
	opcodes[0x1E] = LD_En;
	opcodes[0x26] = LD_Hn;
	opcodes[0x2E] = LD_Ln;

	opcodes[0x7F] = LD_AA;
	opcodes[0x78] = LD_AB;
	opcodes[0x79] = LD_AC;
	opcodes[0x7A] = LD_AD;
	opcodes[0x7B] = LD_AE;
	opcodes[0x7C] = LD_AH;
	opcodes[0x7D] = LD_AL;
	opcodes[0x7E] = LD_A_HL_;

	opcodes[0x40] = LD_BB;
	opcodes[0x41] = LD_BC;
	opcodes[0x42] = LD_BD;
	opcodes[0x43] = LD_BE;
	opcodes[0x44] = LD_BH;
	opcodes[0x45] = LD_BL;
	opcodes[0x46] = LD_B_HL_;

	opcodes[0x48] = LD_CB;
	opcodes[0x49] = LD_CC;
	opcodes[0x4A] = LD_CD;
	opcodes[0x4B] = LD_CE;
	opcodes[0x4C] = LD_CH;
	opcodes[0x4D] = LD_CL;
	opcodes[0x4E] = LD_C_HL_;

	opcodes[0x50] = LD_DB;
	opcodes[0x51] = LD_DC;
	opcodes[0x52] = LD_DD;
	opcodes[0x53] = LD_DE;
	opcodes[0x54] = LD_DH;
	opcodes[0x55] = LD_DL;
	opcodes[0x56] = LD_D_HL_;

	opcodes[0x58] = LD_EB;
	opcodes[0x59] = LD_EC;
	opcodes[0x5A] = LD_ED;
	opcodes[0x5B] = LD_EE;
	opcodes[0x5C] = LD_EH;
	opcodes[0x5D] = LD_EL;
	opcodes[0x5E] = LD_E_HL_;
	
	opcodes[0x60] = LD_HB;
	opcodes[0x61] = LD_HC;
	opcodes[0x62] = LD_HD;
	opcodes[0x63] = LD_HE;
	opcodes[0x64] = LD_HH;
	opcodes[0x65] = LD_HL;
	opcodes[0x66] = LD_H_HL_;

	opcodes[0x68] = LD_LB;
	opcodes[0x69] = LD_LC;
	opcodes[0x6A] = LD_LD;
	opcodes[0x6B] = LD_LE;
	opcodes[0x6C] = LD_LH;
	opcodes[0x6D] = LD_LL;
	opcodes[0x6E] = LD_L_HL_;

	opcodes[0x70] = LD_HL_B;
	opcodes[0x71] = LD_HL_C;
	opcodes[0x72] = LD_HL_D;
	opcodes[0x73] = LD_HL_E;
	opcodes[0x74] = LD_HL_H;
	opcodes[0x75] = LD_HL_L;
	opcodes[0x36] = LD_HL_n;

	opcodes[0x7F] = LD_A_A;
	opcodes[0x47] = LD_B_A;
	opcodes[0x4F] = LD_C_A;
	opcodes[0x57] = LD_D_A;
	opcodes[0x5F] = LD_E_A;
	opcodes[0x67] = LD_H_A;
	opcodes[0x6F] = LD_L_A;

	opcodes[0x02] = LD_BC_A;
	opcodes[0x12] = LD_DE_A;
	opcodes[0x77] = LD_HL_A;
	opcodes[0xEA] = LD_nn_A;
	opcodes[0xFA] = LD_A_nn;
	opcodes[0x3E] = LD_A_val;

	opcodes[0xF2] = LD_A_C_;
	opcodes[0xE2] = LD__C__A;
	opcodes[0x3A] = LD_A__HLD__;
	//opcodes[0x3A] = LD_A__HLneg__;
	//opcodes[0x3A] = LDD_A__HL__;
	opcodes[0x32] = LD__HLD__A;
	//opcodes[0x32] = LD__A_HLI_;
	opcodes[0x22] = LD__HLI_A;
	opcodes[0x2A] = LD__HLI_A;  // these are defined to be the same opcode

	opcodes[0xE0] = LDH__n_A;
	opcodes[0xF0] = LDH_A__n_;

	opcodes[0x01] = LD_BC_nn;
	opcodes[0x11] = LD_DE_nn;
	opcodes[0x21] = LD_HL_nn;
	opcodes[0x31] = LD_SP_nn;
	opcodes[0xF9] = LD_SP_HL;
	opcodes[0xF8] = LD_HL_SPn;
	opcodes[0x08] = LD__nn_SP;

	opcodes[0xF5] = PUSH_AF;
	opcodes[0xC5] = PUSH_BC;
	opcodes[0xD5] = PUSH_DE;
	opcodes[0xE5] = PUSH_HL;
	opcodes[0xF1] = POP_AF;
	opcodes[0xC1] = POP_BC;
	opcodes[0xD1] = POP_DE;
	opcodes[0xE1] = POP_HL;

	opcodes[0x87] = ADD_A_A;
	opcodes[0x80] = ADD_A_B;
	opcodes[0x81] = ADD_A_C;
	opcodes[0x82] = ADD_A_D;
	opcodes[0x83] = ADD_A_E;
	opcodes[0x84] = ADD_A_H;
	opcodes[0x85] = ADD_A_L;
	opcodes[0x86] = ADD_A_HL;
	opcodes[0xC6] = ADD_A_n;

	opcodes[0x8F] = ADC_A_A;
	opcodes[0x88] = ADC_A_B;
	opcodes[0x89] = ADC_A_C;
	opcodes[0x8A] = ADC_A_D;
	opcodes[0x8B] = ADC_A_E;
	opcodes[0x8C] = ADC_A_H;
	opcodes[0x8D] = ADC_A_L;
	opcodes[0x8E] = ADC_A_HL;
	opcodes[0xCE] = ADC_A_n;

	opcodes[0x97] = SUB_A_A;
	opcodes[0x90] = SUB_A_B;
	opcodes[0x91] = SUB_A_C;
	opcodes[0x92] = SUB_A_D;
	opcodes[0x93] = SUB_A_E;
	opcodes[0x94] = SUB_A_H;
	opcodes[0x95] = SUB_A_L;
	opcodes[0x96] = SUB_A_HL;
	opcodes[0xD6] = SUB_A_n;

	opcodes[0x9F] = SBC_A_A;
	opcodes[0x98] = SBC_A_B;
	opcodes[0x99] = SBC_A_C;
	opcodes[0x9A] = SBC_A_D;
	opcodes[0x9B] = SBC_A_E;
	opcodes[0x9C] = SBC_A_H;
	opcodes[0x9D] = SBC_A_L;
	opcodes[0x9E] = SBC_A_HL;
	//opcodes[] = SBC_A_num;
	// IMPLEMENT !!!

	opcodes[0xA7] = AND_A_A;
	opcodes[0xA0] = AND_A_B;
	opcodes[0xA1] = AND_A_C;
	opcodes[0xA2] = AND_A_D;
	opcodes[0xA3] = AND_A_E;
	opcodes[0xA4] = AND_A_H;
	opcodes[0xA5] = AND_A_L;
	opcodes[0xA6] = AND_A_HL;
	opcodes[0xE6] = AND_A_n;

	opcodes[0xB7] = OR_A_A;
	opcodes[0xB0] = OR_A_B;
	opcodes[0xB1] = OR_A_C;
	opcodes[0xB2] = OR_A_D;
	opcodes[0xB3] = OR_A_E;
	opcodes[0xB4] = OR_A_H;
	opcodes[0xB5] = OR_A_L;
	opcodes[0xB6] = OR_A_HL;
	opcodes[0xF6] = OR_A_n;

	opcodes[0xAF] = XOR_A_A;
	opcodes[0xA8] = XOR_A_B;
	opcodes[0xA9] = XOR_A_C;
	opcodes[0xAA] = XOR_A_D;
	opcodes[0xAB] = XOR_A_E;
	opcodes[0xAC] = XOR_A_H;
	opcodes[0xAD] = XOR_A_L;
	opcodes[0xAE] = XOR_A_HL;
	opcodes[0xEE] = XOR_A_n;

	opcodes[0xBF] = CP_A_A;
	opcodes[0xB8] = CP_A_B;
	opcodes[0xB9] = CP_A_C;
	opcodes[0xBA] = CP_A_D;
	opcodes[0xBB] = CP_A_E;
	opcodes[0xBC] = CP_A_H;
	opcodes[0xBD] = CP_A_L;
	opcodes[0xBE] = CP_A_HL;
	opcodes[0xFE] = CP_A_num;

	opcodes[0xC3] = INC_A;
	opcodes[0x04] = INC_B;
	opcodes[0x0C] = INC_C;
	opcodes[0x14] = INC_D;
	opcodes[0x1C] = INC_E;
	opcodes[0x24] = INC_H;
	opcodes[0x2C] = INC_L;
	opcodes[0x34] = INC__HL_;

	opcodes[0x3D] = DEC_A;
	opcodes[0x05] = DEC_B;
	opcodes[0x0D] = DEC_C;
	opcodes[0x15] = DEC_D;
	opcodes[0x1D] = DEC_E;
	opcodes[0x25] = DEC_H;
	opcodes[0x2D] = DEC_L;
	opcodes[0x35] = DEC__HL_;

	opcodes[0xC3] = JP;
	opcodes[0xE9] = JP_HL_;
	opcodes[0xDA] = JP_C;
	opcodes[0xD2] = JP_NC;
	opcodes[0xC2] = JP_NZ;
	opcodes[0xCA] = JP_Z;

	opcodes[0x18] = JR_n;
	opcodes[0x20] = JR_NZ_n;
	opcodes[0x28] = JR_Z_n;
	opcodes[0x30] = JR_NC_n;
	opcodes[0x38] = JR_C_n;

	// 16 bit arithmetic

	opcodes[0x09] = ADD_HL_BC;
	opcodes[0x19] = ADD_HL_DE;
	opcodes[0x29] = ADD_HL_HL;
	opcodes[0x39] = ADD_HL_SP;

	opcodes[0xE8] = ADD_SP_n;

	opcodes[0x03] = INC_BC;
	opcodes[0x13] = INC_DE;
	opcodes[0x23] = INC_HL;
	opcodes[0x33] = INC_SP;

	opcodes[0x0B] = DEC_BC;
	opcodes[0x1B] = DEC_DE;
	opcodes[0x2B] = DEC_HL;
	opcodes[0x3B] = DEC_SP;


	//CB prefixed (16 bit)
	opcodes[0xCB] = std::bind(&CPU::dispatcherCB, this, std::placeholders::_1);
	////


	opcodes[0xC3] = SWAP_A;
	opcodes[0x04] = SWAP_B;
	opcodes[0x0C] = SWAP_C;
	opcodes[0x14] = SWAP_D;
	opcodes[0x1C] = SWAP_E;
	opcodes[0x24] = SWAP_H;
	opcodes[0x2C] = SWAP_L;
	opcodes[0x34] = SWAP__HL_;

	opcodes[0x27] = DA_A;
	opcodes[0x2F] = CPL;
	opcodes[0x3F] = CCF;
	opcodes[0x37] = SCF;
	opcodes[0x00] = NOOP;
	opcodes[0x76] = HALT;
	opcodes[0x10] = STOP;
	opcodes[0xF3] = DI;
	opcodes[0xFB] = EI;

	opcodes[0x07] = RLCA;
	opcodes[0x17] = RLA;
	opcodes[0x0F] = RRCA;
	opcodes[0x1F] = RRA;


	opcodes[0xCD] = CALL_nn;

	opcodes[0xC4] = CALL_NZ_nn;
	opcodes[0xCC] = CALL_Z_nn;
	opcodes[0xD4] = CALL_NC_nn;
	opcodes[0xDC] = CALL_C_nn;

	opcodes[0xC7] = RST_00h;
	opcodes[0xCF] = RST_08h;
	opcodes[0xD7] = RST_10h;
	opcodes[0xDF] = RST_18h;
	opcodes[0xE7] = RST_20h;
	opcodes[0xEF] = RST_28h;
	opcodes[0xF7] = RST_30h;
	opcodes[0xFF] = RST_38h;

	opcodes[0xC9] = RET;
	opcodes[0xC0] = RET_NZ;
	opcodes[0xC8] = RET_Z;
	opcodes[0xD8] = RET_C;
	opcodes[0xD0] = RET_NC;
	opcodes[0xD9] = RETI;

	///

	opcodes[0xD3] = UNDEFINED;
	opcodes[0xDB] = UNDEFINED;
	opcodes[0xDD] = UNDEFINED;
	opcodes[0xE3] = UNDEFINED;
	opcodes[0xE4] = UNDEFINED;
	opcodes[0xEB] = UNDEFINED;
	opcodes[0xEC] = UNDEFINED;
	opcodes[0xED] = UNDEFINED;
	opcodes[0xF4] = UNDEFINED;
	opcodes[0xFC] = UNDEFINED;
	opcodes[0xFD] = UNDEFINED;
}

void CPU::setupCBOpcodes() {
	cb_opcodes[0x00] = RLC_B;
	cb_opcodes[0x01] = RLC_C;
	cb_opcodes[0x02] = RLC_D;
	cb_opcodes[0x03] = RLC_E;
	cb_opcodes[0x04] = RLC_H;
	cb_opcodes[0x05] = RLC_L;
	cb_opcodes[0x06] = RLC_HL;
	cb_opcodes[0x07] = RLC_A;

	cb_opcodes[0x08] = RRC_B;
	cb_opcodes[0x09] = RRC_C;
	cb_opcodes[0x0A] = RRC_D;
	cb_opcodes[0x0B] = RRC_E;
	cb_opcodes[0x0C] = RRC_H;
	cb_opcodes[0x0D] = RRC_L;
	cb_opcodes[0x0E] = RRC_HL;
	cb_opcodes[0x0F] = RRC_A;

	cb_opcodes[0x10] = RL_B;
	cb_opcodes[0x11] = RL_C;
	cb_opcodes[0x12] = RL_D;
	cb_opcodes[0x13] = RL_E;
	cb_opcodes[0x14] = RL_H;
	cb_opcodes[0x15] = RL_L;
	cb_opcodes[0x16] = RL_HL;
	cb_opcodes[0x17] = RL_A;

	cb_opcodes[0x18] = RR_B;
	cb_opcodes[0x19] = RR_C;
	cb_opcodes[0x1A] = RR_D;
	cb_opcodes[0x1B] = RR_E;
	cb_opcodes[0x1C] = RR_H;
	cb_opcodes[0x1D] = RR_L;
	cb_opcodes[0x1E] = RR_HL;
	cb_opcodes[0x1F] = RR_A;

	cb_opcodes[0x20] = SLA_B;
	cb_opcodes[0x21] = SLA_C;
	cb_opcodes[0x22] = SLA_D;
	cb_opcodes[0x23] = SLA_E;
	cb_opcodes[0x24] = SLA_H;
	cb_opcodes[0x25] = SLA_L;
	cb_opcodes[0x26] = SLA_HL;
	cb_opcodes[0x27] = SLA_A;

	cb_opcodes[0x28] = SRA_B;
	cb_opcodes[0x29] = SRA_C;
	cb_opcodes[0x2A] = SRA_D;
	cb_opcodes[0x2B] = SRA_E;
	cb_opcodes[0x2C] = SRA_H;
	cb_opcodes[0x2D] = SRA_L;
	cb_opcodes[0x2E] = SRA_HL;
	cb_opcodes[0x2F] = SRA_A;

	cb_opcodes[0x38] = SRL_B;
	cb_opcodes[0x39] = SRL_C;
	cb_opcodes[0x3A] = SRL_D;
	cb_opcodes[0x3B] = SRL_E;
	cb_opcodes[0x3C] = SRL_H;
	cb_opcodes[0x3D] = SRL_L;
	cb_opcodes[0x3E] = SRL_HL;
	cb_opcodes[0x3F] = SRL_A;

	//

	cb_opcodes[0x40] = BIT_0B;
	cb_opcodes[0x41] = BIT_0C;
	cb_opcodes[0x42] = BIT_0D;
	cb_opcodes[0x43] = BIT_0E;
	cb_opcodes[0x44] = BIT_0H;
	cb_opcodes[0x45] = BIT_0L;
	cb_opcodes[0x46] = BIT_0HL;
	cb_opcodes[0x47] = BIT_0A;

	cb_opcodes[0x48] = BIT_1B;
	cb_opcodes[0x49] = BIT_1C;
	cb_opcodes[0x4A] = BIT_1D;
	cb_opcodes[0x4B] = BIT_1E;
	cb_opcodes[0x4C] = BIT_1H;
	cb_opcodes[0x4D] = BIT_1L;
	cb_opcodes[0x4E] = BIT_1HL;
	cb_opcodes[0x4F] = BIT_1A;

	cb_opcodes[0x50] = BIT_2B;
	cb_opcodes[0x51] = BIT_2C;
	cb_opcodes[0x52] = BIT_2D;
	cb_opcodes[0x53] = BIT_2E;
	cb_opcodes[0x54] = BIT_2H;
	cb_opcodes[0x55] = BIT_2L;
	cb_opcodes[0x56] = BIT_2HL;
	cb_opcodes[0x57] = BIT_2A;

	cb_opcodes[0x58] = BIT_3B;
	cb_opcodes[0x59] = BIT_3C;
	cb_opcodes[0x5A] = BIT_3D;
	cb_opcodes[0x5B] = BIT_3E;
	cb_opcodes[0x5C] = BIT_3H;
	cb_opcodes[0x5D] = BIT_3L;
	cb_opcodes[0x5E] = BIT_3HL;
	cb_opcodes[0x5F] = BIT_3A;

	cb_opcodes[0x60] = BIT_4B;
	cb_opcodes[0x61] = BIT_4C;
	cb_opcodes[0x62] = BIT_4D;
	cb_opcodes[0x63] = BIT_4E;
	cb_opcodes[0x64] = BIT_4H;
	cb_opcodes[0x65] = BIT_4L;
	cb_opcodes[0x66] = BIT_4HL;
	cb_opcodes[0x67] = BIT_4A;

	cb_opcodes[0x68] = BIT_5B;
	cb_opcodes[0x69] = BIT_5C;
	cb_opcodes[0x6A] = BIT_5D;
	cb_opcodes[0x6B] = BIT_5E;
	cb_opcodes[0x6C] = BIT_5H;
	cb_opcodes[0x6D] = BIT_5L;
	cb_opcodes[0x6E] = BIT_5HL;		
	cb_opcodes[0x6F] = BIT_5A;

	cb_opcodes[0x70] = BIT_6B;
	cb_opcodes[0x71] = BIT_6C;
	cb_opcodes[0x72] = BIT_6D;
	cb_opcodes[0x73] = BIT_6E;
	cb_opcodes[0x74] = BIT_6H;
	cb_opcodes[0x75] = BIT_6L;
	cb_opcodes[0x76] = BIT_6HL;
	cb_opcodes[0x77] = BIT_6A;

	cb_opcodes[0x78] = BIT_7B;
	cb_opcodes[0x79] = BIT_7C;
	cb_opcodes[0x7A] = BIT_7D;
	cb_opcodes[0x7B] = BIT_7E;
	cb_opcodes[0x7C] = BIT_7H;
	cb_opcodes[0x7D] = BIT_7L;
	cb_opcodes[0x7E] = BIT_7HL;
	cb_opcodes[0x7F] = BIT_7A;

///

	cb_opcodes[0x80] = RES_0B;
	cb_opcodes[0x81] = RES_0C;
	cb_opcodes[0x82] = RES_0D;
	cb_opcodes[0x83] = RES_0E;
	cb_opcodes[0x84] = RES_0H;
	cb_opcodes[0x85] = RES_0L;
	cb_opcodes[0x86] = RES_0HL;
	cb_opcodes[0x87] = RES_0A;

	cb_opcodes[0x8F] = RES_1B;
	cb_opcodes[0x88] = RES_1C;
	cb_opcodes[0x89] = RES_1D;
	cb_opcodes[0x8A] = RES_1E;
	cb_opcodes[0x8B] = RES_1H;
	cb_opcodes[0x8C] = RES_1L;
	cb_opcodes[0x8D] = RES_1HL;
	cb_opcodes[0x8E] = RES_1A;

	cb_opcodes[0x90] = RES_2B;
	cb_opcodes[0x91] = RES_2C;
	cb_opcodes[0x92] = RES_2D;
	cb_opcodes[0x93] = RES_2E;
	cb_opcodes[0x94] = RES_2H;
	cb_opcodes[0x95] = RES_2L;
	cb_opcodes[0x96] = RES_2HL;
	cb_opcodes[0x97] = RES_2A;

	cb_opcodes[0x98] = RES_3B;
	cb_opcodes[0x99] = RES_3C;
	cb_opcodes[0x9A] = RES_3D;
	cb_opcodes[0x9B] = RES_3E;
	cb_opcodes[0x9C] = RES_3H;
	cb_opcodes[0x9D] = RES_3L;
	cb_opcodes[0x9E] = RES_3HL;
	cb_opcodes[0x9F] = RES_3A;

	cb_opcodes[0xA0] = RES_4B;
	cb_opcodes[0xA1] = RES_4C;
	cb_opcodes[0xA2] = RES_4D;
	cb_opcodes[0xA3] = RES_4E;
	cb_opcodes[0xA4] = RES_4H;
	cb_opcodes[0xA5] = RES_4L;
	cb_opcodes[0xA6] = RES_4HL;
	cb_opcodes[0xA7] = RES_4A;

	cb_opcodes[0xA8] = RES_5B;
	cb_opcodes[0xA9] = RES_5C;
	cb_opcodes[0xAA] = RES_5D;
	cb_opcodes[0xAB] = RES_5E;
	cb_opcodes[0xAC] = RES_5H;
	cb_opcodes[0xAD] = RES_5L;
	cb_opcodes[0xAE] = RES_5HL;
	cb_opcodes[0xAF] = RES_5A;

	cb_opcodes[0xB0] = RES_6B;
	cb_opcodes[0xB1] = RES_6C;
	cb_opcodes[0xB2] = RES_6D;
	cb_opcodes[0xB3] = RES_6E;
	cb_opcodes[0xB4] = RES_6H;
	cb_opcodes[0xB5] = RES_6L;
	cb_opcodes[0xB6] = RES_6HL;
	cb_opcodes[0xB7] = RES_6A;

	cb_opcodes[0xB8] = RES_7B;
	cb_opcodes[0xB9] = RES_7C;
	cb_opcodes[0xBA] = RES_7D;
	cb_opcodes[0xBB] = RES_7E;
	cb_opcodes[0xBC] = RES_7H;
	cb_opcodes[0xBD] = RES_7L;
	cb_opcodes[0xBE] = RES_7HL;
	cb_opcodes[0xBF] = RES_7A;


///

	cb_opcodes[0xC0] = SET_0B;
	cb_opcodes[0xC1] = SET_0C;
	cb_opcodes[0xC2] = SET_0D;
	cb_opcodes[0xC3] = SET_0E;
	cb_opcodes[0xC4] = SET_0H;
	cb_opcodes[0xC5] = SET_0L;
	cb_opcodes[0xC6] = SET_0HL;
	cb_opcodes[0xC7] = SET_0A;

	cb_opcodes[0xC8] = SET_1B;
	cb_opcodes[0xC9] = SET_1C;
	cb_opcodes[0xCA] = SET_1D;
	cb_opcodes[0xCB] = SET_1E;
	cb_opcodes[0xCC] = SET_1H;
	cb_opcodes[0xCD] = SET_1L;
	cb_opcodes[0xCE] = SET_1HL;
	cb_opcodes[0xCF] = SET_1A;

	cb_opcodes[0xD0] = SET_2B;
	cb_opcodes[0xD1] = SET_2C;
	cb_opcodes[0xD2] = SET_2D;
	cb_opcodes[0xD3] = SET_2E;
	cb_opcodes[0xD4] = SET_2H;
	cb_opcodes[0xD5] = SET_2L;
	cb_opcodes[0xD6] = SET_2HL;
	cb_opcodes[0xD7] = SET_2A;

	cb_opcodes[0xD8] = SET_3B;
	cb_opcodes[0xD9] = SET_3C;
	cb_opcodes[0xDA] = SET_3D;
	cb_opcodes[0xDB] = SET_3E;
	cb_opcodes[0xDC] = SET_3H;
	cb_opcodes[0xDD] = SET_3L;
	cb_opcodes[0xDE] = SET_3HL;
	cb_opcodes[0xDF] = SET_3A;

	cb_opcodes[0xE0] = SET_4B;
	cb_opcodes[0xE1] = SET_4C;
	cb_opcodes[0xE2] = SET_4D;
	cb_opcodes[0xE3] = SET_4E;
	cb_opcodes[0xE4] = SET_4H;
	cb_opcodes[0xE5] = SET_4L;
	cb_opcodes[0xE6] = SET_4HL;
	cb_opcodes[0xE7] = SET_4A;

	cb_opcodes[0xE8] = SET_5B;
	cb_opcodes[0xE9] = SET_5C;
	cb_opcodes[0xEA] = SET_5D;
	cb_opcodes[0xEB] = SET_5E;
	cb_opcodes[0xEC] = SET_5H;
	cb_opcodes[0xED] = SET_5L;
	cb_opcodes[0xEE] = SET_5HL;
	cb_opcodes[0xEF] = SET_5A;

	cb_opcodes[0xF0] = SET_6B;
	cb_opcodes[0xF1] = SET_6C;
	cb_opcodes[0xF2] = SET_6D;
	cb_opcodes[0xF3] = SET_6E;
	cb_opcodes[0xF4] = SET_6H;
	cb_opcodes[0xF5] = SET_6L;
	cb_opcodes[0xF6] = SET_6HL;
	cb_opcodes[0xF7] = SET_6A;

	cb_opcodes[0xF8] = SET_7B;
	cb_opcodes[0xF9] = SET_7C;
	cb_opcodes[0xFA] = SET_7D;
	cb_opcodes[0xFB] = SET_7E;
	cb_opcodes[0xFC] = SET_7H;
	cb_opcodes[0xFD] = SET_7L;
	cb_opcodes[0xFE] = SET_7HL;
	cb_opcodes[0xFF] = SET_7A;
}

// bit set / check

void CPU::setBit(BYTE byte, const BYTE bit) {

	byte |= static_cast<BYTE>(exp2(bit));
}

void CPU::unsetBit(BYTE byte, const BYTE bit) {
	byte &= ~static_cast<BYTE>(exp2(bit));
}

bool CPU::isBitSet(BYTE byte, const BYTE bit) {
	return byte & static_cast<BYTE>(exp2(bit));
}


// flags

void CPU::clearFlags() {
	AF &= 0xFF00;
}

/*
void CPU::clearFlags(BYTE flags) {
	BYTE flagRegister = readRegisterF();
	flagRegister &= ~flags;
	writeRegisterF(flagRegister);
}
*/

void CPU::clearFlagZ() {
	AF &= ~0x08;
}

void CPU::clearFlagN() {
	AF &= ~0x04;	
}

void CPU::clearFlagH() {
	AF &= ~0x02;
}

void CPU::clearFlagC() {
	AF &= ~0x01;	
}

void CPU::setFlag(enum CPU::FLAGS f) {
	AF |= f;
}

bool CPU::isFlagSet(enum CPU::FLAGS f) {
	BYTE flagReg = readRegisterF();
	return flagReg & f;
}

////
// Interrupts
////

void CPU::enableMasterInterrupt() {
	masterInterruptEnable = true;
}

void CPU::disableMasterInterrupt() {
	masterInterruptEnable = false;
}

void CPU::requestInterrupt(BYTE id) {
	BYTE req = mmu->readByte(INTERRUPT_REQUEST_REGISTER);
	setBit(req, id);
	mmu->writeByte(INTERRUPT_REQUEST_REGISTER, req);
}

void CPU::serviceInterrupt(BYTE id) {

	disableMasterInterrupt();

	BYTE req = mmu->readByte(INTERRUPT_REQUEST_REGISTER);
	unsetBit(req, id);
	mmu->writeByte(INTERRUPT_REQUEST_REGISTER, req);

	pushStack(program_counter);

	// Jump to Interrput Vector Table locations
	// IRQ highest level is 0
	printf("Servicing Interrput %d", id);
	
	switch(req) {
		case 0: program_counter = V_BLANK_INTERRUPT; break;
		case 1: program_counter = LCD_INTERRPUT; break;
		case 2: program_counter = TIMER_INTERRPUT; break;
		case 4: program_counter = JOYPAD_INTERRPUT; break;
	}
}

void CPU::processInterrupts() {

	if (masterInterruptEnable) {
		BYTE req = mmu->readByte(INTERRUPT_REQUEST_REGISTER);
		BYTE enabled = mmu->readByte(INTERRUPT_ENABLED_REGISTER);
		
		if (req > 0) {
			for (int i = 0; i < 5; ++i) {
				if (isBitSet(req, i)) {
					if (isBitSet(enabled, i))
						serviceInterrupt(i);
				}
			}
		}	
	}
}



