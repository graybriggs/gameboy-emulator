
#ifndef OPCODES_H
#define OPCODES_H

#include <cstdio>

#include "cpu.h"
#include "debug.h"
#include "mmu.h"
#include "types.h"
#include "opcodes.h"

BYTE LD_reg_8bit_immediate(CPU& cpu) {
	BYTE n = cpu.getMMU()->memory[cpu.program_counter + 1];
	cpu.program_counter++;	
	return n;
}

void LD_Bn(CPU& cpu) {
	cpu.writeRegisterB(LD_reg_8bit_immediate(cpu));
	cpu.program_counter += 2;
	cpu.cycles = 8;
}

void LD_Cn(CPU& cpu) {
	cpu.writeRegisterC(LD_reg_8bit_immediate(cpu));
	cpu.program_counter += 2;
	cpu.cycles = 8;
}

void LD_Dn(CPU& cpu) {
	cpu.writeRegisterD(LD_reg_8bit_immediate(cpu));
	cpu.program_counter += 2;
	cpu.cycles = 8;
}

void LD_En(CPU& cpu) {
	cpu.writeRegisterE(LD_reg_8bit_immediate(cpu));
	cpu.program_counter += 2;
	cpu.cycles = 8;
}
	
void LD_Hn(CPU& cpu) {
	cpu.writeRegisterH(LD_reg_8bit_immediate(cpu));
	cpu.program_counter += 2;
	cpu.cycles = 8;
}

void LD_Ln(CPU& cpu) {
	cpu.writeRegisterL(LD_reg_8bit_immediate(cpu));
	cpu.program_counter += 2;
	cpu.cycles = 8;
}


/*
##
#
# 2. LD r1,r2
#
# Register A - the Accumulator
*/
void LD_AA(CPU& cpu) {
	cpu.writeRegisterA(cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_AB(CPU& cpu) {
	cpu.writeRegisterA(cpu.readRegisterB());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_AC(CPU& cpu) {
	cpu.writeRegisterA(cpu.readRegisterC());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_AD(CPU& cpu) {
	cpu.writeRegisterA(cpu.readRegisterD());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_AE(CPU& cpu) {
	cpu.writeRegisterA(cpu.readRegisterE());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_AH(CPU& cpu) {
	cpu.writeRegisterA(cpu.readRegisterH());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_AL(CPU& cpu) {
	cpu.writeRegisterA(cpu.readRegisterL());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_A_HL_(CPU& cpu) {
	cpu.writeRegisterA(cpu.getMMU()->readByte(cpu.readRegisterHL()));
	cpu.program_counter++;
	cpu.cycles = 8;
}

//

void LD_BB(CPU& cpu) {
	cpu.writeRegisterB(cpu.readRegisterB());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_BC(CPU& cpu) {
	cpu.writeRegisterB(cpu.readRegisterC());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_BD(CPU& cpu) {
	cpu.writeRegisterB(cpu.readRegisterD());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_BE(CPU& cpu) {
	cpu.writeRegisterB(cpu.readRegisterE());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_BH(CPU& cpu) {
	cpu.writeRegisterB(cpu.readRegisterH());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_BL(CPU& cpu) {
	cpu.writeRegisterB(cpu.readRegisterL());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_B_HL_(CPU& cpu) {
	cpu.writeRegisterB(cpu.getMMU()->readByte(cpu.readRegisterHL()));
	cpu.program_counter++;
	cpu.cycles = 8;
}


//##
	
void LD_CB(CPU& cpu) {
	cpu.writeRegisterC(cpu.readRegisterB());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_CC(CPU& cpu) {
	cpu.writeRegisterC(cpu.readRegisterC());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_CD(CPU& cpu) {
	cpu.writeRegisterC(cpu.readRegisterD());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_CE(CPU& cpu) {
	cpu.writeRegisterC(cpu.readRegisterE());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_CH(CPU& cpu) {
	cpu.writeRegisterC(cpu.readRegisterH());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_CL(CPU& cpu) {
	cpu.writeRegisterC(cpu.readRegisterL());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_C_HL_(CPU& cpu) {
	cpu.writeRegisterC(cpu.getMMU()->readByte(cpu.readRegisterHL()));
	cpu.program_counter++;
	cpu.cycles = 8;
}


//##
	
void LD_DB(CPU& cpu) {
	cpu.writeRegisterD(cpu.readRegisterB());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_DC(CPU& cpu) {
	cpu.writeRegisterD(cpu.readRegisterC());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_DD(CPU& cpu) {
	cpu.writeRegisterD(cpu.readRegisterD());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_DE(CPU& cpu) {
	cpu.writeRegisterD(cpu.readRegisterE());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_DH(CPU& cpu) {
	cpu.writeRegisterD(cpu.readRegisterH());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_DL(CPU& cpu) {
	cpu.writeRegisterD(cpu.readRegisterL());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_D_HL_(CPU& cpu) {
	cpu.writeRegisterD(cpu.getMMU()->readByte(cpu.readRegisterHL()));
	cpu.program_counter++;
	cpu.cycles = 8;
}


//##
	
void LD_EB(CPU& cpu) {
	cpu.writeRegisterE(cpu.readRegisterB());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_EC(CPU& cpu) {
	cpu.writeRegisterE(cpu.readRegisterC());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_ED(CPU& cpu) {
	cpu.writeRegisterE(cpu.readRegisterD());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_EE(CPU& cpu) {
	cpu.writeRegisterE(cpu.readRegisterE());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_EH(CPU& cpu) {
	cpu.writeRegisterE(cpu.readRegisterH());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_EL(CPU& cpu) {
	cpu.writeRegisterE(cpu.readRegisterL());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_E_HL_(CPU& cpu) {
	cpu.writeRegisterE(cpu.getMMU()->readByte(cpu.readRegisterHL()));
	cpu.program_counter++;
	cpu.cycles = 8;
}



//##
	
void LD_HB(CPU& cpu) {
	cpu.writeRegisterH(cpu.readRegisterB());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_HC(CPU& cpu) {
	cpu.writeRegisterH(cpu.readRegisterC());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_HD(CPU& cpu) {
	cpu.writeRegisterH(cpu.readRegisterD());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_HE(CPU& cpu) {
	cpu.writeRegisterH(cpu.readRegisterE());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_HH(CPU& cpu) {
	cpu.writeRegisterH(cpu.readRegisterH());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_HL(CPU& cpu) {
	cpu.writeRegisterH(cpu.readRegisterL());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_H_HL_(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.readRegisterHL());
	cpu.writeRegisterH(val);
	cpu.program_counter++;
	cpu.cycles = 8;
}

//##

void LD_LB(CPU& cpu) {
	cpu.writeRegisterL(cpu.readRegisterB());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_LC(CPU& cpu) {
	cpu.writeRegisterL(cpu.readRegisterC());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_LD(CPU& cpu) {
	cpu.writeRegisterL(cpu.readRegisterD());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_LE(CPU& cpu) {
	cpu.writeRegisterL(cpu.readRegisterE());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_LH(CPU& cpu) {
	cpu.writeRegisterL(cpu.readRegisterH());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_LL(CPU& cpu) {
	cpu.writeRegisterL(cpu.readRegisterL());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_L_HL_(CPU& cpu) {
	cpu.writeRegisterL(cpu.getMMU()->readByte(cpu.readRegisterHL()));
	cpu.program_counter++;
	cpu.cycles = 8;
}

//##

void LD_HL_r(CPU& cpu, BYTE val) {
	WORD addr = cpu.readRegisterHL();
	cpu.getMMU()->writeByte(addr, val);
	cpu.program_counter++;
}

void LD_HL_B(CPU& cpu) {
	LD_HL_r(cpu, cpu.readRegisterB());
	cpu.cycles = 8;
}

void LD_HL_C(CPU& cpu) {
	LD_HL_r(cpu, cpu.readRegisterC());
	cpu.cycles = 8;
}

void LD_HL_D(CPU& cpu) {
	LD_HL_r(cpu, cpu.readRegisterD());
	cpu.cycles = 8;
}

void LD_HL_E(CPU& cpu) {
	LD_HL_r(cpu, cpu.readRegisterE());
	cpu.cycles = 8;
}

void LD_HL_H(CPU& cpu) {
	LD_HL_r(cpu, cpu.readRegisterH());
	cpu.cycles = 8;
}

void LD_HL_L(CPU& cpu) {
	LD_HL_r(cpu, cpu.readRegisterL());
	cpu.cycles = 8;
}

void LD_HL_n(CPU& cpu) {
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	BYTE val = cpu.getMMU()->readByte(addr);
	LD_HL_r(cpu, val);
	cpu.program_counter += 3;
	cpu.cycles = 12;
}


//##

//# 4. LD n,A

void LD_A_A(CPU& cpu) {
	cpu.writeRegisterA(cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_B_A(CPU& cpu) {
	cpu.writeRegisterB(cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_C_A(CPU& cpu) {
	cpu.writeRegisterC(cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_D_A(CPU& cpu) {
	cpu.writeRegisterD(cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_E_A(CPU& cpu) {
	cpu.writeRegisterE(cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_H_A(CPU& cpu) {
	cpu.writeRegisterH(cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void LD_L_A(CPU& cpu) {
	cpu.writeRegisterL(cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}
	
void LD_BC_A(CPU& cpu) {
	WORD addr = cpu.readRegisterBC();
	cpu.getMMU()->writeByte(addr, cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 8;
}

void LD_DE_A(CPU& cpu) {
	WORD addr = cpu.readRegisterDE();
	cpu.getMMU()->writeByte(addr, cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 8;
}

void LD_HL_A(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	cpu.getMMU()->writeByte(addr, cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 8;
}
	
void LD_nn_A(CPU& cpu) {
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	cpu.getMMU()->writeByte(addr, cpu.readRegisterA());

	cpu.program_counter += 3;
	cpu.cycles = 16;
}

void LD_A_nn(CPU& cpu) {
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	cpu.writeRegisterA(cpu.getMMU()->readByte(addr));
	cpu.program_counter += 3;
	cpu.cycles = 16;
}

void LD_A_val(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
	cpu.writeRegisterA(val);

	cpu.program_counter += 2;
	cpu.cycles = 8;
}
	
//#################	

//# 5 LD A,(C)
//#Put value at address $FF00 + register C into A.
//# Same as: LD A,($FF00+C)

// access memory mapped i/o and and from address FF80 zram
void LD_A_C_(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(0xFF00 + cpu.readRegisterC());
	cpu.writeRegisterA(val);
	cpu.program_counter++;
	cpu.cycles = 8;
}

//###############	

//# 6 LD (C),A
//# Put A into address $FF00 + register C.
void LD__C__A(CPU& cpu) {
	BYTE val = cpu.readRegisterA();
	cpu.getMMU()->writeByte(0xFF00 + cpu.readRegisterC(), val);
	cpu.program_counter++;
	cpu.cycles = 8;
}

//###############

//# 7 LD A,(HLD)

void LD_A__HLD__(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.readRegisterHL());
	cpu.writeRegisterA(val);
	cpu.writeRegisterHL(cpu.readRegisterHL() - 1);
	cpu.program_counter++;
	cpu.cycles = 8;
}

//#8
//# LD A,(HL-)
void LD_A__HLneg__(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.readRegisterHL());
	cpu.writeRegisterA(val);
	cpu.writeRegisterHL(cpu.readRegisterHL() - 1);
	cpu.program_counter++;
	cpu.cycles = 8;
}
	
//#9
//# LDD A,(HL)
void LDD_A__HL__(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.readRegisterHL());
	cpu.writeRegisterA(val);
	WORD word_value = cpu.readRegisterHL();
	--word_value;
	cpu.writeRegisterHL(word_value);
	cpu.program_counter++;
	cpu.cycles = 8;
}

//#10
//# LD (HLD),A
void LD__HLD__A(CPU& cpu) {
	cpu.getMMU()->writeByte(cpu.readRegisterHL(), cpu.readRegisterA());
	cpu.writeRegisterHL(cpu.readRegisterHL() - 1);
	cpu.program_counter++;
	cpu.cycles = 8;
}

//#11
//#12

//#13
//# LD A,(HLI)
void LD_A_HLI_(CPU& cpu) {
	cpu.writeRegisterA(cpu.getMMU()->readByte(cpu.readRegisterHL()));
	cpu.writeRegisterHL(cpu.readRegisterHL() + 1);
	cpu.program_counter++;
	cpu.cycles = 8;
}

//#14
//#15
//#16
//# LD (HLI),A
void LD__HLI_A(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	cpu.getMMU()->writeByte(addr, cpu.readRegisterA());
	cpu.writeRegisterHL(cpu.readRegisterHL() + 1);
	cpu.program_counter++;
	cpu.cycles = 8;
}

//#17
//#18

//#19
//# LDH (n),A
void LDH__n_A(CPU& cpu) {
	BYTE value = cpu.readRegisterA();
	BYTE n = cpu.getMMU()->readByte(cpu.program_counter + 1);
	cpu.getMMU()->writeByte(0xFF00 + n, value);
	cpu.program_counter += 2;
	cpu.cycles = 12;
}

//#20
//# LDH A,(n)
void LDH_A__n_(CPU& cpu) {
	BYTE n = cpu.getMMU()->readByte(cpu.program_counter + 1); // n is specified to be one byte
	BYTE value = cpu.getMMU()->readByte(0xFF00 + n);
	cpu.writeRegisterA(value);
	cpu.program_counter += 2;
	cpu.cycles = 12;
}

//######
//## 3.3.2. -- 16 bit loads
//#####

//#1 LD n,nn
//#

WORD LD_16_nn(CPU& cpu) {
	WORD val = cpu.getMMU()->readWord(cpu.program_counter + 1);
	cpu.program_counter += 2; // read word
	return val;
}

void LD_BC_nn(CPU& cpu) {
	cpu.writeRegisterBC(LD_16_nn(cpu));
	cpu.program_counter++;
	cpu.cycles = 12;
}
	
void LD_DE_nn(CPU& cpu) {
	cpu.writeRegisterDE(LD_16_nn(cpu));
	cpu.program_counter++;
	cpu.cycles = 12;
}

void LD_HL_nn(CPU& cpu) {
	cpu.writeRegisterHL(LD_16_nn(cpu));
	cpu.program_counter++;
	cpu.cycles = 12;
}
	
void LD_SP_nn(CPU& cpu) {
	cpu.getMMU()->memory[cpu.stack_pointer] = LD_16_nn(cpu);
	cpu.program_counter++;
	cpu.cycles = 12;
}


//#2 LD SP,HL
void LD_SP_HL(CPU& cpu) {
	cpu.getMMU()->memory[cpu.stack_pointer] = cpu.readRegisterHL();
	cpu.program_counter++;
	cpu.cycles = 8;
}

//#3. LD HL,SP+n
void LD_HL_SPn(CPU& cpu) {
	BYTE sp_val = cpu.getMMU()->memory[cpu.stack_pointer];
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	BYTE n = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterHL(sp_val + n);

	// reset all flags
	cpu.clearFlags();

	cpu.program_counter += 3;
	cpu.cycles = 12;
}

//#4. LDHL SP,n

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//#5. LD (nn),SP
void LD__nn_SP(CPU& cpu) { // CHECK!!!!!!!!!!!!!!!!!!!
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	cpu.stack_pointer = addr;

	cpu.program_counter += 3;
	cpu.cycles = 20; // ?? what
}


//#6. PUSH nn

void PUSH_16bit(CPU& cpu, WORD data) {
	cpu.pushStack(data);
	cpu.program_counter++;
	cpu.cycles = 16;
}

void PUSH_AF(CPU& cpu) {
	PUSH_16bit(cpu, cpu.readRegisterAF());
}

void PUSH_BC(CPU& cpu) {
	PUSH_16bit(cpu, cpu.readRegisterBC());
}

void PUSH_DE(CPU& cpu) {
	PUSH_16bit(cpu, cpu.readRegisterDE());
}
	
void PUSH_HL(CPU& cpu) {
	PUSH_16bit(cpu, cpu.readRegisterHL());
}


//7. POP nn
// Description:
// Pop two bytes off stack into register pair nn.
// Increment Stack Pointer (SP) twice.

WORD POP_16bit(CPU& cpu) {
	cpu.program_counter++;
	cpu.cycles = 12;
	return cpu.popStack();
}

void POP_AF(CPU& cpu) {
	cpu.writeRegisterAF(POP_16bit(cpu));
}
	
void POP_BC(CPU& cpu) {
	cpu.writeRegisterBC(POP_16bit(cpu));
}

void POP_DE(CPU& cpu) {
	cpu.writeRegisterDE(POP_16bit(cpu));
}
	
void POP_HL(CPU& cpu) {
	cpu.writeRegisterHL(POP_16bit(cpu));
}


	
//########
//#3.3.3. 8-Bit ALU
//########
//Description:
// Add n to A.

BYTE ADD_r_r_8bit(CPU& cpu, BYTE r1, BYTE r2) {
	BYTE result = 0x00;
	result = r1 + r2;
	
	cpu.writeRegisterF(0x00); // clear flags

	if (r1 < 0xF && r2 < 0xF && (r1 + r2) > 0x0F)
		cpu.setFlag(CPU::FLAG_H);
	if (r1 == 0x00)
		cpu.setFlag(CPU::FLAG_Z);
	if (r1 + r2 > 255)
		cpu.setFlag(CPU::FLAG_C);

	return result;
}

void ADD_A_A(CPU& cpu) {
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADD_A_B(CPU& cpu) {
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), cpu.readRegisterC()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADD_A_C(CPU& cpu) {
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), cpu.readRegisterC()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADD_A_D(CPU& cpu) {
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), cpu.readRegisterD()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADD_A_E(CPU& cpu) {
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), cpu.readRegisterE()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADD_A_H(CPU& cpu) {
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), cpu.readRegisterH()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADD_A_L(CPU& cpu) {
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), cpu.readRegisterL()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADD_A_HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE data = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), data));
	cpu.program_counter++;
	cpu.cycles = 8;
}

void ADD_A_n(CPU& cpu) {
	BYTE data = cpu.getMMU()->readByte(cpu.program_counter + 1);
	cpu.writeRegisterA(ADD_r_r_8bit(cpu, cpu.readRegisterA(), data));
	cpu.program_counter += 2;
	cpu.cycles = 8;
}



/*	
2. ADC A,n
Description:
 Add n + Carry flag to A.
*/

BYTE ADC_r_r(CPU& cpu, BYTE reg) {

	BYTE result;

	if (cpu.AF & 0x10) {
		result = reg + 1;
		if (reg + 1 > 255)
			cpu.setFlag(CPU::FLAG_H);
		if (reg == 0)
			cpu.setFlag(CPU::FLAG_Z);
		if (reg > 127)
			cpu.setFlag(CPU::FLAG_H);
	}
	else {
		result = reg;
		if (reg + 1 > 255)
			cpu.setFlag(CPU::FLAG_H);
		if (reg == 0)
			cpu.setFlag(CPU::FLAG_Z);
		if (reg > 127)
			cpu.setFlag(CPU::FLAG_H);		
	}

	return result;
}


void ADC_A_A(CPU& cpu) {
	cpu.writeRegisterA(ADC_r_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADC_A_B(CPU& cpu) {
	cpu.writeRegisterA(ADC_r_r(cpu, cpu.readRegisterB()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADC_A_C(CPU& cpu) {
	cpu.writeRegisterA(ADC_r_r(cpu, cpu.readRegisterC()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADC_A_D(CPU& cpu) {
	cpu.writeRegisterA(ADC_r_r(cpu, cpu.readRegisterD()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADC_A_E(CPU& cpu) {
	cpu.writeRegisterA(ADC_r_r(cpu, cpu.readRegisterE()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADC_A_H(CPU& cpu) {
	cpu.writeRegisterA(ADC_r_r(cpu, cpu.readRegisterH()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void ADC_A_L(CPU& cpu) {
	cpu.writeRegisterA(ADC_r_r(cpu, cpu.readRegisterL()));
	cpu.program_counter++;
	cpu.cycles = 4;
}


void ADC_A_HL(CPU& cpu) {
	BYTE addr = cpu.readRegisterHL(); 
	BYTE val = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(ADC_r_r(cpu, val));
	cpu.program_counter++;
	cpu.cycles = 8;
}

void ADC_A_n(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
	cpu.writeRegisterA(ADC_r_r(cpu, val));
	cpu.program_counter += 2;
	cpu.cycles = 8;
}

/*
3. SUB n
Description:
 Subtract n from A.
*/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// H flag not completed

// if (post_op_reg < 0) cpu.setFlag(CPU::FLAG_C); // CHECK THIS for all SUB operations

BYTE SUB_r_r(CPU& cpu, BYTE r1, BYTE r2) {
	BYTE result = r1 - r2;

	if (result == 0)
		cpu.setFlag(CPU::FLAG_Z);
	if (r1 > 0x7 && r2 >= 0x8)
		cpu.setFlag(CPU::FLAG_N); // set H flag if borrow
	else
		cpu.setFlag(CPU::FLAG_C);

	cpu.setFlag(CPU::FLAG_N);

	return result;
}

void SUB_A_A(CPU& cpu) {
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void SUB_A_B(CPU& cpu) {
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterB()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void SUB_A_C(CPU& cpu) {
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterC()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void SUB_A_D(CPU& cpu) {
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterD()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void SUB_A_E(CPU& cpu) {
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterE()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void SUB_A_H(CPU& cpu) {
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterH()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void SUB_A_L(CPU& cpu) {
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterL()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void SUB_A_HL(CPU& cpu) {
	BYTE addr = cpu.readRegisterHL();
	BYTE data = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), data));
	cpu.program_counter++;
	cpu.cycles = 8;

}

void SUB_A_n(CPU& cpu) {
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	BYTE data = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(SUB_r_r(cpu, cpu.readRegisterA(), data));
	cpu.program_counter += 3;
	cpu.cycles = 8;
}


/*
4. SBC A,n
Description:
 Subtract n + Carry flag from A.
*/

BYTE SBC_r_r(CPU& cpu, BYTE r1, BYTE r2) {
	BYTE result = r1;

	if (cpu.AF & 0x20) {
		result -= (r2 + 1);
		cpu.clearFlags();
	}
	else {
		cpu.clearFlags();
		result -= r2;
		cpu.AF |= 0x30; // there hasn't been a borrow - set H flag and C flag
	}
	if (result == 0)
		cpu.setFlag(CPU::FLAG_Z);

	cpu.setFlag(CPU::FLAG_N);
	// borrow flag???

	return result;
}

void SBC_A_A(CPU& cpu) {
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void SBC_A_B(CPU& cpu) {
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterB()));
	cpu.program_counter++;
	cpu.cycles = 4;
}
void SBC_A_C(CPU& cpu) {
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterC()));
	cpu.program_counter++;
	cpu.cycles = 4;
}
void SBC_A_D(CPU& cpu) {
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterD()));
	cpu.program_counter++;
	cpu.cycles = 4;
}
void SBC_A_E(CPU& cpu) {
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterE()));
	cpu.program_counter++;
	cpu.cycles = 4;
}
void SBC_A_F(CPU& cpu) {
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterF()));
	cpu.program_counter++;
	cpu.cycles = 4;
}
void SBC_A_H(CPU& cpu) {
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterH()));
	cpu.program_counter++;
	cpu.cycles = 4;
}
void SBC_A_L(CPU& cpu) {
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterL()));
	cpu.program_counter++;
	cpu.cycles = 4;
}
void SBC_A_HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	cpu.getMMU()->writeByte(addr, (SBC_r_r(cpu, cpu.readRegisterA(), cpu.getMMU()->readByte(addr))));
	cpu.program_counter++;
	cpu.cycles = 8;
}
void SBC_A_num(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
	cpu.writeRegisterA(SBC_r_r(cpu, cpu.readRegisterA(), val));
	cpu.program_counter += 2;
	cpu.cycles = 12;
}


/*
5. AND n
Description:
 Logically AND n with A, result in A.
Use with:
 n = A,B,C,D,E,H,L,(HL),#
Flags affected:
 Z - Set if result is zero.
 N - Reset.
 H - Set.
 C - Reset.
*/

BYTE AND_r_r(CPU& cpu, BYTE r1, BYTE r2) {
	BYTE result = r1 & r2;
	cpu.clearFlags();
	if (cpu.readRegisterA() == 0)
		cpu.setFlag(CPU::FLAG_Z);
	
	cpu.setFlag(CPU::FLAG_H); // set H flag
	return result;
}


void AND_A_A(CPU& cpu) {
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void AND_A_B(CPU& cpu) {
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void AND_A_C(CPU& cpu) {
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void AND_A_D(CPU& cpu) {
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void AND_A_E(CPU& cpu) {
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void AND_A_H(CPU& cpu) {
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void AND_A_L(CPU& cpu) {
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void AND_A_HL(CPU& cpu) {
	BYTE addr = cpu.readRegisterHL();
	BYTE val = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), val));
	cpu.program_counter++;
	cpu.cycles = 8;
}

void AND_A_n(CPU& cpu) {
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	BYTE val = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(AND_r_r(cpu, cpu.readRegisterA(), val));
	cpu.cycles = 4;
	cpu.program_counter += 3;
	cpu.cycles = 8;
}



/*
6. OR n
Description:
 Logical OR n with register A, result in A
*/

BYTE OR_r_r(CPU& cpu, BYTE r1, BYTE r2) {
	BYTE result = r1 | r2;	
	cpu.clearFlags();
	if (cpu.readRegisterA() == 0)
		cpu.setFlag(CPU::FLAG_Z);

	return result;
}

void OR_A_A(CPU& cpu) {
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void OR_A_B(CPU& cpu) {
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));	
	cpu.program_counter++;
	cpu.cycles = 4;
}

void OR_A_C(CPU& cpu) {
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));	
	cpu.program_counter++;
	cpu.cycles = 4;
}

void OR_A_D(CPU& cpu) {
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));	
	cpu.program_counter++;
	cpu.cycles = 4;
}

void OR_A_E(CPU& cpu) {
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));	
	cpu.program_counter++;
	cpu.cycles = 4;
}

void OR_A_H(CPU& cpu) {
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));	
	cpu.program_counter++;
	cpu.cycles = 4;
}

void OR_A_L(CPU& cpu) {
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));	
	cpu.program_counter++;
	cpu.cycles = 4;
}

void OR_A_HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE val = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), val));	
	cpu.program_counter++;
	cpu.cycles = 8;
}

void OR_A_n(CPU& cpu) {
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	BYTE val = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(OR_r_r(cpu, cpu.readRegisterA(), val));	
	cpu.program_counter += 3;
	cpu.cycles = 8;
}


/*
7. XOR n
Description:
 Logical exclusive OR n with register A, result in A.
*/

BYTE XOR_r_r(CPU& cpu, BYTE r1, BYTE r2) {
	BYTE result = r1 ^ r2;
	cpu.clearFlags();

	if (cpu.readRegisterA() == 0)
		cpu.setFlag(CPU::FLAG_Z);

	return result;
}

void XOR_A_A(CPU& cpu) {
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void XOR_A_B(CPU& cpu) {
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterB()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void XOR_A_C(CPU& cpu) {
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterC()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void XOR_A_D(CPU& cpu) {
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterD()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void XOR_A_E(CPU& cpu) {
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterE()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void XOR_A_H(CPU& cpu) {
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterH()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void XOR_A_L(CPU& cpu) {
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterL()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void XOR_A_HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE val = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), val));
	cpu.program_counter++;
	cpu.cycles = 8;
}

void XOR_A_n(CPU& cpu) {
	WORD addr = cpu.getMMU()->readWord(cpu.program_counter + 1);
	BYTE val = cpu.getMMU()->readByte(addr);
	cpu.writeRegisterA(XOR_r_r(cpu, cpu.readRegisterA(), val));
	cpu.program_counter += 3;
	cpu.cycles = 8;
}

/*
8. CP n
Description:
 Compare A with n. This is basically an A - n
 subtraction instruction but the results are thrown
 away.
*/

void CP_r_r(CPU& cpu, BYTE r1, BYTE r2) {
	BYTE result = r2 - r1;

	if (result == 0)
		cpu.setFlag(CPU::FLAG_Z);

	// set C for no borrow (if A < n)
	if (r1 < r2)
		cpu.setFlag(CPU::FLAG_C);

	if ((r2 & 0x0F) > (r1 & 0x0F))
		cpu.setFlag(CPU::FLAG_H);

	cpu.setFlag(CPU::FLAG_N); // always set
}

void CP_A_A(CPU& cpu) {
	CP_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterA());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void CP_A_B(CPU& cpu) {
	CP_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterB());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void CP_A_C(CPU& cpu) {
	CP_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterC());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void CP_A_D(CPU& cpu) {
	CP_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterD());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void CP_A_E(CPU& cpu) {
	CP_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterE());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void CP_A_H(CPU& cpu) {
	CP_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterH());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void CP_A_L(CPU& cpu) {
	CP_r_r(cpu, cpu.readRegisterA(), cpu.readRegisterL());
	cpu.program_counter++;
	cpu.cycles = 4;
}

void CP_A_HL(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.readRegisterHL());
	CP_r_r(cpu, cpu.readRegisterA(), val);
	cpu.program_counter++;
	cpu.cycles = 8;
}

void CP_A_num(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
	CP_r_r(cpu, cpu.readRegisterA(), val);
	cpu.program_counter += 2;
	cpu.cycles = 8;	
}

/*
9. INC n
Description:
Increment register n.
Use with:
n = A,B,C,D,E,H,L,(HL)
Flags affected:
Z - Set if result is zero.
N - Reset.
H - Set if carry from bit 3.
C - Not affected.
*/

BYTE INC_r(CPU& cpu, BYTE reg) {
	BYTE val = reg + 1;

	cpu.clearFlags();
	if (val == 0)
		cpu.setFlag(CPU::FLAG_Z);
	if (reg <= 0xF && (reg + 1) > 0xF)
		cpu.setFlag(CPU::FLAG_H);

	return val;
}

void INC_A(CPU& cpu) {
	cpu.writeRegisterA(INC_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void INC_B(CPU& cpu) {
	cpu.writeRegisterA(INC_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void INC_C(CPU& cpu) {
	cpu.writeRegisterA(INC_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void INC_D(CPU& cpu) {
	cpu.writeRegisterA(INC_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void INC_E(CPU& cpu) {
	cpu.writeRegisterA(INC_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void INC_H(CPU& cpu) {
	cpu.writeRegisterA(INC_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void INC_L(CPU& cpu) {
	cpu.writeRegisterA(INC_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void INC__HL_(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, INC_r(cpu, reg));
	cpu.program_counter++;
	cpu.cycles = 12;
}

//////////////

BYTE DEC_r(CPU& cpu, BYTE reg) {
	if (!(reg > 15))
		cpu.setFlag(CPU::FLAG_H); // set if no borrow from bit 4

	--reg;

	if (reg == 0)
		cpu.setFlag(CPU::FLAG_Z);

	cpu.setFlag(CPU::FLAG_N);
	return reg;	
}

void DEC_A(CPU& cpu) {
	cpu.writeRegisterA(DEC_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void DEC_B(CPU& cpu) {
	cpu.writeRegisterB(DEC_r(cpu, cpu.readRegisterB()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void DEC_C(CPU& cpu) {

	//printf("")

	cpu.writeRegisterC(DEC_r(cpu, cpu.readRegisterC()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void DEC_D(CPU& cpu) {
	cpu.writeRegisterD(DEC_r(cpu, cpu.readRegisterD()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void DEC_E(CPU& cpu) {
	cpu.writeRegisterE(DEC_r(cpu, cpu.readRegisterE()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void DEC_H(CPU& cpu) {
	cpu.writeRegisterH(DEC_r(cpu, cpu.readRegisterH()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void DEC_L(CPU& cpu) {
	cpu.writeRegisterL(DEC_r(cpu, cpu.readRegisterL()));
	cpu.program_counter++;
	cpu.cycles = 4;
}

void DEC__HL_(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, DEC_r(cpu, reg));
	cpu.program_counter++;
	cpu.cycles = 12;
}

//////////

void JP(CPU& cpu) {
	cpu.program_counter = cpu.getMMU()->readWord(cpu.program_counter + 1);
	cpu.cycles = 12;
}

void JP_HL_(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	cpu.program_counter = addr;

	cpu.cycles = 4;
}

void JP_C(CPU& cpu) {

	if (cpu.isFlagSet(CPU::FLAG_C)) {
		cpu.program_counter = cpu.getMMU()->readWord(cpu.program_counter + 1);
	}
	else {
		cpu.program_counter += 3;
	}
	cpu.cycles = 8;
}

void JP_NC(CPU& cpu) {
	if (!cpu.isFlagSet(CPU::FLAG_C)) {
		cpu.program_counter = cpu.getMMU()->readWord(cpu.program_counter + 1);
	}
	else {
		cpu.program_counter += 3;
	}
	cpu.cycles = 8;
}

void JP_NZ(CPU& cpu) {
	if (!cpu.isFlagSet(CPU::FLAG_Z)) {
		cpu.program_counter = cpu.getMMU()->readWord(cpu.program_counter + 1);
	}
	else {
		cpu.program_counter += 3;
		cpu.cycles = 8;
	}
}

void JP_Z(CPU& cpu) {
	if (cpu.isFlagSet(CPU::FLAG_Z)) {
		cpu.program_counter = cpu.getMMU()->readWord(cpu.program_counter + 1);
	}
	else {
		cpu.program_counter += 3;
		cpu.cycles = 8;
	}
}

/////


void JR_n(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
	cpu.program_counter += val;
	cpu.cycles = 8;
}

void JR_NZ_n(CPU& cpu) {

	if (!(cpu.readRegisterF() & 0xF0)) {
		BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
		cpu.program_counter += val;
	}
	else {
		cpu.program_counter += 2;
	}
	cpu.cycles = 8;

}

void JR_Z_n(CPU& cpu) {
	if (cpu.readRegisterF() & 0xF0) {
		BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
		cpu.program_counter += val;
	}
	else {
		cpu.program_counter += 2;
	}
	cpu.cycles = 8;
}

void JR_NC_n(CPU& cpu) {
	if (!(cpu.readRegisterF() & 0x10)) {
		BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
		cpu.program_counter += val;
	}
	else {
		cpu.program_counter += 2;
	}
	cpu.cycles = 8;
}

void JR_C_n(CPU& cpu) {
	if (cpu.readRegisterF() & 0x10) {
		BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
		cpu.program_counter += val;
	}
	else {
		cpu.program_counter += 2;
	}
	cpu.cycles = 8;
}


/*

3.3.4. 16-Bit Arithmetic
1. ADD HL,n
Description:
Add n to HL.
Use with:
n = BC,DE,HL,SP
Flags affected:
Z - Not affected.
N - Reset.
H - Set if carry from bit 11.
C - Set if carry from bit 15.

*/

WORD ADD_r_r_16bit(CPU& cpu, WORD r1, WORD r2) {
	WORD result = r1 + r2;
	//void clearFlags(CPU::FLAG_N | CPU::FLAG_H | CPU::FLAG_C); // flag Z is unaffected
	cpu.clearFlagN();
	cpu.clearFlagH();
	cpu.clearFlagC();

	if (r1 < 0xFFF && r2 < 0xFFF && (r1 + r2) > 0xFFF)
		cpu.setFlag(CPU::FLAG_H);
	if ((r1 + r2) > 0xFFFF)
		cpu.setFlag(CPU::FLAG_C);

	return result;
}

void ADD_HL_BC(CPU& cpu) {
	cpu.writeRegisterHL(ADD_r_r_16bit(cpu, cpu.readRegisterHL(), cpu.readRegisterBC()));
	cpu.program_counter++;
	cpu.program_counter = 8;
}

void ADD_HL_DE(CPU& cpu) {
cpu.writeRegisterHL(ADD_r_r_16bit(cpu, cpu.readRegisterHL(), cpu.readRegisterDE()));
	cpu.program_counter++;
	cpu.program_counter = 8;
}

void ADD_HL_HL(CPU& cpu) {
	cpu.writeRegisterHL(ADD_r_r_16bit(cpu, cpu.readRegisterHL(), cpu.readRegisterHL()));
	cpu.program_counter++;
	cpu.program_counter = 8;
}


void ADD_HL_SP(CPU& cpu) {
cpu.writeRegisterHL(ADD_r_r_16bit(cpu, cpu.readRegisterHL(), cpu.readStackPointer()));
	cpu.program_counter++;
	cpu.program_counter = 8;
}


/// ??? check!
void ADD_SP_n(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.program_counter + 1);
	BYTE sp_val = cpu.getMMU()->readByte(cpu.stack_pointer);
	sp_val += val;

	cpu.clearFlags();

	cpu.getMMU()->writeByte(cpu.stack_pointer, sp_val);

	cpu.program_counter += 2;
	cpu.cycles = 16;
}


void INC_BC(CPU& cpu) {
	WORD reg = cpu.readRegisterBC();
	++reg;
	cpu.writeRegisterBC(reg);
	cpu.program_counter++;
	cpu.cycles = 8;
}

void INC_DE(CPU& cpu) {

	WORD reg = cpu.readRegisterDE();
	++reg;
	cpu.writeRegisterDE(reg);
	cpu.program_counter++;
	cpu.cycles = 8;
}

void INC_HL(CPU& cpu) {
	WORD reg = cpu.readRegisterHL();
	++reg;
	cpu.writeRegisterHL(reg);
	cpu.program_counter++;
	cpu.cycles = 8;
}

void INC_SP(CPU& cpu) {
	WORD sp = cpu.readStackPointer();
	++sp;
	cpu.writeRegisterBC(sp);
	cpu.program_counter++;
	cpu.cycles = 8;
}

/////

void DEC_BC(CPU& cpu) {
	cpu.writeRegisterBC(cpu.readRegisterBC() - 1);
	cpu.program_counter++;
}

void DEC_DE(CPU& cpu) {
	cpu.writeRegisterDE(cpu.readRegisterDE() - 1);
	cpu.program_counter++;
}

void DEC_HL(CPU& cpu) {
	cpu.writeRegisterHL(cpu.readRegisterHL() - 1);
	cpu.program_counter++;
}

void DEC_SP(CPU& cpu) {
	--(cpu.stack_pointer);
	cpu.program_counter++;
}

//////

void NOOP(CPU& cpu) {

	cpu.cycles = 4;
	cpu.program_counter++;
}

/*

3.3.5 Misc. 

Swap nibbles in the register specified

*/

BYTE SWAP_r(CPU& cpu, BYTE reg) {
	BYTE high = reg & 0xF0;
	BYTE low = reg & 0xF;

	reg = 0x00;
	reg |= (low << 4);
	reg |= (high >> 4);

	return reg;
}

void SWAP_A(CPU& cpu) {
	cpu.writeRegisterA(SWAP_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
}

void SWAP_B(CPU& cpu) {
	cpu.writeRegisterA(SWAP_r(cpu, cpu.readRegisterB()));
	cpu.program_counter++;
}

void SWAP_C(CPU& cpu) {
	cpu.writeRegisterA(SWAP_r(cpu, cpu.readRegisterC()));
	cpu.program_counter++;
}

void SWAP_D(CPU& cpu) {
	cpu.writeRegisterA(SWAP_r(cpu, cpu.readRegisterD()));	
	cpu.program_counter++;
}

void SWAP_E(CPU& cpu) {
	cpu.writeRegisterA(SWAP_r(cpu, cpu.readRegisterE()));	
	cpu.program_counter++;
}

void SWAP_H(CPU& cpu) {
	cpu.writeRegisterA(SWAP_r(cpu, cpu.readRegisterH()));	
	cpu.program_counter++;
}

void SWAP_L(CPU& cpu) {
	cpu.writeRegisterA(SWAP_r(cpu, cpu.readRegisterL()));
	cpu.program_counter++;
}

void SWAP__HL_(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.mmu->readByte(addr);
	cpu.writeRegisterA(SWAP_r(cpu, reg));
	cpu.program_counter++;
}

void DA_A(CPU& cpu) {

	cpu.program_counter++;
}

void CPL(CPU& cpu) {
	cpu.setFlag(CPU::FLAG_N);
	cpu.setFlag(CPU::FLAG_H);
	BYTE reg = cpu.readRegisterA();
	reg = ~reg;
	cpu.writeRegisterA(reg);
	cpu.program_counter++;
	cpu.cycles = 4;
}

void CCF(CPU& cpu) {
	cpu.clearFlagN();
	cpu.clearFlagH();
	if (cpu.readRegisterF() & 0x10)
		cpu.clearFlagC();
	else
		cpu.setFlag(CPU::FLAG_C);

	cpu.program_counter++;
	cpu.cycles = 4;
}

void SCF(CPU& cpu) {
	cpu.clearFlagN();
	cpu.clearFlagH();
	cpu.setFlag(CPU::FLAG_C);
	cpu.program_counter++;
	cpu.cycles = 4;
}


void HALT(CPU& cpu) {
	// ??
	//cpu.program_counter++;
}

void STOP(CPU& cpu) {

}

void DI(CPU& cpu) {

	// Interrputs are disabled after the instruction after DI is executed
	BYTE ins = cpu.getMMU()->readByte(cpu.program_counter + 1);
	cpu.opcodes[ins](cpu);
	cpu.disableMasterInterrupt();
	cpu.cycles = 4;
}

void EI(CPU& cpu) {

	// Interrupts are enabled after the instruction after EI is executed.
	BYTE ins = cpu.getMMU()->readByte(cpu.program_counter + 1);
	cpu.opcodes[ins](cpu);
	cpu.enableMasterInterrupt();
	cpu.cycles = 4;
}

///
// Rotate and shift etc.
///

// helpers
BYTE RLC_r(CPU& cpu, BYTE reg) {
	cpu.clearFlags();
	BYTE data = reg;
	if (data & 0x80)
		cpu.setFlag(CPU::FLAG_C);

	data = (data << 1);

	if (data == 0)
		cpu.setFlag(CPU::FLAG_Z);

	cpu.program_counter++;
	cpu.cycles = 4;

	return data;
}

BYTE RRC_r(CPU& cpu, BYTE reg) {
	cpu.clearFlags();
	BYTE data = reg;
	if (data & 0x01)
		cpu.setFlag(CPU::FLAG_C);

	data = (data >> 1);

	if (data == 0)
		cpu.setFlag(CPU::FLAG_Z);

	cpu.program_counter++;
	cpu.cycles = 4;

	return data;
}

BYTE RL_r(CPU& cpu, BYTE reg) {
	BYTE data = reg;
	BYTE flags = cpu.readRegisterF();

	cpu.clearFlags();

	if (data & 0x08)
		cpu.setFlag(CPU::FLAG_C);

	data = (data << 1);

	if (flags & 0x01)
		data |= 0x01;

	if (data == 0)
		cpu.setFlag(CPU::FLAG_Z);

	cpu.program_counter++;
	cpu.cycles = 4;

	return data;
}

BYTE RR_r(CPU& cpu, BYTE reg) {
	BYTE data = reg;
	BYTE flags = cpu.readRegisterF();

	cpu.clearFlags();

	if (data & 0x01)
		cpu.setFlag(CPU::FLAG_C);

	data = (data >> 1);

	if (flags & 0x01)
		data |= 0x01;

	if (data == 0)
		cpu.setFlag(CPU::FLAG_Z);

	cpu.program_counter++;
	cpu.cycles = 4;
	return data;
}

/////

void RLCA(CPU& cpu) {
	cpu.writeRegisterA(RLC_r(cpu, cpu.readRegisterA()));
}

void RLA(CPU& cpu) {
	cpu.writeRegisterA(RL_r(cpu, cpu.readRegisterA()));
}

void RRCA(CPU& cpu) {
	cpu.writeRegisterA(RRC_r(cpu, cpu.readRegisterA()));
}

void RRA(CPU& cpu) {
	cpu.writeRegisterA(RR_r(cpu, cpu.readRegisterA()));
}

///////////////


void RLC_A(CPU& cpu) {
	cpu.writeRegisterA(RLC_r(cpu, cpu.readRegisterA()));
}
void RLC_B(CPU& cpu) {
	cpu.writeRegisterB(RLC_r(cpu, cpu.readRegisterB()));
}
void RLC_C(CPU& cpu) {
	cpu.writeRegisterC(RLC_r(cpu, cpu.readRegisterC()));
}
void RLC_D(CPU& cpu) {
	cpu.writeRegisterD(RLC_r(cpu, cpu.readRegisterD()));
}
void RLC_E(CPU& cpu) {
	cpu.writeRegisterE(RLC_r(cpu, cpu.readRegisterE()));
}
void RLC_H(CPU& cpu) {
	cpu.writeRegisterH(RLC_r(cpu, cpu.readRegisterH()));
}
void RLC_L(CPU& cpu) {
	cpu.writeRegisterL(RLC_r(cpu, cpu.readRegisterL()));
}
void RLC_HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	cpu.getMMU()->writeByte(addr, RLC_r(cpu, cpu.getMMU()->readByte(addr)));
}

void RL_A(CPU& cpu) {
	cpu.writeRegisterA(RL_r(cpu, cpu.readRegisterA()));
}
void RL_B(CPU& cpu) {
	cpu.writeRegisterB(RL_r(cpu, cpu.readRegisterB()));
}
void RL_C(CPU& cpu){
	cpu.writeRegisterC(RL_r(cpu, cpu.readRegisterC()));
}
void RL_D(CPU& cpu) {
	cpu.writeRegisterD(RL_r(cpu, cpu.readRegisterD()));
}
void RL_E(CPU& cpu) {
	cpu.writeRegisterE(RL_r(cpu, cpu.readRegisterE()));
}
void RL_H(CPU& cpu) {
	cpu.writeRegisterH(RL_r(cpu, cpu.readRegisterH()));
}
void RL_L(CPU& cpu) {
	cpu.writeRegisterL(RL_r(cpu, cpu.readRegisterL()));
}
void RL_HL(CPU& cpu) {
	WORD addr = cpu.getMMU()->readByte(cpu.readRegisterHL());
	cpu.getMMU()->writeByte(addr, RL_r(cpu, cpu.getMMU()->readByte(addr)));
}

void RRC_A(CPU& cpu) {
	cpu.writeRegisterA(RRC_r(cpu, cpu.readRegisterA()));
}
void RRC_B(CPU& cpu) {
	cpu.writeRegisterB(RRC_r(cpu, cpu.readRegisterB()));
}
void RRC_C(CPU& cpu) {
	cpu.writeRegisterC(RRC_r(cpu, cpu.readRegisterC()));
}
void RRC_D(CPU& cpu) {
	cpu.writeRegisterD(RRC_r(cpu, cpu.readRegisterD()));
}
void RRC_E(CPU& cpu) {
	cpu.writeRegisterE(RRC_r(cpu, cpu.readRegisterE()));
}
void RRC_H(CPU& cpu) {
	cpu.writeRegisterH(RRC_r(cpu, cpu.readRegisterH()));
}
void RRC_L(CPU& cpu) {
	cpu.writeRegisterL(RRC_r(cpu, cpu.readRegisterL()));
}
void RRC_HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	cpu.getMMU()->writeByte(addr, RRC_r(cpu, cpu.getMMU()->readByte(addr)));
}

void RR_A(CPU& cpu) {
	cpu.writeRegisterA(RR_r(cpu, cpu.readRegisterA()));
}
void RR_B(CPU& cpu) {
	cpu.writeRegisterB(RR_r(cpu, cpu.readRegisterB()));
}
void RR_C(CPU& cpu) {
	cpu.writeRegisterC(RR_r(cpu, cpu.readRegisterC()));
}
void RR_D(CPU& cpu) {
	cpu.writeRegisterD(RR_r(cpu, cpu.readRegisterD()));
}
void RR_E(CPU& cpu) {
	cpu.writeRegisterE(RR_r(cpu, cpu.readRegisterE()));
}
void RR_H(CPU& cpu) {
	cpu.writeRegisterH(RR_r(cpu, cpu.readRegisterH()));
}
void RR_L(CPU& cpu) {
	cpu.writeRegisterL(RR_r(cpu, cpu.readRegisterL()));
}
void RR_HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	cpu.getMMU()->writeByte(addr, (RR_r(cpu, cpu.getMMU()->readByte(addr))));
}

BYTE SLA_r(CPU& cpu, BYTE reg) {
	BYTE data = cpu.readRegisterA();

	cpu.clearFlags();

	if (data & 0x80)
		cpu.setFlag(CPU::FLAG_C);

	data = (data << 1);

	if (data == 0)
		cpu.setFlag(CPU::FLAG_Z);

	return data;
}

void SLA_A(CPU& cpu) {
 	cpu.writeRegisterA(SLA_r(cpu, cpu.readRegisterA()));	
 	cpu.program_counter++;
 	cpu.cycles = 8;
}
void SLA_B(CPU& cpu) {
	cpu.writeRegisterB(SLA_r(cpu, cpu.readRegisterB()));
	cpu.program_counter++;
 	cpu.cycles = 8;
}
void SLA_C(CPU& cpu) {
	cpu.writeRegisterC(SLA_r(cpu, cpu.readRegisterC()));
	cpu.program_counter++;
 	cpu.cycles = 8;
}
void SLA_D(CPU& cpu) {
	cpu.writeRegisterD(SLA_r(cpu, cpu.readRegisterD()));
	cpu.program_counter++;
 	cpu.cycles = 8;
}
void SLA_E(CPU& cpu) {
	cpu.writeRegisterE(SLA_r(cpu, cpu.readRegisterE()));
	cpu.program_counter++;
 	cpu.cycles = 8;
}
void SLA_H(CPU& cpu) {
	cpu.writeRegisterH(SLA_r(cpu, cpu.readRegisterH()));
 	cpu.program_counter++;
 	cpu.cycles = 8;
}
void SLA_L(CPU& cpu) {
	cpu.writeRegisterL(SLA_r(cpu, cpu.readRegisterL()));
	cpu.program_counter++;
 	cpu.cycles = 8;
}
void SLA_HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	cpu.getMMU()->writeByte(addr, SLA_r(cpu, cpu.getMMU()->readByte(addr)));
	cpu.program_counter++;
 	cpu.cycles = 16;
}

//////

BYTE SRA_r(CPU& cpu, BYTE reg) {
	BYTE data = cpu.readRegisterA();

	// retain bit 7 state
	bool bit7 = (data & 0x80) ? true : false;

	cpu.clearFlags();

	if (data & 0x10)
		cpu.setFlag(CPU::FLAG_C);

	data = (data >> 1);

	if (bit7)
		data |= 0x80;

	if (data == 0)
		cpu.setFlag(CPU::FLAG_Z);

	return data;
}

void SRA_A(CPU& cpu) {
	cpu.writeRegisterA(SRA_r(cpu, cpu.readRegisterA()));
	cpu.program_counter++;
	cpu.cycles = 8;
}
void SRA_B(CPU& cpu) {
	cpu.writeRegisterB(SRA_r(cpu, cpu.readRegisterB()));
	cpu.program_counter++;
	cpu.cycles = 8;
}
void SRA_C(CPU& cpu) {
	cpu.writeRegisterC(SRA_r(cpu, cpu.readRegisterC()));
	cpu.program_counter++;
	cpu.cycles = 8;
}
void SRA_D(CPU& cpu) {
	cpu.writeRegisterD(SRA_r(cpu, cpu.readRegisterD()));
	cpu.program_counter++;
	cpu.cycles = 8;
}
void SRA_E(CPU& cpu) {
	cpu.writeRegisterE(SRA_r(cpu, cpu.readRegisterE()));
	cpu.program_counter++;
	cpu.cycles = 8;
}
void SRA_H(CPU& cpu) {
	cpu.writeRegisterH(SRA_r(cpu, cpu.readRegisterH()));
	cpu.program_counter++;
	cpu.cycles = 8;
}
void SRA_L(CPU& cpu) {
	cpu.writeRegisterL(SRA_r(cpu, cpu.readRegisterL()));
	cpu.program_counter++;
	cpu.cycles = 8;
}
void SRA_HL(CPU& cpu) {
	BYTE val = cpu.getMMU()->readByte(cpu.readRegisterHL());
	cpu.writeRegisterA(SRA_r(cpu, val));
	cpu.program_counter++;
	cpu.cycles = 16;
}

void SRL_r(CPU& cpu) {

}

void SRL_A(CPU& cpu) {

}
void SRL_B(CPU& cpu) {

}
void SRL_C(CPU& cpu) {

}
void SRL_D(CPU& cpu) {

}
void SRL_E(CPU& cpu) {

}
void SRL_H(CPU& cpu) {

}
void SRL_L(CPU& cpu) {

}
void SRL_HL(CPU& cpu) {

}


////

/*
3.3.7. Bit Opcodes
1. BIT b,r
Description:
Test bit b in register r.
Use with:
b = 0 - 7, r = A,B,C,D,E,H,L,(HL)
Flags affected:
Z - Set if bit b of register r is 0.
N - Reset.
H - Set.
C - Not affected.
*/

void BIT_br(CPU& cpu, BYTE bit, BYTE reg) {
	if ((reg & bit) == 0)
		cpu.setFlag(CPU::FLAG_Z); // flag is set. Register value remains at 0.
	else {
		cpu.clearFlagZ();
	}

	cpu.clearFlagN();
	cpu.setFlag(CPU::FLAG_H);
	cpu.program_counter++;
}

void BIT_0A(CPU& cpu) {
	BIT_br(cpu, 1, cpu.readRegisterA());
	cpu.cycles = 8;
}

void BIT_0B(CPU& cpu) {
	BIT_br(cpu, 1, cpu.readRegisterB());
	cpu.cycles = 8;
}

void BIT_0C(CPU& cpu) {
	BIT_br(cpu, 1, cpu.readRegisterC());
	cpu.cycles = 8;
}

void BIT_0D(CPU& cpu) {
	BIT_br(cpu, 1, cpu.readRegisterD());
	cpu.cycles = 8;
}

void BIT_0E(CPU& cpu) {
	BIT_br(cpu, 1, cpu.readRegisterE());
	cpu.cycles = 8;
}

void BIT_0H(CPU& cpu) {
	BIT_br(cpu, 1, cpu.readRegisterH());
	cpu.cycles = 8;
}

void BIT_0L(CPU& cpu) {
	printf("BIT 0L");
	BIT_br(cpu, 1, cpu.readRegisterL());
	cpu.cycles = 8;
}

void BIT_0HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	BIT_br(cpu, 1, reg);
	cpu.cycles = 16;
}


void BIT_1A(CPU& cpu) {
	BIT_br(cpu, 2, cpu.readRegisterA());
	cpu.cycles = 8;
}

// b, B
void BIT_1B(CPU& cpu) {
	BIT_br(cpu, 2, cpu.readRegisterB());
	cpu.cycles = 8;
}

// b, C
void BIT_1C(CPU& cpu) {
	BIT_br(cpu, 2, cpu.readRegisterC());
	cpu.cycles = 8;
}

// b, D
void BIT_1D(CPU& cpu) {
	BIT_br(cpu, 2, cpu.readRegisterD());
	cpu.cycles = 8;
}

// b, E
void BIT_1E(CPU& cpu) {
	BIT_br(cpu, 2, cpu.readRegisterE());
	cpu.cycles = 8;
}

// b, H
void BIT_1H(CPU& cpu) {
	BIT_br(cpu, 2, cpu.readRegisterH());
	cpu.cycles = 8;
}

// b, L
void BIT_1L(CPU& cpu) {
	BIT_br(cpu, 2, cpu.readRegisterL());
	cpu.cycles = 8;
}

// b, HL
void BIT_1HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	BIT_br(cpu, 2, reg);
	cpu.cycles = 16;
}

void BIT_2A(CPU& cpu) {
	BIT_br(cpu, 4, cpu.readRegisterA());
	cpu.cycles = 8;
}
void BIT_2B(CPU& cpu) {
	BIT_br(cpu, 4, cpu.readRegisterB());
	cpu.cycles = 8;
}

void BIT_2C(CPU& cpu) {
	BIT_br(cpu, 4, cpu.readRegisterC());
	cpu.cycles = 8;
}

void BIT_2D(CPU& cpu) {
	BIT_br(cpu, 4, cpu.readRegisterD());
	cpu.cycles = 8;
}

void BIT_2E(CPU& cpu) {
	BIT_br(cpu, 4, cpu.readRegisterE());
	cpu.cycles = 8;
}

void BIT_2H(CPU& cpu) {
	BIT_br(cpu, 4, cpu.readRegisterH());
	cpu.cycles = 8;
}
void BIT_2L(CPU& cpu) {
	BIT_br(cpu, 4, cpu.readRegisterL());
	cpu.cycles = 8;
}

void BIT_2HL(CPU& cpu) {

	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	BIT_br(cpu, 4, reg);
	cpu.cycles = 16;
}

void BIT_3A(CPU& cpu) {
	BIT_br(cpu, 8, cpu.readRegisterA());
	cpu.cycles = 8;
}
void BIT_3B(CPU& cpu) {
	BIT_br(cpu, 8, cpu.readRegisterB());
	cpu.cycles = 8;
}

void BIT_3C(CPU& cpu) {
	BIT_br(cpu, 8, cpu.readRegisterC());
	cpu.cycles = 8;
}

void BIT_3D(CPU& cpu) {
	BIT_br(cpu, 8, cpu.readRegisterD());
	cpu.cycles = 8;
}

void BIT_3E(CPU& cpu) {
	BIT_br(cpu, 8, cpu.readRegisterE());
	cpu.cycles = 8;
}

void BIT_3H(CPU& cpu) {
	BIT_br(cpu, 8, cpu.readRegisterH());
	cpu.cycles = 8;
}

void BIT_3L(CPU& cpu) {
	BIT_br(cpu, 8, cpu.readRegisterL());
	cpu.cycles = 8;
}

void BIT_3HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	BIT_br(cpu, 8, reg);
	cpu.cycles = 16;
}

void BIT_4A(CPU& cpu) {
	BIT_br(cpu, 16, cpu.readRegisterA());
	cpu.cycles = 8;
}

void BIT_4B(CPU& cpu) {
	BIT_br(cpu, 16, cpu.readRegisterB());
	cpu.cycles = 8;
}

void BIT_4C(CPU& cpu) {
	BIT_br(cpu, 16, cpu.readRegisterC());
	cpu.cycles = 8;
}

void BIT_4D(CPU& cpu) {
	BIT_br(cpu, 16, cpu.readRegisterD());
	cpu.cycles = 8;
}

void BIT_4E(CPU& cpu) {
	BIT_br(cpu, 16, cpu.readRegisterE());
	cpu.cycles = 8;
}

void BIT_4H(CPU& cpu) {
	BIT_br(cpu, 16, cpu.readRegisterH());
	cpu.cycles = 8;
}

void BIT_4L(CPU& cpu) {
	BIT_br(cpu, 16, cpu.readRegisterL());
	cpu.cycles = 8;
}

void BIT_4HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	BIT_br(cpu, 16, reg);
	cpu.cycles = 16;
}

void BIT_5A(CPU& cpu) {
	BIT_br(cpu, 32, cpu.readRegisterA());
	cpu.cycles = 8;
}

void BIT_5B(CPU& cpu) {
	BIT_br(cpu, 32, cpu.readRegisterB());
	cpu.cycles = 8;
}

void BIT_5C(CPU& cpu) {
	BIT_br(cpu, 32, cpu.readRegisterC());
	cpu.cycles = 8;
}

void BIT_5D(CPU& cpu) {
	BIT_br(cpu, 32, cpu.readRegisterD());
	cpu.cycles = 8;
}

void BIT_5E(CPU& cpu) {
	BIT_br(cpu, 32, cpu.readRegisterE());
	cpu.cycles = 8;
}

void BIT_5H(CPU& cpu) {
	BIT_br(cpu, 32, cpu.readRegisterH());
	cpu.cycles = 8;
}

void BIT_5L(CPU& cpu) {
	BIT_br(cpu, 32, cpu.readRegisterL());
	cpu.cycles = 8;
}

void BIT_5HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	BIT_br(cpu, 32, reg);
	cpu.cycles = 16;
}		

void BIT_6A(CPU& cpu) {
	BIT_br(cpu, 64, cpu.readRegisterA());
	cpu.cycles = 8;
}

void BIT_6B(CPU& cpu) {
	BIT_br(cpu, 64, cpu.readRegisterB());
	cpu.cycles = 8;
}

void BIT_6C(CPU& cpu) {
	BIT_br(cpu, 64, cpu.readRegisterC());
	cpu.cycles = 8;
}

void BIT_6D(CPU& cpu) {
	BIT_br(cpu, 64, cpu.readRegisterD());
	cpu.cycles = 8;
}

void BIT_6E(CPU& cpu) {
	BIT_br(cpu, 64, cpu.readRegisterE());
	cpu.cycles = 8;
}

void BIT_6H(CPU& cpu) {
	BIT_br(cpu, 64, cpu.readRegisterH());
	cpu.cycles = 8;
}

void BIT_6L(CPU& cpu) {
	BIT_br(cpu, 64, cpu.readRegisterL());
	cpu.cycles = 8;;
}

void BIT_6HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	BIT_br(cpu, 64, reg);
	cpu.cycles = 16;
}

void BIT_7A(CPU& cpu) {
	BIT_br(cpu, 128, cpu.readRegisterA());
	cpu.cycles = 8;
}

void BIT_7B(CPU& cpu) {
	BIT_br(cpu, 128, cpu.readRegisterB());
	cpu.cycles = 8;
}

void BIT_7C(CPU& cpu) {
	BIT_br(cpu, 128, cpu.readRegisterC());
	cpu.cycles = 8;
}

void BIT_7D(CPU& cpu) {
	BIT_br(cpu, 128, cpu.readRegisterD());
	cpu.cycles = 8;
}

void BIT_7E(CPU& cpu) {
	BIT_br(cpu, 128, cpu.readRegisterE());
	cpu.cycles = 8;
}

void BIT_7H(CPU& cpu) {
	BIT_br(cpu, 128, cpu.readRegisterH());
	cpu.cycles = 8;
}

void BIT_7L(CPU& cpu) {
	BIT_br(cpu, 128, cpu.readRegisterL());
	cpu.cycles = 8;	
}

void BIT_7HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	BIT_br(cpu, 128, reg);
	cpu.cycles = 16;
}

///

BYTE SET_br(CPU& cpu, BYTE bit, BYTE reg) {
	cpu.program_counter++;
	return (reg |= bit);
}

void SET_0A(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x01, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void SET_0B(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x01, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void SET_0C(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x01, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void SET_0D(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x01, cpu.readRegisterD()));
	cpu.cycles = 8;	
}

void SET_0E(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x01, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void SET_0H(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x01, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void SET_0L(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x01, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_0HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, SET_br(cpu, 0x01, reg));
	cpu.cycles = 16;	
}


void SET_1A(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x02, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void SET_1B(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x02, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void SET_1C(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x02, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void SET_1D(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x02, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void SET_1E(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x02, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void SET_1H(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x02, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void SET_1L(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x02, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_1HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, SET_br(cpu, 0x02, reg));
	cpu.cycles = 16;	
}


void SET_2A(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x04, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_2B(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x04, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_2C(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x04, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_2D(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x04, cpu.readRegisterL()));
	cpu.cycles = 8;	
}

void SET_2E(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x04, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_2H(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x04, cpu.readRegisterL()));
	cpu.cycles = 8;;	
}

void SET_2L(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x04, cpu.readRegisterL()));
	cpu.cycles = 8;	
}

void SET_2HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, SET_br(cpu, 0x04, reg));
	cpu.cycles = 16;	
}


void SET_3A(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x08, cpu.readRegisterA()));
	cpu.cycles = 8;	
}

void SET_3B(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x08, cpu.readRegisterA()));
	cpu.cycles = 8;	
}

void SET_3C(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x08, cpu.readRegisterA()));
	cpu.cycles = 8;	
}

void SET_3D(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x08, cpu.readRegisterA()));
	cpu.cycles = 8;	
}

void SET_3E(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x08, cpu.readRegisterA()));
	cpu.cycles = 8;		
}

void SET_3H(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x08, cpu.readRegisterA()));
	cpu.cycles = 8;		
}

void SET_3L(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x08, cpu.readRegisterA()));
	cpu.cycles = 8;	
}

void SET_3HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, SET_br(cpu, 0x08, reg));
	cpu.cycles = 16;	
}


void SET_4A(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x10, cpu.readRegisterA()));
	cpu.cycles = 8;	
}

void SET_4B(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x10, cpu.readRegisterB()));
	cpu.cycles = 8;		
}

void SET_4C(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x10, cpu.readRegisterC()));
	cpu.cycles = 8;	
}

void SET_4D(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x10, cpu.readRegisterD()));
	cpu.cycles = 8;	
}

void SET_4E(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x10, cpu.readRegisterE()));
	cpu.cycles = 8;	
}

void SET_4H(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x10, cpu.readRegisterH()));
	cpu.cycles = 8;	
}

void SET_4L(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x10, cpu.readRegisterL()));
	cpu.cycles = 8;	
}

void SET_4HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, SET_br(cpu, 0x10, reg));
	cpu.cycles = 16;	
}


void SET_5A(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x20, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void SET_5B(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x20, cpu.readRegisterB()));
	cpu.cycles = 8;	
}

void SET_5C(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x20, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void SET_5D(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x20, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void SET_5E(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x20, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void SET_5H(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x20, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void SET_5L(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x20, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_5HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, SET_br(cpu, 0x20, reg));
	cpu.cycles = 16;	
}


void SET_6A(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x40, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void SET_6B(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x40, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void SET_6C(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x40, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void SET_6D(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x40, cpu.readRegisterD()));
	cpu.cycles = 8;	
}

void SET_6E(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x40, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void SET_6H(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x40, cpu.readRegisterH()));
	cpu.cycles = 8;	
}

void SET_6L(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x40, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_6HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, SET_br(cpu, 0x40, reg));
	cpu.cycles = 16;	
}


void SET_7A(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x80, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void SET_7B(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x80, cpu.readRegisterB()));
	cpu.cycles = 8;;	
}

void SET_7C(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x80, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void SET_7D(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x80, cpu.readRegisterD()));
	cpu.cycles = 8;	
}

void SET_7E(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x80, cpu.readRegisterE()));
	cpu.cycles = 8;	
}

void SET_7H(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x80, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void SET_7L(CPU& cpu) {
	cpu.writeRegisterA(SET_br(cpu, 0x80, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void SET_7HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, SET_br(cpu, 0x80, reg));
	cpu.cycles = 16;	
}

////
////

BYTE RES_br(CPU& cpu, BYTE bit, BYTE reg) {
	cpu.program_counter++;
	return reg & ~bit;
}

///
void RES_0A(CPU& cpu) {
	cpu.writeRegisterA(RES_br(cpu, 0x01, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void RES_0B(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x01, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void RES_0C(CPU& cpu) {
	cpu.writeRegisterC(RES_br(cpu, 0x01, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void RES_0D(CPU& cpu) {
	cpu.writeRegisterD(RES_br(cpu, 0x01, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void RES_0E(CPU& cpu) {
	cpu.writeRegisterE(RES_br(cpu, 0x01, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void RES_0H(CPU& cpu) {
	cpu.writeRegisterH(RES_br(cpu, 0x01, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void RES_0L(CPU& cpu) {
	cpu.writeRegisterL(RES_br(cpu, 0x01, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void RES_0HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, RES_br(cpu, 0x01, reg));
	cpu.cycles = 16;
}

void RES_1A(CPU& cpu) {
	cpu.writeRegisterA(RES_br(cpu, 0x02, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void RES_1B(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x02, cpu.readRegisterB()));
	cpu.cycles = 8;
}
void RES_1C(CPU& cpu) {
	cpu.writeRegisterC(RES_br(cpu, 0x02, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void RES_1D(CPU& cpu) {
	cpu.writeRegisterD(RES_br(cpu, 0x02, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void RES_1E(CPU& cpu) {
	cpu.writeRegisterE(RES_br(cpu, 0x02, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void RES_1H(CPU& cpu) {
	cpu.writeRegisterH(RES_br(cpu, 0x02, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void RES_1L(CPU& cpu) {
	cpu.writeRegisterL(RES_br(cpu, 0x02, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void RES_1HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, RES_br(cpu, 0x02, reg));
	cpu.cycles = 16;	
}

void RES_2A(CPU& cpu) {
	cpu.writeRegisterA(RES_br(cpu, 0x04, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void RES_2B(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x04, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void RES_2C(CPU& cpu) {
	cpu.writeRegisterC(RES_br(cpu, 0x04, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void RES_2D(CPU& cpu) {
	cpu.writeRegisterD(RES_br(cpu, 0x04, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void RES_2E(CPU& cpu) {
	cpu.writeRegisterE(RES_br(cpu, 0x04, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void RES_2H(CPU& cpu) {
	cpu.writeRegisterH(RES_br(cpu, 0x04, cpu.readRegisterH()));
	cpu.cycles = 8;
}
void RES_2L(CPU& cpu) {
	cpu.writeRegisterL(RES_br(cpu, 0x04, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void RES_2HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, RES_br(cpu, 0x04, reg));
	cpu.cycles = 16;
}

void RES_3A(CPU& cpu) {
	cpu.writeRegisterA(RES_br(cpu, 0x08, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void RES_3B(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x08, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void RES_3C(CPU& cpu) {
	cpu.writeRegisterC(RES_br(cpu, 0x08, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void RES_3D(CPU& cpu) {
	cpu.writeRegisterD(RES_br(cpu, 0x08, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void RES_3E(CPU& cpu) {
	cpu.writeRegisterE(RES_br(cpu, 0x08, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void RES_3H(CPU& cpu) {
	cpu.writeRegisterH(RES_br(cpu, 0x08, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void RES_3L(CPU& cpu) {
	cpu.writeRegisterL(RES_br(cpu, 0x08, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void RES_3HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, RES_br(cpu, 0x08, reg));
	cpu.cycles = 16;
}

void RES_4A(CPU& cpu) {
	cpu.writeRegisterA(RES_br(cpu, 0x10, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void RES_4B(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x10, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void RES_4C(CPU& cpu) {
	cpu.writeRegisterC(RES_br(cpu, 0x10, cpu.readRegisterC()));
	cpu.cycles = 8;
}
void RES_4D(CPU& cpu) {
	cpu.writeRegisterD(RES_br(cpu, 0x10, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void RES_4E(CPU& cpu) {
	cpu.writeRegisterE(RES_br(cpu, 0x10, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void RES_4H(CPU& cpu) {
	cpu.writeRegisterH(RES_br(cpu, 0x10, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void RES_4L(CPU& cpu) {
	cpu.writeRegisterL(RES_br(cpu, 0x10, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void RES_4HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, RES_br(cpu, 0x10, reg));
	cpu.cycles = 16;
}

void RES_5A(CPU& cpu) {
	cpu.writeRegisterA(RES_br(cpu, 0x20, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void RES_5B(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x20, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void RES_5C(CPU& cpu) {
	cpu.writeRegisterC(RES_br(cpu, 0x20, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void RES_5D(CPU& cpu) {
	cpu.writeRegisterD(RES_br(cpu, 0x20, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void RES_5E(CPU& cpu) {
	cpu.writeRegisterE(RES_br(cpu, 0x20, cpu.readRegisterE()));
	cpu.cycles = 8;
}
void RES_5H(CPU& cpu) {
	cpu.writeRegisterH(RES_br(cpu, 0x20, cpu.readRegisterH()));
	cpu.cycles = 8;
}
void RES_5L(CPU& cpu) {
	cpu.writeRegisterL(RES_br(cpu, 0x20, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void RES_5HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, RES_br(cpu, 0x20, reg));
	cpu.cycles = 16;
}

void RES_6A(CPU& cpu) {
	cpu.writeRegisterA(RES_br(cpu, 0x40, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void RES_6B(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x40, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void RES_6C(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x40, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void RES_6D(CPU& cpu) {
	cpu.writeRegisterC(RES_br(cpu, 0x40, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void RES_6E(CPU& cpu) {
	cpu.writeRegisterD(RES_br(cpu, 0x40, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void RES_6H(CPU& cpu) {
	cpu.writeRegisterE(RES_br(cpu, 0x40, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void RES_6L(CPU& cpu) {
	cpu.writeRegisterL(RES_br(cpu, 0x40, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void RES_6HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, RES_br(cpu, 0x40, reg));
	cpu.cycles = 16;
}

void RES_7A(CPU& cpu) {
	cpu.writeRegisterA(RES_br(cpu, 0x80, cpu.readRegisterA()));
	cpu.cycles = 8;
}

void RES_7B(CPU& cpu) {
	cpu.writeRegisterB(RES_br(cpu, 0x80, cpu.readRegisterB()));
	cpu.cycles = 8;
}

void RES_7C(CPU& cpu) {
	cpu.writeRegisterC(RES_br(cpu, 0x80, cpu.readRegisterC()));
	cpu.cycles = 8;
}

void RES_7D(CPU& cpu) {
	cpu.writeRegisterD(RES_br(cpu, 0x80, cpu.readRegisterD()));
	cpu.cycles = 8;
}

void RES_7E(CPU& cpu) {
	cpu.writeRegisterE(RES_br(cpu, 0x80, cpu.readRegisterE()));
	cpu.cycles = 8;
}

void RES_7H(CPU& cpu) {
	cpu.writeRegisterH(RES_br(cpu, 0x80, cpu.readRegisterH()));
	cpu.cycles = 8;
}

void RES_7L(CPU& cpu) {
	cpu.writeRegisterL(RES_br(cpu, 0x80, cpu.readRegisterL()));
	cpu.cycles = 8;
}

void RES_7HL(CPU& cpu) {
	WORD addr = cpu.readRegisterHL();
	BYTE reg = cpu.getMMU()->readByte(addr);
	cpu.getMMU()->writeByte(addr, RES_br(cpu, 0x80, reg));
	cpu.cycles = 16;
}


/////

void CALL(CPU& cpu) {
	cpu.pushStack(cpu.program_counter + 3); // next instruction on stack
	cpu.program_counter = cpu.getMMU()->readWord(cpu.program_counter + 1);
}

void CALL_nn(CPU& cpu) {
	CALL(cpu);
	cpu.cycles = 12;
}

void CALL_NZ_nn(CPU& cpu) {
	if (!cpu.isFlagSet(CPU::FLAG_Z)) {
		CALL(cpu);
	}
	cpu.program_counter += 3;
	cpu.cycles = 12;
}

void CALL_Z_nn(CPU& cpu) {
	if (cpu.isFlagSet(CPU::FLAG_Z)) {
		CALL(cpu);
	}
	cpu.program_counter += 3;
	cpu.cycles = 12;
}

void CALL_NC_nn(CPU& cpu) {
	if (!cpu.isFlagSet(CPU::FLAG_C)) {
		CALL(cpu);
	}
	cpu.program_counter += 3;
	cpu.cycles = 12;
}

void CALL_C_nn(CPU& cpu) {
	if (cpu.isFlagSet(CPU::FLAG_C)) {
		CALL(cpu);
	}
	cpu.program_counter += 3;
	cpu.cycles = 12;
}

////

void RST_00h(CPU& cpu) {
	cpu.pushStack(cpu.program_counter);
	cpu.program_counter = 0x0000;
}
void RST_08h(CPU& cpu) {
	cpu.pushStack(cpu.program_counter);
	cpu.program_counter = 0x0008;
}
void RST_10h(CPU& cpu) {
	cpu.pushStack(cpu.program_counter);
	cpu.program_counter = 0x0010;
}
void RST_18h(CPU& cpu) {
	cpu.pushStack(cpu.program_counter);
	cpu.program_counter = 0x0018;
}

void RST_20h(CPU& cpu) {
	cpu.pushStack(cpu.program_counter);
	cpu.program_counter = 0x0020;
}
void RST_28h(CPU& cpu) {
	cpu.pushStack(cpu.program_counter);
	cpu.program_counter = 0x0028;
}

void RST_30h(CPU& cpu) {
	cpu.pushStack(cpu.program_counter);
	cpu.program_counter = 0x0030;
}
void RST_38h(CPU& cpu) {
	cpu.pushStack(cpu.program_counter);
	cpu.program_counter = 0x0038;
}

///

void RET(CPU& cpu) {
	cpu.program_counter = cpu.popStack();
	cpu.cycles = 8;
}

void RET_NZ(CPU& cpu) {
	if (!cpu.isFlagSet(CPU::FLAG_Z)) {
		cpu.program_counter = cpu.popStack();
	}
	cpu.program_counter++;
}

void RET_Z(CPU& cpu) {
	if (cpu.isFlagSet(CPU::FLAG_Z)) {
		cpu.program_counter = cpu.popStack();
	}
	cpu.program_counter++;
}

void RET_C(CPU& cpu) {
	if (cpu.isFlagSet(CPU::FLAG_C)) {
		cpu.program_counter = cpu.popStack();
	}
	cpu.program_counter++;
}

void RET_NC(CPU& cpu) {
	if (!cpu.isFlagSet(CPU::FLAG_C)) {
		cpu.program_counter = cpu.popStack();
	}
	cpu.program_counter++;
}

void RETI(CPU& cpu) {
	cpu.enableMasterInterrupt();

	cpu.program_counter = cpu.popStack();
	cpu.cycles = 8;
}


////


void UNDEFINED(CPU& cpu) {
	// Z80 specific instructions
	// not implemented for GameBoy.
}

#endif
