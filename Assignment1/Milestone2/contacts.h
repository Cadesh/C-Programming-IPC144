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

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...

struct Address {
	int streetNumber;
	int apartmentNumber;
	char street[41];
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code here...

struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};