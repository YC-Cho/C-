// Filename: singleton.h
// By: Younchul Cho
// Date: January, 2021
// Description:
//  	This program is built by C++
// 	    This file contains Singleton class.

class Singleton 
{
private:
	static Singleton* instance;
	int data;

	/*
	*   Function: Singleton()
	*   Parameter:      None
	*   Return Value:	None
	*   Description:	This function is a constructor
	*						no objects can be created.
	*/
	Singleton()
	{
		data = 0;
	}

public:
    /*
	*   Function: getInstance()
	*   Parameter:      None
	*   Return Value:	Singleton*: The Singleton pointer 
	*   Description:	This function return the Singleton pointer
	*						If the pointer is null(Not create yet), created it and return
    *                       If the pointer has existed, return that
	*/
	static Singleton* getInstance() 
	{
        // Create the new one, if instance is empty
		if (instance == nullptr)
			instance = new Singleton;

		return instance;
	}


    /*
	*   Function: getData()
	*   Parameter:      None
	*   Return Value:	int: The value which is store in the singleton
	*   Description:	This function is to return the value of data
	*/
	int getData()
	{
		return this->data;
	}


    /*
	*   Function: setData()
	*   Parameter:      int data: The value that is going to store
	*   Return Value:	None
	*   Description:	This function is updating the data value.
	*/
	void setData(int data)
	{
		this->data = data;
	}
};