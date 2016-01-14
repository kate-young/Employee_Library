#ifndef _EMPLOYEE_QUEUE_H_
#define _EMPLOYEE_QUEUE_H_

#include "Employee.h"

/* Node of Employees for the linked list. Contains a pointer
to the Employee in the Employee list of the Book class
*/
struct ENode{
	Employee* the_employee;
	ENode* next;
	ENode(Employee& employee, ENode* next_ptr) :
		the_employee(&employee), next(next_ptr) {}
	ENode(Employee& employee) :
		the_employee(&employee), next(NULL) {}
};
class Employee_Queue
{
public:
	Employee_Queue();
	/* Add employee to the queue
	@params new_employee
	*/
	void Employee_Queue::push(Employee& new_employee);
	/* Remove the employee with the highest priority from the queue.
	*/
	void pop();
	/* Determines if queue contains no employees
	@returns true if there are no employees in the queue.
	*/
	bool empty();
	/* Gets employee with the highest priority.
	@returns a pointer to the employee with the highest priority
	*/
	Employee* top();
private:
	/* Number of employees in the queue
	*/
	size_t num_items = 0;
	/* Head of the linked list. This is not necessarily what will be returned
	by top().
	*/
	ENode* head = NULL;
	/* Tail of the linked list.
	*/
	ENode* tail = NULL;
	/* Determine which node contains the employee with the highest priority
	@returns a pointer to the node that contains the employee with the highest priority
	*/
	ENode* Employee_Queue::find_top();
	/* Remove node from linked list
	@params pointer to the node that needs to be removed from the list.
	*/
	void Employee_Queue::remove_node(ENode* the_node);
};

#endif