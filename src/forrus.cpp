#include "forrus.hpp"

unsigned char leftRotate(unsigned char val, int n) 
{ 
  unsigned int t; 
 
  t = val; 
 
  for(int i=0; i < n; i++) { 
    t = t << 1; 
 
    /* If a bit shifts out, it will be in bit 8 
       of the integer t. If this is the case, 
       put that bit on the right side. */ 
    if(t & 256) 
      t = t | 1; // put a 1 on the right end 
  } 
 
  return t; // return the lower 8 bits. 
} 

int myPow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}


// uint8_t leftRotate(uint8_t n, uint8_t d) {
//     return (n << d)|(n >> (8 - d));
// }

uint8_t forrus::round(uint8_t inp, uint8_t key) {
    uint8_t out = inp;

    out ^= key;
    out = leftRotate(out, 3);
    out = (uint8_t)(myPow((float)out, 5.0) % 173);
    out ^= (uint8_t)(myPow((float)key, 5.0) % 173);

    return out;
}

std::array<uint8_t, 16> forrus::hash(std::array<uint8_t, 16> inp) {
    std::array<uint8_t, 16> hash_in = inp;
    std::array<uint8_t, 16> hash_out = {0};

    for (size_t idx = 0; idx < 16; idx++) {
        uint8_t i = hash_in[idx];
        uint8_t c = round(i, 2);

        for (int d = 0; d < 14; d++) {
            c = round(c, 2);
        }

        hash_out[idx] = round(hash_in[idx], c);
    }

    return hash_out;
}