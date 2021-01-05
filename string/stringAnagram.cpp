// Filename: stringAnagram.cpp
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    It checks two strings are match as an anagram or not.
//      Also, separate and store, based on the same anagram, from the list of words.

#include <iostream>
#include <string>
#include "./stringManipulate.h"

int main ()
{
    std::string sValue1 = "Kim";
	std::string sValue2 = "Cho";
	std::string sValue3 = "Kmi";

    // Anagrams
    std::cout << "------ Check Anangram ------" << std::endl;
	std::string anaResult = StringManipulate::CheckAangrams(sValue1, sValue2) ? "Anagram" : "Not anagram";
    std::cout << sValue1 << " and "<< sValue2 << " is " << anaResult << std::endl;

    anaResult = StringManipulate::CheckAangrams(sValue1, sValue3) ? "Anagram" : "Not anagram";
    std::cout << sValue1 << " and "<< sValue3 << " is " << anaResult << std::endl;

    std::cout << "\n--> Group Anangram" << std::endl;
    std::vector<std::string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
    std::cout << "List of words: ";
    for (auto s: input)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

	std::vector<std::vector<std::string>> result = StringManipulate::GroupAnagrams(input);
    for (auto vec: result)
    {
        for(auto s: vec)
        {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
	std::cout << "------ End ------" << std::endl << std::endl;
    return 0;
}