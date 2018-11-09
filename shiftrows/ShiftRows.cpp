#include <iostream>
using namespace std;


int main(){
    int x[4][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15}};
    //int y[4][4] = shiftRows(x);
    for(int i=0; i<4; i++){
        for(int n=0; n<4; n++){
            cout<<x[i][n]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    int numRows = sizeof(x[0])/sizeof(*x[0]);
    for(int i=1; i<numRows; i++){
        for(int n=0; n<i; n++){
            int temp = x[i][0];
            x[i][0] = x[i][1];
            x[i][1] = x[i][2];
            x[i][2] = x[i][3];
            x[i][3] = temp;
        }
    }
    
    for(int i=0; i<4; i++){
        for(int n=0; n<4; n++){
            cout<<x[i][n]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

/*
    cout<<"Shift second row"<<endl;
    int i = 1;
    int temp = x[i][0];
    x[i][0] = x[i][1];
    x[i][1] = x[i][2];
    x[i][2] = x[i][3];
    x[i][3] = temp;
    
    cout<<"Shift third row"<<endl;
    i = 2;
    temp = x[i][0];
    x[i][0] = x[i][1];
    x[i][1] = x[i][2];
    x[i][2] = x[i][3];
    x[i][3] = temp;
    temp = x[i][0];
    x[i][0] = x[i][1];
    x[i][1] = x[i][2];
    x[i][2] = x[i][3];
    x[i][3] = temp;
    
    cout<<"Shift fourth row"<<endl;
    i = 3;
    temp = x[i][0];
    x[i][0] = x[i][1];
    x[i][1] = x[i][2];
    x[i][2] = x[i][3];
    x[i][3] = temp;
    temp = x[i][0];
    x[i][0] = x[i][1];
    x[i][1] = x[i][2];
    x[i][2] = x[i][3];
    x[i][3] = temp;
    temp = x[i][0];
    x[i][0] = x[i][1];
    x[i][1] = x[i][2];
    x[i][2] = x[i][3];
    x[i][3] = temp;
    */
