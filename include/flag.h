#ifndef FLAG_H
#define FLAG_H

#include <stdatomic.h>
typedef struct Cpu_t Cpu_t;

//---------FLAGS--------------------

#define ZERO_FLAG   0b10000000
#define SUB_FLAG    0b01000000
#define HALF_FLAG   0b00100000
#define CARRY_FLAG  0b00010000

//---------------------------------

/**
 * @brief SET FLAG OF ADD 8bits
 * Z0HC
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_ADD_8(Cpu_t* cpu, uint8_t value1, uint8_t value2);

/**
 * @brief SET FLAG OF ADC 8bits
 * Z0HC
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_ADC_8(Cpu_t* cpu, uint8_t value1, uint8_t value2);

/**
 * @brief SET FLAG OF SUB / CP 8bits
 * Z1HC
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_SUB_8(Cpu_t* cpu, uint8_t value1, uint8_t value2);

/**
 * @brief SET FLAG OF SUB / CP 8bits A
 * 1100
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_SUB_8_A(Cpu_t* cpu);

/**
 * @brief SET FLAG OF SBC 8bits
 * Z1HC
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_SBC_8(Cpu_t* cpu, uint8_t value1, uint8_t value2);

/**
 * @brief SET FLAG SBC 8bits A
 * Z1H-
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_SBC_8_A(Cpu_t* cpu, uint8_t value1, uint8_t value2);

/**
 * @brief SET FLAG AND 8bits
 * Z010
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_AND_8(Cpu_t* cpu, uint8_t value1, uint8_t value2);

/**
 * @brief SET FLAG XOR 8bits
 * Z000
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_XOR_8(Cpu_t* cpu, uint8_t value1, uint8_t value2);

/**
 * @brief SET FLAG XOR 8bits A
 * 1000
 * @param cpu 
 */
extern void CPU_set_flag_XOR_8_A(Cpu_t* cpu);

/**
 * @brief SET FLAG OR 8bits
 * Z000
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_OR_8(Cpu_t* cpu, uint8_t value1, uint8_t value2);

/**
 * @brief SET FLAG INC 8bits
 * Z0H-
 * @param cpu 
 * @param value1 
 */
extern void CPU_set_flag_INC_8(Cpu_t* cpu, uint8_t value1);

/**
 * @brief SET FLAG DEC 8bits
 * Z1H-
 * @param cpu 
 * @param value1 
 */
extern void CPU_set_flag_DEC_8(Cpu_t* cpu, uint8_t value1);

/**
 * @brief SET FLAG CPL 8bits
 * -11-
 * @param cpu 
 */
extern void CPU_set_flag_CPL(Cpu_t* cpu);

/**
 * @brief SET FLAG ADD HL, r16
 * -0HC
 * 
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_ADD_16bits_HL(Cpu_t* cpu, uint16_t value1, uint16_t value2);

/**
 * @brief ADD SP, e / LD HL, SP + r8
 * 00HC
 * 
 * @param cpu 
 * @param value1 
 * @param value2 
 */
extern void CPU_set_flag_ADD_SP_dd(Cpu_t* cpu, uint16_t value1, int8_t value2);

/**
 * @brief SET FLAG to RLCA, RLA, RRCA, RRA
 * 
 * @param cpu 
 */
extern void CPU_set_flag_rotate_A(Cpu_t* cpu);

/**
 * @brief FLAG to RLC, RRC, RL, RR, SLA, SRA
 * 
 * @param cpu 
 * @param value 
 */
extern void CPU_set_flag_rotate(Cpu_t* cpu, uint8_t value);

/**
 * @brief SET FLAG SWAP instruction
 * 
 * @param cpu 
 * @param value 
 */
extern void CPU_set_flag_SWAP(Cpu_t* cpu, uint8_t value);

#endif //FLAG_H