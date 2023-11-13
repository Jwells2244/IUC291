/*
 * This program is an airline account, and you are able to add passengers, enter a seat number to check if it is occupied, print a boarding pass, and print a list of the plane
 * Author:Jonathan Wells
 * Completion: Mar 23
 * I am so so sorry for whoever has to try to follow the seatAssignment function. After I finished it I realized how much harder I made it for my self. So sorry about my very sloppy code.
 * For any input asking for a 'y' or whatever,if you dont want to just type any other one single char. It lengthened the print statements too much to add that to ever print statement
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//Prints the menu
void mainMenu(){
	puts("----------------\nWelcome to America Airline(Copyright Free).");
	puts("Here are your options: \nEnter '1' to choose a passenger and then choose a seat for the passenger.");
	puts("Enter '2' to print a boarding pass for the chosen seat number.\nEnter '3' to display a current seat map of the plane.");
	puts("Enter '4' to print a passenger manifesto and their seat numbers.");
	puts("Lastly, enter '5' to be done and quit the program.\n----------------");
}
//Prints the list of the Plane
void printPlane(char planeList[][22]){
	int flag = 0; // Flag is a really inefficient way to check if the row was the row where I take a gap to print the numbers
	puts("The X's show Open seats, and the C stands for Covid seats. The Letter columns are not counted as seats. IF the seat has an O, it is occupied");
	for (int row = 0; row < 7; row ++){
		for (int col = 0; col < 22; col++){
			if (row == 4 && flag == 0){
				printf("   ");
				for (int numRow = 1; numRow < 21; numRow++){
					if (numRow < 10){
						printf(" %i  ", numRow);
					}
					else{
						printf("%i  ", numRow);
					}
				}
				flag = 1;
				printf("\n");
			}
			printf("%c   ", planeList[row][col]);
		}
		printf("\n");
	}
}
//Prints the list of passengers on the plane, with their seat numbers
void passengersOnPlane(char planeList[][22], char *passengerOnPlane[][22]){
	for (int row = 0; row < 7; row++){
		for (int col = 1; col <21; col++){
			if (planeList[row][col] != 'X' || planeList[row][col] != 'C'){
				switch(row){
					case 0:
						printf("%s -- A%i\n", passengerOnPlane[row][col], col);
						break;
					case 1:
                                                printf("%s -- B%i\n", passengerOnPlane[row][col], col);
                                                break;
					case 2:
                                                printf("%s -- D%i\n", passengerOnPlane[row][col], col);
                                                break;
					case 3:
                                                printf("%s -- E%i\n", passengerOnPlane[row][col], col);
                                                break;
					case 4:
                                                printf("%s -- F%i\n", passengerOnPlane[row][col], col);
                                                break;
					case 5:
                                                printf("%s -- H%i\n", passengerOnPlane[row][col], col);
                                                break;
					case 6:
                                                printf("%s -- I%i\n", passengerOnPlane[row][col], col);
                                                break;
				}
			}
		}
	}
}
//Unfortunetely I was unable to print the passenger manifesto. This compiles, but it gives me a segmentation fault(core dumped) when I try to run it. :(
/*
void printAPassengerManifesto(char *passengerPlaneList[][22]){
	int passengers = 0;
	for (int i = 0; i<9; i++){
		for (int x = 1; x<21;x++){
			if (strcmp(passengerPlaneList[i][x], "N") != 0){
				passengers++;
			}
		}
	}
	char passengerarray[passengers][30];
	int counter = 0;
	for (int i = 0; i<9;i++){
		for (int x = 1; x<21;x++){
			if (strcmp(passengerPlaneList[i][x], "N") != 0){
				sprintf(passengerarray[counter],"%s", passengerPlaneList[i][x]);
				counter++;
			}
		}
	}
	char temp[30];
        for(int i=0; i<passengers; i++){
                for(int j=0; j<passengers-1-i; j++){
                        if(strcmp(passengerarray[j], passengerarray[j+1]) > 0){
                                strcpy(temp, passengerarray[j]);
                                strcpy(passengerarray[j], passengerarray[j+1]);
                                strcpy(passengerarray[j+1], temp);
                        }
                }
        }
	for (int x = 0; x<passengers;x++){
		for (int c = 0; c<9;c++){
			for (int y=1; y<21;y++){
				switch(x){
					case (0):
						printf("%s -- A%i\n", passengerarray[x],y);
						break;
					case (1):
                                                printf("%s -- B%i\n", passengerarray[x],y);
                                                break;
					case (2):
                                                printf("%s -- D%i\n", passengerarray[x],y);
                                                break;
					case (3):
                                                printf("%s -- E%i\n", passengerarray[x],y);
                                                break;
					case (4):
                                                printf("%s -- F%i\n", passengerarray[x],y);
                                                break;
					case (5):
                                                printf("%s -- H%i\n", passengerarray[x],y);
                                                break;
					case (6):
                                                printf("%s -- I%i\n", passengerarray[x],y);
                                                break;
				}
			}
		}
	}
}*/
//Prints the non alphabetical list of passengers to choose from
void printPassengerList(char passengerList[][25]){
	printf("List of available passengers: \n");
	for (int i = 0; i<25; i++){
		if (i % 2 == 0){
			printf("\n");
		}
		printf("%s  ", passengerList[i]); 
	}
	printf("\n");
}
//Prints the alphabetical list of passengers
void printAPassengerList(char passengerList[][25]){
	char temp[30];
  	for(int i=0; i<25; i++){
    		for(int j=0; j<25-1-i; j++){
      			if(strcmp(passengerList[j], passengerList[j+1]) > 0){
        			strcpy(temp, passengerList[j]);
        			strcpy(passengerList[j], passengerList[j+1]);
        			strcpy(passengerList[j+1], temp);
      			}
    		}
	}
	printPassengerList(passengerList);
}
//Checks if the passenger given is a valid choice
int validPassenger(char passengerList[][25], char passenger[25]){
	int flag = 0; //Flag for if the passenger is detected, to break it
	for (int i = 0; i < 25; i++){
		if (strcmp(passengerList[i], passenger)==0){
			flag = 1;
			break;
		}
	}
	return (flag);
}
//Removes the new line from a string
void remove_new_line(char string[25])
{
    size_t length = strlen(string);
    if((length > 0) && (string[length-1] == '\n'))
    {
        string[length-1] ='\0';
    }
}
//Checks to see if the seat number is occupied
int occupied(int seatNum, char planeList[][22]){
	int openrow = -1; //Holds whether the seat row is open
	for (int row = 0; row < 7; row = row+2){
		if (planeList[row][seatNum] == 'X'){
			openrow = row;
			break;
		}
	}
	return (openrow);
}
//Checks for the upgrade
char upgrade(char class, char planeList[][22]){
	switch(class){
		case ('F'):
			return 'N';
			break;
		case ('B'):
			for (int i=0; i<9; i+=2){
				if (i!=8){
					for (int x=1;x<4;x++){
						if (planeList[i][x] == 'X'){
							return 'Y';
							break;
						}
					}
				}
			}
			return 'N';
			break;
		case ('E'):
			for (int i = 0; i<9; i+=2){
				if (i!=8){
					for (int x=4; x<8; x++){
						if (planeList[i][x] == 'X'){
							return 'Y';
							break;
						}
					}
				}
			}
			return 'N';
			break;
		default:
			return 'N';
			break;
	}
}
//Checks for the downgrade
char downgrade(char class, char planeList[][22]){
	switch(class){
		case('F'):
			for (int i = 0; i<9;i+=2){
				if (i!=8){
					for (int x=4;x<8;x++){
						if (planeList[i][x] == 'X'){
							return 'Y';
							break;
						}
					}
				}
			}
			return 'N';
			break;
		case('B'):
			for (int i = 0; i<9; i+=2){
				if (i!=8){
					for (int x = 8; x<21;x++){
						if (planeList[i][x] == 'X'){
							return 'Y';
							break;
						}
					}
				}
			}
			return 'N';
			break;
		default:
			return 'N';
			break;
	}
}
//Literally the worst coded function ever. I am so so sorry
void seatAssignment(char class, char planeList[][22], char passenger[25], char* passengerPlaneList[][22]){
	int counter = 0; //counts to 3 to see if the passenger is being stubborn
	int anySeat = 1; //Not sure where this is used, but too afraid to get rid of it.
	int selection; //Variable that holds the seat selection
	char happy = 'n'; //Variable that holds if the passenger is happy with the seat
	char response; //Holds the return from the upgrade/downgrade function calls
	srand(time(0));//Seed for the random
	while (happy != 'y' && counter < 3){
		int i = 0;
		if (class == 'F'){
			selection = (rand() % ((3 - 1)+1)+1);
			for (i; i < 9; i+=2){
				if (i != 8){
					if (planeList[i][selection] == 'X'){
						printf("Your selected seat is %c%i. However, there may be a downgrade available. Are you happy with this seat? Type 'y' for yes and 'd' for downgrade.\n", planeList[i][0], selection);
						scanf(" %c", &happy);
						if (happy != 'y' && happy != 'd'){
							counter += 1;
						}
						else if (happy == 'd'){
                                                	int x=0;
                                                        int o=1;
                                                        response = downgrade(class, planeList);
                                                        if (response == 'Y'){
								for (x; x<9; x+=2){
									if (x!=8){
										o=4;
										for (o; o<8; o++){
											if (planeList[x][o] == 'X'){
												break;
											}
										}
										if (planeList[x][o] == 'X'){
											break;
										}
									}
								}
								printf("There is a seat available in Business class for you. This seat is %c%i. Are you happy with this seat? Type 'y' for yes, or 'n' to go back to your original seat.\n", planeList[x][0], o);
								scanf(" %c", &happy);
								if (happy == 'y'){
									passengerPlaneList[x][o] = passenger;
									planeList[x][o] = 'O';
									selection = o;
								}
								else {
									passengerPlaneList[i][selection] = passenger;
									planeList[i][selection] = 'O';
									happy = 'y';
								}
							}
							else{
								puts("Sorry, there was no open downgrades for you.");
								puts("If you would like to keep your original seat type 'y', and anything else to search again");
								scanf(" %c", &happy);
								if (happy == 'y'){
									passengerPlaneList[x][o] = passenger;
									planeList[x][o] = 'O';
									selection = o;
								}
							}
						}
						else{
							passengerPlaneList[i][selection] = passenger;
							planeList[i][selection] = 'O';
						}
						break;
					}
				}
			}
			if (i == 10){
				printf("Sorry, it seems there was no seats available in first class. Would you like to look for business class instead? Type 'y' for yes\n");
				scanf(" %c", &happy);
				if (happy == 'y'){
					happy = 'n';
					selection = (rand() % ((7-4)+1)+4);
					i = 0;
					for (i; i<9; i+=2){
						if (i != 8){
							if (planeList[i][selection] == 'X'){
								printf("Your selected seat is %c%i. Are you happy with this seat? Type 'y' for yes.\n", planeList[i][0], selection);
								scanf(" %c", &happy);
								if (happy != 'y'){
									counter += 1;
								}
								else{
									passengerPlaneList[i][selection] = passenger;
									planeList[i][selection] = 'O';
								}
								break;
							}
						}
					}
					if (i == 10){
						puts("Sorry, it seems there were no seats available in business class. Would you like to look for economy class instead? Type 'y' for yes\n");
						scanf(" %c", &happy);
						if (happy == 'y'){
							happy = 'n';
							selection = (rand() % ((20-8)+1)+8);
							i = 0;
							for (i; i<9; i+=2){
								if (i != 8){
									if (planeList[i][selection] == 'X'){
										printf("Your selected seat is %c%i. Are you happy with this seat? Type 'y' for yes.\n", planeList[i][0], selection);
										scanf(" %c", &happy);
										if (happy != 'y'){
											counter += 1;
										}
										else{
											passengerPlaneList[i][selection] = passenger;
											planeList[i][selection] = 'O';
										}
										break;
									}
								}
							}
							if (i == 10){
								puts("Sorry, the whole plane is somehow full, next flight is in 3 hours");
								break;
							}
						}
						else if (counter == 2){
							puts("Sorry, next flight leaves in 3 hours\n");
							break;
						}
					}
				}
				else if (counter ==2){
					printf("Sorry, next flight leaves in 3 hours\n");
				}
			}
		}
		else if (class == 'B'){
			selection = (rand() % ((7-4)+1)+4);
                        i = 0;
                        for (i; i<9; i+=2){
	     			if (i != 8){
					if (planeList[i][selection] == 'X'){
						printf("Your selected seat is %c%i. However, there may be an upgraded/downgraded seat available. Are you happy with this seat? Type 'y' for yes, 'd' for downgrade and 'u' to check for an upgrade.\n", planeList[i][0], selection);
						scanf(" %c", &happy);
						if (happy != 'y' && happy != 'u' && happy != 'd'){
							counter += 1;
						}
						else if (happy == 'd'){
                                                        int x=0;
                                                        int o=1;
                                                        response = downgrade(class, planeList);
                                                        if (response == 'Y'){
                                                                for (x; x<9; x+=2){
                                                                        if (x!=8){
                                                                                o=4;
                                                                                for (o; o<8; o++){
                                                                                        if (planeList[x][o] == 'X'){
                                                                                                break;
                                                                                        }
                                                                                }
                                                                                if (planeList[x][o] == 'X'){
                                                                                        break;
                                                                                }
                                                                        }
                                                                }
                                                                printf("There is a seat available in Business class for you. This seat is %c%i. Are you happy with this seat? Type 'y' for yes, or 'n' to go back to your original seat.\n", planeList[x][0], o);
                                                                scanf(" %c", &happy);
                                                                if (happy == 'y'){
                                                                        passengerPlaneList[x][o] = passenger;
                                                                        planeList[x][o] = 'O';
                                                                        selection = o;
                                                                }
                                                                else {
                                                                        passengerPlaneList[i][selection] = passenger;
                                                                        planeList[i][selection] = 'O';
                                                                        happy = 'y';
                                                                }
                                                        }
                                                        else{
                                                                puts("Sorry, there was no open downgrades for you.");
                                                                puts("If you would like to keep your original seat type 'y', and anything else to search again");
                                                                scanf(" %c", &happy);
                                                                if (happy == 'y'){
                                                                        passengerPlaneList[x][o] = passenger;
                                                                        planeList[x][o] = 'O';
                                                                        selection = o;
                                                                }
                                                        }
                                                }
						else if (happy == 'y'){
							passengerPlaneList[i][selection] = passenger;
                                                        planeList[i][selection] = 'O';
						}
						else{
							if (happy == 'u'){
								int x=0;
								int o=1;
								response = upgrade(class, planeList);
								if (response == 'Y'){
									for (x; x<9; x+=2){
										if (x!=8){
											for (o; o<4; o++){
												if (planeList[x][o] == 'X'){
													break;
												}
											}
											if (planeList[x][o] == 'X'){
												break;
											}
										}
									}
									printf("There is a seat available in first class for you. This seat is %c%i. Are you happy with this seat? Type 'y' for yes, or 'n' to go back to your original seat.\n", planeList[x][0], o);
									scanf(" %c", &happy);
									if (happy == 'y'){
                                                                                passengerPlaneList[x][o] = passenger;
                                                                                planeList[x][o] = 'O';
										selection = o;
                                                                        }
									else {
										passengerPlaneList[i][selection] = passenger;
										planeList[i][selection] = 'O';
										happy = 'y';
									}
								}
								else{
                                                                	puts("Sorry, there was no open upgrades for you.");
									puts("If you would like to keep your original seat type 'y', and anything else to search again");
									scanf(" %c", &happy);
									if (happy == 'y'){
										passengerPlaneList[x][o] = passenger;
										planeList[x][o] = 'O';
										selection = o;
									}
                                                        	}  						
							}
							else{
								passengerPlaneList[i][selection] = passenger;
								planeList[i][selection] = 'O';
							}	
						}
						break;
					}
				}
			}
			if (i == 10){
				puts("Sorry, it seems there were no seats available in business class. Would you like to look for economy class instead? Type 'y' for yes\n");
				scanf(" %c", &happy);
				if (happy == 'y'){
					happy = 'n';
					selection = (rand() % ((20-8)+1)+8);
					i = 0;
					for (i; i<9; i+=2){
						if (i != 8){
							if (planeList[i][selection] == 'X'){
								printf("Your selected seat is %c%i. Are you happy with this seat? Type 'y' for yes.\n", planeList[i][0], selection);
								scanf(" %c", &happy);
								if (happy != 'y'){
									counter += 1;
								}
								else{
									passengerPlaneList[i][selection] = passenger;
									planeList[i][selection] = 'O';
								}
								break;
							}
						}
					}
					if (i == 10){
						puts("Sorry, the whole plane is somehow full, next flight is in 3 hours\n");
						break;
					}
					else if (counter == 2){
						puts("Sorry, next flight leaves in 3 hours");
						break;
					}
				}
			}
		}
		else{
			selection = (rand() % ((20-8)+1)+8);
                                        i = 0;
                                        for (i; i<9; i+=2){
                                                if (i != 8){
                                                        if (planeList[i][selection] == 'X'){
                                                                printf("Your selected seat is %c%i. However there may be an upgrade availble. Are you happy with this seat? Type 'y' for yes and 'u' if you want to search for an upgrade.\n", planeList[i][0], selection);
                                                                scanf(" %c", &happy);
                                                                if (happy != 'y' && happy != 'u'){
                                                                        counter += 1;
									if (counter == 2){
					                                puts("Sorry next flight leaves in 3 hours");
                        						}
									break;	
                                                                }
								else if (happy == 'u'){
									int x=0;
                                                                	int o=1;
                                                                	response = upgrade(class, planeList);
	                                                                if (response == 'Y'){
        	                                                                for (x; x<9; x+=2){
                	                                                                if (x!=8){
                        	                                                                for (o; o<4; o++){
                                	                                                                if (planeList[x][o] == 'X'){
                                        	                                                                break;
                                                	                                                }
                                                        	                                }
                                                                	                        if (planeList[x][o] == 'X'){
                                                                        	                        break;
                                                                                	        }
	                                                                                }
		                                                            	}
                                                                        	printf("There is a seat available in first class for you. This seat is %c%i. Are you happy with this seat? Type 'y' for yes, or 'n' to go back to your original seat.\n", planeList[x][0], o);
                                                                        	scanf(" %c", &happy);
                                                                        	if (happy == 'y'){
                                                                                	passengerPlaneList[x][o] = passenger;
                                                                                	planeList[x][o] = 'O';
											selection = o;
                                                                        	}
                                                                        	else {
                                                                                	passengerPlaneList[i][selection] = passenger;
                                                                                	planeList[i][selection] = 'O';
                                                                                	happy = 'y';
                                                                        	}
                                                                	}
                                                                	else{
                                                                        	puts("Sorry, there was no open upgrades for you.");
                                                	                        puts("If you would like to keep your original seat type 'y', and anything else to search again");
                                                        	                scanf(" %c", &happy);
                                                                	        if (happy == 'y'){
                                                                        	        passengerPlaneList[x][o] = passenger;
                                                                                	planeList[x][o] = 'O';
											selection = o;
                                                                        	}
                                                                	}
                                                        	}
                                                                else{
                                                                        passengerPlaneList[i][selection] = passenger;
                                                                        planeList[i][selection] = 'O';
                                                                }
                                                                break;
                                                        }
                                                }
                                        }
                                        if (i == 10){
                                                puts("Sorry, the whole plane is somehow full, next flight is in 3 hours\n");
                                                break;
                                        }
		}
	}
	int passengerchecker = 0;
	for (int j = 0; j<7; j++){
		if (passengerPlaneList[j][selection] == passenger){
			passengerchecker = 1;
		}
	}
	if (passengerchecker == 1){
		printf("Pasenger added successfully\n");
	}
	else{
		printf("Passenger was not added\n");
	}
}
//Prints the passenger Manifesto
void printPassengerManifesto(char* passengerPlaneList[][22]){
	printf("Passengers on the plane:\n");
	for (int row = 0; row < 7; row++){
		for (int col = 1; col < 21; col++){
			if ((strcmp(passengerPlaneList[row][col],"N")) != 0){
				switch(row){
					case (0):
						printf("%s -- A%i\n",passengerPlaneList[row][col], col);
						break;
					case (1):
						printf("%s -- B%i\n",passengerPlaneList[row][col], col);
						break;
					case(2):
						printf("%s -- D%i\n",passengerPlaneList[row][col], col);
                                                break;
					case(3):
						printf("%s -- E%i\n",passengerPlaneList[row][col], col);
                                                break;
					case(4):
						printf("%s -- F%i\n",passengerPlaneList[row][col], col);
                                                break;
					case(5):
						printf("%s -- H%i\n",passengerPlaneList[row][col], col);
                                                break;
					case(6):
						printf("%s -- I%i\n",passengerPlaneList[row][col], col);
                                                break;
				}
			}
		}
	}
	puts("Done");	
}
//Prints the boarding pass for the seat number chosen
void printBoardingPass(char seat[4],char* passengerPlaneList[][22]){
	int length = strlen(seat);
	int seatNum;
	int colNum;
	if (seat[0] == 'A'){
		seatNum = 0;
	}
	else if (seat[0] == 'D'){
		seatNum = 2;
	}
	else if (seat[0] == 'F'){
		seatNum = 4;
	}
	else if (seat[0] == 'I'){
		seatNum = 6;
	}
	else{
		seatNum = -1;
	}
	if (length == 2){
		if (seat[1] == '1'){
			colNum = 1;
		}
		else if (seat[1] == '2'){
			colNum = 2;
		}
		else if (seat[1] == '3'){
                        colNum = 3;
                }
		else if (seat[1] == '4'){
                        colNum = 4;
                }
		else if (seat[1] == '5'){
                        colNum = 5;
                }
		else if (seat[1] == '6'){
                        colNum = 6;
                }
		else if (seat[1] == '7'){
                        colNum = 7;
                }
		else if (seat[1] == '8'){
                        colNum = 8;
                }
		else if (seat[1] == '9'){
                        colNum = 9;
                }
		if (seatNum != -1){
			if (strcmp(passengerPlaneList[seatNum][colNum],"N") != 0 ){
				printf("-----BOARDINGPASS-----\nPassenger: %s\nSeat: %c%i\n-----",passengerPlaneList[seatNum][colNum],seat[0],colNum);
			}	
			else{
				printf("Seat Unassigned - No Boarding Pass Available. Try Again!\n");
			}
		}
		else{
			printf("Due to covid rules, that seat is unassigned and unavailable. Try Again!\n");
		}
	}
	else{
		if (seat[1] == '2'){
			colNum = 20;
		}
		else{
			if (seat[2] == '0'){
				colNum = 10;
			}
			else if (seat[2] == '1'){
				colNum = 11;	
			}
			else if (seat[2] == '2'){
                                colNum = 12;
                        }
			else if (seat[2] == '3'){
                                colNum = 13;
                        }
			else if (seat[2] == '4'){
                                colNum = 14;
                        }
			else if (seat[2] == '5'){
                                colNum = 15;
                        }
			else if (seat[2] == '6'){
                                colNum = 16;
                        }
			else if (seat[2] == '7'){
                                colNum = 17;
                        }
			else if (seat[2] == '8'){
                                colNum = 18;
                        }
			else if (seat[2] == '9'){
                                colNum = 19;
                        }
		}
                if (seatNum != -1){
                        if (strcmp(passengerPlaneList[seatNum][colNum],"N") != 0 ){
                                printf("-----BOARDINGPASS-----\nPassenger: %s\nSeat: %c%i\n-----",passengerPlaneList[seatNum][colNum],seat[0],colNum);
                        }       
                        else{
                                printf("Seat Unassigned - No Boarding Pass Available. Try Again!\n");
                        }
                }
                else{
                        printf("Due to covid rules, that seat is unassigned and unavailable. Try Again!\n");
                }
        }
}


int main(void){
	int menuChoice, alphabetically, seatNum; //Varius variables 
	//Reading the names
	FILE *filePointer;
	char passengerList[25][25];
	filePointer = fopen("names.txt", "r");
	for (int i = 0; i < 25; i++){
		char firstName[15];
		char lastName[15];
		fscanf(filePointer, "%s", firstName);
		fscanf(filePointer, "%s", lastName);
		sprintf(passengerList[i], "%s %s", firstName, lastName);
	}
	fclose(filePointer);
	char class, alpha;
	char chosenSeatNum[4];
	char passenger[25];
	char planeList[7][22] = {//List that only holds if the seats are occupied, open, or covid. Yes it's confusing to have occupied by X
		{'A', 'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','A'},
		{'B', 'C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','B'},
		{'D', 'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','D'},
		{'E', 'C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','E'},
		{'F', 'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','F'},
		{'H', 'C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','C','H'},
		{'I', 'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','I'}
	};	
	char *passengerPlaneList[7][22] = {//Holds the actual names in each seat
		{"A","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","A"},
		{"B","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","B"},
		{"D","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","D"},
		{"E","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","E"},
		{"F","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","F"},
		{"H","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","H"},
		{"I","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","N","I"}
	};
	while (menuChoice != 5){
		mainMenu();
		scanf(" %i", &menuChoice);
		if (menuChoice == 5){
			puts("Program exited successfully");
			break;
		}
		else{
			switch(menuChoice){
				case(1):
					puts("Enter 1 to view the passenger list alphabetically, and any other number for standard view: ");
					scanf(" %i", &alphabetically);
					if (alphabetically == 1){
						printAPassengerList(passengerList);
					}
					else{
						printPassengerList(passengerList);
					}
					puts("Please enter the full name, CASE SENSITIVE of the passenger you wish to add to the plane:");
					getchar();
					fgets(passenger, sizeof(passenger), stdin);
					remove_new_line(passenger);
					fflush(stdout);
					while (validPassenger(passengerList, passenger)!= 1){
						puts("Error! Passenger not found. Pls enter the full name, CASE SENSITIVE of the passenger you wish to add to the plane: ");
						fgets(passenger, sizeof(passenger), stdin);
						remove_new_line(passenger);
						fflush(stdout);
						fflush(stdin);
					}
					fflush(stdout);
					puts("This passenger can be added to the plane. What class do you want?");
					puts("Please type 'F' for first class\nPlease type 'B' for business class\nAnything else will be economy class");
					scanf(" %c", &class);
					switch(class){
						case('F'):
							printf("You have selected First Class for %s\n", passenger);
							break;
						case('B'):
							printf("You have selected Business Class for %s\n", passenger);
							break;
						default:
							printf("You have selected Economy Class for %s\n", passenger);
							
							break;
					}
					seatAssignment(class, planeList, passenger, passengerPlaneList);
					break;
				case(2):
					puts("Enter the seat you'd like to print the boarding pass for: ");
					scanf(" %s", chosenSeatNum);
					printBoardingPass(chosenSeatNum, passengerPlaneList);
					break;
				case(3):
					printPlane(planeList);
					fflush(stdout);
					break;
				case(4):
					//printf("Would you like to print the passenger manifesto in alphabetical order? Type 'y' for yes.\n");
					//scanf(" %c", &alpha);
					//if (alpha == 'y'){
						//printAPassengerManifesto(passengerPlaneList);
					//}
					//else{
					//	printPassengerManifesto(passengerPlaneList);
					//}
					printPassengerManifesto(passengerPlaneList);
					fflush(stdout);
					break;
				default:
					puts("Error. Invalid Input");
					fflush(stdout);
					break;
			}
		}
	}
	return (0);
}
