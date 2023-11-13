#include<stdio.h>
#include<string.h>
/**'
Authors : Brage Qviller, Jonathan Wells
A program that allows the user to enter Staff codes and pay amounts and then tells you the monthly or average pay that the person is getting
Spring C291, January 30th
Revision :All of the commented out code is either deprecated or doesn't work, it's just to show a revision history
1: First made the Staffcode functions
2: Then got the calculations function to work
3: Proper documentation added
**/

/* Does Not Work lol
char *input(void){
   printf("Enter the Staff Code :\n");
   char *userInput;
   scanf("%c", &userInput);
   char *tokenInput = userInput;
   char *token;
   token = strtok(tokenInput, " ");
    while ((token != "A") || (token != "S") || (token != "R") || (token != "J") || (token != "T") || (token != "H")){
         if (token == "?") {
                printf("options\n");
           }
        printf("Enter the Staff Code :\n");
        userInput = scanf("%c", &userInput);
        tokenInput = userInput;
        token = strtok(tokenInput, " ");

           }
    printf(userInput);
    return userInput;

}
*/
void printStaffCodeOptions(){
        printf("-----\nOPTIONS MENU\n-----\nAdministrator -- A\nStaff -- S\nRegular Faculty -- R\nAdjunct -- J\nTA -- T\nHourly -- H\n");
	}
char getCode(void){
	printf("Enter the staff code(? for options, Q to be done: \n");
	char userInput; //Collects user input
	scanf("%c", &userInput);
	while ((userInput != 'A') &&(userInput != 'Q') && (userInput != 'S') && (userInput != 'R') && (userInput != 'J') && (userInput != 'T') && (userInput != 'H')){
		if (userInput == '?'){
			printStaffCodeOptions();
		}
		else{
			printf("Error. Unrecognized input.\n");
		}
		printf("Enter the Staff Code(? for options, Q to be done: \n");
		scanf(" %c", &userInput);
	}
	return userInput;
	}
float getSecondInput(char code ){
	float input; //Takes user input
/*	if ((code == 'A') || (code == 'S') || (code == 'R')){
		printf("Enter the salary amount: \n");
	}
	else if (code == 'J'){
		printf("Enter the amount of credit hours the Adjunct is teaching this semester: \n");
	}
	else if (code == 'T'){
		printf("Enter the amount of courses the TA is teaching: \n");
	}
	else {
		printf("Enter the amount that the hourly worker gets paid per hour: \n");
	}*/ //Needed to add a switch statement
	switch(code){
		case 'A':
		case 'S':
		case 'R':
			printf("Enter the salary amount: \n");
			break;
		case 'J':
			printf("Enter the amount of credit hours the Adjunct is teaching this semester: \n");
			break;
		case 'T' :
			printf("Enter the amount of courses the TA is teaching: \n");
			break;
		case 'H' :
			printf("Enter the amount that the hourly worker gets paid per hour: \n");
	}
	scanf("%f", &input);
	return input;
}
float getThirdInput(char code){
	float input;//Takes user Input
/*	if (code == 'R'){
		printf("Enter the amount of credits of overload the regular faculty member has: \n");
	}
	else if (code == 'T'){
		printf("Enter the amount of hours this TA worked this month: \n");
	}
	else if (code == 'S'){
		printf("Enter the amount of overtime hours this staff member worked this month: \n");
	}
	else {
		printf("Enter the amount of hours the Hourly employee worked this month: ");
	}*///Needed a Switch
	switch(code){
		case 'R':
			printf("Enter the amount of credits of overload the regular faculty member has: \n");
			break;
		case 'T':
			printf("Enter the amount of hours this TA worked this month: \n");
			break;
		case 'S':
			printf("Enter the amount of overtime hours this staff member worked this month: \n");
			break;
		case 'H':
			printf("Enter the amount of hour the Hourly employee worked this month: \n");
			break;
	}
	scanf("%f", &input);
	return input;
}


void calculations(char code, float secondInput, float thirdInput){
	float monthlyPay, weeklyPay, hourlyPay, monthlyPayOvertime; //Different variables to be used in different switch cases, that determine different amounts of pay
	switch(code){
		case 'A':
			monthlyPay = secondInput/12;
			weeklyPay = monthlyPay/4;
			printf("This Administrator makes %f a year, %f a month, and %f a week.\n",secondInput, monthlyPay, weeklyPay);
			break;
		case 'S':
			if (thirdInput >= 10){
				printf("Error, staff worked more than the eligible amount of overtime. Setting overtime hours down to 10.\n");
				thirdInput = 10.0;
			}
			hourlyPay = ((secondInput/12.0)/4.0)/40.0;
			weeklyPay = hourlyPay * 40.0;
			monthlyPay = secondInput/12.0;
		        monthlyPayOvertime=monthlyPay + (thirdInput*(hourlyPay*1.5));
			printf("This Staff member has a %f salary, makes %f a month, and %f a week. This staff member also worked %f hours of overtime this month, bringing their monthly pay total for this month up to %f \n",secondInput, monthlyPay, weeklyPay,thirdInput,monthlyPayOvertime);
			break;
		case 'R':
			monthlyPay = (secondInput/10 + (((thirdInput/3)*8500)/5));
			printf("This Regular faculty member has a %f salary, makes %f a month with the overtime of teaching %f credit hours of overload.\n",secondInput, monthlyPay,thirdInput);
			break;
		case 'J':
			if (secondInput > 9){
				printf("Error, Adjunct faculty can only teach up to 9 credit hours a semester. Setting credit hours to be equal to 9.\n");
				secondInput = 9;
			}
			monthlyPay = ((secondInput/3)*8500)/5;
			printf("This Adjunct faculty member is teaching %f credit hours this semester, and so makes %f for this semester.\n",secondInput,monthlyPay);
			break;
		case 'T':
			if (thirdInput>48){
				printf("Error, TAs are only allowed to work 2 hours a week of overtime per month, setting overtime down to 8 hours");
				thirdInput = 48.0;
			}
			monthlyPay = (secondInput*2500)/5;
			hourlyPay = (monthlyPay/4)/40;
			if (thirdInput > 40){
				monthlyPayOvertime =monthlyPay + ((thirdInput-40)*hourlyPay);
				printf("This TA teaches %f classes this semester, and worked a total of %f hours this month, with %f hours of that being overtime. They earned %f this month.\n",secondInput, thirdInput, thirdInput-40, monthlyPayOvertime);
				break;
			}
			else{
				printf("This TA teaches %f classes this semester and worked a total of %f hours this month, and earned %f for this month.\n", secondInput, thirdInput, monthlyPay);
				break;
			}
		case 'H':
			if (thirdInput > 160){
				printf("Error, Hourly employees can not work more than 40 hours per week in a month. Setting total hours down to 160\n");
				thirdInput = 160.0;
			}
			if (thirdInput > 80){
				monthlyPay = secondInput*80 + ((thirdInput-80)*(1.25*secondInput));
				printf("This Hourly employee worked %f hours this month on %f dollars per hour, making %f with overtime added this month.\n",
						thirdInput, secondInput, monthlyPay);
				break;
			}
			else{
				monthlyPay = secondInput*thirdInput;
				printf("This Hourly employee worked %f hours this month on %f dollars per hour, making them %f dollars this month.\n",thirdInput, secondInput, monthlyPay);
				break;
			}
		}
}
  /* if (code == "A" number1){
   float monthly_Admin = number1 / 12;
   float weekly_Admin = monthly_Admin / 4;
   float pay_Admin = number1;
   }
   else if (token == "S" number1 number2){
	if (number2 >= 10){
	float number2 = 10;
	}
   float hourly_pay = (((number1 / 12) / 4) / 40);
   float pay_staff = number1 + (hourly_pay * 1.5 * number2);
   float monthly_staff = number1 / 12;
   float weekly_staff = monthly_staff / 4;
   
   }
   else if (token == "R" number1 number2) {
   float pay_regular = number1 + (8500 * (floor(number2 / 3));
   float monthly_regular = number1 / 10;
   float weekly_regular = monthly_regular / 4;
   }
   else if (token == "J" number1){
   float pay_adjunct = 8500 * (floor(number1 / 3));
   float monthly_adjunct = pay_adjunct / 5;
   float weekly_adjunct = monthly_adjunct / 4;
   }
   else if (token == "T" number1 number2){
        if (number2 >= 48){
	float number2 = 48;
	}
   float ta = (2500 * number1) + ((12.5 * (number2 - 40)) * 5);
   float monthly_ta = (2500 * number1) / 5;
   float weekly_ta = monthly_ta / 4;
   }
   else if (token == "H" number1 number2){
   float normal_hours = number2
        if (number2 >= 160){
	float number2 = 160;
	}
        if (number2 >= 80){
	float normal_hours = 20;
	}
   float pay_hourly = (number1 * normal_hours) + (number1 * 1.25 * (number2 - 20);
   float monthly_hourly = number1 * number2;
   float weekly_hourly = monthly_hourly / 4;
   }
}*/





int main(void){
	/*char staffCode;
	staffCode = getCode();
	printf("%c\n", staffCode); 
	float secondInput;
	secondInput = getSecondInput(staffCode);
	printf("%f\n", secondInput);
	float thirdInput;
	if ((staffCode != 'A') && (staffCode != 'J')){
		thirdInput = getThirdInput(staffCode);
		printf("%f\n", thirdInput);
	}*/
	char staffCode; // Holds the Staff Code
	float secondInput; //Holds the second input that the user enters, usually salary
	float thirdInput; //Optional Variable, what it holds depends on the staff code
	while (staffCode != 'Q'){
		staffCode = getCode();
		if (staffCode == 'Q'){//Ends the program
			break;
		}
		secondInput = getSecondInput(staffCode); //Uses the staffCode that was just obtained to get the User's Second Input
		if ((staffCode != 'A') && (staffCode != 'J')){
			thirdInput = getThirdInput(staffCode);
		}
		calculations(staffCode, secondInput, thirdInput); //The call to the actual calculations function
	}
	printf("Data entry finished\n");
	return(0);

}
