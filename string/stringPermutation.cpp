// Filename: stringPermutation.cpp
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    It is to find every possible combination based on the string.
//      Also, it is possible to find combinations in a specific range.

#include <iostream>
#include <string>
#include "./stringManipulate.h"

int main ()
{
    // Find the Permutation of string
    std::cout << "------ Permutation ------" << std::endl;
    std::string theString = "abcd";
    std::cout << "Original: " << theString << std::endl;
    StringManipulate::Permutation(theString);

    std::cout << "Permutation in a specific range" << std::endl;
    StringManipulate::Permutation(theString, 1, 4);
    std::cout << "------ End ------" << std::endl << std::endl;
    return 0;
}