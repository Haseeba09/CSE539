#ifndef KEYEXPANSION_H
#define KEYEXPANSION_H

//constants for 128-bit AES
const int Nb = 4; //block size
const int Nr = 10; //number of rounds
const int Nk = 4; //key length (in words)

void KeyExpansion(unsigned char key[4 * Nk], unsigned char w[Nb*(Nr + 1)][4]);

#endif