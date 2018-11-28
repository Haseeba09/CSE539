#include <iostream>
#include <string.h>
#include <bitset>
using namespace std;



void bitwise_xor(unsigned char text[], unsigned char text2[])
{
    int textlen = (sizeof(text)/sizeof(*text));
    for(int i = textlen - 1 ; i >= 0; i--){
        text[i] = (char) (text[i] ^ text2[i]);
    }
}

int main(){
    unsigned char plaintext[] = "this is the plain text that will be encrypted";
    int plaintextLength = (sizeof(plaintext)/sizeof(*plaintext)) - 1;
    int lastblock = plaintextLength%16;
    int numberofblocks = plaintextLength/16 + 1;
    if(lastblock == 0){numberofblocks = plaintextLength/16;}
    unsigned char ciphertext[plaintextLength];
    unsigned char decipheredtext[plaintextLength];
    unsigned char key[] = "abcdefghabcdefgh";
    unsigned char IV[] = "4326dasfabcdefgh";
    unsigned char tempiv[16];
    

    memcpy(tempiv,IV,8);
    
    for(int i = 0; i< numberofblocks; i++){
        unsigned char temp[16];
        if(i == numberofblocks -1 ) { memcpy(temp, plaintext + i*16, lastblock); }
        else { memcpy(temp, plaintext + i*16, 16); }
        bitwise_xor(tempiv,key); //aes block encryption function goes here
        bitwise_xor(temp,tempiv);
        if(i == numberofblocks -1 ) { memcpy(ciphertext + i*16, temp, lastblock); }
        else { memcpy(ciphertext + i*16, temp, 16); }
    }

    
    memcpy(tempiv,IV,8);
    for(int i = 0; i< numberofblocks; i++){
        unsigned char temp[16];
        if(i == numberofblocks -1 ) { memcpy(temp, ciphertext + i*16, lastblock); }
        else { memcpy(temp, ciphertext + i*16, 16); }
        bitwise_xor(tempiv,key); //aes block encryption function goes here
        bitwise_xor(temp,tempiv);
        if(i == numberofblocks -1 ) { memcpy(decipheredtext + i*16, temp, lastblock); }
        else { memcpy(decipheredtext + i*16, temp, 16); }
    }

    


    cout<< "Cipher text : ";
    for(int i = 0; i< plaintextLength; i++){
        printf("%02X ", ciphertext[i]);
    }

    cout << "\nDeciphered text : " << decipheredtext << "\n";
}




