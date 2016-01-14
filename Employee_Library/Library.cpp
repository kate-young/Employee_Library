#include "stdafx.h"
#include "Library.h"


Library::Library(){}
Library::~Library() {}
/* Lookup book in active_books list and pass it to the first employee in
it's queue.
@params book_name - name of book to be circulated
@params start_date - date to circulate the book
*/
void Library::circulate_book(const std::string& book_name, const Date& start_date) {
	list<Book>::iterator iter = active_books.begin();
	while (iter != active_books.end()) {
		if (iter->get_name() == book_name) // Find book in active_books list
			iter->circulate(start_date); // circulate book
		++iter;
	}
}
/* Lookup book in the active_books list and pass it to the next employee
in the book's queue
@params book_name - name of book to be passed
@params pass_date - date to pass the book
*/
void Library::pass_on(const std::string& book_name, const Date& pass_date) {
	list<Book>::iterator iter = active_books.begin();
	while (iter != active_books.end()) { 
		if (iter->get_name() == book_name) { // Find book in active_books list
			iter->pass(pass_date); // pass book
			if (iter->is_archived()) {
				archived_books.push_back(*iter); // add book to archive list
				active_books.remove(*iter);		// add book to active list
				return;
			}
		}
		++iter;
	}
}
/* Add book to the active_books list
@params book_name - name of new book
*/
void Library::add_book(const string& book_name) {
	list<Book>::iterator iter = active_books.begin();
	while (iter != active_books.end()) {
		if (book_name == iter->get_name())
			throw std::exception("Book is already in the library");
		++iter;
	}
	Book new_book = Book(book_name);
	active_books.push_back(new_book);
}
/* Add employee to all the active book's queues
@params employee_name - name of new employee
*/
void Library::add_employee(const string& employee_name) {
	Employee new_employee = Employee(employee_name);
	employees.push_back(new_employee);
	list<Book>::iterator iter = active_books.begin();
	while (iter != active_books.end()) {
		iter->add_employee(employees.back());
		++iter;
	}
}