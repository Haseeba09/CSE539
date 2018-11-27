#include <iostream>
using namespace std;

unsigned char partialKeyGen(int p, int q,unsigned long long int x);

int main(){
    int p = 5651;
    int q = 5623;
    unsigned long long int x = 2;
    unsigned char key[16];
    
    key[0] = partialKeyGen(p,q,x);

    for(int i=1; i<16; i++){
        key[i] = partialKeyGen(p,q,key[i-1]);
    }

    for(int i=0; i<16; i++){
        cout<<(int)key[i]<<endl;
    }

    return 0;
}

unsigned char partialKeyGen(int p, int q, unsigned long long int x){
    unsigned char partialKey = 0x00;
    int M = p*q;

    for(int i=0; i<8; i++){
        unsigned long long int temp = x;
        int output = 0;
        temp = temp*temp;
        cout<<"temp: "<<temp<<endl;
        x = temp % M;
        output = x%2;
        int exponent=1;
        for(int n=0; n<i; n++){
            exponent *=2;
        }
        partialKey += output*exponent;
    }

    return partialKey;
}