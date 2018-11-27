#include <iostream>
#include "shiftrows.h"
using namespace std;


void shiftRows(unsigned char state[][4], bool inverse){
    if(inverse){
        for(int i=1; i<4; i++){
                for(int n=0; n<i; n++){
                    unsigned char temp = state[i][3];
                    state[i][3] = state[i][2];
                    state[i][2] = state[i][1];
                    state[i][1] = state[i][0];
                    state[i][0] = temp;
                }
            }
    }
    else{
        for(int i=1; i<4; i++){
                for(int n=0; n<i; n++){
                    unsigned char temp = state[i][0];
                    state[i][0] = state[i][1];
                    state[i][1] = state[i][2];
                    state[i][2] = state[i][3];
                    state[i][3] = temp;
                }
            }
    }
    
}

