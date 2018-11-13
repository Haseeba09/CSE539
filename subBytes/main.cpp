#include <iostream>
#include "subbytes.h"
using namespace std;
void printState(unsigned char x[][4]);

int main(){
	unsigned char x[4][4] = {{0x41,0x42,0x43,0x44}, 
                    {0x45,0x46,0x47,0x48}, 
                    {0x49,0x4A,0x4B,0x4C},
                    {0x4D,0x4E,0x4F,0x50}};
  

    cout<<"Original State:"<<endl;
    printState(x);
    subBytes(x,false);
    cout<<"Shift State:"<<endl;
    printState(x);
    subBytes(x, true);
    cout<<"InvShift State:"<<endl;
    printState(x);	
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




