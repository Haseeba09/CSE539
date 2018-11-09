#include <iostream>
using namespace std;

void shiftRows(unsigned char x[][4]);
void printState(unsigned char x[][4]);

int main(){
    unsigned char x[4][4] = {{0x41,0x42,0x43,0x44}, 
                    {0x45,0x46,0x47,0x48}, 
                    {0x49,0x4A,0x4B,0x4C},
                    {0x4D,0x4E,0x4F,0x50}};
    printState(x);
    shiftRows(x);
    printState(x);
    
    return 0;
}

void shiftRows(unsigned char x[][4]){
    for(int i=1; i<4; i++){
        for(int n=0; n<i; n++){
            unsigned char temp = x[i][0];
            x[i][0] = x[i][1];
            x[i][1] = x[i][2];
            x[i][2] = x[i][3];
            x[i][3] = temp;
        }
    }
}

void printState(unsigned char x[][4]){
    for(int i=0; i<4; i++){
            for(int n=0; n<4; n++){
                cout<<x[i][n]<<" ";
            }
        cout<<endl;
    }
    cout<<endl;
}
