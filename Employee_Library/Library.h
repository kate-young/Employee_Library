#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <list>
#include "Book.h"
#include "Date.h"
#include "Employee.h"
#include "Employee_Queue.h"

class Library {
public:
	Library();
	~Library();
	/* Lookup book in active_books list and pass it to the first employee in
	it's queue.
	@params book_name - name of book to be circulated
	@params start_date - date to circulate the book
	*/
	void circulate_book(const std::string& book_name, const Date& start_date);
	/* Lookup book in the active_books list and pass it to the next employee
	in the book's queue
	@params book_name - name of book to be passed
	@params pass_date - date to pass the book
	*/
	void pass_on(const std::string& book_name, const Date& pass_date);
	/* Add book to the active_books list
	@params book_name - name of new book
	*/
	void add_book(const std::string& book_name);
	/* Add employee to all the active book's queues
	@params employee_name - name of new employee
	*/
	void add_employee(const std::string& employee_name);
private:
	/* List of books that are being passed to employees
	*/
	list<Book> active_books;
	/* List of books that are done being passed to employees
	*/
	list<Book> archived_books;
	/* List of employees that to get the books.
	*/
	list<Employee> employees = {};
};

#endif
