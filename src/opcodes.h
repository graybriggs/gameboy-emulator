
#ifndef OPCODES_H
#define OPCODES_H

class CPU;

BYTE LD_reg_8bit_immediate(CPU& cpu, BYTE reg);
void LD_Bn(CPU& cpu);
void LD_Cn(CPU& cpu);
void LD_Dn(CPU& cpu);
void LD_En(CPU& cpu);
void LD_Hn(CPU& cpu);
void LD_Ln(CPU& cpu);

void LD_AA(CPU& cpu);
void LD_AB(CPU& cpu);
void LD_AC(CPU& cpu);
void LD_AD(CPU& cpu);
void LD_AE(CPU& cpu);
void LD_AH(CPU& cpu);
void LD_AL(CPU& cpu);
void LD_A_HL_(CPU& cpu);

void LD_BB(CPU& cpu);
void LD_BC(CPU& cpu);
void LD_BD(CPU& cpu);
void LD_BE(CPU& cpu);
void LD_BH(CPU& cpu);
void LD_BL(CPU& cpu);
void LD_B_HL_(CPU& cpu);

void LD_CB(CPU& cpu);
void LD_CC(CPU& cpu);
void LD_CD(CPU& cpu);
void LD_CE(CPU& cpu);
void LD_CH(CPU& cpu);
void LD_CL(CPU& cpu);
void LD_C_HL_(CPU& cpu);

void LD_DB(CPU& cpu);
void LD_DC(CPU& cpu);
void LD_DD(CPU& cpu);
void LD_DE(CPU& cpu);
void LD_DH(CPU& cpu);
void LD_DL(CPU& cpu);
void LD_D_HL_(CPU& cpu);

void LD_EB(CPU& cpu);
void LD_EC(CPU& cpu);
void LD_ED(CPU& cpu);
void LD_EE(CPU& cpu);
void LD_EH(CPU& cpu);
void LD_EL(CPU& cpu);
void LD_E_HL_(CPU& cpu);

void LD_HB(CPU& cpu);
void LD_HC(CPU& cpu);
void LD_HD(CPU& cpu);
void LD_HE(CPU& cpu);
void LD_HH(CPU& cpu);
void LD_HL(CPU& cpu);
void LD_H_HL_(CPU& cpu);

void LD_LB(CPU& cpu);
void LD_LC(CPU& cpu);
void LD_LD(CPU& cpu);
void LD_LE(CPU& cpu);
void LD_LH(CPU& cpu);
void LD_LL(CPU& cpu);
void LD_L_HL_(CPU& cpu);

//
void LD_HL_r(CPU& cpu, BYTE val);
//
void LD_HL_B(CPU& cpu);
void LD_HL_C(CPU& cpu);
void LD_HL_D(CPU& cpu);
void LD_HL_E(CPU& cpu);
void LD_HL_H(CPU& cpu);
void LD_HL_L(CPU& cpu);
void LD_HL_n(CPU& cpu);

void LD_A_A(CPU& cpu);
void LD_B_A(CPU& cpu);
void LD_C_A(CPU& cpu);
void LD_D_A(CPU& cpu);
void LD_E_A(CPU& cpu);
void LD_H_A(CPU& cpu);
void LD_L_A(CPU& cpu);

void LD_BC_A(CPU& cpu);
void LD_DE_A(CPU& cpu);
void LD_HL_A(CPU& cpu);
void LD_nn_A(CPU& cpu);
void LD_A_nn(CPU& cpu);
void LD_A_val(CPU& cpu);


void LD_A_C_(CPU& cpu);
void LD__C__A(CPU& cpu);
void LD_A__HLD__(CPU& cpu);
void LD_A__HLneg__(CPU& cpu);
void LDD_A__HL__(CPU& cpu);
void LD__HLD__A(CPU& cpu);
void LD_A_HLI_(CPU& cpu);
void LD__HLI_A(CPU& cpu);
void LDH__n_A(CPU& cpu);
void LDH_A__n_(CPU& cpu);

// 16-bit loads
WORD LD_16_nn(CPU& cpu);
///
void LD_BC_nn(CPU& cpu);
void LD_DE_nn(CPU& cpu);
void LD_HL_nn(CPU& cpu);
void LD_SP_nn(CPU& cpu);
void LD_SP_HL(CPU& cpu);
void LD_HL_SPn(CPU& cpu);
void LD__nn_SP(CPU& cpu);

///
void PUSH_16bit(CPU& cpu, WORD data);
////
void PUSH_AF(CPU& cpu);
void PUSH_BC(CPU& cpu);
void PUSH_DE(CPU& cpu);
void PUSH_HL(CPU& cpu);

//
WORD POP_16bit(CPU& cpu);
///
void POP_AF(CPU& cpu);
void POP_BC(CPU& cpu);
void POP_DE(CPU& cpu);
void POP_HL(CPU& cpu);

//
BYTE ADD_r_r_8bit(CPU& cpu, BYTE r1, BYTE r2);
//
void ADD_A_A(CPU& cpu);
void ADD_A_B(CPU& cpu);
void ADD_A_C(CPU& cpu);
void ADD_A_D(CPU& cpu);
void ADD_A_E(CPU& cpu);
void ADD_A_H(CPU& cpu);
void ADD_A_L(CPU& cpu);
void ADD_A_HL(CPU& cpu);
void ADD_A_n(CPU& cpu);

//
BYTE ADC_r_r(CPU& cpu, BYTE reg);
//
void ADC_A_A(CPU& cpu);
void ADC_A_B(CPU& cpu);
void ADC_A_C(CPU& cpu);
void ADC_A_D(CPU& cpu);
void ADC_A_E(CPU& cpu);
void ADC_A_H(CPU& cpu);
void ADC_A_L(CPU& cpu);
void ADC_A_HL(CPU& cpu);
void ADC_A_n(CPU& cpu);

//
BYTE SUB_r_r(CPU& cpu, BYTE r1, BYTE r2);
//
void SUB_A_A(CPU& cpu);
void SUB_A_B(CPU& cpu);
void SUB_A_C(CPU& cpu);
void SUB_A_D(CPU& cpu);
void SUB_A_E(CPU& cpu);
void SUB_A_H(CPU& cpu);
void SUB_A_L(CPU& cpu);
void SUB_A_HL(CPU& cpu);
void SUB_A_n(CPU& cpu);


BYTE SBC_r_r(CPU& cpu, BYTE r1, BYTE r2);
void SBC_A_A(CPU& cpu);
void SBC_A_B(CPU& cpu);
void SBC_A_C(CPU& cpu);
void SBC_A_D(CPU& cpu);
void SBC_A_E(CPU& cpu);
void SBC_A_H(CPU& cpu);
void SBC_A_L(CPU& cpu);
void SBC_A_HL(CPU& cpu);
void SBC_A_num(CPU& cpu);
// IMPLEMENT !!!!

//
BYTE AND_r_r(CPU& cpu);
//
void AND_A_A(CPU& cpu);
void AND_A_B(CPU& cpu);
void AND_A_C(CPU& cpu);
void AND_A_D(CPU& cpu);
void AND_A_E(CPU& cpu);
void AND_A_H(CPU& cpu);
void AND_A_L(CPU& cpu);
void AND_A_HL(CPU& cpu);
void AND_A_n(CPU& cpu);

//
BYTE OR_r_r(CPU& cpu);
//
void OR_A_A(CPU& cpu);
void OR_A_B(CPU& cpu);
void OR_A_C(CPU& cpu);
void OR_A_D(CPU& cpu);
void OR_A_E(CPU& cpu);
void OR_A_H(CPU& cpu);
void OR_A_L(CPU& cpu);
void OR_A_HL(CPU& cpu);
void OR_A_n(CPU& cpu);

//
BYTE XOR_r_r(CPU& cpu);
//
void XOR_A_A(CPU& cpu);
void XOR_A_B(CPU& cpu);
void XOR_A_C(CPU& cpu);
void XOR_A_D(CPU& cpu);
void XOR_A_E(CPU& cpu);
void XOR_A_H(CPU& cpu);
void XOR_A_L(CPU& cpu);
void XOR_A_HL(CPU& cpu);
void XOR_A_n(CPU& cpu);

void CP_A_A(CPU& cpu);
void CP_A_B(CPU& cpu);
void CP_A_C(CPU& cpu);
void CP_A_D(CPU& cpu);
void CP_A_E(CPU& cpu);
void CP_A_H(CPU& cpu);
void CP_A_L(CPU& cpu);
void CP_A_HL(CPU& cpu);
void CP_A_num(CPU& cpu);

///
BYTE INC_r(CPU& cpu, BYTE reg);
///
void INC_A(CPU& cpu);
void INC_B(CPU& cpu);
void INC_C(CPU& cpu);
void INC_D(CPU& cpu);
void INC_E(CPU& cpu);
void INC_H(CPU& cpu);
void INC_L(CPU& cpu);
void INC__HL_(CPU& cpu);

//
BYTE INC_r(CPU& cpu, BYTE reg);
//
void DEC_A(CPU& cpu);
void DEC_B(CPU& cpu);
void DEC_C(CPU& cpu);
void DEC_D(CPU& cpu);
void DEC_E(CPU& cpu);
void DEC_H(CPU& cpu);
void DEC_L(CPU& cpu);
void DEC__HL_(CPU& cpu);

void JP(CPU& cpu);
void JP_HL_(CPU& cpu);
void JP_C(CPU& cpu);
void JP_NC(CPU& cpu);
void JP_NZ(CPU& cpu);
void JP_Z(CPU& cpu);

void JR_n(CPU& cpu);
void JR_NZ_n(CPU& cpu);
void JR_Z_n(CPU& cpu);
void JR_NC_n(CPU& cpu);
void JR_C_n(CPU& cpu);

// 16 bit arithmetic

void ADD_HL_BC(CPU& cpu);
void ADD_HL_DE(CPU& cpu);
void ADD_HL_HL(CPU& cpu);
void ADD_HL_SP(CPU& cpu);

void ADD_SP_n(CPU& cpu);

void INC_BC(CPU& cpu);
void INC_DE(CPU& cpu);
void INC_HL(CPU& cpu);
void INC_SP(CPU& cpu);

void DEC_BC(CPU& cpu);
void DEC_DE(CPU& cpu);
void DEC_HL(CPU& cpu);
void DEC_SP(CPU& cpu);

void NOOP(CPU& cpu);

//
BYTE SWAP_r(CPU& cpu, BYTE reg);
//
void SWAP_A(CPU& cpu);
void SWAP_B(CPU& cpu);
void SWAP_C(CPU& cpu);
void SWAP_D(CPU& cpu);
void SWAP_E(CPU& cpu);
void SWAP_H(CPU& cpu);
void SWAP_L(CPU& cpu);
void SWAP__HL_(CPU& cpu);

void DA_A(CPU& cpu);
void CPL(CPU& cpu);
void CCF(CPU& cpu);
void SCF(CPU& cpu);
void NOOP(CPU& cpu);
void HALT(CPU& cpu);
void STOP(CPU& cpu);
void DI(CPU& cpu);
void EI(CPU& cpu);

//

void RLC_r(CPU& cpu);
void RL_r(CPU& cpu);
void RRC_r(CPU& cpu);
void RR_r(CPU& cpu);

//

void RLCA(CPU& cpu);
void RLA(CPU& cpu);
void RRCA(CPU& cpu);
void RRA(CPU& cpu);

//

void RLC_A(CPU& cpu);
void RLC_B(CPU& cpu);
void RLC_C(CPU& cpu);
void RLC_D(CPU& cpu);
void RLC_E(CPU& cpu);
void RLC_H(CPU& cpu);
void RLC_L(CPU& cpu);
void RLC_HL(CPU& cpu);

void RL_A(CPU& cpu);
void RL_B(CPU& cpu);
void RL_C(CPU& cpu);
void RL_D(CPU& cpu);
void RL_E(CPU& cpu);
void RL_H(CPU& cpu);
void RL_L(CPU& cpu);
void RL_HL(CPU& cpu);

void RRC_A(CPU& cpu);
void RRC_B(CPU& cpu);
void RRC_C(CPU& cpu);
void RRC_D(CPU& cpu);
void RRC_E(CPU& cpu);
void RRC_H(CPU& cpu);
void RRC_L(CPU& cpu);
void RRC_HL(CPU& cpu);

void RR_A(CPU& cpu);
void RR_B(CPU& cpu);
void RR_C(CPU& cpu);
void RR_D(CPU& cpu);
void RR_E(CPU& cpu);
void RR_H(CPU& cpu);
void RR_L(CPU& cpu);
void RR_HL(CPU& cpu);

void SLA_r(CPU& cpu);
void SLA_A(CPU& cpu);
void SLA_B(CPU& cpu);
void SLA_C(CPU& cpu);
void SLA_D(CPU& cpu);
void SLA_E(CPU& cpu);
void SLA_H(CPU& cpu);
void SLA_L(CPU& cpu);
void SLA_HL(CPU& cpu);

void SRA_r(CPU& cpu);
void SRA_A(CPU& cpu);
void SRA_B(CPU& cpu);
void SRA_C(CPU& cpu);
void SRA_D(CPU& cpu);
void SRA_E(CPU& cpu);
void SRA_H(CPU& cpu);
void SRA_L(CPU& cpu);
void SRA_HL(CPU& cpu);

void SRL_r(CPU& cpu);
void SRL_A(CPU& cpu);
void SRL_B(CPU& cpu);
void SRL_C(CPU& cpu);
void SRL_D(CPU& cpu);
void SRL_E(CPU& cpu);
void SRL_H(CPU& cpu);
void SRL_L(CPU& cpu);
void SRL_HL(CPU& cpu);

//
//
void BIT_br(CPU& cpu, BYTE bit, BYTE reg);
//
void BIT_0A(CPU& cpu);
void BIT_0B(CPU& cpu);
void BIT_0C(CPU& cpu);
void BIT_0D(CPU& cpu);
void BIT_0E(CPU& cpu);
void BIT_0H(CPU& cpu);
void BIT_0L(CPU& cpu);
void BIT_0HL(CPU& cpu);

void BIT_1A(CPU& cpu);
void BIT_1B(CPU& cpu);
void BIT_1C(CPU& cpu);
void BIT_1D(CPU& cpu);
void BIT_1E(CPU& cpu);
void BIT_1H(CPU& cpu);
void BIT_1L(CPU& cpu);
void BIT_1HL(CPU& cpu);

void BIT_2A(CPU& cpu);
void BIT_2B(CPU& cpu);
void BIT_2C(CPU& cpu);
void BIT_2D(CPU& cpu);
void BIT_2E(CPU& cpu);
void BIT_2H(CPU& cpu);
void BIT_2L(CPU& cpu);
void BIT_2HL(CPU& cpu);

void BIT_3A(CPU& cpu);
void BIT_3B(CPU& cpu);
void BIT_3C(CPU& cpu);
void BIT_3D(CPU& cpu);
void BIT_3E(CPU& cpu);
void BIT_3H(CPU& cpu);
void BIT_3L(CPU& cpu);
void BIT_3HL(CPU& cpu);

void BIT_4A(CPU& cpu);
void BIT_4B(CPU& cpu);
void BIT_4C(CPU& cpu);
void BIT_4D(CPU& cpu);
void BIT_4E(CPU& cpu);
void BIT_4H(CPU& cpu);
void BIT_4L(CPU& cpu);
void BIT_4HL(CPU& cpu);

void BIT_5A(CPU& cpu);
void BIT_5B(CPU& cpu);
void BIT_5C(CPU& cpu);
void BIT_5D(CPU& cpu);
void BIT_5E(CPU& cpu);
void BIT_5H(CPU& cpu);
void BIT_5L(CPU& cpu);
void BIT_5HL(CPU& cpu);		


void BIT_6A(CPU& cpu);
void BIT_6B(CPU& cpu);
void BIT_6C(CPU& cpu);
void BIT_6D(CPU& cpu);
void BIT_6E(CPU& cpu);
void BIT_6H(CPU& cpu);
void BIT_6L(CPU& cpu);
void BIT_6HL(CPU& cpu);

void BIT_7A(CPU& cpu);
void BIT_7B(CPU& cpu);
void BIT_7C(CPU& cpu);
void BIT_7D(CPU& cpu);
void BIT_7E(CPU& cpu);
void BIT_7H(CPU& cpu);
void BIT_7L(CPU& cpu);
void BIT_7HL(CPU& cpu);

//
BYTE SET_br(CPU& cpu, BYTE bit, BYTE reg);
//
void SET_0A(CPU& cpu);
void SET_0B(CPU& cpu);
void SET_0C(CPU& cpu);
void SET_0D(CPU& cpu);
void SET_0E(CPU& cpu);
void SET_0H(CPU& cpu);
void SET_0L(CPU& cpu);
void SET_0HL(CPU& cpu);

void SET_1A(CPU& cpu);
void SET_1B(CPU& cpu);
void SET_1C(CPU& cpu);
void SET_1D(CPU& cpu);
void SET_1E(CPU& cpu);
void SET_1H(CPU& cpu);
void SET_1L(CPU& cpu);
void SET_1HL(CPU& cpu);

void SET_2A(CPU& cpu);
void SET_2B(CPU& cpu);
void SET_2C(CPU& cpu);
void SET_2D(CPU& cpu);
void SET_2E(CPU& cpu);
void SET_2H(CPU& cpu);
void SET_2L(CPU& cpu);
void SET_2HL(CPU& cpu);

void SET_3A(CPU& cpu);
void SET_3B(CPU& cpu);
void SET_3C(CPU& cpu);
void SET_3D(CPU& cpu);
void SET_3E(CPU& cpu);
void SET_3H(CPU& cpu);
void SET_3L(CPU& cpu);
void SET_3HL(CPU& cpu);

void SET_4A(CPU& cpu);
void SET_4B(CPU& cpu);
void SET_4C(CPU& cpu);
void SET_4D(CPU& cpu);
void SET_4E(CPU& cpu);
void SET_4H(CPU& cpu);
void SET_4L(CPU& cpu);
void SET_4HL(CPU& cpu);

void SET_5A(CPU& cpu);
void SET_5B(CPU& cpu);
void SET_5C(CPU& cpu);
void SET_5D(CPU& cpu);
void SET_5E(CPU& cpu);
void SET_5H(CPU& cpu);
void SET_5L(CPU& cpu);
void SET_5HL(CPU& cpu);

void SET_6A(CPU& cpu);
void SET_6B(CPU& cpu);
void SET_6C(CPU& cpu);
void SET_6D(CPU& cpu);
void SET_6E(CPU& cpu);
void SET_6H(CPU& cpu);
void SET_6L(CPU& cpu);
void SET_6HL(CPU& cpu);

void SET_7A(CPU& cpu);
void SET_7B(CPU& cpu);
void SET_7C(CPU& cpu);
void SET_7D(CPU& cpu);
void SET_7E(CPU& cpu);
void SET_7H(CPU& cpu);
void SET_7L(CPU& cpu);
void SET_7HL(CPU& cpu);

//

void RES_0A(CPU& cpu);
void RES_0B(CPU& cpu);
void RES_0C(CPU& cpu);
void RES_0D(CPU& cpu);
void RES_0E(CPU& cpu);
void RES_0H(CPU& cpu);
void RES_0L(CPU& cpu);
void RES_0HL(CPU& cpu);

void RES_1A(CPU& cpu);
void RES_1B(CPU& cpu);
void RES_1C(CPU& cpu);
void RES_1D(CPU& cpu);
void RES_1E(CPU& cpu);
void RES_1H(CPU& cpu);
void RES_1L(CPU& cpu);
void RES_1HL(CPU& cpu);

void RES_2A(CPU& cpu);
void RES_2B(CPU& cpu);
void RES_2C(CPU& cpu);
void RES_2D(CPU& cpu);
void RES_2E(CPU& cpu);
void RES_2H(CPU& cpu);
void RES_2L(CPU& cpu);
void RES_2HL(CPU& cpu);

void RES_3A(CPU& cpu);
void RES_3B(CPU& cpu);
void RES_3C(CPU& cpu);
void RES_3D(CPU& cpu);
void RES_3E(CPU& cpu);
void RES_3H(CPU& cpu);
void RES_3L(CPU& cpu);
void RES_3HL(CPU& cpu);

void RES_4A(CPU& cpu);
void RES_4B(CPU& cpu);
void RES_4C(CPU& cpu);
void RES_4D(CPU& cpu);
void RES_4E(CPU& cpu);
void RES_4H(CPU& cpu);
void RES_4L(CPU& cpu);
void RES_4HL(CPU& cpu);

void RES_5A(CPU& cpu);
void RES_5B(CPU& cpu);
void RES_5C(CPU& cpu);
void RES_5D(CPU& cpu);
void RES_5E(CPU& cpu);
void RES_5H(CPU& cpu);
void RES_5L(CPU& cpu);
void RES_5HL(CPU& cpu);

void RES_6A(CPU& cpu);
void RES_6B(CPU& cpu);
void RES_6C(CPU& cpu);
void RES_6D(CPU& cpu);
void RES_6E(CPU& cpu);
void RES_6H(CPU& cpu);
void RES_6L(CPU& cpu);
void RES_6HL(CPU& cpu);

void RES_7A(CPU& cpu);
void RES_7B(CPU& cpu);
void RES_7C(CPU& cpu);
void RES_7D(CPU& cpu);
void RES_7E(CPU& cpu);
void RES_7H(CPU& cpu);
void RES_7L(CPU& cpu);
void RES_7HL(CPU& cpu);

//
void CALL(CPU& cpu);
//
void CALL_nn(CPU& cpu);
void CALL_NZ_nn(CPU& cpu);
void CALL_Z_nn(CPU& cpu);
void CALL_NC_nn(CPU& cpu);
void CALL_C_nn(CPU& cpu);

//

void RST_00h(CPU& cpu);
void RST_08h(CPU& cpu);
void RST_10h(CPU& cpu);
void RST_18h(CPU& cpu);
void RST_20h(CPU& cpu);
void RST_28h(CPU& cpu);
void RST_30h(CPU& cpu);
void RST_38h(CPU& cpu);

//

void RET(CPU& cpu);
void RET_C(CPU& cpu);
void RET_NZ(CPU& cpu);
void RET_Z(CPU& cpu);
void RET_NC(CPU& cpu);
void RETI(CPU& cpu);


void UNDEFINED(CPU& cpu);



#endif