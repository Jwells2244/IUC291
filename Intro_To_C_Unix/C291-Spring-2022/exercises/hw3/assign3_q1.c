/* 
 * Assignment 3, Q1 
 * Author: Jonathan Wells, Tuesday Feb 1, 2022
 * Revision History:
 * 
*/


#include <stdio.h>
#include <string.h>


int main(void){
	//a
	unsigned int first = 1001; //Stores the value of an unsigned int 1001 for the first question in question 1
	printf("%-12.6u\n", first);
	//B
	char letters[26];
	memset(letters, 0, 26);
	char input;
	printf("Input char: ");
	scanf(" %c", &input);
	while (input != 'z'){
		strncat(letters, &input, 1);
		printf("String: %s\n", letters);
		printf("Input character: \n");
		scanf(" %c", &input);
	}
	//c
	printf("%08.3f\n", 7.350);
	//d
	int octalValue;
	printf("Enter octal value: ");
	scanf("%o", &octalValue);
	printf("My octal value: %o\n", octalValue);
	//e
	int num;
	num = 300;
	printf("With & sign: %ls\n", &num);
	printf("Without & sign: %i\n", num);
	//f
	unsigned int threeHundred = -300;
	printf("Unsigned -300: %u\n", threeHundred);
	//g
	printf("100 in octal: %o\n", 100);
	//h
	unsigned char hex;
	printf("Enter hex: ");
	scanf("%hhx", &hex);
	printf("Value of hex: %x\n", hex);
	//i
	printf("0x%x\n", 100);
	//j
	int hour, minute, second;
	printf("Input time in the form hh-mm-ss: ");
	scanf("%i:%i:%i:", &hour, &minute, &second);
	printf("Hours: %i Minutes: %i Seconds: %i\n", hour, minute, second);
	//k
	hour = 0;
	minute = 0;
	second = 0;
	printf("Input time in the form hh-mm-ss: ");
	scanf("%i:%i:%i:", &hour, &minute, &second);
	printf("Hours: %i Minute: %i Seconds: %i\n", hour, minute, second);
	//L
	char let[26];
	printf("Input string in the form 'character': ");
	scanf(" %*c%10s%*c", let);
	printf("The input was %s\n", let);
	return (0);
}
