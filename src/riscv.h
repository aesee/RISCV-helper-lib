#ifndef RISCV_H_INCLUDED
#define RISCV_H_INCLUDED
#include "bit64_type.h"

typedef uint64_t addr_type;
typedef uint64_t reg_type;
typedef bit64_type bits_type;

namespace riscv
{
        //reg_type& value(const addr_type addr);
		double& value(const addr_type addr);
        bits_type& bits(const addr_type addr);

        void reg_set(const addr_type addr, addr_type val);
        void reg_or(const addr_type addr, addr_type val);

        void init();
        void trap();

        class csr
        {
            public:
                static reg_type readMstatus();
                static reg_type readMcycle();
                static reg_type readMcause();
                static reg_type readMie();
                static reg_type readMip();
                static reg_type readMepc();
                static reg_type readMbadaddr();
                static void setMtvec(reg_type value);
        };

        //registers * saveContext();
        //void restoreContext(registers & regs);

        class ra {public: static void write(reg_type value); static reg_type read(); };
        class sp {public: static void write(reg_type value); static reg_type read(); };
        class gp {public: static void write(reg_type value); static reg_type read(); };
        class tp {public: static void write(reg_type value); static reg_type read(); };
        class t0 {public: static void write(reg_type value); static reg_type read(); };
        class t1 {public: static void write(reg_type value); static reg_type read(); };
        class t2 {public: static void write(reg_type value); static reg_type read(); };
        class s0 {public: static void write(reg_type value); static reg_type read(); };
        class s1 {public: static void write(reg_type value); static reg_type read(); };
        class a0 {public: static void write(reg_type value); static reg_type read(); };
        class a1 {public: static void write(reg_type value); static reg_type read(); };
        class a2 {public: static void write(reg_type value); static reg_type read(); };
        class a3 {public: static void write(reg_type value); static reg_type read(); };
        class a4 {public: static void write(reg_type value); static reg_type read(); };
        class a5 {public: static void write(reg_type value); static reg_type read(); };
        class a6 {public: static void write(reg_type value); static reg_type read(); };
        class a7 {public: static void write(reg_type value); static reg_type read(); };
        class s2 {public: static void write(reg_type value); static reg_type read(); };
        class s3 {public: static void write(reg_type value); static reg_type read(); };
        class s4 {public: static void write(reg_type value); static reg_type read(); };
        class s5 {public: static void write(reg_type value); static reg_type read(); };
        class s6 {public: static void write(reg_type value); static reg_type read(); };
        class s7 {public: static void write(reg_type value); static reg_type read(); };
        class s8 {public: static void write(reg_type value); static reg_type read(); };
        class s9 {public: static void write(reg_type value); static reg_type read(); };
        class s10 {public: static void write(reg_type value); static reg_type read(); };
        class s11 {public: static void write(reg_type value); static reg_type read(); };
        class t3 {public: static void write(reg_type value); static reg_type read(); };
        class t4 {public: static void write(reg_type value); static reg_type read(); };
        class t5 {public: static void write(reg_type value); static reg_type read(); };
        class t6 {public: static void write(reg_type value); static reg_type read(); };
};



// Set float support
/*static inline void
__attribute__((always_inline))
floatTurnOn()
{
    uint64_t tmp = readMstatus();
    const uint64_t addr = 0x2000;
	asm volatile (
        "or %[r], %[w], %[r]"
        : [r] "=r"(tmp)
		: [w] "rK"(addr)
		:

		"csrrs x0, mstatus, %[r]"
        :
		: [r] "rK"(tmp)
		:
	);
}*/

#endif // RISCV_H_INCLUDED
