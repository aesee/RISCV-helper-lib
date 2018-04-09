#include "Riscv.h"

//reg_type& riscv::value(const addr_type addr)
double& riscv::value(const addr_type addr)
{
	return
     //*reinterpret_cast<reg_type*>(addr);
	 *reinterpret_cast<double*>(addr);
}

bits_type& riscv::bits(const addr_type addr)
{
    return
     *reinterpret_cast<bits_type*>(addr);
}

void riscv::reg_set(const addr_type addr, addr_type val)
{
	*reinterpret_cast<volatile reg_type*>(addr) = val;
}

void riscv::reg_or(const addr_type addr, addr_type val)
{
	*reinterpret_cast<volatile reg_type*>(addr) |= val;
}

void riscv::init()
{
	asm("la x10, end_label");
    asm("csrrw x0, mtvec, x10");

	asm volatile("csrrs x11, mstatus, x0\nli x10, 0x2000\nor x11, x10, x11\nCSRRS x0, mstatus, x11");
}

void riscv::trap()
{
	asm("end_label:");
    asm("csrrs x9, mstatus, x0");//0x8000000a00007880
    asm("csrrs x10, mcause, x0");//0x8000000000000007
    asm("csrrs x11, mie, x0");//0x80
    asm("csrrs x12, mip, x0");//0x80
    asm("csrrs x13, mepc, x0");
    asm("csrrs x14, mbadaddr, x0");

    for(;;);
}

reg_type riscv::csr::readMstatus()
{
	reg_type tmp;

	asm volatile (
		"csrr %[r],mstatus"

        : [r] "=r"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
    	);

    return tmp;
}

reg_type riscv::csr::readMcycle()
{
	reg_type tmp;

    asm volatile (
    	"csrr %[r],mcycle"

        : [r] "=r"(tmp) /* Outputs */
        : /* Inputs */
        : /* Clobbers */
        );

    return tmp;
}

void riscv::ra::write(reg_type value)
{
	asm volatile(
    "mv x1, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::ra::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x1" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::sp::write(reg_type value)
{
	asm volatile(
    "mv x2, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::sp::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x2" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::gp::write(reg_type value)
{
	asm volatile(
    "mv x3, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::gp::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x3" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::tp::write(reg_type value)
{
	asm volatile(
    "mv x4, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::tp::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x4" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::t0::write(reg_type value)
{
	asm volatile(
    "mv x5, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::t0::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x5" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::t1::write(reg_type value)
{
	asm volatile(
    "mv x6, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::t1::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x6" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::t2::write(reg_type value)
{
	asm volatile(
    "mv x7, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::t2::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x7" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s0::write(reg_type value)
{
	asm volatile(
    "mv x8, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s0::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x8" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s1::write(reg_type value)
{
	asm volatile(
    "mv x9, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s1::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x9" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::a0::write(reg_type value)
{
	asm volatile(
    "mv x10, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::a0::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x10" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::a1::write(reg_type value)
{
	asm volatile(
    "mv x11, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::a1::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x11" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::a2::write(reg_type value)
{
	asm volatile(
    "mv x12, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::a2::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x12" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::a3::write(reg_type value)
{
	asm volatile(
    "mv x13, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::a3::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x13" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::a4::write(reg_type value)
{
	asm volatile(
    "mv x14, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::a4::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x14" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::a5::write(reg_type value)
{
	asm volatile(
    "mv x15, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::a5::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x15" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::a6::write(reg_type value)
{
	asm volatile(
    "mv x16, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::a6::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x16" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::a7::write(reg_type value)
{
	asm volatile(
    "mv x17, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::a7::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x17" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s2::write(reg_type value)
{
	asm volatile(
    "mv x18, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s2::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x18" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s3::write(reg_type value)
{
	asm volatile(
    "mv x19, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s3::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x19" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s4::write(reg_type value)
{
	asm volatile(
    "mv x20, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s4::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x20" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s5::write(reg_type value)
{
	asm volatile(
    "mv x21, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s5::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x21" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s6::write(reg_type value)
{
	asm volatile(
    "mv x22, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s6::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x22" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s7::write(reg_type value)
{
	asm volatile(
    "mv x23, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s7::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x23" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s8::write(reg_type value)
{
	asm volatile(
    "mv x24, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s8::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x24" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s9::write(reg_type value)
{
	asm volatile(
    "mv x25, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s9::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x25" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s10::write(reg_type value)
{
	asm volatile(
    "mv x26, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s10::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x26" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::s11::write(reg_type value)
{
	asm volatile(
    "mv x27, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::s11::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x27" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::t3::write(reg_type value)
{
	asm volatile(
    "mv x28, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::t3::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x28" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::t4::write(reg_type value)
{
	asm volatile(
    "mv x29, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::t4::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x29" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::t5::write(reg_type value)
{
	asm volatile(
    "mv x30, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::t5::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x30" : [res] "=r"(tmp) : :
    );
    return tmp;
}

void riscv::t6::write(reg_type value)
{
	asm volatile(
    "mv x31, %[v]" : :[v] "rK"(value) :
    );
}

reg_type riscv::t6::read()
{
	reg_type tmp;
    asm volatile(
    	"mv %[res], x31" : [res] "=r"(tmp) : :
    );
    return tmp;
}
