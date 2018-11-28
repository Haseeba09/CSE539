//SECURE CODING: DCL51-CPP. Do not declare or define a reserved identifier
#ifndef SUBBYTES_H
#define SUBBYTES_H

void subBytes(unsigned char state[][4], bool inverse);

extern unsigned char sBox[256];

#endif
