#include "cpu.h"

/**
 * @brief LD r8, r8
 * 
 * @param cpu 
 * @param registre1 
 * @param registre2 
 */
void
LD_r8_r8(Cpu_t* cpu, uint8_t* registre1, uint8_t* registre2)
{
    if (!cpu || !registre1 || !registre2)
        return;
    
    *registre1 = *registre2;

    //FLAGS NOT CHANGED

    cpu->timer = 4;
    cpu->PC++;
}

/**
 * @brief LD r8, (HL)
 * 
 * @param cpu 
 * @param registre 
 * @param memory 
 */
void
LD_r8_mem_HL(Cpu_t* cpu, uint8_t* registre, uint8_t* memory)
{
    if (!cpu || !registre || !memory)
        return;
    
    *registre = memory[(cpu->H << 8) + cpu->L];

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LD r8, n
 * 
 * @param cpu 
 * @param registre 
 * @param memory 
 */
void
LD_r8_d8(Cpu_t* cpu, uint8_t* registre, uint8_t* memory)
{
    if (!cpu || !registre || !memory)
        return;

    *registre = memory[++cpu->PC];

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LD (HL), r8
 * 
 * @param cpu 
 * @param registre 
 * @param memory 
 */
void
LD_mem_HL_r8(Cpu_t* cpu, uint8_t* registre, uint8_t* memory)
{
    if (!cpu || !registre || !memory)
        return;
    
    memory[(cpu->H << 8) + cpu->L] = *registre;

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LD (HL), n
 * 
 * @param cpu 
 * @param memory 
 */
void
LD_mem_HL_d8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];

    memory[(cpu->H << 8) + cpu->L] = imediate_data;

    //FLAGS NOT CHANGED

    cpu->timer = 12;
    cpu->PC++;
}

/**
 * @brief LD A, (BC)
 *        LD A, (DE)
 * 
 */
void
LD_A_mem_r16(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory)
{
    if (!cpu || !registre_high || !registre_low || !memory)
        return;
    
    cpu->A = memory[(*registre_high << 8) + *registre_low];

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LD (BC), A
 *        LD (DE), A
 * 
 * @param cpu 
 * @param registre_high 
 * @param registre_low 
 * @param memory 
 */
void
LD_mem_r16_A(Cpu_t* cpu, uint8_t* registre_high, uint8_t* registre_low, uint8_t* memory)
{
    if (!cpu || !registre_high || !registre_low || !memory)
        return;
    
    memory[(*registre_high << 8) + *registre_low] = cpu->A;

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LD A, (a16)
 * 
 * @param cpu 
 * @param memory 
 */
void
LD_A_a16(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    cpu->A = memory[CPU_get_little_endian_data16bits(cpu, memory)];

    //FLAGS NOT CHANGED

    cpu->timer = 16;
    cpu->PC += 3;
}

/**
 * @brief LD (a16), A
 * 
 */
void
LD_a16_A(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    memory[CPU_get_little_endian_data16bits(cpu, memory)] = cpu->A;

    //FLAGS NOT CHANGED

    cpu->timer = 16;
    cpu->PC += 3;
}

/**
 * @brief LD A, (a8)
 * 
 * @param cpu 
 * @param memory 
 */
void
LD_A_a8(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];

    cpu->A = memory[0xFF00 + imediate_data];

    //FLAGS NOT CHANGED

    cpu->timer = 12;
    cpu->PC++;
}

/**
 * @brief LD (a8), A
 * 
 * @param cpu 
 * @param memory 
 */
void
LD_a8_A(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint8_t imediate_data = memory[++cpu->PC];

    memory[0xFF00 + imediate_data] = cpu->A;

    //FLAGS NOT CHANGED

    cpu->timer = 12;
    cpu->PC++;
}

/**
 * @brief LD A, (C)
 * 
 * @param cpu 
 * @param memory 
 */
void
LD_A_mem_C(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    cpu->A = memory[0xFF00 + cpu->C];

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LD (C), A
 * 
 */
void
LD_mem_C_A(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    memory[0xFF00 + cpu->C] = cpu->A;

    //FLAGS NOT CHANGED

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LDi A, (HL) / LD A, (HL+)
 * 
 * @param cpu 
 * @param memory 
 */
void
LDI_A_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;

    uint16_t HL = (cpu->H << 8) + cpu->L;

    cpu->A = memory[HL];

    HL = (HL + 1) & 0xFFFF;

    //FLAGS NOT CHANGED

    cpu->H = (HL & 0xFF00) >> 8;
    cpu->L = HL & 0x00FF;

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LDi (HL), A / LD (HL+), A
 * 
 * @param cpu 
 * @param memory 
 */
void
LDI_mem_HL_A(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint16_t HL = (cpu->H << 8) + cpu->L;

    memory[HL] = cpu->A;

    HL = (HL + 1) & 0xFFFF;

    //FLAGS NOT CHANGED

    cpu->H = (HL & 0xFF00) >> 8;
    cpu->L = HL & 0x00FF;

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LDd A, (HL) / LD A, (HL-)
 * 
 * @param cpu 
 * @param memory 
 */
void
LDD_A_mem_HL(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;
    
    uint16_t HL = (cpu->H << 8) + cpu->L;

    cpu->A = memory[HL];

    HL = (HL - 1) & 0xFFFF;

    //FLAGS NOT CHANGED

    cpu->H = (HL & 0xFF00) >> 8;
    cpu->L = HL & 0x00FF;

    cpu->timer = 8;
    cpu->PC++;
}

/**
 * @brief LDd (HL), A / LD (HL-), A
 * 
 * @param cpu 
 * @param memory 
 */
void
LDD_mem_HL_A(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        return;

    uint16_t HL = (cpu->H << 8) + cpu->L;

    memory[HL] = cpu->A;

    HL = (HL - 1) & 0xFFFF;

    //FLAGS NOT CHANGED

    cpu->H = (HL & 0xFF00) >> 8;
    cpu->L = HL & 0x00FF;

    cpu->timer = 8;
    cpu->PC++;
}