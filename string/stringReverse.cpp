// Filename: stringRverse.cpp
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    It is going to reverse the string.

#include <iostream>
#include <string>
#include "./stringManipulate.h"

int main ()
{
    std::string theString = "Thank you so much!";

	// Reverse the String
    std::cout << "------ Reverse the String ------" << std::endl;

    std::cout << theString << " --> ";
	StringManipulate::Reverse(theString);
	std::cout << theString << std::endl;
    
    std::cout << theString << " --> ";
    StringManipulate::ReverseRotate(theString.begin(), theString.end());
	std::cout << theString << std::endl;

    std::cout << "------ End ------" << std::endl << std::endl;

    return 0;
}