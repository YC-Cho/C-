// Filename: stringTrim.cpp
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    It is converting from the string to vector
//          and vector to string.

#include <iostream>
#include <string>
#include "./stringManipulate.h"

int main ()
{
    // String to Vector
    std::cout << "------ String to Vector ------" << std::endl;
    std::string theString = "This is a random string";

    // Convert string to vector
	std::vector<std::string> vec = StringManipulate::StrToVec(theString, ' ');

    // Printing the value of vector
    std::cout << "String: " << theString << std::endl;
	for (uint32_t i = 0; i < vec.size(); i++)
	{
		std::cout << i << ". " << vec[i] << std::endl;
	}
    std::cout << "------ End ------" << std::endl << std::endl;



    // Vector to String
    std::cout << "------ Vector to String ------" << std::endl;
    std::vector<std::string> vecs(3);
	vecs[0] = "Jason";
	vecs[1] = "Beck";
	vecs[2] = "Tom";
    std::cout << "Vector value: ";
    for(auto s: vecs)
    {
        std::cout << s << " ";
    }

    std::cout << std::endl;

    // Convert vector to string with seperator(,) and then printing out
	std::cout << StringManipulate::VecToStr(vecs, ',') << std::endl;

    std::cout << "------ End ------" << std::endl << std::endl;
    return 0;
}
