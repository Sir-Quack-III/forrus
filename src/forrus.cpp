#include "forrus.hpp"

uint8_t forrus::round(uint8_t inp, uint8_t key) {
    uint8_t out = inp;

    
}
std::array<uint8_t, 16> forrus::hash(std::array<uint8_t, 16> inp) {
    std::array<uint8_t, 16> hash_in = inp;
    std::array<uint8_t, 16> hash_out;

    size_t idx;

    for (size_t idx = 0; idx < 16; idx++) {
        uint8_t i = hash_in[idx];

    }

    return {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
}