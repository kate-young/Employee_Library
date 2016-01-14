#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string>
#include "Date.h"

class Employee
{
public:
	Employee();
	Employee(const string& employee_name);
	/* Gets employee's priority which is the difference between the number of days
	the employee waited for the book and the number of days the employee retained the book.
	*/
	int get_priority() const;
	/* Name of employee
	@returns the name of the employee
	*/
	std::string get_name() const;
	/* Add to the emloyee's wait time.
	@params pass_date - the date the book is being passed to the employee
	@params start_date - the date the book was put in circulation
	*/
	void set_wait_time(const Date& pass_date, const Date& start_date);
	/* Add to the employee's retaining time.
	@params pass_date - the date the book is being passed to the next employee
	@params last_passed_date - the date the book was passed to this employee
	*/
	void set_retaining_time(const Date& pass_date, const Date& last_passed_date);
private:
	/* Name of the employee
	*/
	std::string name;
	/* Time, in days, that the Employee has been waiting for a book
	*/
	size_t wait_time = 0;
	/* Time, in days, that the Employee has had a book
	*/
	size_t retaining_time = 0;
};

#endif
