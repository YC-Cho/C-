// Filename: stringMinipulate.h
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    This file contains class that is called StrigMinipuate
//		This class has several functions to manipulate the string.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <string.h>


class StringManipulate
{
public:
	/*
	*   Function: Reverse()
	*   Parameter:      string& str: The original string.
	*   Return Value:	None
	*   Description:	This function reverses the string
	*						using the reverse function that is in STL
	*/
	static void Reverse(std::string& str)
	{
		reverse(str.begin(), str.end());
	}


	
	/*
	*   Function: ReverseRotate()
	*   Parameter:      T first: The original string.
	*					T last: The original string.
	*   Return Value:	None
	*   Description:	This function reverses the string,
	*						and argument type is using a template.
	*/
	template <typename T>
	static void ReverseRotate(T first, T last)
	{
		if ((first == last) || std::next(first) == last)
			return;

		T middle = first;
		
		std::advance(middle, std::distance(first, last) / 2);
		ReverseRotate(first, middle);
		ReverseRotate(middle, last);
		std::rotate(first, middle, last);
	}


	
	/*
	*   Function: ReverseRotate()
	*   Parameter:      string str1: The first string.
	*					string str2: The second string.
	*   Return Value:	bool:	true: If two strings are anagram
	*							false: If two strings are not anagram
	*   Description:	This function checks the two strings are anagram or not.
	*/
	static bool CheckAangrams(std::string str1, std::string str2)
	{
		if (str1.size() != str2.size())
		{
			return false;
		}

		// Sort each string
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		// If the string is same, it means two strings are match
		return str1 == str2 ? true : false;
	}



	
	/*
	*   Function: GroupAnagrams()
	*   Parameter:      vector<string>& strs: The list of words
	*   Return Value:	vector<vector<string>:	
	*							Each vector stores the list of words that match in same anagram.
	*   Description:	This function checks the anagram,
	*						If the words are a match in anagrams, it stores the same vector.
	*						The vector size will be different because of match words.
	*/
    static std::vector<std::vector<std::string>>GroupAnagrams(std::vector<std::string>& strs)
	{
		if (strs.size() == 0)
			return {};

		std::unordered_map<std::string, int> map;
		std::vector<std::vector<std::string>> answer;

		int idx = 0;
		int stringSize = strs.size();

		for (int i = 0; i < stringSize; i++)
		{
			// Get each stirng from the vector
			std::string str = strs[i];

			// Sorting the string
			sort(str.begin(), str.end());

			// Check the string is already in the map
			if (map.find(str) == map.end())
			{
				// Increase the map for new string
				map[str] = idx;
				idx++;
			}

			// Store the string into the map
			map[strs[i]] = map[str];
		}

		// Store into the vector from the map
		answer.resize(idx);
		for (int i = 0; i < stringSize; i++)
		{
			int idx = map[strs[i]];
			answer[idx].push_back(strs[i]);
		}

		return answer;
	}



	



	// Find all permutation of a given string

	/*
	*   Function: Permutation()
	*   Parameter:      string str: The original string
	*   Return Value:	None
	*   Description:	This function is running the permutation for all characters in the string.
	*/
	static void Permutation(std::string str)
	{
		Permutation(str, 0, str.length());
	}

	

	/*
	*   Function: Permutation()
	*   Parameter:      string str: The original string
	*					int start: The start point of permutation
	*					int end: The end point of permutation
	*   Return Value:	None
	*   Description:	This function is running the permutation.
	*						It is permutated in a specific range that is given.
	*/
	static void Permutation(std::string str, int start, int end)
	{
		if (end > str.length())
		{
			std::cout << "String size is only " << str.length()
				<< ". " << end << " is out of range." << std::endl;
			return;
		}
			
		// Nothing, if the string is only one character
		if (start == end - 1)
		{
			std::cout << str << std::endl;
			return;
		}

		// Process each character
		for (int i = start; i < end; i++)
		{
			// swap character at index start with current character
			std::swap(str[start], str[i]);

			// Recursion
			Permutation(str, start + 1, end);
			
			// roll back (restore the string to its original state)
			std::swap(str[start], str[i]);
		}
	}
	



    /*
	*   Function: StrToVec()
	*   Parameter:      string str:		The original string
	*					char separator: The separator(delimiter) of the string
	*   Return Value:	vector<string>: The group of string that separated from the string
	*   Description:	This function is slicing the original string at the separator position.
	*						Every string, which is sliced, is going to store in the vector and return.
	*/
	static std::vector<std::string> StrToVec(std::string str, char separator)
	{
		std::vector<std::string> vecsWords;
        std::stringstream ss(str);
		std::string sIndivStr;

		while (getline(ss, sIndivStr, separator))
		{
			// Slice the string and push back into the vector
			vecsWords.push_back(sIndivStr);
		}

		// Returning the vector
		return vecsWords;
	}


    
	/*
	*   Function: VecToStr()
	*   Parameter:      vector<string>& vec:	The vector that stores a list of string
	*					char separator:			The separator(delimiter) that is going to separate each string.
	*   Return Value:	string: The string that stores every string that was in the vector
	*   Description:	This function is creating the string that gathering all value which is in the vector.
	*						Between the value, which is stored in a vector, is separated by a separator.
	*/
	static std::string VecToStr(std::vector<std::string>& vec, char separator)
	{
		std::string returnStr = "";
		for (auto cust : vec)
		{
			// Get the value and adding into the string, and separator
			returnStr += cust + separator;
		}

		return returnStr;
	}


	/*
	*   Function: TrimLeft()
	*   Parameter:      string str:	The original string.
	*   Return Value:	string: The string which is after removed the left side whitespace.
	*   Description:	This function is trimming the left side of the whitespace
	*                       in the original string.
	*/
	static std::string TrimLeft(std::string str)
	{
		std::string whitespaces(" \t\f\n\r");

		// Remove the whitespace from the beginning until the word start
		str.erase(0, str.find_first_not_of(whitespaces));

		return str;
	}


	/*
	*   Function: TrimRight()
	*   Parameter:      string str:	The original string.
	*   Return Value:	string: The string which is after removed the right side whitespace.
	*   Description:	This function is trimming the right side of the whitespace
	*                       in the original string.
	*/
	static std::string TrimRight(std::string str)
	{
		std::string whitespaces(" \t\f\n\r");

		// Remove the whitespace from end of string
		str.erase(str.find_last_not_of(whitespaces) + 1);

		return str;
	}



	/*
	*   Function: TrimWhitespace()
	*   Parameter:      string str:	The original string.
	*   Return Value:	string: The string which is after removed all whitespace.
	*   Description:	This function is trimming all whitespace
	*                       from beginning to end in the string.
	*/
	static std::string TrimWhitespace(std::string str)
	{
		// Remove the whitespace which is middle of string
		str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

		return str;
	}



    
	/*
	*   Function: FindSubStringMatches()
	*   Parameter:      string str:		The original string.
	*					string subStr:	The string(character) that is going to find.
	*   Return Value:	vector<int>: The index point that is located subStr in the original string.
	*   Description:	This function is looking for the specific string(character) during the string.
	*						If it found, it stores the index point into the vector and returning that.
	*/
	static std::vector<int> FindSubStringMatches(std::string str, std::string subStr)
	{
		std::vector<int> matchingIndexes;
		int index = str.find(subStr, 0);

		while (index != (int)(std::string::npos))
		{
			// If it found, stores into the vector
			matchingIndexes.push_back(index);

			// Change the index to the next position it found
			index = str.find(subStr, index + 1);
		}

		return matchingIndexes;
	}



    
	/*
	*   Function: ReplaceAllSubStrings()
	*   Parameter:      string str:		The original string.
	*					string subStr:	The string(character) that is going to change.
	*					string newStr:	The string(character) to be change.
	*   Return Value:	string: The string after change the word(s).
	*   Description:	This function is find the string and change it.
	*					It returns the string after changed all of that.
	*/
	static std::string ReplaceAllSubStrings(std::string str, std::string subStr, std::string newStr)
	{
		// Find the indexes
		std::vector<int> matches = FindSubStringMatches(str, subStr);

		if (matches.size() > 0)
		{
			int lengthDifference = newStr.size() - subStr.size();
			int timesLooped = 0;

			for (auto index : matches)
			{
				str.replace(index + (timesLooped * lengthDifference),
					subStr.size(),
					newStr);
				
				timesLooped++;
			}
		}

		return str;
	}
	
	
    
	/*
	*   Function: ReplaceAllSubStrings()
	*   Parameter:      string str:		The original string.
	*					int	key:		The key value for encrypt.
	*					bool encrypt:	Indicates encrypt or decrypt.
	*   Return Value:	string: The string after encrypt or decrypt the string.
	*   Description:	This function is encrypting or decrypting the string
	*						based on the key value.
	*/
	static std::string CaesarCipher(std::string str, int key, bool encrypt)
	{
		std::string returnStr = "";
		int charCode = 0;
		char letter;

		if (encrypt)
		{
			key = key * -1;
		}
		

		for (char& c : str)
		{
			// Change, if the value is alphabet
			if (isalpha(c))
			{
				charCode = (int)c + key;

				if (isupper(c))
				{
					// Circulate if the value is out of alphabet range
					if (charCode > (int)'Z')
					{
						charCode -= 26;
					}
					else if (charCode < (int)'A')
					{
						charCode += 26;
					}
				}
				else
				{
					// Circulate if the value is out of alphabet range
					if (charCode > (int)'z')
					{
						charCode -= 26;
					}
					else if (charCode < (int)'a')
					{
						charCode += 26;
					}
				}

				// Change integer to character and adding to string
				letter = charCode;
				returnStr += letter;
			}
			// Not to change, if the value is not alpabet
			else
			{
				// letter = c;
				returnStr += c;
			}
		}

		return returnStr;
	}
};