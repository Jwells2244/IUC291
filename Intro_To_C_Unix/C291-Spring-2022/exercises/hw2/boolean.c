/* Print a table of values for some boolean functions. 
 * Author: Jonathan Wells, Brage Qviller
 * Spring 2022 C291, January 30th
 * Revision 1:Added the four neccessary functions, and then made sure they could all be printed in the correct format
*/
#include <stdio.h>
int function1(int b1, int b2, int b3, int b4){
	//b1 || b2 || b3 || b4 Function
	return b1 +b2 + b3 + b4 >= 1;
}
int function2(int b1, int b2, int b3, int b4){
	//!( !b1 ||b2 ) && (!b3 || b4 )
	//I distributed the ! sign across the first parenthesis
	return (b1 + !b2) * (!b3 + b4) >=1;
}
int function3(int b1, int b2, int b3, int b4){
	// (b1 && b2) || (b1 || (b3 && b4))
	return (b1 * b2) + (b1 + (b3 * b4))>= 1;
}
int function4(int b1, int b2, int b3, int b4){
	// (b3 && b1) || (b2 && b4)
	return (b3 * b1) + (b2 * b4) >= 1;
}
int main(void)
{
   int   b1, b2, b3, b4;             /* boolean variables */
   int   cnt = 0;
   printf("\n%5s%5s%5s%5s%5s%7s%7s%7s%7s%11s\n\n",   /* headings */
      "Cnt", "b1", "b2", "b3", "b4",
      "fct1", "fct2", "fct3", "fct4", "majority");
   for (b1 = 0; b1 <= 1; ++b1)
      for (b2 = 0; b2 <= 1; ++b2)
         for (b3 = 0; b3 <= 1; ++b3)
            for (b4 = 0; b4 <= 1; ++b4)
                printf("%5d%5d%5d%5d%5d%6d%6d%7d%9d%9d\n",
                	++cnt, b1, b2, b3, b4,
                	function1(b1,b2,b3,b4),function2(b1,b2,b3,b4),function3(b1,b2,b3,b4),
                     	function4(b1,b2,b3,b4),b1+b2+b3+b4>=2);
   putchar('\n');
   return 0;
}
