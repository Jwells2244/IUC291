// Program to calculate the power of given equation - > x^n
// example - 2^10 -> 1024
// Number of errors/bugs = 13

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>

//the return value of your func should be x^n result
int my_power(int x, int n) {
	if(n == 0){
	    	//return 1
        	return 1;
	}
	//x
	else if(n == 1){
        	return x;
	}
	//changes including getting rid of the double declaration for m, with some others.
	int m;
	if (n<0){
		m = n/-x;
	}
	else {
		m = n /x;
	}
	//initializes ans
	int ans = x;
	//1
	int cur = 1;
	//No need for it to be a recursive function, so I changed some logic
 	while(cur < n) {
        	cur++;
        	ans = ans * x;
    	}
 	return ans;
}

int main() 
{		
	int x = 2;
	int n = 10;
	//Added declaration
	int return_value_function;
	return_value_function = my_power(x, n);
	//%i s
	printf("The power value of %i ^ %i is :: %d \n", x,n,return_value_function);
	return (0);
}
