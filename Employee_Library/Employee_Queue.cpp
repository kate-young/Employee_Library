#include "stdafx.h"
#include "Employee_Queue.h"


Employee_Queue::Employee_Queue()
{
}
/* Add employee to the queue
@params new_employee
*/
void Employee_Queue::push(Employee& new_employee) {
	if (head == NULL) { // if list is empty, create tail and set tail equal to head
		tail = new ENode(new_employee);
		head = tail;
	}
	else { // add new node to the end of the list
		tail->next = new ENode(new_employee);
		tail = tail->next;
	}
	num_items++;
}
/* Remove the employee with the highest priority from the queue.
*/
void Employee_Queue::pop() {
	ENode* top_node = find_top();
	remove_node(top_node);
	num_items--;
}
/* Determines if queue contains no employees
@returns true if there are no employees in the queue.
*/
bool Employee_Queue::empty() {
	return head == NULL;
}
/* Gets employee with the highest priority.
@returns a pointer to the employee with the highest priority
*/
Employee* Employee_Queue::top() {
	return find_top()->the_employee;
}
/* Determine which node contains the employee with the highest priority
@returns a pointer to the node that contains the employee with the highest priority
*/
ENode* Employee_Queue::find_top() {
	ENode* current_node = head;
	ENode* top_node = head;
	while (current_node != NULL) { // Find the employee in the list with the highest priority
		if (current_node->the_employee->get_priority() > top_node->the_employee->get_priority()) {
			top_node = current_node;
		}
		current_node = current_node->next;
	}
	return top_node;
}
/* Remove node from linked list
@params pointer to the node that needs to be removed from the list.
*/
void Employee_Queue::remove_node(ENode* the_node) {
	if (the_node == head) {
		head = head->next; // set new head, then delete
		delete the_node;
		return;
	}
	ENode* current = head;
	while (current->next->next != NULL) {
		if (current->next == the_node)
			break; // find node before the current node
		current = current->next;
	}	
	if (the_node == tail) {
		tail = current;			// set new tail
		current->next = NULL; 
		delete the_node;
		return;
	}
	current->next = current->next->next; // update previous node's next to this node's next.
	delete the_node;
}

