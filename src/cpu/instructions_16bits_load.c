#include "cpu.h"

/**
 * @brief LD rr, d16
 * 
 * LD BC, d16
 * LD DE, d16
 * LD HL, d16
 * LD SP, d16
 * 
 * @param cpu 
 * @param registre_high 
 * @param registre_low 
 * @param memory 
 */
void
LD_r16_d16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory)
{
    if (!cpu || !registre_high || !registre_low || !memory)
        return;
    
    uint16_t imediate_data = CPU_get_little_endian_data16bits(cpu, memory);
    
    *registre_high = (imediate_data & 0xFF00) >> 8;
    *registre_low = imediate_data & 0x00FF;

    //FLAGS NOT CHANGED

    cpu->timer = 12;
    cpu->PC += 3;
}

/**
 * @brief LD SP, d16
 * 
 * @param cpu 
 * @param memory 
 */
void
LD_SP_d16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint16_t imediate_data = CPU_get_little_endian_data16bits(cpu, memory);

    //FLAG NOT CHANGED

    cpu->SP = imediate_data;
    
    cpu->timer = 12;
    cpu->PC += 3;
}

/**
 * @brief LD (a16), SP
 * 
 * @param cpu 
 * @param memory 
 */
void
LD_a16_SP(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint16_t imediate_data = CPU_get_little_endian_data16bits(cpu, memory);

    memory[imediate_data] = cpu->SP;

    //FLAGS NOT CHANGED

    cpu->timer = 20;
    cpu->PC += 3;
}

/**
 * @brief LD SP, HL
 * 
 * @param cpu 
 */
void
LD_SP_HL(Cpu_t* cpu)
{
    if (!cpu)
        return;

    cpu->SP = (cpu->H << 8) + cpu->L;

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief PUSH r16
 * 
 * @param cpu 
 */
void
PUSH_r16(Cpu_t* cpu,uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory)
{
    if (!cpu || !registre_high || !registre_low || !memory)
        return;
    
    memory[--cpu->SP] = *registre_high;
    memory[--cpu->SP] = *registre_low;

    //FLAGS NOT CHANGED

    cpu->timer = 16;
    cpu->PC++;
}

/**
 * @brief POP r16
 * 
 * @param cpu 
 * @param registre_high 
 * @param registre_low 
 * @param memory 
 */
void
POP_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory)
{
    if (!cpu || !registre_high || !registre_low || !memory)
        return;
    
    *registre_low = memory[cpu->SP++];
    *registre_high = memory[cpu->SP++];
    
    //FLAGS NOT CHANGED

    cpu->timer = 12;
    cpu->PC++;
}

