#include <iostream>
#include <string>
#include <vector>


enum type {
    Unknonw = 0,
	Books = 1,
	Papers = 2,
	Flyers = 3
};


class Base
{
protected:
	std::string name;
	int type;
	int year;

public:
    /*****      Constructor     ******/
	Base(void)
	{
		this->name = "Unknown";
		this->type = 0;
		this->year = 0;
	}
	Base(std::string name, int year, int type = 0)
	{
		this->name = name;
		this->type = type;
		this->year = year;
	}
	Base(int type)
	{
		this->name = "Unknown";
		this->type = type;
		this->year = 0;
	}


    /*****      Method     ******/
    /*  Update the variable */
	void setType(int type)
	{
		this->type = type;
	}

	void setYear(int year)
	{
		this->year = year;
	}


    /*  Return the value of variable */
	int getType()
	{
		return this->type;
	}
	int getYear()
	{
		return this->year;
	}
	std::string getName()
	{
		return this->name;
	}


    /*****      Virtual Method     ******/    
    /* It going to be overridden in the subclass */
	virtual void Create(std::string name, int year, int type)
	{
		this->name = name;
		this->type = type;
		this->year = year;
	}

    virtual void Print()
    {
        std::cout << "Base: ";
        std::cout << "\tName: " << this->name;
        std::cout << "\tType: " << this->type;
        std::cout << "\tYear: " << this->year << std::endl;
    }
};


/* A concrete class that inheritance of Base class */
class Book : Base
{
private:
	std::string author;
	int isdn;

public:
    /*****      Constructor     ******/
	Book() : Base(Books) 
	{
		this->author = "Unknown";
		this->isdn = 0;
	};
	Book(std::string bookName, std::string author, int year, int isdn)
	{
		Base::Create(bookName, year, Books);
		this->author = author;
		this->isdn = isdn;
	}

    /*****      Method     ******/
    /*  Update the variable */
    void setAuthor(std::string author)
    {
        this->author = author;
    }
    void setIsdn(int num)
    {
        this->isdn = num;
    }
    
    /*  Return the value of variable */
    std::string getAuthor()
	{
		return this->author;
	}
    int getIsdn()
    {
        return this->isdn;
    }


    /*****      Override Method     ******/
    // Also, overload the function
	void Create()
	{
		Base::Create("Unknown", 1900, Books);
		this->author = "Unknown";
		this->isdn = 0;
	}

	void Create(std::string name)
	{
		Base::Create(name, 1900, Books);
		this->author = "Unknown";
		this->isdn = 0;
	}

	void Create(std::string name, int year)
	{
		Base::Create(name, year, Books);
		this->author = "Unknown";
		this->isdn = 0;
	}

	void Create(std::string name, int year, std::string author, int isdn)
	{
		Base::Create(name, year, Books);
		this->author = author;
		this->isdn = isdn;
	}

    virtual void Print()
    {
        std::cout << "Book: ";
        std::cout << "\tName: " << getName();
        std::cout << "\tType: " << getType();
        std::cout << "\tYear: " << getYear();
        std::cout << "\tAuthor: " << this->author;
        std::cout << "\tISDN: " << this->isdn << std::endl;
    }
};


/* A concrete class that inheritance of Base class */
class Paper : Base
{
private:
	std::string conference;

public:
    /*****      Constructor     ******/
	Paper() : Base(Papers) 
	{
		this->conference = "Unknown";
	};
	Paper(std::string bookName, std::string conference, int year, int isdn)
	{
		Base::Create(bookName, year, Papers);
		this->conference = conference;
	}

    /*****      Method     ******/
    /*  Update the variable */
    void setConference(std::string conference)
    {
        this->conference = conference;
    }
    
    /*  Return the value of variable */
    std::string getConference()
	{
		return this->conference;
	}


    /*****      Override Method     ******/
    // Also, overload the function
	void Create()
	{
		Base::Create("Unknown", 1900, Papers);
		this->conference = "Unknown";
	}

	void Create(std::string name)
	{
		Base::Create(name, 1900, Papers);
		this->conference = "Unknown";
	}

	void Create(std::string name, int year)
	{
		Base::Create(name, year, Papers);
		this->conference = "Unknown";
	}

	void Create(std::string name, int year, std::string conference, int isdn)
	{
		Base::Create(name, year, Papers);
		this->conference = conference;
	}

    virtual void Print()
    {
        std::cout << "Paper: ";
        std::cout << "\tName: " << getName();
        std::cout << "\tType: " << getType();
        std::cout << "\tYear: " << getYear();
        std::cout << "\tConference: " << this->conference << std::endl;
    }
};



// A Storage Class that stores the book, paper, etc
class Storage
{
private:
	std::vector<Base*> shelf;

public:
    /*****      Deconstructor     ******/
	~Storage()
	{
		shelf.clear();
	}


    /*****      Method     ******/
    /*  Insert the object into the storage */
	void Insert(Base* obj)
	{
		// Check the book is already in the storage
		std::vector<Base*>::iterator it
			= std::find(shelf.begin(), shelf.end(), obj);

		// Store if this is unique
		if (it == shelf.end())
		{
			shelf.push_back(obj);
		}
		// Do not store because already in there
		else
		{
			std::cout << "==>  " << obj->getName()
				<< " is is already in the shelf." << std::endl;
		}
			
	}



    /*  Remove the object into the storage */
	void Remove(std::string name)
	{	
		for (int i = 0; i < shelf.size(); i++)
		{
			if (shelf[i]->getName() == name)
			{
				std::cout << "*** Remove from the storage: " << std::endl;
				shelf[i]->Print();
				
				shelf.erase(shelf.begin() + i);
				break;
			}
		}
	}

    /*  Print out the detailed  information that is stored */
    void Print()
    {
        std::cout << "**** Printing all stuff in shelf" << std::endl;
        for(int i = 0; i < shelf.size(); i++)
        {
            std::cout << i << ". ";
            shelf[i]->Print();
        }
        std::cout << "-- END --------------" << std::endl;
    }
};