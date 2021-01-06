#include <iostream>
#include "singleton.h"

Singleton* Singleton::instance = 0;

int main()
{
	// Create the singleton
    Singleton* s1 = s1->getInstance();
	std::cout << s1->getData() << std::endl;	// Print the default data value


	// Update the value
	s1->setData(100);
	std::cout << s1->getData() << std::endl;	// Print the updated data value
	

	// Try to create the other singleton
	// 		Acturaly, it is going to return exited singleton
	Singleton* s2 = s2->getInstance();
	// That is why it is printed the updated value instead of the default
	std::cout << s2->getData() << std::endl;

	// Change the second one
	s2->setData(200);
	
	// But also, the first one data value is changed.
	// 		Because it is pointing the same thing
	std::cout << s1->getData() << std::endl;
}