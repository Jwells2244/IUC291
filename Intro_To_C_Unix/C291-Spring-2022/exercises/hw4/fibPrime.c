/*A Program that checks whether the nth fibonacci number is prime, by iteratively checking each number below n
 * Author: Jonathan Wells
 * Date: Feb 16th, 2022
 *Had a core dump error for a while, but fixed it by making k=2 instead of 0, since I guess c doesn't like something being modulused by 0, since it never
 *Finds the remainder, but once I changed that it was all good
 */



#include <stdio.h>
#include <stdlib.h>

int is_prime(int n){
	for (int k = 2;k<n;k++){
		if (n%k == 0){
			return 0;
		}
	}
	return 1;
}

int is_fib_prime(int num){
	//Three variables that iteratively step through the fibonacci sequence
	//The result contains the next number in the fibonacci sequence after every loop of the for loop
	 int stepper1=0, stepper2=1,result;
	for (int i = 0;i<num;i++){
		if (i <= 1){
			result = i;
		}
		else{
			result = stepper1+stepper2;
			stepper1=stepper2;
			stepper2=result;
		}
	}
	return is_prime(result);
}




int main(void){
	//After some testing, I believe that every sequence number past 10 is 0, because the numbers get so big that there has to be
	//some number that divides them
	int test = 13;
	printf("%i\n",is_fib_prime(test));
	return (0);
}
