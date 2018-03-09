/*

	Workshop : WS05 Home
	Section : IPC144 SLL
	Date : 10 OCT 2017
	*/


// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "emp_athome.h"

// Define Number of Employees "SIZE" to be 4
#define SIZE 4

// Declare Struct Employee
//declared in .h file

/* main program */
int main(void) {

	int option = 0;
	int iSelectedId = -1;
	int iFoundId = -1;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee aEmployee[SIZE] = { { 0 } }; //double brackets otherwise gcc will make a warning
	int i;
	int empAdded = 0;

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		// "3. Update Employee Salary"
		// "4. Remove Employee"
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");

		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			for (i = 0; i < SIZE; i++) {

				if (aEmployee[i].idNumber > 0) {  //writes only employees with valid id
					printf("%6d%9d%11.2lf\n", aEmployee[i].idNumber, aEmployee[i].iAge, aEmployee[i].dSalary);
				}
			}
			printf("\n");
			break;
		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 
			if (empAdded < SIZE) { //checks for empty slots in array

				for (i = 0; i < SIZE; i++) {   

					if (aEmployee[i].idNumber == 0) { //finds the first empty slot to insert new employee
						printf("Enter Employee ID: ");
						scanf("%d", &aEmployee[i].idNumber);
						printf("Enter Employee Age: ");
						scanf("%d", &aEmployee[i].iAge);
						printf("Enter Employee Salary: ");
						scanf("%lf", &aEmployee[i].dSalary);
						printf("\n");
						empAdded++;  //counts employee
						i = SIZE;
					}
				}
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}


			break;

       /////////////////////////////////////////////////////
		case 3: //Update Employee Salary
			printf("Update Employee Salary\n");
			printf("======================\n");
			
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &iSelectedId);
			
				for (i = 0; i < SIZE; i++) {
					if (iSelectedId == aEmployee[i].idNumber) {//found the id
						iFoundId = i;
						i = SIZE;
					}
				}
			} while (iFoundId < 0);


			printf("The current salary is %.2f\n", aEmployee[iFoundId].dSalary);
			printf("Enter Employee New Salary: ");
			scanf("%lf", &aEmployee[iFoundId].dSalary);
			printf("\n");

	    iFoundId = -1;
		break;
		/////////////////////////////////////////////////////
		case 4: //Remove Employee
			printf("Remove Employee\n");
			printf("===============\n");

			do {
				printf("Enter Employee ID: ");
				scanf("%d", &iSelectedId);

				for (i = 0; i < SIZE; i++) {
					if (iSelectedId == aEmployee[i].idNumber) {//found the id
						iFoundId = i;
						printf("Employee %d will be removed\n\n", iSelectedId);
						aEmployee[i].idNumber = 0;
						empAdded--; //decreases the employee counter
						i = SIZE;
					}
				}
			} while (iFoundId < 0);

			iFoundId = -1;

		break;
       /////////////////////////////////////////////////////
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}
	} while (option != 0);


	return 0;
}




// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   99999.99
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/