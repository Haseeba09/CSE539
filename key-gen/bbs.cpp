#include <iostream>
using namespace std;

string partialKeyGen(int p, int q,unsigned long long x);

int main(){
    int p = 5651;
    int q = 5623;
    unsigned long long  x = 123;

    string key;
    
    key = partialKeyGen(p,q,x);
    cout<<key<<endl;

    return 0;
}

string partialKeyGen(int p, int q, unsigned long long  x){
    string key = "";
    int M = p*q;
    int binaryKey[128];
    int brokenUpBinaryKey[16][8];
    unsigned char partialKey[16];

    for(int i=0; i<128; i++){
        unsigned long long  temp = x;
        int output = 0;
        temp = temp*temp;
        //cout<<"temp: "<<temp<<endl;
        x = temp % M;
        output = x%2;
        binaryKey[i] = output;
        // int exponent=1;
        // for(int n=0; n<i; n++){
        //     exponent *=2;
        // }
        // partialKey += output*exponent;
    }
    
    for(int i=0; i<128; i++){
        cout<<binaryKey[i];
    }
    int n =0;
    for(int i=0; i<128; i++){        
        if(i>1 && i%8 == 0){
            n++;
        }
        brokenUpBinaryKey[n][i%8] = binaryKey[i];
        // cout<<"\n binKey = "<<binaryKey[i];
        // cout<<"\n broken"<<n<<" "<<i%8<<" = "<<brokenUpBinaryKey[n][i%8];        
    }
    cout<<endl;
    cout<<"next"<<endl;

    for(int i =0; i<16; i++){
        for(int n=0; n<8; n++){
            cout<<brokenUpBinaryKey[i][n];
        }
        
    }
    cout<<endl;

    for(int i=0; i<16; i++){
        // int exponent=1;
        // for(int n=0; n<i; n++){
        //     exponent *=2;
        // }
        partialKey[i] = 0;
        for(int n=0; n<8; n++){
            int exponent=1;
            for(int m=0; m<n; m++){
                exponent *=2;
            }
            partialKey[i] += brokenUpBinaryKey[i][n]*exponent;
        }
    cout<<partialKey[i]<<endl;
    }

    for(int i=0; i<16; i++){
        key+=partialKey[i];
    }
    



    return key;
}