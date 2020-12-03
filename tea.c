/*
 * Implementation of TEA - Tiny Encryption Algorithm
 * Coded by: ringzer0dev
 * Originally designed by Wheeler and Needham, 1994 
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#define __STDC_FORMAT_MACROS

uint64_t KEY[4]; // Key space for bit shifts in encryption, decryption functions


void encrypt(uint64_t *v) {
    uint64_t v0 = v[0], v1 = v[1], sum = 0, i; // v0 init
    uint64_t delta = 0x123457898765432; // a key schedule constant    
    /*
     * This loop performs bit shifts and performs XOR on v0 and v1, which are of subdivisions the v[] array. 
     * 32 iterations per sub-array and assigns the result of each operation in the position 0 and 1 of vector v[]
     */
    for (i = 0; i < 32; i++) {
        sum += delta;
        v0 += ((v1 << 4) + KEY[0]) ^ (v1 + sum) ^ ((v1 >> 5) + KEY[1]);
        v1 += ((v0 << 4) + KEY[2]) ^ (v0 + sum) ^ ((v0 >> 5) + KEY[3]);
    }
    v[0] = v0;
    v[1] = v1;
}
