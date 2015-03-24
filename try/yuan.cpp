// try.cpp : Defines the entry point for the console application.
//


#include "human.h"


int main(){
    int x;
    human tom;
    tom.set_weight(201);
    tom.get_weight(x);
    cout << x +1<< endl;
    cout << tom.get_weight (x)-1 << endl;
    return 0;
}

