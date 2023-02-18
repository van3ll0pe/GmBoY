#include "flag.h"
#include "cpu.h"


void
CPU_set_flag_ADD_8(Cpu_t* cpu, uint8_t value1, uint8_t value2)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    if ((value1 + value2) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);

    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    if (((value1 & 0xF) + (value2 & 0xF)) & 0x10)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F = cpu->F & (~HALF_FLAG);
    
    //CARRY FLAG
    if ((value1 + value2) & 0x100)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_ADC_8(Cpu_t* cpu, uint8_t value1, uint8_t value2)
{
    if (!cpu)
        return;

    uint8_t C = (cpu->F & CARRY_FLAG) >> 4; //GET CARRY_FLAG

    //ZERO FLAG
    if ((value1 + value2 + C) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    if (((value1 & 0xF) + (value2 & 0xF) + C) & 0x10)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F = cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    if ((value1 + value2 + C) & 0x100)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_SUB_8(Cpu_t* cpu, uint8_t value1, uint8_t value2)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    if ((value1 - value2) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F | SUB_FLAG;

    //HALF CARRY FLAG
    if (((value1 & 0xF) - (value2 & 0xF)) & 0x10)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F = cpu->F & (~HALF_FLAG);
    
    //CARRY FLAG
    if ((value1 - value2) & 0x100)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_SUB_8_A(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    cpu->F = cpu->F | ZERO_FLAG;

    //SUB FLAG
    cpu->F = cpu->F | SUB_FLAG;

    //HALF CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_SBC_8(Cpu_t* cpu, uint8_t value1, uint8_t value2)
{
    if (!cpu)
        return;

    uint8_t C = (cpu->F & CARRY_FLAG) >> 4; //GET CARRY FLAG
    
    //ZERO FLAG
    if ((value1 - value2 - C) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F | SUB_FLAG;

    //HALF CARRY FLAG
    if (((value1 & 0xF) - (value2 & 0xF) - C) & 0x10)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F = cpu->F & (~HALF_FLAG);
    
    //CARRY FLAG
    if ((value1 - value2 - C) & 0x100)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_SBC_8_A(Cpu_t* cpu, uint8_t value1, uint8_t value2)
{
    if (!cpu)
        return;
    
    uint8_t C = (cpu->F & CARRY_FLAG) >> 4;

    //ZERO FLAG
    if ((value1 - value2 - C) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F | SUB_FLAG;
    
    //HALF CARRY FLAG
    if (((value1 & 0xF) - (value2 & 0xF) - C) & 0x10)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    //NOT CHANGED
}

void
CPU_set_flag_AND_8(Cpu_t* cpu, uint8_t value1, uint8_t value2)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    if ((value1 & value2) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    cpu->F = cpu->F | HALF_FLAG;

    //CARRY FLAG
    cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_XOR_8(Cpu_t* cpu, uint8_t value1, uint8_t value2)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    if ((value1 ^ value2) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_XOR_8_A(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    cpu->F = cpu->F | ZERO_FLAG;

    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_OR_8(Cpu_t* cpu, uint8_t value1, uint8_t value2)
{
    if (!cpu)
        return;

    //ZERO FLAG
    if ((value1 | value2) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    
    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);
}

void
CPU_set_flag_INC_8(Cpu_t* cpu, uint8_t value1)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    if ((value1 + 1) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY
    if (((value1 & 0xF) + 1) & 0x10)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F = cpu->F & (~HALF_FLAG);
    
    //CARRY FLAG
    //NOT CHANGED
}

void
CPU_set_flag_DEC_8(Cpu_t* cpu, uint8_t value1)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    if ((value1 - 1) & 0xFF == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F | SUB_FLAG;

    //HALF CARRY FLAG
    if (((value1 & 0xF) - 1) & 0x10)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F = cpu->F & (~HALF_FLAG);
    
    //CARRY FLAG
    //NOT CHANGED
}

void
CPU_set_flag_CPL(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    //NOT CHANGED

    //SUB FLAG
    cpu->F = cpu->F | SUB_FLAG;

    //HALF CARRY FLAG
    cpu->F = cpu->F | HALF_FLAG;

    //CARRY FLAG
    //NOT CHANGED
}

void
CPU_set_flag_ADD_16bits_HL(Cpu_t* cpu, uint16_t value1, uint16_t value2)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    //NOT CHANGED

    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    if (((value1 & 0xFFF)) + ((value2 & 0xFFF)) & 0x1000)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F = cpu->F & (~HALF_FLAG);
    
    //CARRY FLAG
    if ((value1 + value2) & 0x10000)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_ADD_SP_dd(Cpu_t* cpu, uint16_t value1, int8_t value2)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    cpu->F = cpu->F & (~ZERO_FLAG);

    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    if (((value1 & 0xF) + (value2 & 0xF)) & 0x10)
        cpu->F = cpu->F | HALF_FLAG;
    else
        cpu->F = cpu->F & (~HALF_FLAG);
    
    //CARRY FLAG
    if (((value1 & 0xFF) + value2) & 0x100)
        cpu->F = cpu->F | CARRY_FLAG;
    else
        cpu->F = cpu->F & (~CARRY_FLAG);
}


void
CPU_set_flag_rotate_A(Cpu_t* cpu)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    cpu->F = cpu->F & (~ZERO_FLAG);

    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    //CHECKED on function
}

void
CPU_set_flag_rotate(Cpu_t* cpu, uint8_t value)
{
    if (!cpu)
        return;

    //ZERO FLAG
    if (value == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);

    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    //CHECKED on function
}

void
CPU_set_flag_SWAP(Cpu_t* cpu, uint8_t value)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    if (value == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);

    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    cpu->F = cpu->F & (~HALF_FLAG);

    //CARRY FLAG
    cpu->F = cpu->F & (~CARRY_FLAG);
}

void
CPU_set_flag_BIT(Cpu_t* cpu, uint8_t value)
{
    if (!cpu)
        return;
    
    //ZERO FLAG
    if (value == 0)
        cpu->F = cpu->F | ZERO_FLAG;
    else
        cpu->F = cpu->F & (~ZERO_FLAG);
    
    //SUB FLAG
    cpu->F = cpu->F & (~SUB_FLAG);

    //HALF CARRY FLAG
    cpu->F = cpu->F | HALF_FLAG;

    //CARRY FLAG
    //NOT CHANGED
}