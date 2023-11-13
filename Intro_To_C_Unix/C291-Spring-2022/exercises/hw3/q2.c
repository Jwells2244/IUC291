/*Program for Question 2 on Assignment 3
 * Jonathan Wells
 * Tuesday February 8th, 2022
 * I used comments to say what I thought each print statement would print
 */
#include <stdio.h>
int main(){
	//This will just print 32100
	printf( "%-10d\n", 32100 );
	//This one won't work the %c needs to be a %s
	//printf( "%c\n", "This is a C string" );
	//Now it prints this is a C string
	printf( "%s\n", "This is a C string" );
	//Prints 021 then \n 0X11 then \n then 1.008806e+03
	printf( "%#o\n%#X\n%#e\n", 17, 17, 1008.80609 );
	//The numbers aren't big enough to be long ints
	//printf( "% ld\n%+ld\n", 1000000, 8000000 );
	//Now it prints 100000 \n 8000000
	printf( "% d\n%+d\n", 1000000, 800000 );
	//Prints right justified 266
	printf( "%10.3g\n", 265.93738 );
	//Prints 8125.922
	printf( "%*.*lf\n", 8, 3, 8125.921654 );
	//Prints 9.539E+02
	printf( "%10.3E\n", 953.92738 );
	//This is trying to print an object with type int, but it needs a double
	//printf( "%d\n", 20.987 );
	//Now it prints 20.987000
	printf( "%f\n", 20.987 );
	return (0);	
}
