#include "cpu.h"
#include "flag.h"

void
JP_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || memory)
        return;
    
    //FLAGS NOT CHANGED
    cpu->timer = 16;
    cpu->PC = CPU_get_little_endian_data16bits(cpu, memory);
}

void
JP_HL(Cpu_t *cpu)
{
    if (!cpu)
        return;

    //FLAGS NOT CHANGED
    cpu->timer = 4;
    cpu->PC = (cpu->H << 8) + cpu->L;
}

void
JP_NZ_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED
    
    if ((cpu->F & ZERO_FLAG) == 0) //if the ZERO FLAG is 0, so jump to a16
    {
        cpu->timer = 16;
        cpu->PC = CPU_get_little_endian_data16bits(cpu, memory);
    }
    else    //if ZERO FLAG is 1, so continue
    {
        cpu->timer = 12;
        cpu->PC += 3;
    }
}

void
JP_NC_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;

    //FLAGS NOT CHANGED

    if ((cpu->F & CARRY_FLAG) == 0) //if CARRY FLAG is 0, jump to a16
    {
        cpu->timer = 16;
        cpu->PC = CPU_get_little_endian_data16bits(cpu, memory);
    }
    else
    {
        cpu->timer = 12;
        cpu->PC += 3;
    }
}

void
JP_Z_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    if (cpu->F & ZERO_FLAG) //if ZERO FLAG is 1, jump to a16
    {
        cpu->timer = 16;
        cpu->PC = CPU_get_little_endian_data16bits(cpu, memory);
    }
    else
    {
        cpu->timer = 12;
        cpu->PC += 3;
    }
}

void
JP_C_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    if (cpu->F & CARRY_FLAG) //if CARRY FLAG is 1, jump to a16
    {
        cpu->timer = 16;
        cpu->PC = CPU_get_little_endian_data16bits(cpu, memory);
    }
    else
    {
        cpu->timer = 12;
        cpu->PC += 3;
    }
}

void
JR_dd(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    int8_t dd = memory[++cpu->PC];

    //FLAGS NOT CHANGED
    cpu->timer = 12;
    cpu->PC += dd;
}

void
JR_NZ_dd(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    int8_t dd = memory[++cpu->PC];

    //FLAGS NOT CHANGED
    
    if ((cpu->F & ZERO_FLAG) == 0) //if ZERO FLAG is 0, jmp to PC+dd
    {
        cpu->timer = 12;
        cpu->PC += dd;
    }
    else
    {
        cpu->timer = 8;
        cpu->PC++;
    }
}

void
JR_NC_dd(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    int8_t dd = memory[++cpu->PC];

    //FLAGS NOT CHANGED

    if ((cpu->F & CARRY_FLAG) == 0) //if CARRY FLAG is 0 jmp to PC+dd
    {
        cpu->timer = 12;
        cpu->PC += dd;
    }
    else
    {
        cpu->timer = 8;
        cpu->PC++;
    }
}

void
JR_Z_dd(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    int8_t dd = memory[++cpu->PC];

    //FLAGS NOT CHANGED

    if (cpu->F & ZERO_FLAG) //if ZERO FLAG is 1 jmp to PC+dd
    {
        cpu->timer = 12;
        cpu->PC += dd;
    }
    else
    {
        cpu->timer = 8;
        cpu->PC++;
    }
}

void
JR_C_dd(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    int8_t dd = memory[++cpu->PC];

    //FLAGS NOT CHANGED

    if (cpu->F & CARRY_FLAG) //if CARRY FLAG is 1 jmp to PC+dd
    {
        cpu->timer = 12;
        cpu->PC += dd;
    }
    else
    {
        cpu->timer = 8;
        cpu->PC++;
    }
}

void
CALL_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    uint16_t a16 = CPU_get_little_endian_data16bits(cpu, memory);

    cpu->PC += 3;
    memory[--cpu->SP] = (cpu->PC & 0xFF00) >> 8; //high 8bits of PC in the stack
    memory[--cpu->SP] = (cpu->PC & 0x00FF);      //low 8bits of PC in the stack

    cpu->timer = 24;
    cpu->PC = a16;
}

void
CALL_NZ_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    uint16_t a16 = CPU_get_little_endian_data16bits(cpu, memory);

    cpu->PC += 3;

    if ((cpu->F & ZERO_FLAG) == 0) //if ZERO FLAG is 0
    {
        memory[--cpu->SP] = (cpu->PC & 0xFF00) >> 8; //high 8bits of PC in the stack
        memory[--cpu->SP] = (cpu->PC & 0x00FF);      //low 8bits of PC in the stack

        cpu->timer = 24;
        cpu->PC = a16;
    }
    else
        cpu->timer = 12;
        //PC is on the next opcode
}

void
CALL_NC_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;

    //FLAGS NOT CHANGED

    uint16_t a16 = CPU_get_little_endian_data16bits(cpu, memory);

    cpu->PC += 3;

    if ((cpu->F & CARRY_FLAG) == 0) //if CARRY FLAG is 0
    {
        memory[--cpu->SP] = (cpu->PC & 0xFF00) >> 8;
        memory[--cpu->SP] = (cpu->PC & 0x00FF);

        cpu->timer = 24;
        cpu->PC = a16;
    }
    else
        cpu->timer = 12;
        //PC is on the next opcode
}

void
CALL_Z_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    uint16_t a16 = CPU_get_little_endian_data16bits(cpu, memory);

    cpu->PC += 3;

    if (cpu->F & ZERO_FLAG) //if ZERO FLAG is SET
    {
        memory[--cpu->SP] = (cpu->PC & 0xFF00) >> 8;
        memory[--cpu->SP] = (cpu->PC & 0x00FF);

        cpu->timer = 24;
        cpu->PC = a16;
    }
    else
        cpu->timer = 12;
        //PC is on the next opcode
}

void
CALL_C_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    uint16_t a16 = CPU_get_little_endian_data16bits(cpu, memory);

    cpu->PC += 3; 

    if (cpu->F & CARRY_FLAG) //if CARRY FLAG is SET
    {
        memory[--cpu->SP] = (cpu->PC & 0xFF00) >> 8;
        memory[--cpu->SP] = (cpu->PC & 0x00FF);

        cpu->timer = 24;
        cpu->PC = a16;
    }
    else
        cpu->timer = 12;
        //PC is on the next opcode
}

void
RET(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;

    //FLAGS NOT CHANGED

    uint8_t a16_low = memory[cpu->SP++];  //get low 8bits
    uint8_t a16_high = memory[cpu->SP++]; //get high 8bits

    cpu->timer = 16;
    cpu->PC = (a16_high << 8) + a16_low; //PC = a16
}

void
RETI(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;

    cpu->EMI = 1;
    RET(cpu, memory); //DO the RET
}

void
RET_NZ(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    if ((cpu->F & ZERO_FLAG) == 0) //if ZERO FLAG is reset
    {
        uint8_t a16_low = memory[cpu->SP++];  //get low 8bits
        uint8_t a16_high = memory[cpu->SP++]; //get high 8bits

        cpu->timer = 20;
        cpu->PC = (a16_high << 8) + a16_low;
    }
    else
    {
        cpu->timer = 8;
        cpu->PC++;
    }
}

void
RET_NC(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    if ((cpu->F & CARRY_FLAG) == 0)
    {
        uint8_t a16_low = memory[cpu->SP++];  //get low 8bits
        uint8_t a16_high = memory[cpu->SP++]; //get high 8bits

        cpu->timer = 20;
        cpu->PC = (a16_high << 8) + a16_low;
    }
    else
    {
        cpu->timer = 8;
        cpu->PC++;
    }
}

void
RET_Z(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    if (cpu->F & ZERO_FLAG)
    {
        uint8_t a16_low = memory[cpu->SP++];  //get low 8bits
        uint8_t a16_high = memory[cpu->SP++]; //get high 8bits

        cpu->timer = 20;
        cpu->PC = (a16_high << 8) + a16_low;
    }
    else
    {
        cpu->timer = 8;
        cpu->PC++;
    }
}

void
RET_C(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    //FLAGS NOT CHANGED

    if (cpu->F & CARRY_FLAG)
    {
        uint8_t a16_low = memory[cpu->SP++];  //get low 8bits
        uint8_t a16_high = memory[cpu->SP++]; //get high 8bits

        cpu->timer = 20;
        cpu->PC = (a16_high << 8) + a16_low;
    }
    else
    {
        cpu->timer = 8;
        cpu->PC++;
    }
}