#ifndef RISCV_H_INCLUDED
#define RISCV_H_INCLUDED

// Read mcycle CSR
static inline uint64_t
__attribute__((always_inline))
readMstatus()
{
	uint64_t tmp;

	asm volatile (
		"csrr %[r],mstatus"

		: [r] "=r"(tmp) /* Outputs */
		: /* Inputs */
		: /* Clobbers */
	);

	return tmp;
}

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

// Read mcycle CSR
static inline uint64_t
__attribute__((always_inline))
readMcycle()
{
	uint64_t tmp;

	asm volatile (
		"csrr %[r],mcycle"

		: [r] "=r"(tmp) /* Outputs */
		: /* Inputs */
		: /* Clobbers */
	);

	return tmp;
}

// Write value in x31
static inline void
__attribute__((always_inline))
writeInX31(uint64_t value)
{
	asm volatile (
		"mv x31, %[v]"

		: /* Outputs */
		: [v] "rK"(value) /* Inputs */
		: /* Clobbers */
	);
}

#endif // RISCV_H_INCLUDED
