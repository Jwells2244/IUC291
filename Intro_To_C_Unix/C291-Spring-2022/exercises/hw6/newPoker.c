
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//I thought the source code provided to us was kind of confusing, So I just did mine from scratch with the Deck being an array of ints 0-51
//If you take the number, say 27, and /13, it will give you 2, which is the suit. If you modulus it, it will give you 1, which is a 3(kind of confusing but every value is +2 of the modulus result
//
//Shuffles the Deck
void shuffle(int deck[]){
	srand(time(0));
	for (int i = 0; i < 150; i++) {
	    	int from = rand() % 52;
	    	int to = rand() % 52;
	    	int card = deck[from];
	    	deck[from] = deck[to];
	    	deck[to] = card;
	}
}
//Used as an easy helper method for highestCard
int highest(int hand[]){
	int highest = hand[0]%13;
	for (int i = 0; i<5;i++){
		if (highest<hand[i]%13){
			highest = hand[i]%13;
		}
	}
	return highest;
}
//In combination with highest(), gets the highest value of every hand and compares them.
void highestCard(int uhand[], int shand[], int thand[], int fhand[], int fthhand[]){
	int uhighest, shighest, thighest, fhighest, fthhighest;
	uhighest = highest(uhand);
	shighest = highest(shand);
	thighest = highest(thand);
	fhighest = highest(fhand);
	fthhighest = highest(fthhand);
	if (uhighest>shighest && uhighest>thighest && uhighest>fhighest && uhighest>fthhighest){
		printf("You have the highest card\n");
	}
	else{
		printf("You do not have the highest card\n");
	}
}
//Organizes a hand to be easier to check for pairs and everything
void organized(int hand[]){
	for (int x = 0; x<5; x++){
		hand[x] = hand[x]%13;
	}
	int temp, i, j, k;
   	for (j = 0; j < 5; ++j){
      		for (k = j + 1; k < 5; ++k){
         		if (hand[j] > hand[k]){
            			temp = hand[j];
           			hand[j] = hand[k];
            			hand[k] = temp;
         		}
      		}
   	}
}
//Checking for pairs, three of a kind, full house, four of a kind, and multiple pairs. Kind of misleading name. Sorry, I know its a little complicated. 
//This function takes the organized version of the hand, so it eliminates some of the extra ifs I would've had to throw in
void pairs(int hand[]){
	int ohand[] = {hand[0],hand[1],hand[2],hand[3],hand[4]};
        organized(ohand);
	//printf("%i   %i   %i   %i   %i\n", ohand[0], ohand[1], ohand[2], ohand[3], ohand[4]);
	//Four of a kind
	if ((ohand[0] == ohand[1] && ohand[1]==ohand[2] && ohand[2]==ohand[3]) || (ohand[1] == ohand[2] && ohand[2]==ohand[3] && ohand[3]==ohand[4])){
		printf("You have a 4 of a kind!\n");
	}
	else{
		//3 of a kind/Full House
		if ((ohand[0] == ohand[1] && ohand[1]==ohand[2]) || (ohand[1] == ohand[2] && ohand[2]==ohand[3]) || (ohand[2] == ohand[3] && ohand[3]==ohand[4])){
			if (ohand[0] == ohand[1] && ohand[1]==ohand[2]){
				if (ohand[3] == ohand[4]){
					printf("You have a full house!\n");
				}
				else{
					printf("You have a 3 of a kind!\n");
				}
			}
			else if (ohand[1] == ohand[2] && ohand[2]==ohand[3]){
				if (ohand[4] == ohand[0]){
                                        printf("You have a full house!\n");
                                }
                                else{
                                        printf("You have a 3 of a kind!\n");
                                }
			}
			else if (ohand[2]==ohand[3] && ohand[3]==ohand[4]){
				if (ohand[0] == ohand[1]){
                                        printf("You have a full house!\n");
                                }
                                else{
                                        printf("You have a 3 of a kind!\n");
                                }
			}
		}
		//Pairs
		else{
			if (ohand[0]==ohand[1]){
				if (ohand[2]==ohand[3] || ohand[3]==ohand[4]){
					printf("You have two pairs!\n");
				}
				else{
					printf("You have a pair\n");
				}
			}
			else if (ohand[1]==ohand[2]){
				if (ohand[3]==ohand[4]){
                                        printf("You have two pairs!\n");
                                }
                                else{
                                        printf("You have a pair\n");
                                }
			}
			else if (ohand[2] == ohand[3]){
				printf("You have a pair\n");
			}
			else if (ohand[3] ==ohand[4]){
				printf("You have a pair\n");
			}
			else{
				printf("You don't have a 4 of a kind, 3 of a kind, full house, or even a pair.\n");
			}
		}
	}
}
//Checks for straight using an organized hand
void straight(int uhand[]){
	int ohand[] = {uhand[0],uhand[1],uhand[2],uhand[3],uhand[4]};
	organized(ohand);
	if ((ohand[0] == ohand[1]+1) && (ohand[1] == ohand[2]+1) && (ohand[2] == ohand[3]+1) && (ohand[3] == ohand[4]+1)){
		printf("You have a straight\n");
	}
	else{
		printf("You do not have a straight\n");
	}
}
//Sort of confusing here, but this sorts the array while keeping the original value, since its needed for Royal Flush 
void sorted(int hand[]){
	int temp, i, j, k;
        for (j = 0; j < 5; ++j){
                for (k = j + 1; k < 5; ++k){
                        if (hand[j] > hand[k]){
                                temp = hand[j];
                                hand[j] = hand[k];
                                hand[k] = temp;
                        }
                }
        }
}
//Checks for a roayl Flush. Probably could've done this in Pairs, but that function is big enough as it is
void royalFlush(int hand[]){
	int shand[] = {hand[0],hand[1],hand[2],hand[3],hand[4]};
	sorted(shand);
	if (shand[0]/13==shand[1]/13 && shand[1]/13==shand[2]/13 && shand[2]/13==shand[3]/13 && shand[3]/13==shand[4]/13){
		if (shand[0]%13==8 && shand[1]%13==9 && shand[2]%13==10 && shand[3]%13==11 && shand[4]%13==12){
			printf("You have a Royal Flush!!!!\n");
		}
		else{
			printf("You do not have a Royal Flush\n");
		}
	}
	else{
		printf("You do not have a Royal Flush\n");
	}	
}
//Displays a hand in user understandable methods, without using the original numbers
void printHand(int hand[]){
	char *suitsStr[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
        char *facesStr[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
            "10", "Jack", "Queen", "King", "Ace"};
	printf("Here is the hand you've been dealt: \n");
	for (int i = 0; i<5;i++){
		printf("A %s of %s\n",facesStr[hand[i]%13],suitsStr[hand[i]/13]);
	}
}


int main(void){
	int deck[52];
	for (int i = 0; i < 52; i++) {
     	deck[i] = i;
	}
	shuffle(deck);
	//Dealing
	int counter = 0;//Used to deal
        int stepper=0;//Used to deal
	//The 5 hands for the players
	int userhand[5];
	int secondhand[5];
	int thirdhand[5];
	int fourthhand[5];
	int fifthhand[5];
        for (int i = 0; counter<5;i++){
                if (i == 0){
                        userhand[counter] = deck[stepper];
                }
                else if (i==1){
                        secondhand[counter] = deck[stepper];
                }
                else if (i==2){
                        thirdhand[counter] = deck[stepper];
                }
                else if (i==3){
                        fourthhand[counter] = deck[stepper];
                }
                else if (i==4){
                        fifthhand[counter] = deck[stepper];
                }
                else{
                        counter ++;
                        i = -1;
                }
                stepper++;
       	}
	//Testing
	//printf("%i    %i  %i    %i   %i\n", userhand[0], userhand[1], userhand[2], userhand[3], userhand[4]);
	//printf("%i    %i  %i    %i   %i\n", secondhand[0], secondhand[1], secondhand[2], secondhand[3], secondhand[4]);
	//printf("%i    %i  %i    %i   %i\n", thirdhand[0], thirdhand[1], thirdhand[2], thirdhand[3], thirdhand[4]);
	//printf("%i    %i  %i    %i   %i\n", fourthhand[0], fourthhand[1], fourthhand[2], fourthhand[3], fourthhand[4]);
	//printf("%i    %i  %i    %i   %i\n", fifthhand[0], fifthhand[1], fifthhand[2], fifthhand[3], fifthhand[4]);
	printHand(userhand);
	highestCard(userhand, secondhand, thirdhand, fourthhand, fifthhand);
	pairs(userhand);
	straight(userhand);
	royalFlush(userhand);
	return (0);
}
