/*A Program that goes through 10,000 trials to calculate how many people it takes to be in a room
 * where the rpobability of them having the same birthday is over 1/2
 * Author: Jonathan Wells
 * Date: Feb 14th, 2022
 * Had to debug this program to find out why my number was only 187 initially, but realized that my break only broke me out of one loop, not the other
 * so I got that fixed and now its good to go
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main(void){
	time_t t; //Used to randomize the random seed
	srand((unsigned) time(&t)); //Randomizes the random seed
	float trueTrials = 0.0; //The counter for the amount of trials that had the same birthdays in them
	float initialTrueTrials; //The counter to check to see if the amount of true trials has gone up during an iteration, and if it has
	//It breaks from the for loop
	for (int i = 0;i<10000;i++){
		int numArray[i];
		for (int n = 0; n<i;n++){
			numArray[n] = rand()%365+1;	
		}
		for (int checker = 0; checker<i; checker++){
			initialTrueTrials = trueTrials;
			for  (int looper = 0; looper<i; looper++){
				if (looper != checker){
					if (numArray[checker] == numArray[looper]){
						trueTrials += 1.0;
						break;
					}
				}
			}
			if (initialTrueTrials != trueTrials){
				break;
			}
		}
		if ((trueTrials/10000.0) >= .5){
			//The instructions for this seem a little ambiguous, but I assumed you didn't want like
			//3000 print statements, so I just printed the first occurence
			printf("The least n to break even is - %i\n", i);
			break;
		}
	}
	
	return (0);
}
