#include "cpu.h"
#include "flag.h"

/**
 * @brief ADD HL, r16
 * 
 * r16 = BC, DE, HL
 * 
 */
void
ADD_HL_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low)
{
    if (!cpu || !registre_high || !registre_low)
        return;
    
    uint16_t HL = (cpu->H << 8) + cpu->L;
    uint16_t r16 = (*registre_high << 8) + *registre_low;

    uint16_t accumulator = (HL + r16) & 0xFFFF;

    CPU_set_flag_ADD_16bits_HL(cpu, HL, r16);

    cpu->H = (accumulator & 0xFF00) >> 8;
    cpu->L = (accumulator & 0x00FF); 

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief ADD HL, SP
 * 
 * @param cpu 
 */
void
ADD_HL_SP(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    uint16_t HL = (cpu->H << 8) + cpu->L;
    uint16_t accumulator = (HL + cpu->SP) & 0xFFFF;

    CPU_set_flag_ADD_16bits_HL(cpu, HL, cpu->SP);

    cpu->H = (accumulator & 0xFF00) >> 8;
    cpu->L = (accumulator & 0x00FF);

    cpu->timer = 8;
    cpu->PC++;
}

void
INC_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low)
{
    if (!cpu || !registre_high || !registre_low)
        return;
    
    uint16_t r16 = (*registre_high << 8) + *registre_low;

    uint16_t accumulator = (r16 + 1) & 0xFFFF;

    *registre_high = (accumulator & 0xFF00) >> 8;
    *registre_low = (accumulator & 0x00FF);

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief INC SP
 * 
 * @param cpu 
 */
void
INC_SP(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    cpu->SP = (cpu->SP + 1) & 0xFFFF;

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief DEC r16
 * r16 = BC, DE, HL
 * 
 * @param cpu 
 * @param registre_high 
 * @param registre_low 
 */
void
DEC_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low)
{
    if (!cpu || !registre_high || !registre_low)
        return;
    
    uint16_t r16 = (*registre_high << 8) + *registre_low;
    uint16_t accumulator = (r16 - 1) & 0xFFFF;

    //FLAGS NOT CHANGED

    *registre_high = (accumulator & 0xFF00) >> 8;
    *registre_low = (accumulator & 0x00FF);

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief DEC SP
 * 
 * @param cpu 
 */
void
DEC_SP(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    cpu->SP = (cpu->SP - 1) & 0xFFFF;

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief ADD SP, r8
 * r8 means here signed imediate data
 * 
 * @param cpu 
 * @param memory 
 */
void
ADD_SP_dd(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    int8_t signed_imediate_data = memory[++cpu->PC];
    
    CPU_set_flag_ADD_SP_dd(cpu, cpu->SP, signed_imediate_data);

    cpu->SP = (cpu->SP + signed_imediate_data) & 0xFFFF;

    cpu->timer = 16;
    cpu->PC++;
}

/**
 * @brief LD HL, SP + r8
 * 
 */
void
LD_HL_SP_dd(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    int8_t signed_imediate_data = memory[++cpu->PC];

    CPU_set_flag_ADD_SP_dd(cpu, cpu->SP, signed_imediate_data);

    uint16_t HL = (cpu->SP + signed_imediate_data) & 0xFFFF;

    cpu->H = (HL & 0xFF00) >> 8;
    cpu->L = (HL & 0x00FF);

    cpu->timer = 12;
    cpu->PC++;
}