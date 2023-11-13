// The factorial of an integer is the product of the number with all
// the positive integers below it.

// For example: Factorial of 5 = 5 * 4 * 3 * 2 * 1 = 120

// Number of errors/bugs = 7

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>
//The factorial function needed to be above the main
//Needed to take an int number
int factorial(int number) {
  	//Needed brackets around the if
	//Needed to be  <= 2, and number, insted of number-1
	if(number <=2){
    		return number;}
	else{
	//Needed to be factorial-1, because it was an infinite program otherwise
  		return number * factorial(number-1);
	}
}



int main(void) {
	int n,fact;
	printf("Debugging Practice 1 - Quiz 3, Q3\n\n");
	printf("Please enter the number whose factorial you wish to find: ");
	//Needs to be &i not &f
	scanf(" %i", &n);//Needed an & sign in front of n
	fact = factorial(n);
	//%i, not %c
	printf("The factorial of %d is %i\n", n, fact);
}


 

