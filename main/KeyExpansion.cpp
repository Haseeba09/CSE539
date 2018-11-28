//CSE539 project - Paul Simerda
//	professor Bazzi

//KeyExpansion functionality

#include "keyexpansion.h"
#include "subbytes.h"
#include "multiplication.h"

void SubWord(unsigned char word[4]);
void RotWord(unsigned char word[4]);
unsigned char getRcon(int round);

void KeyExpansion(unsigned char key[4 * Nk], unsigned char w[Nb*(Nr + 1)][4]) {

	unsigned char temp[4];

	int i = 0;
	int index =0;
	while (i < Nk) {
		//w[i] = word(key[4 * i], key[4 * i + 1], key[4 * i + 2], key[4 * i + 3]);
		for (int byte = 0; byte < 4; byte++) {
			w[i][byte] = key[index];
			//SECURE CODING: EXP50-CPP. Do not depend on the order of evaluation 
			//for side effects
			index++;
		}
		//SECURE CODING: EXP50-CPP. Do not depend on the order of evaluation 
		//for side effects
		i += 1;
	}

	i = Nk;

	while (i < Nb * (Nr + 1)){

		//temp = w[i - 1];
		for (int byte = 0; byte < 4; byte++) {
			temp[byte] = w[i - 1][byte];
		}

		if (i % Nk == 0) {
			RotWord(temp);
			SubWord(temp);
			
			//initialize Rcon
			//temp ^= Rcon[i / Nk];
			unsigned char Rcon[4];
			Rcon[0] = getRcon(i/Nk);
			for (int j = 1; j < 4; j++) {
				Rcon[j] = 0x00;
			}

			for (int byte = 0; byte < 4; byte++) {
				temp[byte] ^= Rcon[byte];
			}
		}
		//else if (Nk > 6 and i % Nk = 4) {
		//	SubWord(temp);
		//}

		//w[i] = w[i - Nk] ^ temp;
		for (int byte = 0; byte < 4; byte++) {
			w[i][byte] = w[i - Nk][byte] ^ temp[byte];
		}
		//SECURE CODING: EXP50-CPP. Do not depend on the order of evaluation 
		//for side effects
		i = i + 1;

	}

}

// takes a four-byte input word and applies the S-box to each of 
// the four bytes to produce an output word
void SubWord(unsigned char word[4])
{
	for (int i = 0; i < 4; i++)
	{
		word[i] = sBox[(word[i])];
	}
}

// performs a cyclic permutation
void RotWord(unsigned char word[4])
{
	unsigned char temp;

	temp = word[0];

	for (int i = 0; i < 3; i++) {
		word[i] = word[i + 1];
	}

	word[3] = temp;
}

//recursively get Rcon
unsigned char getRcon(int round)
{
	if (round == 1) {
		return 0x01;
	}
	else {
		return multiplyBy2(getRcon(round - 1));
	}
}
