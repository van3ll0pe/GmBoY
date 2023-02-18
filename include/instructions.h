#ifndef __INSTRUCTIONS_H__
#define __INSTRUCTIONS_H__

#include <stdatomic.h>

typedef struct Cpu_t Cpu_t;

/************ 8bits arithmetic / logic ***************/

extern void ADD_r8(Cpu_t* cpu, uint8_t* registre);
extern void ADD_d8(Cpu_t* cpu, uint8_t* memory);
extern void ADD_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void ADC_r8(Cpu_t* cpu, uint8_t* registre);
extern void ADC_d8(Cpu_t* cpu, uint8_t* memory);
extern void ADC_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void SUB_r8(Cpu_t* cpu, uint8_t* registre);
extern void SUB_d8(Cpu_t* cpu, uint8_t* memory);
extern void SUB_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void SBC_r8(Cpu_t* cpu, uint8_t* registre);
extern void SBC_d8(Cpu_t* cpu, uint8_t* memory);
extern void SBC_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void AND_r8(Cpu_t* cpu, uint8_t* registre);
extern void AND_d8(Cpu_t* cpu, uint8_t* memory);
extern void AND_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void XOR_r8(Cpu_t* cpu, uint8_t* registre);
extern void XOR_d8(Cpu_t* cpu, uint8_t* memory);
extern void XOR_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void OR_r8(Cpu_t* cpu, uint8_t* registre);
extern void OR_d8(Cpu_t* cpu, uint8_t* memory);
extern void OR_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void CP_r8(Cpu_t* cpu, uint8_t* registre);
extern void CP_d8(Cpu_t* cpu, uint8_t* memory);
extern void CP_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void INC_r8(Cpu_t* cpu, uint8_t* registre);
extern void INC_mem_HL(Cpu_t* cpu, uint8_t* memory);
extern void DEC_r8(Cpu_t* cpu, uint8_t* registre);
extern void DEC_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void CPL(Cpu_t* cpu);
extern void DAA(Cpu_t* cpu);

/************ 8bits load ***************/

extern void LD_r8_r8(Cpu_t* cpu, uint8_t* registre1, uint8_t* registre2);
extern void LD_r8_mem_HL(Cpu_t* cpu, uint8_t* registre, uint8_t* memory);
extern void LD_r8_d8(Cpu_t* cpu, uint8_t* registre, uint8_t* memory);

extern void LD_mem_HL_r8(Cpu_t* cpu, uint8_t* registre, uint8_t* memory);
extern void LD_mem_HL_d8(Cpu_t* cpu, uint8_t* memory);

extern void LD_A_mem_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory);
extern void LD_mem_r16_A(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory);

extern void LD_A_a16(Cpu_t* cpu, uint8_t* memory);
extern void LD_a16_A(Cpu_t* cpu, uint8_t* memory);

extern void LD_A_a8(Cpu_t* cpu, uint8_t* memory);
extern void LD_a8_A(Cpu_t* cpu, uint8_t* memory);

extern void LD_A_mem_C(Cpu_t* cpu, uint8_t* memory);
extern void LD_mem_C_A(Cpu_t* cpu, uint8_t* memory);

extern void LDI_A_mem_HL(Cpu_t* cpu, uint8_t* memory);
extern void LDI_mem_HL_A(Cpu_t* cpu, uint8_t* memory);
extern void LDD_A_mem_HL(Cpu_t* cpu, uint8_t* memory);
extern void LDD_mem_HL_A(Cpu_t* cpu, uint8_t* memory);

/************ 16bits load ***************/

extern void LD_r16_d16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory);
extern void LD_SP_d16(Cpu_t* cpu, uint8_t* memory);

extern void LD_a16_SP(Cpu_t* cpu, uint8_t* memory);

extern void LD_SP_HL(Cpu_t* cpu);

extern void PUSH_r16(Cpu_t* cpu,uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory);
extern void POP_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory);

/************ 16bits arithmetic / logic ***************/

extern void ADD_HL_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low);
extern void ADD_HL_SP(Cpu_t* cpu);

extern void INC_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low);
extern void INC_SP(Cpu_t* cpu);

extern void DEC_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low);
extern void DEC_SP(Cpu_t* cpu);

extern void ADD_SP_dd(Cpu_t* cpu, uint8_t* memory);
extern void LD_HL_SP_dd(Cpu_t* cpu, uint8_t* memory);

/************ 8bits rotate / shift ***************/

extern void RLCA(Cpu_t* cpu);
extern void RLA(Cpu_t* cpu);
extern void RRCA(Cpu_t* cpu);
extern void RRA(Cpu_t* cpu);

extern void RLC_r8(Cpu_t* cpu, uint8_t* registre);
extern void RLC_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void RRC_r8(Cpu_t* cpu, uint8_t* registre);
extern void RRC_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void RL_r8(Cpu_t* cpu, uint8_t* registre);
extern void RL_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void RR_r8(Cpu_t* cpu, uint8_t* registre);
extern void RR_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void SLA_r8(Cpu_t* cpu, uint8_t* registre);
extern void SLA_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void SRA_r8(Cpu_t* cpu, uint8_t* registre);
extern void SRA_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void SRL_r8(Cpu_t* cpu, uint8_t* registre);
extern void SRL_mem_HL(Cpu_t* cpu, uint8_t* memory);

extern void SWAP_r8(Cpu_t* cpu, uint8_t* registre);
extern void SWAP_mem_HL(Cpu_t* cpu, uint8_t* memory);

/************ 8bits single Bit ***************/

extern void BIT_r8(Cpu_t* cpu, uint8_t pos, uint8_t* registre);
extern void BIT_mem_HL(Cpu_t* cpu, uint8_t pos, uint8_t* memory);

extern void SET_r8(Cpu_t* cpu, uint8_t pos, uint8_t* registre);
extern void SET_mem_HL(Cpu_t* cpu, uint8_t pos, uint8_t* memory);

extern void RES_r8(Cpu_t* cpu, uint8_t pos, uint8_t* registre);
extern void RES_mem_HL(Cpu_t* cpu, uint8_t pos, uint8_t* memory);

#endif //__INSTRUCTIONS_H__