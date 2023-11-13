/* Instructions:
 *
 *
 1. Write a program to assign a grade to Student. 
	- Get the number of assignmnets from user.
    - Get the students score out of how many points for each assignmnet. i.e. 48/50
	- Calculate percentage and return the grade associated with a range of marks.
 2. The overall score range and the associated grades are as follows:
     a. [97-100] = A+
     b. [90-97] = A
     c. [80-90] = B
     d. [70-80] = C
     e. less than 70 is a failing grade and should be given an F
     e. greater than 100 or less than 0 is invalid and your code should print "Invalid"
 3. Use the skeleton code provided below to create a new function "printGrade" to assign a grade based on the score ranges.
 4. Use print statements in your function to display the grade. For example, if the input marks is 77, the output should read:
        "Your grade is : C"
 5. Please adhere to standard C syntax conventions and use comments to explain your code. Failure to do so will result in a penalty.
 *
 *Author: Jonathan Wells
 * Revision, Thursday February 10th, 2022
 * Finished program, it checks for the users grade, then the grade the users was out of, then outputs the grade, and does that for every assignment
 * the user entered
 *
 */

#include <stdio.h>

void printGrade(float score){
	//print the students grade based on their score in the class
	if ((score>100) || (score<0)){
		printf("Invalid\n");
		return;
	}
	else{
		if (score>97){
			printf("Your grade is : A+\n");
			return;
		}
		else{
			if (score>90){
				printf("Your grade is : A\n");
				return;
			}
			else{
			       if (score>80){
					printf("Your grade is : B\n");
					return;
			       }
			       else{
				       if (score>70){
					       printf("Your grade is : C\n");
					       return;
					}
				       else{
					       printf("Your grade is : F\n");
					       return;
					}
			}
		}
	}
	}
}
int main(void){
	float score; //Holds first input
	float maxScore; //Holds second input for each score
	float grade; //Holds final grade that is sent to the printGrade function
	int assignments; //Holds the amount of assignments the user enters
	int counter = 0; //Keeps the do while loop running until it equals the amount of assignment
	printf("How many assignments did you have: \n");
	scanf(" %i", &assignments);
	do {

    //get the number of assignmnets from the student
		printf("Enter your score for this assignment as a decimal : \n" );

    //get the student's score and the max score for each assignment
		scanf(" %f", &score);
		printf("Enter the max score possible for this assignment as a decimal: \n");
		scanf(" %f", &maxScore);
		grade = score/maxScore;
    //calculate the student's percentage in the class using the information you've gathered.

		printGrade(grade*100);
		counter++;
	} while(counter < assignments);
	return (0);
}
