// Employee_Library.cpp : main project file.

#include "stdafx.h"
#include "Date.h"
#include "Library.h"


int main()
{
	Library library;

	// Add books to the list of active books
	library.add_book("Software Engineering");
	library.add_book("Chemistry");

	// Add employees to both book's queues
	library.add_employee("Adam");
	library.add_employee("Sam");
	library.add_employee("Ann");	

	// Circulate both books
	library.circulate_book("Chemistry", Date(2015, 3, 1, DateFormat::US));
	library.circulate_book("Software Engineering", Date(2015, 4, 1, DateFormat::US));

	// Pass Chemistry book to all employees
	library.pass_on("Chemistry", Date(2015, 3, 5, DateFormat::US)); // Pass from Adam to Sam
	library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US)); // Pass from Sam to Ann
	library.pass_on("Chemistry", Date(2015, 3, 15, DateFormat::US)); // Pass from Ann to Archive

	// Pass Software Engineering book to all employees
	library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US)); // Pass from Sam to Ann
	library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US)); // Pass from Ann to Adam
	library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US)); // Pass from Adam to Archive

	std::system("Pause");
	return 0;
}
