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
    
    uint8_t last_bit = (cpu->A & LAST_BIT);

    cpu->A <<= 1;

    if (last_bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        cpu->A = cpu->A | FIRST_BIT;
    }
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
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

    uint8_t last_bit = (cpu->A & LAST_BIT);
    uint8_t C = (cpu->F & CARRY_FLAG);

    cpu->A <<= 1;

    //SET THE 0th bit of A by the CARRY FLAG
    if (C)
        cpu->A = cpu->A | FIRST_BIT;
    
    //SET THE CARRY FLAG by the 7th bit of A
    if (last_bit)
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
    
    uint8_t first_bit = (cpu->A & FIRST_BIT);

    cpu->A >>= 1;

    if (first_bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        cpu->A = cpu->A | LAST_BIT;
    }
    else
        cpu->F = cpu->F & (~CARRY_FLAG);

    CPU_set_flag_rotate_A(cpu);

    cpu->timer = 4;
    cpu->PC++;
}

void
RRA(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    uint8_t first_bit = (cpu->A & FIRST_BIT);
    uint8_t C = (cpu->F & CARRY_FLAG);

    cpu->A >>= 1;

    //SET CARRY FLAG WITH VALUE OF 0th BIT
    if (first_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    //SET 7th BIT WITH VALUE OF CARRY FLAG
    if (C)
        cpu->A = cpu->A | LAST_BIT;

    CPU_set_flag_rotate_A(cpu);

    cpu->timer = 4;
    cpu->PC++;
}

void
RLC_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t last_bit = (*registre & LAST_BIT);

    *registre <<= 1;

    if (last_bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        *registre = *registre | FIRST_BIT;
    }
    else
        cpu->F = cpu->F & (~CARRY_FLAG);

    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
RLC_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu ||!memory)
        return;
    
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];


    uint8_t last_bit = (mem_HL & LAST_BIT);

    mem_HL <<= 1;

    if (last_bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        mem_HL = mem_HL | FIRST_BIT;
    }
    else
        cpu->F = cpu->F & (~CARRY_FLAG);

    CPU_set_flag_rotate(cpu, mem_HL);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    cpu->timer = 16;
    cpu->PC++;
}

void
RRC_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t first_bit = (*registre & FIRST_BIT);

    *registre >>= 1;

    if (first_bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        *registre = *registre | LAST_BIT;
    }
    else
        cpu->F = cpu->F & (~CARRY_FLAG);

    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
RRC_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];

    uint8_t first_bit = (mem_HL & FIRST_BIT);

    mem_HL >>= 1;

    if (first_bit)
    {
        cpu->F = cpu->F | CARRY_FLAG;
        mem_HL = mem_HL | LAST_BIT;
    }
    else
        cpu->F = cpu->F & (~CARRY_FLAG);

    CPU_set_flag_rotate(cpu, mem_HL);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    cpu->timer = 16;
    cpu->PC++;
}

void
RL_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t last_bit = (*registre & LAST_BIT);
    uint8_t C = (cpu->F & CARRY_FLAG);

    *registre <<= 1;

    if (last_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);


    if (C)
        *registre = *registre | FIRST_BIT;
    
    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
RL_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t last_bit = (mem_HL & LAST_BIT);
    uint8_t C = (cpu->F & CARRY_FLAG);

    mem_HL <<= 1;

    if (last_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);

    if (C)
        mem_HL = mem_HL | FIRST_BIT;
    
    CPU_set_flag_rotate(cpu, mem_HL);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    cpu->timer = 16;
    cpu->PC++;
}

void
RR_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t first_bit = (*registre & FIRST_BIT);
    uint8_t C = (cpu->F & CARRY_FLAG);

    *registre >>= 1;

    if (first_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    if (C)
        *registre = *registre | LAST_BIT;
    
    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
RR_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t first_bit = (mem_HL & FIRST_BIT);
    uint8_t C = (cpu->F & CARRY_FLAG);

    mem_HL >>= 1;

    if (first_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    if (C)
        mem_HL = mem_HL | LAST_BIT;

    CPU_set_flag_rotate(cpu, mem_HL);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    cpu->timer = 16;
    cpu->PC++;
}

void
SLA_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t last_bit = (*registre & LAST_BIT);

    *registre <<= 1;

    if (last_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    //the 0 is automatic for the side bit, no need to put it on

    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
SLA_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t last_bit = (mem_HL & LAST_BIT);

    mem_HL <<= 1;

    if (last_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    //the 0 is automatic for the side bit, no need to put it on

    CPU_set_flag_rotate(cpu, mem_HL);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    cpu->timer = 16;
    cpu->PC++;
}

void
SRA_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t first_bit = (*registre & FIRST_BIT);
    uint8_t last_bit = (*registre & LAST_BIT);

    *registre >>= 1;
    
    if (first_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    //put a 1 or stay 0 at the last bit
    *registre = *registre | last_bit;
    
    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
SRA_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];

    uint8_t first_bit = (mem_HL & FIRST_BIT);
    uint8_t last_bit = (mem_HL & LAST_BIT);

    mem_HL >>= 1;

    if (first_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    //put a 1 or stay 0 at the last bit
    mem_HL = mem_HL | last_bit;

    CPU_set_flag_rotate(cpu, mem_HL);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    cpu->timer = 16;
    cpu->PC++;
}

void
SRL_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t first_bit = (*registre & FIRST_BIT);

    *registre >>= 1;

    if (first_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    //the last bit is 0 with the rotate

    CPU_set_flag_rotate(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
SRL_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t first_bit = (mem_HL & FIRST_BIT);

    mem_HL >>= 1;

    if (first_bit)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
    
    //the last bit is 0 with the rotate

    CPU_set_flag_rotate(cpu, mem_HL);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    cpu->timer = 16;
    cpu->PC++;
}

void
SWAP_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t nybble_high = (*registre & 0xF0) >> 4; //high 4bits of register into low 4 bits
    *registre <<= 4; //lower 4 bits become 4 high bits
    *registre += nybble_high;

    CPU_set_flag_SWAP(cpu, *registre);

    cpu->timer = 8;
    cpu->PC++;
}

void
SWAP_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t nybble_high = (mem_HL & 0xF0) >> 4;

    mem_HL <<=4;
    mem_HL += nybble_high;

    CPU_set_flag_SWAP(cpu, mem_HL);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    cpu->timer = 16;
    cpu->PC++;
}