#include <iostream>
#include "KeyGen.h"
using namespace std;



int main(){
    int p = 5651;
    int q = 5623;
    unsigned long long  x = 12;

    string key;
    
    key = keyGen(p,q,x);
    cout<<key<<endl;

    return 0;
}
