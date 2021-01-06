#include <iostream>
#include "facade.h"


int main()
{
    // Create the Fancy car
    FacadeCar* f1 = new FacadeCar();
    f1->CreateFancyCar();


    // Create the Working car
    FacadeCar* f2 = new FacadeCar();
    f2->CreateWorkingCar();


    // Destroy the car
    f1->DestroyFancyCar();
    f2->DestroyWorkingCar();

    return 0;
}