#ifndef REG_ACCESS_H
#define REG_ACCESS_H

typedef uint64_t addr_type;
typedef uint64_t reg_type;

template<const addr_type addr,
         const reg_type val = 0>
class reg_access
{
    public:
        static void reg_set()
        {
             *reinterpret_cast<volatile reg_type*>(addr) = val;
        }

        static void reg_or()
        {
            *reinterpret_cast<volatile reg_type*>(addr) |= val;
        }
};

#endif // REG_ACCESS_H
