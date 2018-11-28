#include <iostream>
#include <string.h>
#include <bitset>
#include <array>
#include "AES.h"
#include "ofb.h"
#include "keyexpansion.h"
using namespace std;


void bitwise_xor(unsigned char* x, unsigned char* y)
{
    int len = sizeof(x)/sizeof(*x);
    for(int i = len - 1 ; i >= 0; i--){
        x[i] = (char) (x[i] ^ y[i]);
    }
}

void ofb(unsigned char key[],unsigned char IV[],unsigned char* message, unsigned char outputtext[], bool decrypt, int length ){    
    int messageLength = length;
    int lastblock = messageLength%16;
    int numberofblocks = messageLength/16 + 1;
    if(lastblock == 0){numberofblocks -= 1;}
    
    for(int i = 0; i < numberofblocks; i++){
        unsigned char temp[16];
        unsigned char tempiv[16];
        memcpy(tempiv, IV, 16);
        if(i == numberofblocks -1 ) { memcpy(temp, message + i*16, lastblock); }
        else { memcpy(temp, message + i*16, 16); }
        //bitwise_xor(IV,key); //aes block encryption function goes here
        
        unsigned char keyArray[4][4];
        int index =0;
        for(int i=0; i<4; i++){
            for(int n=0; n<4; n++){
                keyArray[i][n] = key[index];
                //SECURE CODING: EXP50-CPP. Do not depend on the order of evaluation 
		        //for side effects
                index++;
            }
        }
        //aes block encrypt/decrypt
        unsigned char keyExpandedArray[44][4];
        KeyExpansion(key, keyExpandedArray);

        // for(int i=0; i<44; i++){
        //     cout<<dec<<i<<" ";
        //     for(int n=0; n<4; n++){
        //         cout<<hex<<(int)keyExpandedArray[i][n];
        //     }
        //     cout<<endl;
        // }

        if(decrypt){Cipher(tempiv,tempiv,keyExpandedArray);}
        else{Cipher(tempiv,tempiv,keyExpandedArray);}

        bitwise_xor(temp,IV);
        if(i == numberofblocks -1 ) { memcpy(outputtext + i*16, temp, lastblock); }
        else { memcpy(outputtext + i*16, temp, 16); }
    }
}




