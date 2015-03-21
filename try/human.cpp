//#include "stdafx.h"
#include "human.h"
#include <string>


int human::set_weight(int x)
{
    if (x>0 && x<200){
        weight = x;
        cout << x;
    }
    else
        cout << "Invalid weight.";
    return 0;
}


int human::get_weight(int &x)
{
    x = weight;
    return 0;
}
