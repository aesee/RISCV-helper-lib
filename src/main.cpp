#include <cstdint>
#include "reg_access.h"
#include "reg_map.h"
#include "riscv.h"

struct reg
{
    static constexpr uint64_t portb = 0x10021000U;
};

int main()
{
// mtvec
	asm("la x10, end_label"); //asm("la x10, mtvec_handler+1");
	asm("csrrw x0, mtvec, x10");

//============================================================

    reg_access<reg::portb,
               32000U>::reg_set();

    reg_access<reg::portb,
               0x20U>::reg_or();

    reg_map<reg::portb>::value() = 0U;

    reg_map<reg::portb>::bits().b1 = 1;

//============================================================
    int bp = 1;

    asm("end_label:");
    asm("csrrs x9, mstatus, x0");//0x8000000a00007880
    asm("csrrs x10, mcause, x0");//0x8000000000000007
    asm("csrrs x11, mie, x0");//0x80
    asm("csrrs x12, mip, x0");//0x80
    asm("csrrs x13, mepc, x0");
    asm("csrrs x14, mbadaddr, x0");//????

    for(;;);

    return 0;
}
