// Test program for AES mixcolumns method

#include <iostream>
#include "mixcolumns.h"

using namespace std;

void printState(unsigned char (&x)[4][4]);

int main() {

	unsigned char matrixA[4][4] = {{0xdb, 0xf2, 0x01, 0xc6},
						   {0x13, 0x0a, 0x01, 0xc6},
						   {0x53, 0x22, 0x01, 0xc6},
						   {0x45, 0x5c, 0x01, 0xc6} };
	unsigned char colTest[4] = {0xd4, 0xbf, 0x5d, 0x30};

	cout << "Testing mixcolumns...\n";
	printState(matrixA);
	MixColumns(matrixA, false);
	printState(matrixA);
	cout << "Done....\n";
	cin.ignore();

	cout << "Testing inverse mixcolumns...\n";
	MixColumns(matrixA, true);
	printState(matrixA);
	cout << "Done.....\n";
	cin.ignore();

	return 0;
}

void printState(unsigned char (&x)[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			cout << hex << (int) x[i][n] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
