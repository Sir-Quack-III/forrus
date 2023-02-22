#include <iostream>
#include "forrus.hpp"

int main() {
    std::array<uint8_t, 16> inp = {2, 90, 126, 43, 183, 111, 40, 193, 205, 23, 153, 64, 93, 42, 82, 69};
    std::array<uint8_t, 16> out = forrus::hash(inp);
    
    for (int i = 0; i < inp.size(); i++) printf("%d, ", inp[i]);
    std::cout << std::endl;

    for (int i = 0; i < out.size(); i++) printf("%d, ", out[i]);
    std::cout << std::endl;

    printf("%d\n", forrus::round(128, 4));
    return 0;
}