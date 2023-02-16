#include "cpu.h"
#include "flag.h"
/**
 * @brief RLCA
 * 
 * 7th bit of A is copied into the carry flag and the 0th bit of A
 * after a rotate on the left.
 * 
 * @param cpu 
 */

void
RLCA(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    uint8_t save_7bit = (cpu->A & 0b10000000) >> 7; //0 ou 1

    cpu->A <<= 1;

    if (save_7bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        cpu->A = cpu->A | 0b00000001;
    }
    else
    {
        cpu->F = cpu->F & (~CARRY_FLAG);
        cpu->A = cpu->A & (~0b00000001);
    }
    
    CPU_set_flag_rotate_A(cpu);

    cpu->timer = 4;
    cpu->PC++;
}

/**
 * @brief RLA
 * the 7th bit of A is into CARRY FLAG, and the CARRY FLAG is copied into 0th bit of A;
 * 
 * @param cpu 
 */
void
RLA(Cpu_t* cpu)
{
    if (!cpu)
        return;

    uint8_t save_7bit = (cpu->A & 0b10000000) >> 7; //0 ou 1
    uint8_t C = (cpu->F & CARRY_FLAG) >> 4; //0 ou 1

    cpu->A <<= 1;

    //SET THE 0th bit of A by the CARRY FLAG
    if (C)
        cpu->A = cpu->A | 0b00000001;
    else
        cpu->A = cpu->A & (~0b00000001);
    
    //SET THE CARRY FLAG by the 7th bit of A
    if (save_7bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);

    CPU_set_flag_rotate_A(cpu);

    cpu->timer = 4;
    cpu->PC++;
}

/**
 * @brief RRCA
 * The 0th bit of A is copied into the CARRY FLAG and the 7th bit of A after the rotate
 * 
 * @param cpu 
 */
void
RRCA(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    uint8_t save_0bit = (cpu->A & 0b000000001); //0 ou 1

    cpu->A >>= 1;

    if (save_0bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        cpu->A = cpu->A | 0b10000000;
    }
    else
    {
        cpu->F = cpu->F & (~CARRY_FLAG);
        cpu->A = cpu->A & (~0b10000000);
    }

    CPU_set_flag_rotate_A(cpu);

    cpu->timer = 4;
    cpu->PC++;
}

void
RRA(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    uint8_t save_0bit = (cpu->A & 0b00000001); //0 ou 1
    uint8_t C = (cpu->F & CARRY_FLAG) >> 4; //0 ou 1

    cpu->A >>= 1;

    //SET CARRY FLAG WITH VALUE OF 0th BIT
    if (save_0bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    //SET 7th BIT WITH VALUE OF CARRY FLAG
    if (C)
        cpu->A = cpu->A | 0b10000000;
    else
        cpu->A = cpu->A & (~0b10000000);

    CPU_set_flag_rotate_A(cpu);

    cpu->timer = 4;
    cpu->PC++;
}

void
RLC_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t save_7bit = (*registre & 0b10000000) >> 7;

    *registre <<= 1;

    if (save_7bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        *registre = *registre | 0b00000001;
    }
    else
    {
        cpu->F = cpu->F & (~CARRY_FLAG);
        *registre = *registre & (~0b00000001);
    }

    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
RRC_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t save_0bit = (*registre & 0b00000001);

    *registre >>= 1;

    if (save_0bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        *registre = *registre | 0b100000000;
    }
    else
    {
        cpu->F = cpu->F & (~CARRY_FLAG);
        *registre = *registre & (~0b100000000);
    }

    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

