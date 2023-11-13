// Program to check if the given number is a palindrome
// Number of errors/bugs = 15

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>
//Needed to be above the function, and return an int
//char w was never used
int func(int n)
{
                int given_number;
                int remainder;
		//Declaration of temp
		int temp;
		//Initializes given number to n
		given_number = n;
		//Temp is set to 0
		temp = 0;
		//Had to make major changes to the logic. 
                while (n > 0) {
                        remainder = n % 10;
                        n = n/10;
                        temp = (temp*10) + remainder;

                }
//Booleans needed to be ints
                if (given_number == temp)
                {
                        return 1;
                }
                else
                {
                        return 0;
                }
}

//int 
int main() {
	//int
        int return_value_function = 1001;       
	//New variable
	int return_value;
	//Set the bool variable to the boolean return
        //func
	return_value = func(return_value_function);
	//Reverse the check
        if (return_value){
                printf("It is a palindrome \n");
        }
        else{
               printf("It is not a palindrome \n");
        }
	//Return (0);
	return (0);
}


