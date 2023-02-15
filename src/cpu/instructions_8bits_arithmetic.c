#include "cpu.h"
#include "flag.h"

void
ADD_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t accumulator = (cpu->A + *registre) & 0xFF;

    CPU_set_flag_ADD_8(cpu, cpu->A, *registre);

    cpu->A = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
ADD_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];
    uint8_t accumulator = (cpu->A + imediate_data) & 0XFF;

    CPU_set_flag_ADD_8(cpu, cpu->A, imediate_data);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
ADD_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t accumulator = (cpu->A + HL) & 0xFF;

    CPU_set_flag_ADD_8(cpu, cpu->A, HL);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
ADC_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;

    uint8_t C = (cpu->F & CARRY_FLAG) >> 4;
    uint8_t accumulator = (cpu->A + *registre + C) & 0xFF;

    CPU_set_flag_ADC_8(cpu, cpu->A, *registre);

    cpu->A = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
ADC_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];
    uint8_t C = (cpu->F & CARRY_FLAG) >> 4;
    uint8_t accumulator = (cpu->A + imediate_data + C) & 0xFF;

    CPU_set_flag_ADC_8(cpu, cpu->A, imediate_data);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
ADC_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t C = (cpu->F & CARRY_FLAG) >> 4;
    uint8_t accumulator = (cpu->A + HL + C) & 0xFF;

    CPU_set_flag_ADC_8(cpu, cpu->A, HL);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
SUB_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t accumulator = (cpu->A - *registre) & 0xFF;

    if (registre == &cpu->A) //Si le registre est le registre A
        CPU_set_flag_SUB_8_A(cpu);
    else
        CPU_set_flag_SUB_8(cpu, cpu->A, *registre);

    cpu->A = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
SUB_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];
    uint8_t accumulator = (cpu->A - imediate_data) & 0xFF;

    CPU_set_flag_SUB_8(cpu, cpu->A, imediate_data);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
SUB_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;

    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t accumulator = (cpu->A - HL) & 0xFF;

    CPU_set_flag_SUB_8(cpu, cpu->A, HL);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
SBC_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t C = (cpu->F & CARRY_FLAG) >> 4;
    uint8_t accumulator = (cpu->A - *registre - C) & 0xFF;

    if (registre == &cpu->A)
        CPU_set_flag_SBC_8_A(cpu, cpu->A, *registre);
    else
        CPU_set_flag_SBC_8(cpu, cpu->A, *registre);
    
    cpu->A = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
SBC_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t C = (cpu->F & CARRY_FLAG) >> 4;
    uint8_t imediate_data = memory[++cpu->PC];
    uint8_t accumulator = (cpu->A - imediate_data - C) & 0xFF;

    CPU_set_flag_SBC_8(cpu, cpu->A, imediate_data);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
SBC_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t C = (cpu->F & CARRY_FLAG) >> 4;
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t accumulator = (cpu->A - HL - C) & 0xFF;

    CPU_set_flag_SBC_8(cpu, cpu->A, HL);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
AND_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t accumulator = (cpu->A & *registre) & 0xFF;

    CPU_set_flag_AND_8(cpu, cpu->A, *registre);

    cpu->A = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
AND_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;

    uint8_t imediate_data = memory[++cpu->PC];
    uint8_t accumulator = (cpu->A & imediate_data) & 0xFF;

    CPU_set_flag_AND_8(cpu, cpu->A, imediate_data);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
AND_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t accumulator = (cpu->A & HL) & 0xFF;

    CPU_set_flag_AND_8(cpu, cpu->A, HL);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
XOR_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t accumulator = (cpu->A ^ *registre) & 0xFF;

    if (registre == &cpu->A)
        CPU_set_flag_XOR_8_A(cpu);
    else
        CPU_set_flag_XOR_8(cpu, cpu->A, *registre);

    cpu->A = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
XOR_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];
    uint8_t accumulator = (cpu->A ^ imediate_data) & 0xFF;

    CPU_set_flag_XOR_8(cpu, cpu->A, imediate_data);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
XOR_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t accumulator = (cpu->A ^ HL) & 0xFF;

    CPU_set_flag_XOR_8(cpu, cpu->A, HL);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
OR_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t accumulator = (cpu->A | *registre) & 0xFF;

    CPU_set_flag_OR_8(cpu, cpu->A, *registre);
    
    cpu->A = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
OR_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];
    uint8_t accumulator = (cpu->A | imediate_data) & 0xFF;

    CPU_set_flag_OR_8(cpu, cpu->A, imediate_data);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
OR_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t accumulator = (cpu->A | HL) & 0xFF;

    CPU_set_flag_OR_8(cpu, cpu->A, HL);

    cpu->A = accumulator;
    cpu->timer = 8;
    cpu->PC++;
}

void
CP_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    if (registre == &cpu->A)
        CPU_set_flag_SUB_8_A(cpu);
    else
        CPU_set_flag_SUB_8(cpu, cpu->A, *registre);
    
    cpu->timer = 4;
    cpu->PC++;
}

void
CP_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];

    CPU_set_flag_SUB_8(cpu, cpu->A, imediate_data);

    cpu->timer = 8;
    cpu->PC++;
}

void
CP_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];

    CPU_set_flag_SUB_8(cpu, cpu->A, HL);

    cpu->timer = 8;
    cpu->PC++;
}

void
INC_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t accumulator = (*registre + 1) & 0xFF;

    CPU_set_flag_INC_8(cpu, *registre);

    *registre = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
INC_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t accumulator = (HL + 1) & 0xFF;

    CPU_set_flag_INC_8(cpu, HL);

    memory[(cpu->H << 8) + cpu->L] = accumulator;
    cpu->timer = 12;
    cpu->PC++;
}

void
DEC_r8(Cpu_t* cpu, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t accumulator = (*registre - 1) & 0xFF;

    CPU_set_flag_DEC_8(cpu, *registre);

    *registre = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
DEC_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t accumulator = (HL - 1) & 0xFF;

    CPU_set_flag_DEC_8(cpu, HL);

    memory[(cpu->H << 8) + cpu->L] = accumulator;
    cpu->timer = 12;
    cpu->PC++;
}

void
CPL(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    uint8_t accumulator = (cpu->A ^ 0xFF) & 0xFF;

    CPU_set_flag_CPL(cpu);

    cpu->A = accumulator;
    cpu->timer = 4;
    cpu->PC++;
}

void
DAA(Cpu_t* cpu)
{
    if (!cpu)
        return;

    //GET FLAG VALUE
    uint8_t zero_flag = (cpu->F & ZERO_FLAG) >> 7;
    uint8_t substract_flag = (cpu->F & SUB_FLAG) >> 6;
    uint8_t half_carry_flag = (cpu->F & HALF_FLAG) >> 5;
    uint8_t carry_flag = (cpu->F & CARRY_FLAG) >> 4;

    if (substract_flag) //if the last operation was a subtraction
    {
        if (carry_flag || cpu->A > 0x99)
        {
            cpu->A = (cpu->A + 0x60) & 0xFF;
            cpu->F = cpu->F | CARRY_FLAG;
        }

        if (half_carry_flag || (cpu->A & 0xF) > 0x09)
            cpu->A = (cpu->A + 0x6) & 0xFF;

    }
    else //if the last operation was an addition
    {
        if (carry_flag)
            cpu->A = (cpu->A - 0x60) & 0xFF;

        if (half_carry_flag)
            cpu->A = (cpu->A - 0x6) & 0xFF;
    }

    //ZERO FLAG
    if (cpu->A == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //HALF CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);
}