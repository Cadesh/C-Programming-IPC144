/*
Name:      Andre Luiz Valle Rosa
eMail:     al-vallerosa@myseneca.ca
Student:   115997173
Section:   SLL
*/

// Start your code below:
#include<stdio.h>

int main(void)
{
	double dAmount;
	int iCoins;
	const double dTax = 0.13; //GST tax % is a constant.
	double dGST; //the tax value after calculation.
        int iAmount; // will be used because of the modulus operation

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &dAmount);  

	//GST
	dGST = dAmount * dTax + .005; // Tax owed. Adds 0.005 to round correctly in VS and GCC compilers.
	printf("GST: %.2lf\n", dGST);

	//BALANCE OWING
	dAmount = dAmount + dGST; //the total value owed.
	printf("Balance owing: $%.2lf\n", dAmount);

	//LOONIES
	iCoins = (int)dAmount;        //explicit cast to int.
	dAmount = dAmount - iCoins;    //reusing the same variable  
	printf("Loonies required: %d, balance owing $%.2lf\n", iCoins, dAmount);

	//prepares amount to be used
	iAmount = (int)(dAmount * 100);  //turn the double amount into a int amount to use modulus

	//QUARTERS
	iCoins = (iAmount / 25);     
	//Calculating the balance owing, I am reusing dAmount again.
	iAmount = iAmount % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", iCoins, (double)iAmount/100);

	//DIMES
	iCoins = (iAmount / 10);
	//Calculating the balance owing, I am reusing dAmount again.
	iAmount = iAmount % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", iCoins, (double)iAmount / 100);

	//NICKELS
	iCoins = (iAmount / 5);
	//Calculating the balance owing, I am reusing dAmount again.
	iAmount = iAmount % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", iCoins, (double)iAmount / 100);

	//PENNIES
	printf("Pennies required: %d, balance owing $0.00\n", iAmount);


	return 0;

	//program worked fine. I used 5 variables. The dTax variable was used because I wanted to use a "const" in my code.
}
