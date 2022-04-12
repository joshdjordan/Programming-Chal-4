#include "BinaryTree.h"
#include "employee.h"

int main()
{
	BinaryTree<employee> tree;
	employee emp;

	// employee 1 //
	emp = employee(1021, "John Williams"); // sets object to employee 1 info
	tree.insert(emp);

	// employee 2 //
	emp = employee(1057, "Bill Witherspoon"); // sets object to employee 1 info
	tree.insert(emp);

	// employee 3 //
	emp = employee(2487, "Jennifer Twain"); // sets object to employee 1 info
	tree.insert(emp);

	// employee 4 //
	emp = employee(3769, "Sophia Lancaster"); // sets object to employee 1 info
	tree.insert(emp);

	// employee 5 //
	emp = employee(1017, "Debbie Reece"); // sets object to employee 1 info
	tree.insert(emp);

	// employee 6 //
	emp = employee(1275, "George McMullen"); // sets object to employee 1 info
	tree.insert(emp);

	// employee 7 //
	emp = employee(1899, "Ashley Smith"); // sets object to employee 1 info
	tree.insert(emp);

	// employee 8 //
	emp = employee(4218, "Josh Plemmons"); // sets object to employee 1 info
	tree.insert(emp);

	tree.InOrder_Traversal();

	return 0;
}