//CSE539 project - Paul Simerda
//	professor Bazzi

//Mixcolumns functionality

#include "mixcolumns.h";

//Function prototypes
void MixCol(unsigned char(&col)[4]);
void InvMixCol(unsigned char(&col)[4]);
unsigned char multiplyBy2(unsigned char element);
unsigned char multiplyBy3(unsigned char element);
unsigned char multiplyBy9(unsigned char element);
unsigned char multiplyBy11(unsigned char element);
unsigned char multiplyBy13(unsigned char element);
unsigned char multiplyBy14(unsigned char element);

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
void MixColumns(unsigned char (&matrixA)[4][4], bool inverse) {
	unsigned char tempCol[4];

	for (int i = 0; i < 4; i++) {
		//access column to be transformed
		for (int j = 0; j < 4; j++) {
			tempCol[j] = matrixA[j][i];			
		}

		if (inverse) {
			InvMixCol(tempCol);
		}
		else {
			MixCol(tempCol);
		}

		//write transformed column back into matrix
		for (int k = 0; k < 4; k++) {
			matrixA[k][i] = tempCol[k];
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

//Performs multiplication by 2
unsigned char multiplyBy2(unsigned char element) {
	unsigned char tempElem = element;
	//perform a left shift
	tempElem = tempElem << 1;
	//if leftmost element is a one XOR with 0x1b
	if (element & (1 << (8 - 1))) {
		tempElem ^= 0x1b;
		return tempElem;
	}
	else {
		return tempElem;
	}
}

//Performs multiplication by 3 by dividing multiplication into multiplying 
// by 2 and by 1 and XORing the result
unsigned char multiplyBy3(unsigned char element) {
	return multiplyBy2(element) ^ element;
}

unsigned char multiplyBy9(unsigned char element) {
	return multiplyBy2(multiplyBy2(multiplyBy2(element))) ^ element;
}

unsigned char multiplyBy11(unsigned char element) {
	return multiplyBy2(multiplyBy2(multiplyBy2(element)) ^ element) ^ element;
}

unsigned char multiplyBy13(unsigned char element) {
	return multiplyBy2(multiplyBy2(multiplyBy3(element))) ^ element;
}

unsigned char multiplyBy14(unsigned char element) {
	return multiplyBy2(multiplyBy2(multiplyBy3(element)) ^ element);
}
