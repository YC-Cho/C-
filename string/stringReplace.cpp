// Filename: stringReplace.cpp
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    It is to find the character or word in the string
//          and change it to the others.

#include <iostream>
#include <string>
#include "./stringManipulate.h"

int main ()
{
    std::string theString = "I know you.";

    std::cout << "------ Replace the word ------" << std::endl;
    std::cout << "Original string: " << theString << std::endl;
	
    // Change the specific word to another
    theString = StringManipulate::ReplaceAllSubStrings(theString, "know", "do not know");

	std::cout << "ReplaceAllSubStrings: " << theString << std::endl;
    std::cout << "------ End ------" << std::endl << std::endl;
    
    return 0;
}