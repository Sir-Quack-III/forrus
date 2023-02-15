#include <stdint.h>
#include <array>

namespace forrus {
    uint8_t round(uint8_t inp, uint8_t key);
    std::array<uint8_t, 16> hash(std::array<uint8_t, 16> inp);
}
