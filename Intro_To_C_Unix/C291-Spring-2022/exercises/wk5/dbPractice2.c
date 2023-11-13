// Program to count the input characters. 
// It reads the input from the keyboard until user hits ENTER
// and then prints it on screen.  
// Number of errors/bugs = 13

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>
//No int
int main()
{
	//Needed to be an int
	//Needs to initialize c
	int count;
	char c;
	printf("Enter word:\n");
	c = getchar();
	//int i
	//Needed to be != '\n'
	for (int i=0; c != '\n'; i++)
	{
		count++;
		putchar(c);
		c = getchar();
		fflush(stdout);
 	} 
	// /n and ,
 	printf("\nnum of chars including spaces: %i\n", count);
 	//Return 0 not 1
	return (0); 
}
