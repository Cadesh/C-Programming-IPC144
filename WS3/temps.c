// Name:           Andre Luiz Valle Rosa
// Student Number: 115997173
// Email:          al-vallerosa@myseneca.ca
// Section:        SLL
// Workshop:       WS03 LOGIC


#include <stdio.h>

#define NUNS 4  //Number 

int main(void)
{
	//TITLE
	printf("---=== IPC Temperature Analyzer ===---\n");

	int counter = 1;
	int iLoTemp, iHiTemp;
	int iTotalHigh = 0;
	int iTotalLow = 0;
	int validate = 0;
	const int iHighest = 41;
	const int iLowest = -41;
    int iHighestOfAll = 0;
	int iLowestOfAll = 0;
	int iDayOfHigher = 0;
	int iDayOfLower = 0;

	//FOR LOOP
	for (counter = 1; counter <= NUNS; counter++)
	{

		printf("Enter the high value for day %d: ", counter);
		scanf("%d", &iHiTemp);
		printf("\n");


		printf("Enter the low value for day %d: ", counter);
		scanf("%d", &iLoTemp);
		printf("\n");



		while ((iHiTemp > iLoTemp) && (iHiTemp < iHighest) && (iLoTemp > iLowest))
		{
			if (iHighestOfAll < iHiTemp) {
				iHighestOfAll = iHiTemp; //stores highest temperature
				iDayOfHigher = counter;  //stores the day
			}
			if (iLowestOfAll > iLoTemp) {
				iLowestOfAll = iLoTemp;  //stores lowest temperature
				iDayOfLower = counter;   //stores the day
			}
			iTotalHigh = iTotalHigh + iHiTemp;
			iTotalLow = iTotalLow + iLoTemp;
			validate = 1;
			break;
		}


		if (validate == 0) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high "
				"must be greater than low.\n");
			printf("\n");
			counter--;
		}

	validate = 0;
	} //END for (counter; counter <= NUNS; counter++)

	 // MEAN CALCULATION
	double dMean = (double)(iTotalHigh + iTotalLow) / (2 * NUNS);
	printf("The average (mean) temperature was: %0.2f\n", dMean);
	printf("The highest temperature was %d, on day %d\n", iHighestOfAll, iDayOfHigher);
	printf("The lowest temperature was %d, on day %d\n", iLowestOfAll, iDayOfLower);

	return 0;

}