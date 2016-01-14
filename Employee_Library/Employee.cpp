#include "stdafx.h"
#include "Employee.h"


Employee::Employee(): name(""), wait_time(0), retaining_time(0)
{
}
Employee::Employee(const string& employee_name) :name(employee_name), wait_time(0), retaining_time(0) {}
/* Gets employee's priority which is the difference between the number of days
the employee waited for the book and the number of days the employee retained the book.
*/
int Employee::get_priority() const {
	return wait_time - retaining_time;
}
/* Name of employee
@returns the name of the employee
*/
std::string Employee::get_name() const{
	return name;
}
/* Add to the emloyee's wait time.
@params pass_date - the date the book is being passed to the employee
@params start_date - the date the book was put in circulation
*/
void Employee::set_wait_time(const Date& pass_date, const Date& start_date) {
	wait_time += pass_date - start_date;
}
/* Add to the employee's retaining time.
@params pass_date - the date the book is being passed to the next employee
@params last_passed_date - the date the book was passed to this employee
*/
void Employee::set_retaining_time(const Date& pass_date, const Date& last_passed_date) {
	retaining_time += pass_date - last_passed_date;
}