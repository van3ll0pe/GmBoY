#include "cpu.h"
#include <stdlib.h>

/**
 * @brief INIT a pointer of Cpu_t
 * On failure returns NULL
 * 
 * @return Cpu_t* 
 */
Cpu_t*
CPU_create(void)
{
    Cpu_t*  cpu = malloc(sizeof(Cpu_t) * 1);
    if (!cpu)
        return NULL;
    
    cpu->A = 0;
    cpu->B = 0;
    cpu->C = 0;
    cpu->D = 0;
    cpu->E = 0;
    cpu->F = 0;
    cpu->H = 0;
    cpu->L = 0;
    cpu->PC = 0;
    cpu->SP = 0;
    cpu->timer = 0;

    cpu->EMI = 0;

    return cpu;
}

/**
 * @brief Free memory of pointer Cpu_t
 * 
 * @param cpu 
 */
void
CPU_destroy(Cpu_t* cpu)
{
    if (cpu)
        free(cpu);
}

/**
 * @brief get imediate_data 16bits in little endian to the good way
 * If there is error -> exit
 * else returns the 16bits value.
 * 
 * the function doesn't move the position of the PC register
 * 
 * @param cpu 
 * @param memory 
 * @return uint16_t 
 */
uint16_t
CPU_get_little_endian_data16bits(Cpu_t* cpu, uint8_t* memory)
{
    if (!cpu || !memory)
        exit(EXIT_FAILURE);
    
    uint16_t imediate_data = memory[cpu->PC + 2];
    imediate_data <<= 8;
    imediate_data += memory[cpu->PC + 1];

    return imediate_data;
}