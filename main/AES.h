#ifndef AES_H
#define AES_H
#include "keyexpansion.h"

// //constants for 128-bit AES
// const int Nb = 4; //block size
// const int Nr = 10; //number of rounds

void Cipher(unsigned char in[4 * Nb], unsigned char out[4 * Nb], unsigned char word[Nb*(Nr + 1)][4]);
void InvCipher(unsigned char in[4 * Nb], unsigned char out[4 * Nb], unsigned char word[Nb*(Nr + 1)][4]);

#endif