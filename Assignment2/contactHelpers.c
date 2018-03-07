/* -------------------------------------------
Name: Andre Luiz Valle Rosa
Student number: 115997173
Email: alvalle-rosa@myseneca.ca
Section: IPC144 SLL
Date: 05 DEC 2017
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS


//#include <ctype.h>
#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


//////////////////////////////////////////////////////////////////////
// Clear the standard input buffer
void clearKeyboard(void)
{
	//clear the buffer
	while (getchar() != '\n'); // empty execution code block on purpose
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();

}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// getInt: Empty function definition goes here:
int getInt(void)
{
	int value;
	char NL = 'x';

	scanf(" %d%c", &value, &NL);

	while (NL != '\n')  
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf(" %d%c", &value, &NL);

	}
	//printf("Integer entered: %d", value);
	return value;
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// getIntInRange: Empty function definition goes here:
int getIntInRange(int inferiorLimit, int superiorLimit)
{
	int iLoc = getInt();

	while ((iLoc < inferiorLimit) || (iLoc > superiorLimit))
	{
		//clearKeyboard();
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", 
			    inferiorLimit, superiorLimit);
		iLoc = getInt();
	}

	//printf("Integer entered: %d\n", iLoc);
	return iLoc;
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// yes: Empty function definition goes here:
int yes(void)
{
	char lChar = 'x';
	char lChar2 = 'x';
	int response = -1;

	scanf(" %c%c", &lChar, &lChar2);

	while (!((lChar2 == '\n') && ((lChar == 'Y') || (lChar == 'y') || 
		                          (lChar == 'n') || (lChar == 'N'))))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		//scanf(" %c%*c[^\n]", &lChar, &lChar2);
		scanf(" %c%c", &lChar, &lChar2);

	}

	if ((lChar == 'Y') || (lChar == 'y')) {
		response = 1;
	}
	else if ((lChar == 'N') || (lChar == 'n')) {
		response = 0;
	}

	return response;
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// menu: Empty function definition goes here:
int menu(void)
{

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
	printf("\n");
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// ContactManagerSystem: Empty function definition goes here:
void ContactManagerSystem(void)
{
	int iSelection;
	//char cExit;
	//int opt;

	do {
		iSelection = menu();
	//For selections between 1 and 6, the application should 
	//pause and then return to displaying the menu. 
	switch (iSelection)
	{
	case 0:
		printf("\nExit the program? (Y)es/(N)o: ");
		int opt = yes();
		if (opt == 1) {
			printf("\nContact Management System: terminated\n");
			return;
		}
		else { printf("\n"); }

		break;
	case 1:
		printf("\n<<< Feature 1 is unavailable >>>\n\n");
		pause();
		printf("\n");
		break;
	case 2:
		printf("\n<<< Feature 2 is unavailable >>>\n\n");
		pause();
		printf("\n");
		break;
	case 3:
		printf("\n<<< Feature 3 is unavailable >>>\n\n");
		pause();
		printf("\n");
		break;
	case 4:
		printf("\n<<< Feature 4 is unavailable >>>\n\n");
		pause();
		printf("\n");
		break;
	case 5:
		printf("\n<<< Feature 5 is unavailable >>>\n\n");
		pause();
		printf("\n");
		break;
	case 6:
		printf("\n<<< Feature 6 is unavailable >>>\n\n");
		pause();
		printf("\n");
		break;
	default:
		printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> ");
		break;
	}

	} while ((iSelection >= 0) || (iSelection <= 6));

	return;
}
//////////////////////////////////////////////////////////////////////