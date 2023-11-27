#include <stdio.h>

int getTimeEnd(int dTimeStart, int dDay)
{
	int dTimeEnd;
	
	// Loop until the user inputs a valid time in military format
	do 
	{
		if (!dTimeStart && dDay == 1)
		{
			printf("What time did you wake up?\n\n");
		}
		else
		{
			printf("What time did the activity end?\n\n");
		}
		
		printf("[0000 - 2359]\n\n");
		printf("Enter time: ");
		scanf("%d", &dTimeEnd);
		printf("\n");
		
		if (dTimeEnd < 0 || dTimeEnd >= 2400 || dTimeEnd % 100 >= 60)
		{
			printf("ERROR\n\n");
		}	
	}
	while (dTimeEnd < 0 || dTimeEnd >= 2400 || dTimeEnd % 100 >= 60);
	
	return dTimeEnd / 100 * 60 + (dTimeEnd % 100);
}

int getCategory(int dTimeStart, int dDay)
{
	int dCategory;
	
	// Loop until the user inputs a valid category
	do
	{
		if (!dTimeStart && dDay == 1)
		{
			dCategory = 9;
		}
		else
		{
			printf("Categories of Activities\n\n");
			printf("[1] Health\n");
			printf("[2] Leisure\n");
			printf("[3] Work\n");
			printf("[4] Chores\n");
			printf("[5] Self-Improvement\n");
			printf("[6] Helping Others\n");
			printf("[7] Family\n");
			printf("[8] Rest\n");
			printf("[9] Sleep\n");
			printf("[10] Eating\n\n");
			printf("Enter category: ");
			scanf("%d", &dCategory);
			printf("\n");
		}
			
		if(dCategory < 1 || dCategory > 10)
		{
			printf("ERROR\n\n");
		}
	} while (dCategory < 1 || dCategory > 10);		
	
	return dCategory;
}

int isCorrect()
{
	int dCorrect;
	
	do
	{
		printf("This activity lasts for more than 3 hours. Is this correct?\n\n");
		printf("[1] Yes\n");
		printf("[0] No\n\n");
		printf("Enter option: ");
		scanf("%d", &dCorrect);
		printf("\n");
					
		if (dCorrect != 0 && dCorrect != 1)
		{
			printf("ERROR\n\n");
		}	
	} while (dCorrect != 0 && dCorrect != 1);
	
	return dCorrect;
}

int getContinue()
{
	int dContinue;
	
	// Loop until user provides a valid input
	do
	{
		printf("Would you like to continue using the program for this next day?\n\n");
		printf("[1] Yes\n");
		printf("[0] No\n\n");
		printf("Enter option: ");
		scanf("%d", &dContinue);		
		printf("\n");
			
		if(dContinue != 0 && dContinue != 1)
		{
			printf("ERROR\n\n");
		}	
	} while (dContinue != 0 && dContinue != 1);
	
	return dContinue;
}

void addDuration(int dCategory, int dDuration, int* dPreviousHealth, int* dPreviousLeisure, int* dPreviousWork, int* dPreviousChores, int* dPreviousSelf, int* dPreviousHelping, int* dPreviousFamily, int* dPreviousRest, int* dPreviousSleep, int* dPreviousEating, int* dTotalHealth, int* dTotalLeisure, int* dTotalWork, int* dTotalChores, int* dTotalSelf, int* dTotalHelping, int* dTotalFamily, int* dTotalRest, int* dTotalSleep, int* dTotalEating)
{
	// Add the duration to the category chosen by the user
	switch (dCategory)
	{
		case 1:
			*dPreviousHealth += dDuration;
			*dTotalHealth += dDuration;
			break;
				
		case 2: 
			*dPreviousLeisure += dDuration;
			*dTotalLeisure += dDuration;
			break;
				
		case 3: 
			*dPreviousWork += dDuration;
			*dTotalWork += dDuration;
			break;
				
		case 4: 
			*dPreviousChores += dDuration;		
			*dTotalChores += dDuration;
			break;
			
		case 5: 
			*dPreviousSelf += dDuration;
			*dTotalSelf += dDuration;
			break;
			
		case 6:
			*dPreviousHelping += dDuration;
			*dTotalHelping += dDuration;
			break;
			
		case 7:
			*dPreviousFamily += dDuration;
			*dTotalFamily += dDuration;
			break;
			
		case 8:
			*dPreviousRest += dDuration;
			*dTotalRest += dDuration;
			break;
			
		case 9:
			*dPreviousSleep += dDuration;	
			*dTotalSleep += dDuration;
			break;
			
		case 10:
			*dPreviousEating += dDuration;
			*dTotalEating += dDuration;
			break;				
	}
}

void sortTimeSpent(int* dA, int* dB)
{	
	// Swap the values of dA and dB if dA is less than dB
	if (*dA < *dB)
	{
		int dTemp = *dA;
		*dA = *dB;
		*dB = dTemp;
	}
}

void printStatistics(int* isPrintedH, int* isPrintedL, int* isPrintedW, int* isPrintedC, int* isPrintedS, int* isPrintedHelp, int* isPrintedF, int* isPrintedR, int* isPrintedSleep, int* isPrintedE, int dDay, int nMinutes, int* dPreviousHealth, int* dPreviousLeisure, int* dPreviousWork, int* dPreviousChores, int* dPreviousSelf, int* dPreviousHelping, int* dPreviousFamily, int* dPreviousRest, int* dPreviousSleep, int* dPreviousEating)
{	
	// Conditional tree that prints the value of nMinutes if it hasn't been printed and if it is equal to the category
	if (*dPreviousHealth == nMinutes && *isPrintedH != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Health\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay)); 
		*isPrintedH = 1;
	}
	else if (*dPreviousLeisure == nMinutes && *isPrintedL != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Leisure\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedL = 1;
	}	
	else if (*dPreviousWork == nMinutes && *isPrintedW != 1 )
	{
		printf("%02dh %02dm | %6.2f%% | Work\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedW = 1;
	}
	else if (*dPreviousChores == nMinutes && *isPrintedC != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Chores\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedC = 1;
	}	
	else if (*dPreviousSelf == nMinutes && *isPrintedS != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Self-Improvement\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedS = 1;
	}
	else if (*dPreviousHelping == nMinutes && *isPrintedHelp != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Helping Others\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedHelp = 1;
	}	
	else if (*dPreviousFamily == nMinutes && *isPrintedF != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Family\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedF = 1;
	}	
	else if (*dPreviousRest == nMinutes && *isPrintedR != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Rest\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedR = 1;
	}	
	else if (*dPreviousSleep == nMinutes && *isPrintedSleep != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Sleep\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedSleep = 1;
	}	
	else if (*dPreviousEating == nMinutes && *isPrintedE != 1)
	{
		printf("%02dh %02dm | %6.2f%% | Eating\n", nMinutes / 60, nMinutes % 60, nMinutes / (14.4 * dDay));
		*isPrintedE = 1;
	}	
}

void displayPreviousDayStatistics(int* dPreviousHealth, int* dPreviousLeisure, int* dPreviousWork, int* dPreviousChores, int* dPreviousSelf, int* dPreviousHelping, int* dPreviousFamily, int* dPreviousRest, int* dPreviousSleep, int* dPreviousEating)
{
	// Declare and initialize the order of the activities
	int dFirst = *dPreviousHealth;
	int dSecond = *dPreviousLeisure;
	int dThird = *dPreviousWork;
	int dFourth = *dPreviousChores;
	int dFifth = *dPreviousSelf;
	int dSixth = *dPreviousHelping;
	int dSeventh = *dPreviousFamily;
	int dEight = *dPreviousRest;
	int dNinth = *dPreviousSleep;
	int dTenth = *dPreviousEating;
	
	// Declare and initialize the boolean flags to 0
	int isPrintedH = 0;
	int isPrintedL = 0;
	int isPrintedW = 0;
	int isPrintedC = 0;
	int isPrintedS = 0;
	int isPrintedHelp = 0;
	int isPrintedF = 0;
	int isPrintedR = 0;
	int isPrintedSleep = 0;
	int isPrintedE = 0;
	
	// Sort the values until it is ordered from greatest to least
	while (dFirst < dSecond || dSecond < dThird || dThird < dFourth || dFourth < dFifth || dFifth < dSixth || dSixth < dSeventh || dSeventh < dEight || dEight < dNinth || dNinth < dTenth)
	{
		sortTimeSpent(&dFirst, &dSecond);
		sortTimeSpent(&dSecond, &dThird);
		sortTimeSpent(&dThird, &dFourth);
		sortTimeSpent(&dFourth, &dFifth);
		sortTimeSpent(&dFifth, &dSixth);
		sortTimeSpent(&dSixth, &dSeventh);
		sortTimeSpent(&dSeventh, &dEight);
		sortTimeSpent(&dEight, &dNinth);
		sortTimeSpent(&dNinth, &dTenth);
	}
	
	// Print the previous day statistics
	printf("Previous Day Statistics (Past 24 hours)\n\n");
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dFirst, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dSecond, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dThird, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dFourth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dFifth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dSixth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dSeventh, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dEight, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dNinth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, 1, dTenth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printf("\n");
	
	// Reset the previous day categories
	*dPreviousHealth = *dPreviousLeisure = *dPreviousWork = *dPreviousChores = *dPreviousSelf = *dPreviousHelping = *dPreviousFamily = *dPreviousRest = *dPreviousSleep = *dPreviousEating = 0;
}

void displayTotalStatistics(int dDay, int* dTotalHealth, int* dTotalLeisure, int* dTotalWork, int* dTotalChores, int* dTotalSelf, int* dTotalHelping, int* dTotalFamily, int* dTotalRest, int* dTotalSleep, int* dTotalEating)
{
	// Declare and initialize the order of the categories
	int dFirst = *dTotalHealth;
	int dSecond = *dTotalLeisure;
	int dThird = *dTotalWork;
	int dFourth = *dTotalChores;
	int dFifth = *dTotalSelf;
	int dSixth = *dTotalHelping;
	int dSeventh = *dTotalFamily;
	int dEight = *dTotalRest;
	int dNinth = *dTotalSleep;
	int dTenth = *dTotalEating;
	
	// Declare and initialize the boolean flags to 0
	int isPrintedH = 0;
	int isPrintedL = 0;
	int isPrintedW = 0;
	int isPrintedC = 0;
	int isPrintedS = 0;
	int isPrintedHelp = 0;
	int isPrintedF = 0;
	int isPrintedR = 0;
	int isPrintedSleep = 0;
	int isPrintedE = 0;
	
	// Sort the values until it is ordered from greatest to least
	while (dFirst < dSecond || dSecond < dThird || dThird < dFourth || dFourth < dFifth || dFifth < dSixth || dSixth < dSeventh || dSeventh < dEight || dEight < dNinth || dNinth < dTenth)
	{
		sortTimeSpent(&dFirst, &dSecond);
		sortTimeSpent(&dSecond, &dThird);
		sortTimeSpent(&dThird, &dFourth);
		sortTimeSpent(&dFourth, &dFifth);
		sortTimeSpent(&dFifth, &dSixth);
		sortTimeSpent(&dSixth, &dSeventh);
		sortTimeSpent(&dSeventh, &dEight);
		sortTimeSpent(&dEight, &dNinth);
		sortTimeSpent(&dNinth, &dTenth);
	}
	
	// Print the total statistics
	printf("Total Statistics (Past %d hours)\n\n", dDay * 24);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dFirst, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dSecond, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dThird, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dFourth, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dFifth, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dSixth, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dSeventh, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dEight, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dNinth, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dTenth, dTotalHealth, dTotalLeisure, dTotalWork, dTotalChores, dTotalSelf, dTotalHelping, dTotalFamily, dTotalRest, dTotalSleep, dTotalEating);
	printf("\n");
}

int main()
{
	int dTimeEnd, dTimeStart = 0000;
	int dCategory;
	int dDuration;
	int dDay = 1;
	int dContinue = 1;
	
	int dPreviousHealth = 0, dPreviousLeisure = 0, dPreviousWork = 0, dPreviousChores = 0, dPreviousSelf = 0, dPreviousHelping = 0, dPreviousFamily = 0, dPreviousRest = 0, dPreviousSleep = 0, dPreviousEating = 0;
	int dTotalHealth = 0, dTotalLeisure = 0, dTotalWork = 0, dTotalChores = 0, dTotalSelf = 0, dTotalHelping = 0, dTotalFamily = 0, dTotalRest = 0, dTotalSleep = 0, dTotalEating = 0;
	
	printf("Wellness Tracker\n\n");
	
	// Loop while the user opts to continue
	do
	{	
		// Get Time End
		dTimeEnd = getTimeEnd(dTimeStart, dDay);

		// Get Category
		dCategory = getCategory(dTimeStart, dDay);
		
		if (dTimeEnd > dTimeStart)
		{
			dDuration = dTimeEnd - dTimeStart;
			
			if (dDuration > 180 && dCategory != 9)
			{
				// Error handling for activities lasting more than 3 hours that is not sleep
				if(isCorrect())
				{
					addDuration(dCategory, dDuration, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
					
					dTimeStart = dTimeEnd;
				}
				else
				{
					printf("Input ignored, input again\n\n");
				}
			}
			else
			{
				addDuration(dCategory, dDuration, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
			
				dTimeStart = dTimeEnd;
			}
		}
		else
		{
			dDuration = 1440 - dTimeStart + dTimeEnd;
			
			if(dDuration > 180 && dCategory != 9)
			{	
				// Error handling for activities lasting more than 3 hours that is not sleep
				if(isCorrect())
				{
					addDuration(dCategory, dDuration - dTimeEnd, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
						
					displayPreviousDayStatistics(&dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating);
							
					if(dDay > 1)
					{
						displayTotalStatistics(dDay, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
					}
							
					dDay++;
							
					addDuration(dCategory, dTimeEnd, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
							
					dContinue = getContinue();
					
					dTimeStart = dTimeEnd;
				}
				else
				{
					printf("Input ignored, input again\n\n");
				}
			}
			else
			{
				addDuration(dCategory, dDuration - dTimeEnd, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
				
				displayPreviousDayStatistics(&dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating);
				
				if(dDay > 1)
				{
					displayTotalStatistics(dDay, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
				}
					
				dDay++;
				
				addDuration(dCategory, dTimeEnd, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
				
				dContinue = getContinue();
				
				dTimeStart = dTimeEnd;
			}
		}
	} while (dContinue);
	
	printf("Thank you!\n");		
	
	return 0;
}
