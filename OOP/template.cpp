#include <iostream>
#include "template.h"

int main()
{
    Motocycle* moto = new Motocycle();
    Truck* truck = new Truck();
    
    moto->PutWheel();
    moto->AddWeight();

    truck->PutWheel();
    truck->AddWeight();

    moto->Print();
    truck->Print();

    return 0;
}