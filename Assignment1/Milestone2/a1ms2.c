/* -------------------------------------------
Name: Andre Luiz Valle Rosa
Student number: 115997173
Email: alvalle-rosa@myseneca.ca
Section: IPC144 SLL
Date: 20 OCT 2017
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main (void)
{
    // Declare variables here:
	struct Name sName = {"" ,"" ,"" };
	struct Address sAddress = { 0,0,"","","" };
	struct Numbers sNumbers = {"","",""};
	char option[2] = ("n");   //defining the array size to avoid warnings

    // Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");



    // Contact Name Input:
	/////////////////////////////////////////////////////////////////////////////
	printf("Please enter the contact's first name: ");
	scanf("%30s", sName.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		sName.middleInitial[0] = '\0';
	} else {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", sName.middleInitial);

	}
	
	printf("Please enter the contact's last name: ");
	scanf("%35s", sName.lastName);

    // Contact Address Input:
	/////////////////////////////////////////////////////////////////////////////
	printf("Please enter the contact's street number: ");
	scanf("%d", &sAddress.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%40s", sAddress.street);

	printf("Do you want to enter an appartment number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		sAddress.apartmentNumber = -1;
	}
	else {
		printf("Please enter the contact's appartment number: ");
		scanf("%d", &sAddress.apartmentNumber);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", sAddress.postalCode);

	printf("Please enter the contact's city: ");
	scanf("%40s", sAddress.city);

	
    // Contact Numbers Input:
	///////////////////////////////////////////////////////////////////////////
	
	//CELL
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		sNumbers.cell[0] = '\0';
	}
	else {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %20[^\n]", sNumbers.cell);
	}

    //HOME
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		sNumbers.home[0] = '\0';
	}
	else {
		printf("Please enter the contact's home phone number: ");
		scanf(" %20[^\n]", sNumbers.home);

	}

	//BUSINESS
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		sNumbers.business[0] = '\0';
	}
	else {
		printf("Please enter the contact's business phone number: ");
		scanf(" %20[^\n]", sNumbers.business);
	}
	printf("\n");

	////////////////////////////////////////////////////////////////////////
    // Display Contact Summary Details
	printf("Contact Details\n");
	printf("---------------\n");

	printf("Name Details\n");
	printf("First name: %s\n", sName.firstName);
	printf("Middle initial(s): %s\n", sName.middleInitial);
	printf("Last name: %s\n", sName.lastName);
	printf("\n");

	printf("Address Details\n");
	printf("Street number: %d\n", sAddress.streetNumber);
	printf("Street name: %s\n", sAddress.street);
	printf("Apartment: %d\n", sAddress.apartmentNumber);
	printf("Postal code: %s\n", sAddress.postalCode);
	printf("City: %s\n", sAddress.city);
	printf("\n");

	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", sNumbers.cell);
	printf("Home phone number: %s\n", sNumbers.home);
	printf("Business phone number: %s\n", sNumbers.business);
	printf("\n");

    // Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");

    return 0;
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/