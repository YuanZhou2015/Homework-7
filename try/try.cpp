// try.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "human.h"


void main(){
    int x;
    human tom;
    tom.set_weight(99);
    tom.get_weight(x);
    cout << x;
    cout << tom.get_weight (x);
    return;
}

