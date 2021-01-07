#include <iostream>
#include <algorithm>
#include "inheritance.h"


int main()
{
	// Create the storage
    Storage* storage = new Storage();

	// Create the book and paper
	Book* book1 = new Book();
	Book* book2 = new Book();
	Paper* paper1 = new Paper();
    Paper* paper2 = new Paper();

	book1->Create("Book1");
	book2->Create("Book2", 2019, "James", 123423);
    paper1->Create("Paper1");
	paper2->Create("Paper2", 2021, "Bob", 333444);

	// Insert book and paper into storage
	storage->Insert((Base*)book1);
	storage->Insert((Base*)paper1);
	storage->Insert((Base*)book2);
    storage->Insert((Base*)paper2);
    storage->Insert((Base*)book1);

	// Print all element in the storage
    storage->Print();

	// Remove the object that has specific value
	storage->Remove("Paper2");

	// Print again
    storage->Print();

	// Release the memory
	free(paper1);
    free(paper2);
	free(book1);
	free(book2);
	free(storage);

    return 0;
}