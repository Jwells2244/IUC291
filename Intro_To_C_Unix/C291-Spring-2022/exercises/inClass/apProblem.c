
//Jonathan Wells
//2/24/2022
//AP Principles problem

#include <stdio.h>
#include <string.h>


int getInt(){
	int input;
	printf("Enter the number: \n");
	scanf("%i", &input);
	return input;
}
int getModulusNum(int in){
	int input;
	printf("Enter the number you're taking away from %i: \n", in);
	scanf("%i", &input);
	return input;
}


int main(void){
	int length;
	printf("Welcome to the modulus sequence calculator: !\n");
	printf("This program takes as many numbers you want, then takes the number that you want to take away from that number in modulus, and then sorts them increasingly\n");
	printf("First, enter how many integers you want to enter: \n");
	scanf("%i", &length);
	int numArray[length];
	int modulusArray[length];
	for (int i = 0; i < length; i++){
		int input = getInt();
		numArray[i] = input;
		modulusArray[i] = getModulusNum(input);
	}
	for (int x = 0; x < length; x++){
		numArray[x] = numArray[x] % modulusArray[x];
	}
	int a, i, j;
        for (i = 0; i < length; ++i){
                for (j = i + 1; j < length; ++j){
                        if (numArray[i] > numArray[j]){
                                a = numArray[i];
                                numArray[i] = numArray[j];
                                numArray[j] = a;
                        }
                }
        }
	printf("Your sorted array is: \n");
	for (int j = 0; j < length; j++){
		printf("%i\n", numArray[j]);
	}
}
