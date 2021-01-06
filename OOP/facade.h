// Filename: facade.h
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
//      This is for facade design pattern
// 	    This file contains VehicleBody, VehicleColor, VehicleType
//          and, FacadeCar class.

#include <iostream>

/* 
*	NAME	:	VehicleBody
*	PURPOSE :	The purpose of this class is to create 
*					and destory the body part of car
*/
class VehicleBody
{
public:
    /*
	*   Function: CreateBody()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is to create the vehicle body
	*/
    void CreateBody()
    {
        std::cout << "Create the new body" << std::endl;
    }

    /*
	*   Function: CreateBody()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is to destroy the car body
	*/
    void DestroyBody()
    {
        std::cout << "Destory the body" << std::endl;
    }
};



/* 
*	NAME	:	VehicleColor
*	PURPOSE :	The purpose of this class is to set the color of the vehicle
*/
class VehicleColor
{
public:
    /*
	*   Function: SetDefaultColor()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is setting the color of the vehicle
    *                       as to the default color
	*/
    void SetDefaultColor()
    {
        std::cout << "This is white car" << std::endl;
    }

    /*
	*   Function: SetRedColor()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is setting the color of the vehicle
    *                       as to red color.
	*/
    void SetRedColor()
    {
        std::cout << "This car red car" << std::endl;
    }
};




/* 
*	NAME	:	VehicleType
*	PURPOSE :	The purpose of this class is to set the vehicle type
*/
class VehicleType
{
public:
    /*
	*   Function: SetSportCar()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is setting the car as a sports car
	*/
    void SetSportsCar()
    {
        std::cout << "This car is sports car" << std::endl;
    }
    /*
	*   Function: SetVan()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is setting the car like a van type
	*/
    void SetVan()
    {
        std::cout << "This car is van" << std::endl;
    }
};




/* 
*	NAME	:	FacadeCar
*	PURPOSE :	The purpose of this class is
*                   create a car using facade design pattern
*/
class FacadeCar
{
private:
    VehicleBody*    body;
    VehicleColor*   color;
    VehicleType*    type;

public:
    /*
	*   Function: FacadeCar()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is a constructor, initialize the variables
	*/
    FacadeCar()
    {
        body = new VehicleBody();
        type = new VehicleType();
        color = new VehicleColor();
    }


    /*
	*   Function: CreateFancyCar()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is creaete the fancy car
	*/
    void CreateFancyCar()
    {
        std::cout << "Let's create the fancy car!!" << std::endl;
        body->CreateBody();
        type->SetSportsCar();
        color->SetRedColor();
        std::cout << "Let's go driving!!!!!!" << std::endl;
    }


    /*
	*   Function: CreateWorkingCar()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is create the working car
	*/
    void CreateWorkingCar()
    {
        std::cout << "Let's create the car for working" << std::endl;
        body->CreateBody();
        type->SetVan();
        color->SetDefaultColor();
        std::cout << "Let's go work....." << std::endl;
    }


    /*
	*   Function: DestroyFancyCar()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is destroy the fancy car
	*/
    void DestroyFancyCar()
    {
        std::cout << "It is not fancy anymore." << std::endl;
        body->DestroyBody();
        std::cout << "Let's go to find a more fantastic one!!" << std::endl;
    }


    /*
	*   Function: DestroyWorkingCar()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is destroy the working car
	*/
    void DestroyWorkingCar()
    {
        std::cout << "It is not working anymore." << std::endl;
        body->DestroyBody();
        std::cout << "Let's go to find a stronger one!!" << std::endl;
    }
};