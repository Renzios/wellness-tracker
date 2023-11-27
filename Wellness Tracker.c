#include <stdio.h>

int getTimeEnd(int dTimeStart, int dDay)
{
	int dTimeEnd;
	
	// loops if invalid input
	do 
	{
		if (dTimeStart != 0)
		{
			printf("What time did the next activity end? (0000-2359) ");
			scanf("%d", &dTimeEnd);	
		}
		else if (!dTimeStart && dDay == 1)
		{
			printf("What time did you wake up? (0000-2359) ");
			scanf("%d", &dTimeEnd);
		}
		
		if (dTimeEnd < 0 || dTimeEnd >= 2400 || dTimeEnd % 100 >= 60)
		{
			printf("ERROR! Please input again.\n");
		}	
	}
	while (dTimeEnd < 0 || dTimeEnd >= 2400 || dTimeEnd % 100 >= 60);
	
	// return Time End as minutes
	return dTimeEnd / 100 * 60 + (dTimeEnd % 100);
}

int getCategory(int dTimeStart, int dDay)
{
	int dCategory;
	
	if (dTimeStart != 0)
	{
		printf("CATEGORY OF ACTIVITIES\n");
		printf("[1] Health\n");
		printf("[2] Leisure\n");
		printf("[3] Work\n");
		printf("[4] Chores\n");
		printf("[5] Self-Improvement\n");
		printf("[6] Helping Others\n");
		printf("[7] Family\n");
		printf("[8] Rest\n");
		printf("[9] Sleep\n");
		printf("[10] Eating\n");
		printf("What activity did you do? ");
		scanf("%d", &dCategory);
	}
	else if (!dTimeStart && dDay == 1)
	{
		dCategory = 9; // Assume user is sleeping on the first day
	}
	
	return dCategory;
}

int getContinue()
{
	int dContinue;
	
	printf("Do you want to continue using this Wellness Tracker? (0 - No / 1 - Yes) ");
	scanf("%d", &dContinue);		
	
	return dContinue;
}

void addDuration(int dCategory, int dDuration, int* dPreviousHealth, int* dPreviousLeisure, int* dPreviousWork, int* dPreviousChores, int* dPreviousSelf, int* dPreviousHelping, int* dPreviousFamily, int* dPreviousRest, int* dPreviousSleep, int* dPreviousEating, int* dTotalHealth, int* dTotalLeisure, int* dTotalWork, int* dTotalChores, int* dTotalSelf, int* dTotalHelping, int* dTotalFamily, int* dTotalRest, int* dTotalSleep, int* dTotalEating)
{
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
	if (*dA < *dB)
	{
		int dTemp = *dA;
		*dA = *dB;
		*dB = dTemp;
	}
}

void printStatistics(int* isPrintedH, int* isPrintedL, int* isPrintedW, int* isPrintedC, int* isPrintedS, int* isPrintedHelp, int* isPrintedF, int* isPrintedR, int* isPrintedSleep, int* isPrintedE, int dDay, int a, int* dPreviousHealth, int* dPreviousLeisure, int* dPreviousWork, int* dPreviousChores, int* dPreviousSelf, int* dPreviousHelping, int* dPreviousFamily, int* dPreviousRest, int* dPreviousSleep, int* dPreviousEating)
{	
	if (*dPreviousHealth == a && *isPrintedH != 1)
	{
		printf("          Health | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay)); 
		*isPrintedH = 1;
	}
	else if (*dPreviousLeisure == a && *isPrintedL != 1)
	{
		printf("         Leisure | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedL = 1;
	}	
	else if (*dPreviousWork == a && *isPrintedW != 1 )
	{
		printf("            Work | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedW = 1;
	}
	else if (*dPreviousChores == a && *isPrintedC != 1)
	{
		printf("          Chores | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedC = 1;
	}	
	else if (*dPreviousSelf == a && *isPrintedS != 1)
	{
		printf("Self-Improvement | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedS = 1;
	}
	else if (*dPreviousHelping == a && *isPrintedHelp != 1)
	{
		printf("  Helping Others | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedHelp = 1;
	}	
	else if (*dPreviousFamily == a && *isPrintedF != 1)
	{
		printf("          Family | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedF = 1;
	}	
	else if (*dPreviousRest == a && *isPrintedR != 1)
	{
		printf("            Rest | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedR = 1;
	}	
	else if (*dPreviousSleep == a && *isPrintedSleep != 1)
	{
		printf("           Sleep | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedSleep = 1;
	}	
	else if (*dPreviousEating == a && *isPrintedE != 1)
	{
		printf("          Eating | %02dh %02dm | %6.2f%%\n", a / 60, a % 60, a / (14.4 * dDay));
		*isPrintedH = 0;
		*isPrintedL = 0;
		*isPrintedW = 0;
		*isPrintedC = 0;
		*isPrintedS = 0;
		*isPrintedHelp = 0;
		*isPrintedF = 0;
		*isPrintedR = 0;
		*isPrintedSleep = 0;
		*isPrintedE = 0;
	}		
}

void displayPreviousDayStatistics(int dDay, int* dPreviousHealth, int* dPreviousLeisure, int* dPreviousWork, int* dPreviousChores, int* dPreviousSelf, int* dPreviousHelping, int* dPreviousFamily, int* dPreviousRest, int* dPreviousSleep, int* dPreviousEating)
{
	int x;
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
	
	int isPrintedH = 0, isPrintedL = 0, isPrintedW = 0, isPrintedC = 0, isPrintedS = 0, isPrintedHelp = 0, isPrintedF = 0, isPrintedR = 0, isPrintedSleep = 0, isPrintedE = 0;
	dDay = 1;
	
	for (x = 1; x < 10; x++)
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
	
	printf("\n");
	printf("PREVIOUS DAY'S STATISTICS\n");
	printf("CATEGORY         | DURATION| PERCENTAGE\n");
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dFirst, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dSecond, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dThird, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dFourth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dFifth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dSixth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dSeventh, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dEight, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dNinth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printStatistics(&isPrintedH, &isPrintedL, &isPrintedW, &isPrintedC, &isPrintedS, &isPrintedHelp, &isPrintedF, &isPrintedR, &isPrintedSleep, &isPrintedE, dDay, dTenth, dPreviousHealth, dPreviousLeisure, dPreviousWork, dPreviousChores, dPreviousSelf, dPreviousHelping, dPreviousFamily, dPreviousRest, dPreviousSleep, dPreviousEating);
	printf("\n");
		
	*dPreviousHealth = 0;
	*dPreviousLeisure = 0;
	*dPreviousWork = 0;
	*dPreviousChores = 0;
	*dPreviousSelf = 0;
	*dPreviousHelping = 0;
	*dPreviousFamily = 0;
	*dPreviousRest = 0;
	*dPreviousSleep = 0;
	*dPreviousEating = 0;
}

void displayTotalStatistics(int dDay, int* dTotalHealth, int* dTotalLeisure, int* dTotalWork, int* dTotalChores, int* dTotalSelf, int* dTotalHelping, int* dTotalFamily, int* dTotalRest, int* dTotalSleep, int* dTotalEating)
{
	int x;
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
	
	int isPrintedH = 0, isPrintedL = 0, isPrintedW = 0, isPrintedC = 0, isPrintedS = 0, isPrintedHelp = 0, isPrintedF = 0, isPrintedR = 0, isPrintedSleep = 0, isPrintedE = 0;
	
	for (x = 1; x < 10; x++)
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
	
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("TOTAL STATISTICS\n");
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
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

main()
{
	int dTimeEnd, dTimeStart = 0000;
	int dCategory;
	int dDuration;
	int dCorrect;
	int dDay = 1;
	int dContinue = 1;
	int isFirstActivity = 1;
	
	int dPreviousHealth = 0, dPreviousLeisure = 0, dPreviousWork = 0, dPreviousChores = 0, dPreviousSelf = 0, dPreviousHelping = 0, dPreviousFamily = 0, dPreviousRest = 0, dPreviousSleep = 0, dPreviousEating = 0;
	int dTotalHealth = 0, dTotalLeisure = 0, dTotalWork = 0, dTotalChores = 0, dTotalSelf = 0, dTotalHelping = 0, dTotalFamily = 0, dTotalRest = 0, dTotalSleep = 0, dTotalEating = 0;
	
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("WELLNESS TRACKER\n");
	printf("An Individual-only Machine Project for CCPROG1\n");
	printf("Programmed by Lorenzo Nery\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	
	while (dContinue)
	{	
		// GET TIME END
		dTimeEnd = getTimeEnd(dTimeStart, dDay);

		// GET CATEGORY
		do
		{
			dCategory = getCategory(dTimeStart, dDay);
			
			if(dCategory < 1 || dCategory > 10)
				printf("ERROR! Please input again.\n");
		} while (dCategory < 1 || dCategory > 10);	
		
		// DURATION
		if (dTimeEnd > dTimeStart)
		{
			dDuration = dTimeEnd - dTimeStart;
			
			if (dDuration > 180 && dCategory != 9)
			{
				do
				{
					printf("This activity lasts for more than 3 hours. Are you sure? (0 - No / 1 - Yes) ");
					scanf("%d", &dCorrect);
					
					if(dCorrect == 0 || dCorrect == 1)
					{
						if(dCorrect == 1)
						{
							
							dTimeStart = dTimeEnd;
							addDuration(dCategory, dDuration, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
							dCorrect = 0;
						}
						else
						{
							printf("Please input the time end and the category of the activity again.\n"); // INPUT TIME END AND CATEGORY AGAIN
						}
					}
					else
					{
						printf("ERROR! Please input again.\n"); // INPUT CORRECT AGAIN
					}	
				} while (dCorrect);
			}
			else
			{
				dTimeStart = dTimeEnd;
				addDuration(dCategory, dDuration, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
			}
		}
		else
		{
			dDuration = 1440 - dTimeStart;
			
			if(dDuration > 180 && dCategory != 9)
			{
				do
				{
					printf("This activity lasts for more than 3 hours. Are you sure? (0 - No / 1 - Yes) ");
					scanf("%d", &dCorrect);
					
					if(dCorrect == 0 || dCorrect == 1)
					{
						if(dCorrect == 1)
						{
							
							dTimeStart = dTimeEnd;
							addDuration(dCategory, dDuration, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
							
							displayPreviousDayStatistics(dDay, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating);
							
							dDuration = dTimeEnd; // ADD REMAINING TIME OF LAST ACTIVITY
							
							if(dDay > 1)
							{
								displayTotalStatistics(dDay, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
							}
								
							dDay++;
							
							addDuration(dCategory, dDuration, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
							
							do
							{
								dContinue = getContinue();
			
								if(dContinue != 0 && dContinue != 1)
									printf("ERROR! Please input again.\n");
							} while (dContinue != 0 && dContinue != 1);
							dCorrect = 0;
						}
						else
						{
							printf("Please input the time end and the category of the activity again.\n"); // INPUT TIME END AND CATEGORY AGAIN
						}
					}
					else
					{
						printf("ERROR! Please input again.\n"); // INPUT CORRECT AGAIN
					}
				} while (dCorrect);
			}
			else
			{
				dTimeStart = dTimeEnd;
				addDuration(dCategory, dDuration, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
				
				displayPreviousDayStatistics(dDay, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating);
				
				dDuration = dTimeEnd; // ADD REMAINING TIME OF LAST ACTIVITY
				
				if(dDay > 1)
				{
					displayTotalStatistics(dDay, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
				}
					
				dDay++;
				
				addDuration(dCategory, dDuration, &dPreviousHealth, &dPreviousLeisure, &dPreviousWork, &dPreviousChores, &dPreviousSelf, &dPreviousHelping, &dPreviousFamily, &dPreviousRest, &dPreviousSleep, &dPreviousEating, &dTotalHealth, &dTotalLeisure, &dTotalWork, &dTotalChores, &dTotalSelf, &dTotalHelping, &dTotalFamily, &dTotalRest, &dTotalSleep, &dTotalEating);
				
				do
				{
					dContinue = getContinue();
			
					if(dContinue != 0 && dContinue != 1)
						printf("ERROR! Please input again.\n");
				} while (dContinue != 0 && dContinue != 1);
			}
		}
	}
	
	printf("THANK YOU FOR TESTING THIS WELLNESS TRACKER!");		
}
