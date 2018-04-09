#include "Riscv.h"

struct reg
{
    static constexpr uint64_t testAddr = 0x10021000U;
    static constexpr uint64_t testAddr2 = 0x10021015U;
};

int main()
{
    riscv::init();

    riscv::value(reg::testAddr) = 192;

    auto testVariable = riscv::value(reg::testAddr);

    riscv::value(reg::testAddr) = 0;
    riscv::bits(reg::testAddr).b2 = 1;

    auto cycles = riscv::csr::readMcycle();
    auto status = riscv::csr::readMstatus();

    riscv::s5::write(0x1111111111111111);
    auto x31 = riscv::t6::read();

    return 0;
}
