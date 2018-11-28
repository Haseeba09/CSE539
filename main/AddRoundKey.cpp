#include "AddRoundKey.h"
#include <iostream>
using namespace std;

const int Nb = 4; //block size

void addRoundKey(unsigned char state[4][4], unsigned char word[][4], int round)
{
	//range:	round*Nb -> (round+1)*Nb-1
	
	int col = 0;
	for (int i = round * Nb; i <= (round + 1)*Nb - 1; i++) {
		for (int byte = 0; byte < 4; byte++) {
			state[byte][col] ^= word[i][byte];
		}
		col++;
	}


}
