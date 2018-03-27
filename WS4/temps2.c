// Name: Andre Luiz Valle Rosa
// Student Number: 115997173
// Email: alvalle-rosa@myseneca.ca
// Section: IPC144 SLL
// Workshop: WS04 

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include <stdio.h>

#define SIZE 10

int main(void)
{
	int aHighTemp[SIZE] = { 0 };
	int aLowTemp[SIZE] = { 0 };
	int iHTemp, iLTemp;
	int index;
	int iSize = 0;
	int iHighest = -100, iLowest = +100;
	int iHDay, iLDay, iSelectedDay = 0;
	double dSum = 0;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	if ((iSize < 3) || (iSize > 10)) {

		printf("Please enter the number of days, between 3 and 10, inclusive: ");
		scanf("%d", &iSize);
		printf("\n");

		while ((iSize < 3) || (iSize > 10)) {
			printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &iSize);
			printf("\n");
		}
	}

	//ask for the temperatures
	for (index = 1; index <= iSize; index++)
	{
		printf("Day %d - High: ", index);
		scanf("%d", &iHTemp);

		printf("Day %d - Low: ", index);
		scanf("%d", &iLTemp);

		//saves in array
		aHighTemp[index - 1] = iHTemp;
		aLowTemp[index - 1] = iLTemp;

	}
	printf("\n");
	printf("Day  Hi  Low\n");

	//list the temperatures in a tabular way
	for (index = 0; index <= iSize - 1; index++)
	{
		printf("%d    %d    %d\n", (index + 1), aHighTemp[index], aLowTemp[index]);
	}
	printf("\n");

	//looks for highest and lowest temperature
	for (index = 0; index <= iSize - 1; index++)
	{
		if (aHighTemp[index] > iHighest) {
			iHighest = aHighTemp[index];
			iHDay = index + 1;
		  }
		if (aLowTemp[index] < iLowest) {
			iLowest = aLowTemp[index]; \
		    iLDay = index + 1;
		}
	}
	printf("The highest temperature was %d, on day %d\n", iHighest, iHDay);
	printf("The lowest temperature was %d, on day %d\n", iLowest, iLDay);
	printf("\n");


	  do {

		printf("Enter a number between 1 and %d to see the average temperature "
				"for the entered number of days, enter a negative number to exit: ", iSize);
		scanf("%d", &iSelectedDay);
		printf("\n");

		while ((iSelectedDay > iSize) || (iSelectedDay == 0))
		{
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", iSize);
			scanf("%d", &iSelectedDay);
			printf("\n");
		}

		//calculate the mean
		if (iSelectedDay > 0) {
			for (index = 0; index <= iSelectedDay - 1; index++)
			{
				dSum = dSum + aHighTemp[index] + aLowTemp[index];
			}
			double dMean = (dSum / (iSelectedDay * 2));
			printf("The average temperature up to day %d is: %.2f", iSelectedDay, dMean);
			printf("\n\n");
			dSum = 0;
		}

	  } while (iSelectedDay >= 0);
	
	printf("Goodbye!\n");

	return 0;
}