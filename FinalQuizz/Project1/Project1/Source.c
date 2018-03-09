#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 10

struct Team
{
	char teamName[31];
	int goalsAgainst;
	int goalsScored;
};

int readStats(struct Team *aTeam, const int iSize)
{
	int i; 
	struct Team lTeam = { {"\0"}, {0}, {0} };
	char Continue = '\0';
	int GetTeam;

	for (i = 0; i < iSize; i++)
	{
		printf("Do you want to enter a Team? (Yes/Quit) ");
		scanf("%c", &Continue);
		while (getchar() != '\n');

			if ((Continue == 'Y') || (Continue == 'y')) {

				printf("Enter Team name: ");
				scanf("%[^\n]30s", lTeam.teamName);

				printf("Enter Team Goals Against: ");
				scanf("%d", &lTeam.goalsAgainst);

				while (lTeam.goalsAgainst < 0) {
					printf("Invalid value, enter a positive number.");
					scanf("%d", &lTeam.goalsAgainst);
				}

				printf("Enter Goals Scored: ");
				scanf("%d", &lTeam.goalsScored);

				while (lTeam.goalsScored < 0) {
					printf("Invalid value, enter a positive number.");
					scanf("%d", &lTeam.goalsScored);
				}
				while (getchar() != '\n');
				aTeam[i] = lTeam;

			}
			else {
				i = iSize;
			}
	}
return 0;
}

int main(void)
{
	struct Team *aTeam [SIZE];

	readStats(aTeam, SIZE);

	return 0;

}