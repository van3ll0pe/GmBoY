#ifndef __CPU_H__
#define __CPU_H__

#include <stdatomic.h>

#define LAST_BIT 0b10000000
#define FIRST_BIT 0b00000001

typedef struct Cpu_t{
    uint8_t A;
    uint8_t B;
    uint8_t C;
    uint8_t D;
    uint8_t E;
    uint8_t F;
    uint8_t H;
    uint8_t L;

    uint16_t PC;
    uint16_t SP;

    uint8_t EMI;

    uint8_t timer;
}Cpu_t;



/************ PROTOTYPES***************/
extern Cpu_t* CPU_create(void);
extern void CPU_destroy(Cpu_t* cpu);
extern uint16_t CPU_get_little_endian_data16bits(Cpu_t* cpu, uint8_t* memory);


#endif //__CPU_H__