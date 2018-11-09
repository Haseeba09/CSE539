#include <iostream>
using namespace std;

void shiftRows(int x[][4]);
void printState(int x[][4]);

int main(){
    int x[4][4] = {{0,1,2,3}, 
                    {4,5,6,7}, 
                    {8,9,10,11},
                    {12,13,14,15}};
    printState(x);
    shiftRows(x);
    printState(x);
    
    return 0;
}

void shiftRows(int x[][4]){
    for(int i=1; i<4; i++){
        for(int n=0; n<i; n++){
            int temp = x[i][0];
            x[i][0] = x[i][1];
            x[i][1] = x[i][2];
            x[i][2] = x[i][3];
            x[i][3] = temp;
        }
    }
}

void printState(int x[][4]){
    for(int i=0; i<4; i++){
            for(int n=0; n<4; n++){
                cout<<x[i][n]<<" ";
            }
        cout<<endl;
    }
    cout<<endl;
}
