#ifndef HOBBES_UTIL_MEMORY_H_INCLUDED
#define HOBBES_UTIL_MEMORY_H_INCLUDED

#include <cstddef>
#include <stdexcept>
#include "region.H"

namespace hobbes {

// Check if a pointer has static lifetime (allocated in static/global memory or from a region)
inline bool isStaticLifetime(const void* ptr, const region& r) {
    // Null pointers are always safe
    if (ptr == nullptr) {
        return true;
    }

    // Get the address range of static/global memory
    extern char __data_start;    // Start of data segment
    extern char _end;           // End of data/bss segment

    // Check if the pointer falls within static/global memory range
    if (reinterpret_cast<const char*>(ptr) >= &__data_start &&
        reinterpret_cast<const char*>(ptr) <= &_end) {
        return true;
    }

    // Check if the pointer belongs to the region's memory
    return r.contains(ptr);
}

} // namespace hobbes

#endif
