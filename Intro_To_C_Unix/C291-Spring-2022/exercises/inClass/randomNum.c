//Trevor Cutshall 
//Jonathan Wells
//2/22/2022
//Random number generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void variants1(){
   srand(time(0));
    int randomNum = (rand() % 100 - 1) + 1;
    int Guess;
    //printf("%i", randomNum);
    printf("Guess a number: ");
    scanf("%i", &Guess);
    while (Guess != randomNum){
        if (Guess > randomNum) {
            printf("Guess is too high!\n");
        }
        else{
            printf("Guess is too low!\n");
        }
        printf("Guess a number: ");
        scanf("%i", &Guess);
    }
    printf("You got it!\n"); 
}

void variants2(){
    int Number, cGuess;
    printf("Enter a number: ");
    scanf("%i", &Number);
    int min = 0, max = 100;
    srand(time(0));
    cGuess = (rand() % max - min + 1) + min;
    
    while (cGuess != Number){
        if (cGuess > Number){
            max = cGuess;
            printf("You are too high!\n");
        }
        else{
            min = cGuess;
            printf("You are too low!\n");
        }
        cGuess = (rand() % max - min + 1) + min;
        
    }
    printf("You got it!\n");
}
void variants3(){
    srand(time(0));
    int randomNum = (rand() % 100 - 1) + 1;
    int Guess;
    //printf("%i", randomNum);
    printf("Guess a number: ");
    scanf("%i", &Guess);
    int lie = (rand() % 2) + 1;
    int lieUsed = 0;
    //printf("%i", lie);
    while (Guess != randomNum){
        if ((Guess > randomNum && lie == 1) && lieUsed == 0) {
            printf("Guess is too low!\n");
            lieUsed = 1;
        }
        else if ((Guess > randomNum && lie == 2) && lieUsed == 1){
            printf("Guess is too high!\n");
        }
        else if ((Guess > randomNum && lie == 1) && lieUsed == 1){
            printf("Guess is too high!\n");
        }
        else if ((Guess > randomNum && lie == 2) && lieUsed == 0){
            printf("Guess is too high!\n");
        }
        else if (Guess < randomNum && lie == 1 && lieUsed == 0){
            printf("Guess is too high!\n");
            lieUsed = 1;
        }
        else if ((Guess < randomNum && lie == 2) && lieUsed == 1){
            printf("Guess is too low!\n");
        }
        else if ((Guess < randomNum && lie == 2) && lieUsed == 0){
            printf("Guess is too low!\n");
        }
        else if ((Guess < randomNum && lie == 1) && lieUsed == 1){
            printf("Guess is too low!\n");
        }
        printf("Guess a number: ");
        scanf("%i", &Guess);
        int lie = (rand() % 2) + 1;
    }
    printf("You got it!\n");
    
}



int main()
{   
    printf("Variant 1\n");
    variants1();
    printf("Variant 2\n");
    variants2();
    printf("Variant 3\n");
    variants3();
    //3 variants of guessing game
    //1 Computer generates secret number 
    /*
    
    */
    //2 User generates secret number and computer guesses
    /*
    
    
    */
    //3 number 1 One of the guesses will be a lie
    
    //printf("Hello World");

    return 0;
}
