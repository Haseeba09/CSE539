#include <iostream>
using namespace std;

string keyGen(int p, int q,unsigned long long x);

int main(){
    int p = 5651;
    int q = 5623;
    unsigned long long  x = 12;

    string key;
    
    key = keyGen(p,q,x);
    cout<<key<<endl;

    return 0;
}

string keyGen(int p, int q, unsigned long long  x){
    string key = "";
    int M = p*q;
    int binaryKey[128];
    int brokenUpBinaryKey[16][8];
    unsigned char partialKey[16];

    //Get random bits using BBS
    for(int i=0; i<128; i++){
        unsigned long long  temp = x;
        int output = 0;
        temp = temp*temp;
        x = temp % M;
        output = x%2;
        binaryKey[i] = output;
    }
    //Break up binary key into 16 peices of 8 bits
    int n =0;
    for(int i=0; i<128; i++){        
        if(i>1 && i%8 == 0){
            n++;
        }
        brokenUpBinaryKey[n][i%8] = binaryKey[i];       
    }
    //and each peice of the key to a byte array, converting from
    //binary to dec
    for(int i=0; i<16; i++){
        partialKey[i] = 0;
        for(int n=0; n<8; n++){
            int exponent=1;
            for(int m=0; m<n; m++){
                exponent *=2;
            }
            partialKey[i] += brokenUpBinaryKey[i][n]*exponent;
        }
    }
    //concatenate each byte into a string
    for(int i=0; i<16; i++){
        key+=partialKey[i];
    }

    return key;
}