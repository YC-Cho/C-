// Filename: stringTrim.cpp
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    It is trimming the whitespace from the string.

#include <iostream>
#include <string>
#include "./stringManipulate.h"

int main ()
{
    std::cout << "------ Trim (Left and Right) ------" << std::endl;
	std::string theString = "               Lots of whitespace           ";
    std::cout << "Original string:           " << '"' << theString << '"' << std::endl;

    std::cout << "Trim the left side:        " << '"' << StringManipulate::TrimLeft(theString) << '"' << std::endl;
    std::cout << "Trim the right side:       " << '"' << StringManipulate::TrimRight(theString) << '"' << std::endl;
    std::cout << "Remove the all whitespace: " << '"' << StringManipulate::TrimWhitespace(theString) << '"' << std::endl;
    std::cout << "------ End ------" << std::endl;

    return 0;
}