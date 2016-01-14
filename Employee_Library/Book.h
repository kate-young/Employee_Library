#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>
#include "Date.h"
#include "Employee_Queue.h"

class Book
{
public:
	Book();
	Book::Book(const string& book_name);
	/* Set archive attribute to true and end date to archive_date
	@params archive_date - the date that the book is to be archived
	*/
	void archive(const Date& archive_date);
	/* Name of the book
	@returns name
	*/
	std::string get_name() const;
	/* Give book to employee at the top of the queue, updates start_date and last_passed_date
	@params circulate_date - sets start_date and last_passed_date
	*/
	void circulate(const Date& circulate_date);
	/* Compares name of both books
	@returns true if this book's name == other_book's name
	*/
	bool operator==(const Book& other_book) const;
	/* Pass book to next employee in the queue. Updates the current employee's retaining_time
	with the time from the last_passed_date to the pass_date and removes that employee from the queue.
	Archives the book if the current employee was the last employee in the queue. If the current 
	employee is not the last employee, updates the next employee's wait_time with the time from the 
	book's start date to the pass_date.
	@params pass_date - date to pass the book to the next employee or archive the book
	*/
	void pass(const Date& pass_date);
	/* Add the referenced employee to the book's queue.
	@params new_employee - employee to be added the the queue.
	*/
	void add_employee(Employee& new_employee);
	/* Gets if the book is archived or not.
	@returns true if the book is archived, and false if not.
	*/
	bool is_archived() const;
private:
	/* Name of book
	*/
	std::string name;
	/* Book's start date. Updated when book is circulated.
	*/
	Date start_date;
	/* Book's end date. Updated when book is archived.
	*/
	Date end_date;
	/* Last time the book was passed.
	*/
	Date last_passed_date;
	/* Queue of emloyees who are going to recieve the book
	*/
	Employee_Queue employees;
	/* True if book is archived, false if not
	*/
	bool archived;
};

#endif

