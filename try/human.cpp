
#include "human.h"
#include <string>
#include <cstdlib>


int human::set_weight(int x)
{
    if (x>0 && x<200){
        weight = x;
        cout << x <<endl;
    }
    else{
        cout << "Invalid weight.";
        exit(EXIT_FAILURE);
    }
    return 0;
}


int human::get_weight(int &x)
{
    x = weight;
    return x;
}
