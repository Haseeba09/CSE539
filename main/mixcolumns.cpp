//CSE539 project - Paul Simerda
//	professor Bazzi

//Mixcolumns functionality

#include "mixcolumns.h";
#include "multiplication.h";

//Function prototypes
void MixCol(unsigned char(&col)[4]);
void InvMixCol(unsigned char(&col)[4]);

//Global matrix used for mulitiplication in transformation
const int mixMatrix[4][4] = {{2, 3, 1, 1},
							 {1, 2, 3, 1},
							 {1, 1, 2, 3},
							 {3, 1, 1, 2}};

const int invMixMatrix[4][4] = { {14, 11, 13, 9},
								{9, 14, 11, 13}, 
								{13, 9, 14, 11},
								{11, 13, 9, 14} };

//Traverses given AES matrix by columns
void MixColumns(unsigned char state[][4], bool inverse) {
	unsigned char tempCol[4];

	for (int i = 0; i < 4; i++) {
		//access column to be transformed
		for (int j = 0; j < 4; j++) {
			tempCol[j] = state[j][i];			
		}

		if (inverse) {
			InvMixCol(tempCol);
		}
		else {
			MixCol(tempCol);
		}

		//write transformed column back into matrix
		for (int k = 0; k < 4; k++) {
			state[k][i] = tempCol[k];
		}

	}
}

//Performs mixcolumns operation on given column of matrix
void InvMixCol(unsigned char (&col)[4]) {
	unsigned char tempCol[4] = { 0,0,0,0 };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (invMixMatrix[i][j] == 9) {
				tempCol[i] ^= multiplyBy9(col[j]);
			} else if(invMixMatrix[i][j] == 11) {
				tempCol[i] ^= multiplyBy11(col[j]);
			}
			else if (invMixMatrix[i][j] == 13) {
				tempCol[i] ^= multiplyBy13(col[j]);
			}
			else if (invMixMatrix[i][j] == 14) {
				tempCol[i] ^= multiplyBy14(col[j]);
			}
		}
	}

	//copy tempCol into original column
	for (int k = 0; k < 4; k++) {
		col[k] = tempCol[k];
	}
}

//Performs the inverse mixcoulmns transformation on given column of matrix
void MixCol(unsigned char(&col)[4]) {
	unsigned char tempCol[4] = { 0,0,0,0 };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mixMatrix[i][j] == 1) {
				tempCol[i] ^= col[j];
			}
			else if (mixMatrix[i][j] == 2) {
				tempCol[i] ^= multiplyBy2(col[j]);
			}
			else if (mixMatrix[i][j] == 3) {
				tempCol[i] ^= multiplyBy3(col[j]);
			}
		}
	}

	//copy tempCol into original column
	for (int k = 0; k < 4; k++) {
		col[k] = tempCol[k];
	}
}