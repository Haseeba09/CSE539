// CSE539 project - Paul Simerda
// professor Bazzi

// AES implementation

#include "AES.h"
#include "mixcolumns.h"
#include "shiftrows.h"
#include "subbytes.h"
#include "AddRoundKey.h"

void Cipher(unsigned char in[4*Nb], unsigned char out[4*Nb], unsigned char word[Nb*(Nr+1)][4]) {

	unsigned char state[4][4];

	//transforming input byte into a 2D block 
	for (int row = 0; row < (sizeof(state)/sizeof(state[0])); row++) {
		for (int col = 0; col < (sizeof(state[0])/sizeof(char)); col++) {
			state[row][col] = in[row*col];
		}
	}

	addRoundKey(state, word, 0);

	for(int round = 1; round<=Nr-1; round++) { //round = 1 step 1 to Nr–1
		subBytes(state, false); 
		shiftRows(state, false);
		MixColumns(state, false);
		addRoundKey(state, word, round);
	}

	subBytes(state, false);
	shiftRows(state, false);
	addRoundKey(state, word, Nr);

	//transforming 2D block into output byte 
	for (int row = 0; row < (sizeof(state) / sizeof(state[0])); row++) {
		for (int col = 0; col < (sizeof(state[0]) / sizeof(char)); col++) {
			out[row*col] = state[row][col];
		}
	}
}


void InvCipher(unsigned char in[4*Nb], unsigned char out[4*Nb], unsigned char word[Nb*(Nr+1)][4]) {

	unsigned char state[4][4];

	//transforming input byte into a 2D block 
	for (int row = 0; row < (sizeof(state) / sizeof(state[0])); row++) {
		for (int col = 0; col < (sizeof(state[0]) / sizeof(char)); col++) {
			state[row][col] = in[row*col];
		}
	}

	// word from: Nr*Nb -> (Nr+1)*Nb-1
	addRoundKey(state, word, Nr*Nb);	//Nr*Nb = 40

	for (int round = Nr-1; round>=1; round--) {//round = Nr - 1 step - 1 downto 1

		shiftRows(state, true); 
		subBytes(state, true); 
		// words from: round*Nb -> (round+1)*Nb-1
		addRoundKey(state, word, round*Nb); 
		MixColumns(state, true); 
	}

	shiftRows(state, true);
	subBytes(state, true);
	//words from: 0 -> Nb-1
	addRoundKey(state, word, 0);

	//transforming 2D block into output byte 
	for (int row = 0; row < (sizeof(state) / sizeof(state[0])); row++) {
		for (int col = 0; col < (sizeof(state[0]) / sizeof(char)); col++) {
			out[row*col] = state[row][col];
		}
	}
}