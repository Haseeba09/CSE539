#include <iostream>
using namespace std;

void shiftRows(unsigned char x[][4], bool inverse);


void shiftRows(unsigned char x[][4], bool inverse){
    if(inverse){
        for(int i=1; i<4; i++){
                for(int n=0; n<i; n++){
                    unsigned char temp = x[i][3];
                    x[i][3] = x[i][2];
                    x[i][2] = x[i][1];
                    x[i][1] = x[i][0];
                    x[i][0] = temp;
                }
            }
    }
    else{
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
    
}

