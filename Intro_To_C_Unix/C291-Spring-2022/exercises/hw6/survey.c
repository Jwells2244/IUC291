#include <stdio.h>
#include <string.h>
int main(void) {
	char topics[][50] = {"rising global temperatures", "world hunger", "social justice", "war in Ukraine", "inflation", "legalization of cannabis", "student loan crisis"};
	int responses[7][10];//Holds the 2 digit array of everyones responses
	printf("Pls enter responses in the form 1(couldn't care less) - 10(All I think about)\n");
	int averages[] = {0,0,0,0,0,0,0};//Holds the totals, kind of misleading name
	//Conducting Survey Loops
	for (int x = 1; x<11;x++){
		printf("Respondee #%i:\n", x);	
		fflush(stdout);
		for (int i = 0; i < 7; ++i){
			printf("How important is the issue of %s to you?\n", *(topics + i));
			(x!=1) ?scanf(" %i", &responses[i][x-1]):(scanf("%i",&responses[i][x-1]));
			averages[i] = averages[i]+responses[i][x-1];
			fflush(stdout);
		}
	}
	int f; //Used to be able to hold the value of that for loop, however I don't need it anymore as it was changed after I did it
	printf("Here are the results of the survey:\n\n");
	//Printing the chart of the responses for each topic
	for (int c = 0; c<7;c++){
		if (c==0){
			printf("%s    ",*(topics + c));
		}
		else if (c==1){
			printf("%s                  ",*(topics + c));
		}
		else if (c==2){
			printf("%s                ",*(topics + c));
		}
		else if (c==3){
			printf("%s                ",*(topics + c));
		}
		else if (c==4){
			printf("%s                     ",*(topics + c));
		}
		else if (c==5){
			printf("%s      ",*(topics + c));
		}
		else{
			printf("%s           ",*(topics + c));
		}
		f = 0;
		for (f; f<10; f++){
			printf("%i   ", responses[c][f]);
		}
		printf("Avg -- %i   ", averages[c]/10);
		printf("\n");
	}
	int highestI, lowestI;
	highestI=0;
	lowestI=0;//Used to find highest and lowest, I made these before making the sort, and I could get rid and do these after.
	for (int j = 0; j<7; j++){
		if (averages[j]>averages[highestI]){
			highestI = j;
		}
		else if (averages[j]<averages[lowestI]){
			lowestI = j;
		}	
	}
	//testing
	//printf("%i  %i  %i  %i  %i  %i  %i\n",averages[0], averages[1], averages[2], averages[3], averages[4], averages[5], averages[6]);
	printf("The issue that the respondents cared the most about is %s, with a point total of %i\n", *(topics+highestI), averages[highestI]);
	printf("The issue that the respondents cared the least about is %s, with a point total of %i\n", *(topics+lowestI), averages[lowestI]);
	int sortedAverages[7] = {averages[0],averages[1],averages[2],averages[3],averages[4],averages[5],averages[6]};
	int i, j, temp;
	char tempS[10] = {"\0"};
	for (i = 0; i < 7; ++i){ //Sorts sortedAverages by least to greatest, and also sorts topics in the same way so that you can call the 0 index and it will be the lowest value, and the corresponging topic
		for (j = i + 1; j < 7; ++j){
			if (sortedAverages[i] > sortedAverages[j]){
				strcpy(tempS, *(topics+i));
				temp = sortedAverages[i];
				strcpy(*(topics+i),*(topics+j));
				sortedAverages[i] = sortedAverages[j];
				strcpy(*(topics+j),tempS);
				sortedAverages[j] = temp;
			}
		}
	}
	//Testing
	//printf("%i  %i  %i  %i  %i  %i  %i\n",sortedAverages[0], sortedAverages[1], sortedAverages[2], sortedAverages[3], sortedAverages[4], sortedAverages[5], sortedAverages[6]);
	printf("Here is the order of topics people cared about from least to greatest: \n");
	for (int i = 0; i< 7; i++){//Prints order of topics and values from least to greatest
		printf("%s -- %i\n", *(topics+i), sortedAverages[i]);	
	}
	printf("\n");
	printf("10 People were surveyed in this survey\n");
	return 0;
}


