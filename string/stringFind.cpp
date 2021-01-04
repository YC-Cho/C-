// Filename: stringFind.cpp
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    If is check the word is in the string.
//      It returns to indexes that the locations of the word.


#include <iostream>
#include <string>
#include "./stringManipulate.h"

int main ()
{
    std::cout << "------ Find the word ------" << std::endl;
	std::string theString = "Happy New Year";
    std::string targetWord = "a";

	// Find the location(index) of specific words
    std::vector<int> matches = StringManipulate::FindSubStringMatches(theString, targetWord);

    std::cout << "Original string: " << theString << " / Target is: " << targetWord << std::endl;
	for (uint32_t i = 0; i < matches.size(); ++i)
	{
		std::cout << "Find a Target(" << targetWord << ") word at " << matches[i] << std::endl;
	}
    std::cout << "------ End ------" << std::endl << std::endl;
    
    return 0;
}