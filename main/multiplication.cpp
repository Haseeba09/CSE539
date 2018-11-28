//CSE539 project - Paul Simerda
//	professor Bazzi

//Multiplication functions

#include "multiplication.h"

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