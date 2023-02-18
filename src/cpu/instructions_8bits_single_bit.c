#include "cpu.h"
#include "flag.h"
#include <math.h>

void
BIT_r8(Cpu_t* cpu, uint8_t pos, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t check_bit = (unsigned char)pow(2.0, (double)pos); //get the good bit with the position

    uint8_t value_bit = (*registre & check_bit);    //get the value of the bit pos in the register

    CPU_set_flag_BIT(cpu, value_bit);


    cpu->timer = 8;
    cpu->PC++;
}

void
BIT_mem_HL(Cpu_t* cpu, uint8_t pos, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t check_bit = (unsigned char)pow(2.0, (double)pos);

    uint8_t value_bit = (mem_HL & check_bit);

    CPU_set_flag_BIT(cpu, value_bit);

    cpu->timer = 12;
    cpu->PC++;
}

void
SET_r8(Cpu_t* cpu, uint8_t pos, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t check_bit = (unsigned char)pow(2.0, (double)pos);

    *registre = *registre | check_bit; // put the bit pos to 1

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

void
SET_mem_HL(Cpu_t* cpu, uint8_t pos, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];

    uint8_t check_bit = (unsigned char)pow(2.0, (double)pos);

    mem_HL = mem_HL | check_bit;

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    //FLAGS NOT CHANGED

    cpu->timer = 16;
    cpu->PC++;
}

void
RES_r8(Cpu_t* cpu, uint8_t pos, uint8_t* registre)
{
    if (!cpu || !registre)
        return;
    
    uint8_t check_bit = (unsigned char)pow(2.0, (double)pos);

    *registre = *registre & (~check_bit); //put the bit pos to 0

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

void
RES_mem_HL(Cpu_t* cpu, uint8_t pos, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t mem_HL = memory[(cpu->H << 8) + cpu->L];
    uint8_t check_bit = (unsigned char)pow(2.0, (double)pos);

    mem_HL = mem_HL & (~check_bit);

    memory[(cpu->H << 8) + cpu->L] = mem_HL;

    //FLAGS NOT CHANGED
    
    cpu->timer = 16;
    cpu->PC++;
}