//ATTENTION
//This does not work, and it would take me a lot of time to delete and restart, and so pls refer to newPoker.c for the working solution to the poker game!


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void shuffle(char **array, size_t n){
    	srand(time(0));
	if (n > 1) 
	{
		size_t i;
		for (i = 0; i < n - 1; i++) 
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			char *t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}
char * highestCard( char **hand){
	char highest[3];
	strncpy(highest,hand[0],3);
	char *nextVal;
	char substring[] = highest[0][1];
	strcat(substring, highest[0][2]);
	printf("%c\n", hand[1][1]);
	printf("%s\n", highest);
	printf("%s\n", substring);
/*	for (int i = 0;i<5;i++){
		nextVal = hand[i];
		if (strcmp(highest[1:],nextVal[1:]>0)){
			continue;
		}
	}*/
}

int main(){
	const char *sDeck[] = {"S12","S13","S14","S15","S16","S17","S18","S19","S20","S21","S22","S23","S24","C12","C13","C14","C15","C16","C17","C18","C19","C20","C21","C22","C23","C24",
		"H12","H13","H14","H15","H16","H17","H18","H19","H20","H21","H22","H23","H24","D12","D13","D14","D15","D16","D17","D18","D19","D20","D21","D22","D23","D24"};
	char *aDeck[] = {"S12","S13","S14","S15","S16","S17","S18","S19","S20","S21","S22","S23","S24","C12","C13","C14","C15","C16","C17","C18","C19","C20","C21","C22","C23","C24",
                "H12","H13","H14","H15","H16","H17","H18","H19","H20","H21","H22","H23","H24","D12","D13","D14","D15","D16","D17","D18","D19","D20","D21","D22","D23","D24"};
	shuffle(aDeck, 52);
	char *userhand[5] = {};
	char *secondHand[5] = {};
	char *thirdHand[5] = {};
	char *fourthHand[5] = {};
	char *fifthHand[5] = {};
	int counter = 0;
	int stepper=0;
	for (int i = 0; counter<5;i++){
		if (i == 0){
			userhand[counter] = aDeck[stepper];
		}
		else if (i==1){
			secondHand[counter] = aDeck[stepper];
		}
		else if (i==2){
			thirdHand[counter] = aDeck[stepper];
		}
		else if (i==3){
			fourthHand[counter] = aDeck[stepper];
		}
		else if (i==4){
			fifthHand[counter] = aDeck[stepper];
		}
		else{
			counter ++;
			i = -1;
		}
		stepper++;
	}
	//Uncomment to show that all hands get initialized correctly.
	//printf("%s  %s   %s   %s   %s\n", userhand[0],userhand[1],userhand[2],userhand[3],userhand[4]);
	//printf("%s  %s   %s   %s   %s\n", secondHand[0],secondHand[1],secondHand[2],secondHand[3],secondHand[4]);
	//printf("%s  %s   %s   %s   %s\n", thirdHand[0],thirdHand[1],thirdHand[2],thirdHand[3],thirdHand[4]);
	//printf("%s  %s   %s   %s   %s\n", fourthHand[0],fourthHand[1],fourthHand[2],fourthHand[3],fourthHand[4]);
	//printf("%s  %s   %s   %s   %s\n", fifthHand[0],fifthHand[1],fifthHand[2],fifthHand[3],fifthHand[4]);
	highestCard(userhand);
	return (0);
}
