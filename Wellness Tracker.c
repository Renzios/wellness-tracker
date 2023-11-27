// Wellness Tracker

#include <stdio.h>

int getTimeEnd(int nDay, int nTimeStart);
int getCategory(int nDay, int nTimeStart);
int getDuration(int nTimeStart, int nTimeEnd);
int isCorrect(int nCategory, int nDuration);
void addDuration(int nCategory, int nDuration, int *nHealth, int *nLeisure, int *nWork, int *nChores, int *nSelf, int *nHelping, int *nFamily, int *nRest, int *nSleep, int *nEating,
					int *nTotalHealth, int *nTotalLeisure, int *nTotalWork, int *nTotalChores, int *nTotalSelf, int *nTotalHelping, int *nTotalFamily, int *nTotalRest, int *nTotalSleep, int *nTotalEating);
int isContinue();

int main()
{	
	int nIsContinue;

	int nTimeStart = 0;
	
	int nHealth = 0;
	int nLeisure = 0;
	int nWork = 0;
	int nChores = 0;
	int nSelf = 0;
	int nHelping = 0;
	int nFamily = 0;
	int nRest = 0;
	int nSleep = 0;
	int nEating = 0;
	
	int nTotalHealth = 0;
	int nTotalLeisure = 0;
	int nTotalWork = 0;
	int nTotalChores = 0;
	int nTotalSelf = 0;
	int nTotalHelping = 0;
	int nTotalFamily = 0;
	int nTotalRest = 0;
	int nTotalSleep = 0;
	int nTotalEating = 0;
	
	int nDay = 1;
	
	do
	{	
		// Get Time End
		int nTimeEnd = getTimeEnd(nDay, nTimeStart);
			
		// Get Category
		int nCategory = getCategory(nDay, nTimeStart);
		
		// Get Duration
		int nDuration = getDuration(nTimeStart, nTimeEnd);
		
		// Is Correct
		if (isCorrect(nCategory, nDuration))
		{
			nTimeStart = nTimeEnd;
			addDuration(nCategory, nDuration, &nHealth, &nLeisure, &nWork, &nChores, &nSelf, &nHelping, &nFamily, &nRest, &nSleep, &nEating,
						&nTotalHealth, &nTotalLeisure, &nTotalWork, &nTotalChores, &nTotalSelf, &nTotalHelping, &nTotalFamily, &nTotalRest, &nTotalSleep, &nTotalEating);
						
			if (nTimeEnd > nTimeStart)
			{	
				nIsContinue = 1;		
			}
			else
			{
				// Display statistics
				
				// Add remaining time
				nDuration = nTimeEnd;
				addDuration(nCategory, nDuration, &nHealth, &nLeisure, &nWork, &nChores, &nSelf, &nHelping, &nFamily, &nRest, &nSleep, &nEating,
							&nTotalHealth, &nTotalLeisure, &nTotalWork, &nTotalChores, &nTotalSelf, &nTotalHelping, &nTotalFamily, &nTotalRest, &nTotalSleep, &nTotalEating);
				
				nIsContinue = isContinue();
				nDay++;
			}
			
			
		}
		else
		{
			printf("Input ignored\n\n");
			
			nIsContinue = 1;
		}
		
	} while (nIsContinue);
	
	printf("Program End\n");
	
	return 0;
}

int getTimeEnd(int nDay, int nTimeStart)
{
	int nTimeEnd;
	
	do
	{
		if (nDay == 1 && !nTimeStart)
		{
			printf("What time did you wake up? [0000 - 2359]\n\n");
		}
		else
		{
			printf("What time did the next activity end? [0000 - 2359]\n\n");
		}
		
		printf("Enter time: ");
		scanf("%d", &nTimeEnd);
		printf("\n");
		
		if (nTimeEnd < 0 || nTimeEnd > 2359 || nTimeEnd % 100 > 59)
		{
			printf("Invalid time\n\n");
		}
	} while (nTimeEnd < 0 || nTimeEnd > 2359 || nTimeEnd % 100 > 59);
	
	return nTimeEnd / 100 * 60 + nTimeEnd % 100;
}

int getCategory(int nDay, int nTimeStart)
{
	int nCategory;
	
	do
	{
		if (nDay == 1 && !nTimeStart)
		{
			nCategory = 9;
		}
		else
		{
			printf("Category of Activities\n\n");
			
			printf("\t[1] Health\n\n");
			
			printf("\t[2] Leisure\n\n");
			
			printf("\t[3] Work\n\n");
			
			printf("\t[4] Chores\n\n");
			
			printf("\t[5] Self-Improvement\n\n");
			
			printf("\t[6] Helping Others\n\n");
			
			printf("\t[7] Family\n\n");
			
			printf("\t[8] Rest\n\n");
			
			printf("\t[9] Sleep\n\n");
			
			printf("\t[10] Eating\n\n");
			
			printf("Enter category: ");
			scanf("%d", &nCategory);
			printf("\n");
		}
		
		if (nCategory < 1 || nCategory > 10)
		{
			printf("Invalid category\n\n");
		}
	} while (nCategory < 1 || nCategory > 10);
	
	return nCategory;
}

int getDuration(int nTimeStart, int nTimeEnd)
{
	int nDuration;
	
	if (nTimeEnd > nTimeStart)
	{
		nDuration = nTimeEnd - nTimeStart;
	}
	else
	{
		nDuration = 1440 - nTimeStart;
	}
	
	return nDuration;
}

int isCorrect(int nCategory, int nDuration)
{
	int nIsCorrect;
	
	if (nCategory != 9 && nDuration > 300)
	{
		char cOption;
		
		do
		{
			printf("This activity lasts for more than 3 hours. Is this correct?\n\n");
			
			printf("[Y] Yes\n\n");
			
			printf("[N] No\n\n");
			
			printf("Enter option: ");
			scanf(" %c", &cOption);
			printf("\n");
			
			switch (cOption)
			{
				case 'Y':
				
				case 'y':
					nIsCorrect = 1;
					break;
					
				case 'N':
					
				case 'n':
					nIsCorrect = 0;
					break;
					
				default:
					printf("Invalid Option\n\n");
					break;	
			}
		} while (cOption != 'Y' && cOption != 'y' && cOption != 'N' && cOption != 'n');
	}
	else
	{
		nIsCorrect = 1;
	}
	
	return nIsCorrect;
}

void addDuration(int nCategory, int nDuration, int *nHealth, int *nLeisure, int *nWork, int *nChores, int *nSelf, int *nHelping, int *nFamily, int *nRest, int *nSleep, int *nEating,
					int *nTotalHealth, int *nTotalLeisure, int *nTotalWork, int *nTotalChores, int *nTotalSelf, int *nTotalHelping, int *nTotalFamily, int *nTotalRest, int *nTotalSleep, int *nTotalEating)
{
	switch (nCategory)
	{
		case 1:
			*nHealth += nDuration;
			*nTotalHealth += nDuration;
			break;
			
		case 2:
			*nLeisure += nDuration;
			*nTotalLeisure += nDuration;
			break;
			
		case 3:
			*nWork += nDuration;
			*nTotalWork += nDuration;
			break;
			
		case 4:
			*nChores += nDuration;
			*nTotalChores += nDuration;
			break;
			
		case 5:
			*nSelf += nDuration;
			*nTotalSelf += nDuration;
			break;
			
		case 6:
			*nHelping += nDuration;
			*nTotalHelping += nDuration;
			break;
			
		case 7:
			*nFamily += nDuration;
			*nTotalFamily += nDuration;
			break;
			
		case 8:
			*nRest += nDuration;
			*nTotalRest += nDuration;
			break;
			
		case 9:
			*nSleep += nDuration;
			*nTotalSleep += nDuration;
			break;
			
		case 10:
			*nEating += nDuration;
			*nTotalEating += nDuration;
			break;
	}
}

void displayStatistics(int nDay, int *nHealth, int *nLeisure, int *nWork, int *nChores, int *nSelf, int *nHelping, int *nFamily, int *nRest, int *nSleep, int *nEating)
{
	
}

int isContinue()
{
	int nIsContinue;
	
	char cOption;
	
	do
	{
		printf("Would you like to continue using the program for this new day?\n\n");
		
		printf("[Y] Yes\n\n");
		
		printf("[N] No\n\n");
		
		printf("Enter option: ");
		scanf(" %c", &cOption);
		printf("\n");
		
		switch (cOption)
		{
			case 'Y':
			
			case 'y':
				nIsContinue = 1;
				break;
				
			case 'N':
				
			case 'n':
				nIsContinue = 0;
				break;
				
			default:
				printf("Invalid Option\n\n");
				break;	
		}
	} while (cOption != 'Y' && cOption != 'y' && cOption != 'N' && cOption != 'n');
	
	return nIsContinue;
}
