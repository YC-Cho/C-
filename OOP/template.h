#include <iostream>

/* 
*	NAME	:	Vehicle
*	PURPOSE :	This is a super class.
*				It gives a template to child class.
*/
class Vehicle
{
protected:
    /*****      Varialbe     ******/
    int wheel;
    int weight;

public:
    /*****      Set Method     ******/
    void setWheel(int num)
    {
        this->wheel = num;
    };

    void setWeight(int num)
    {
        this->weight = num;
    }

    /*****      Get Method     ******/
    int getWheel()
    {
        return this->wheel;
    };

    int getWeight()
    {
        return this->weight;
    };


    /*****      Virtual Method     ******/
    virtual void PutWheel() {};
    virtual void AddWeight() {};
    virtual void Print() {};
};



/* 
*	NAME	:	Motocycle
*	PURPOSE :	This is a concrete class that inheritance of Vehicle class.
*				It has override the three functions.
*/
class Motocycle : Vehicle
{
public:
    void PutWheel()
    {
        Vehicle::setWheel(2);
    }

    void AddWeight()
    {
        Vehicle::setWeight(getWeight() + 10);
    }

    void Print()
    {
        std::cout << "Motocycle has " << getWheel()
            << " wheels, and weight is " << getWeight()
            << std::endl;
    }
};



/* 
*	NAME	:	Truck
*	PURPOSE :	This is a concrete class that inheritance of Vehicle class.
*				It has override the three functions.
*/
class Truck : Vehicle
{
public:
    void PutWheel()
    {
        Vehicle::setWheel(4);
    }

    void AddWeight()
    {
        Vehicle::setWeight(getWeight() + 230);
    }

    void Print()
    {
        std::cout << "Truck has " << getWheel()
            << " wheels, and weight is " << getWeight()
            << std::endl;
    }
};