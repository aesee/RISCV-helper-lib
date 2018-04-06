#ifndef REG_MAP_H
#define REG_MAP_H
#include <cstdint>
#include "bit64_type.h"

template<const addr_type addr>
class reg_map
{
    public:
        typedef uint64_t addr_type;
        typedef uint64_t reg_type;
        typedef bit64_type bits_type;

        static reg_type& value()
        {
            return
             *reinterpret_cast<reg_type*>(addr);
        }

        static bits_type& bits()
        {
            return
             *reinterpret_cast<bits_type*>(addr);
        }
};

#endif // REG_MAP_H
