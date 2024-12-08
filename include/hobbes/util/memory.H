#ifndef HOBBES_UTIL_MEMORY_H_INCLUDED
#define HOBBES_UTIL_MEMORY_H_INCLUDED

#include <cstddef>
#include <memory>
#include <type_traits>
#include "region.H"

namespace hobbes {

// Check if a pointer has static lifetime (allocated in static/global memory or from a region)
inline bool isStaticLifetime(const void* ptr, const region& r) {
    // Null pointers are always safe
    if (ptr == nullptr) {
        return true;
    }

    // Check if the pointer belongs to the region's memory
    if (r.contains(ptr)) {
        return true;
    }

    // For other pointers, we consider them unsafe
    return false;
}

} // namespace hobbes

#endif
