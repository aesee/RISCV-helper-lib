#include "Riscv.h"

struct reg
{
    static constexpr uint64_t testAddr = 0x10021000U;
    static constexpr uint64_t testAddr2 = 0x10021015U;
};

void testReadWrite();
void testContext();

int main()
{
    // Trap for the exceptions
    riscv::init();

    testReadWrite();

    testContext();

    return 0;
}

void testReadWrite()
{
    riscv::value(reg::testAddr) = 192;

    auto testVariable = riscv::value(reg::testAddr);

    riscv::value(reg::testAddr) = 0;
    riscv::bits(reg::testAddr).b2 = 1;

    auto cycles = riscv::csr::readMcycle();
    auto status = riscv::csr::readMstatus();

    riscv::s5::write(0x1111111111111111);
    auto x31 = riscv::t6::read();
}

void testContext()
{
	riscv::a0::write(10);
    riscv::a1::write(10);
    riscv::a2::write(10);
    riscv::a3::write(10);
    riscv::a4::write(10);
    riscv::a5::write(10);
    riscv::a6::write(10);
    riscv::a7::write(10);
    //auto context = riscv::saveContext();
	riscv::a0::write(0);
    riscv::a1::write(0);
    riscv::a2::write(0);
    riscv::a3::write(0);
    riscv::a4::write(0);
    riscv::a5::write(0);
    riscv::a6::write(0);
    riscv::a7::write(0);
    //riscv::restoreContext(*context);
}
