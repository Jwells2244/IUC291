/*Program for quiz 4 to test quesiton 5
 * Author: Jonathan Wells
 * Quiz 4 question 5
 * February 14th, 2022
 */

#include <stdio.h>
int main(void){
	int threeA = 100;
	int threeB = 0x12A;
	int threeC = 0701;
	printf("3A: %i in decimal, 01100100 in binary, %o in octal, and %x in hexadecimal\n", threeA, threeA, threeA);
	printf("3B: %i in decimal, 100101010 in binary, %o in octal, and %x in hexadecimal\n", threeB, threeB, threeB);
	printf("3C: %i in decimal, 111000001 in binary, %o in octal, and %x in hexadecimal\n", threeC, threeC, threeC);
	int a = 28;
	int b = 127;
	printf("4a: A+B = %i, B-A = %i, A*B = %i\n", a+b, b-a, a*b);
	a = 1004;
	b = 32769;
	printf("4b: A+B = %i, B-A = %i, A*B = %i\n", a+b, b-a, a*b);
	a = 65697;
	b = 725248;
	printf("4C: A+B = %i, B-A = %i, A*B = %i\n", a+b, b-a, a*b);
	
	return (0);
}
