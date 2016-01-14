#include "stdafx.h"
#include "Book.h"


Book::Book() :archived(false) {}
Book::Book(const string& book_name) :name(book_name), archived(false){
	start_date = Date(1, 1, 1, DateFormat::US);
	end_date = Date(1, 1, 1, DateFormat::US);
	last_passed_date = start_date;
}
/* Set archive attribute to true and end date to archive_date
@params archive_date - the date that the book is to be archived
*/
void Book::archive(const Date& archive_date) {
	archived = true;
	end_date = archive_date;
}
/* Name of the book
@returns name
*/
std::string Book::get_name() const{
	return name;
}
/* Give book to employee at the top of the queue, updates start_date and last_passed_date
@params circulate_date - sets start_date and last_passed_date
*/
void Book::circulate(const Date& circulate_date) {
	start_date = circulate_date;
	last_passed_date = start_date;
}
/* Compares name of both books
@returns true if this book's name == other_book's name
*/
bool Book::operator==(const Book& other_book) const {
	return name == other_book.get_name();
}
/* Pass book to next employee in the queue. Updates the current employee's retaining_time
with the time from the last_passed_date to the pass_date and removes that employee from the queue.
Archives the book if the current employee was the last employee in the queue. If the current
employee is not the last employee, updates the next employee's wait_time with the time from the
book's start date to the pass_date.
@params pass_date - date to pass the book to the next employee or archive the book
*/
void Book::pass(const Date& pass_date) {
	Employee* temp = employees.top();	// save top employee
	employees.pop();					// remove current emloyee from the queue
	temp->set_retaining_time(pass_date, last_passed_date); // set retaining time for previous top employee
	last_passed_date = pass_date;	// update the book's last passed date to this passed date
	if (employees.empty()) {		// If queue is now empty, archive the book
		archive(pass_date);
		return;
	}
	employees.top()->set_wait_time(pass_date, start_date); // set wait time for next employee
}
/* Add the referenced employee to the book's queue.
@params new_employee - employee to be added the the queue.
*/
void Book::add_employee(Employee& new_employee) {
	employees.push(new_employee);
}
/* Gets if the book is archived or not.
@returns true if the book is archived, and false if not.
*/
bool Book::is_archived() const {
	return archived;
}
