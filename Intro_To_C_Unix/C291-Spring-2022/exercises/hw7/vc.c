/*  C version of the -wc command in Linux. I spelled it wrong when making this file originally, so thats why its called vc.c
 *  On the instructions, I wasn't sure what you meant by dynamic input buffer, so I just set the filename input to a max of 100?
 *  This uses two of the pretty much identical while loop, because I needed to figure out how many words are in the file to size the wordArray and counts dynamically
 * Date: Sunday April 10th, 2022
 * Jonathan Wells
 */
#include <ctype.h> //Used to make chars lowercase
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	FILE* ptr; //File pointer
	char ch; //The char that changes as it reads through the file, becoming each individual char
	int charCount = 0; //Keeps track of the characters within a file
	int wordCount = 0; //Keeps track of the words in the file, used to dynamically size arrays
	int i = 0; //Used to iterate through the files when forming each indivual word
	int j = 1;
	char *str; //Holds the completed string for each word
	char filename[100]; //Holds the users filename input -- See header for more details
	memset(filename, 0, 100);
	puts("Enter filename: ");
	fgets(filename, 100, stdin);
	strtok(filename, "\n"); //Gets rid of the \n because it wont compare correctly otherwise
	ptr = fopen(filename, "r");	
	if (ptr == NULL){
		printf("File cannot be opened\n");
	}
	else{
		int longestString = 0;//For sizing each pointer in the wordArray
		while (ch != EOF){
                        i = 0; 
                        j = 1;
                        str = (char*)malloc(sizeof(char));
                        while (ch != ' ' && ch != '.' && ch != '?' && ch != '!' && ch != EOF && ch != '\n'){
                                ch = fgetc(ptr);
                                if (ch != ' ' && ch != '.' && ch != '?' && ch != '!' && ch != EOF && ch != '\n'){
                                        str = (char*)realloc(str, j * sizeof(char));
                                        str[i] = ch;
                                        j++;
                                        i++;
                                }       
                        }
                        str[i] = '\0';
                        if (strlen(str) != 0){
				if (strlen(str) > longestString){
					longestString = strlen(str);
				}
                                wordCount ++;
                        }
                        free(str);
                        if (ch == ' ' || ch == '.' || ch == '?' || ch == '!' || ch == '\n'){
                                ch = 'n';
                        }
		}
		fseek(ptr, 0L, SEEK_SET);//Set the 'cursor' in the file back to the beginning
		char **wordArray = malloc(wordCount * sizeof(char *));//Holds the unique words 
		int counter;//Just for a for loop
		for (counter = 0; counter < wordCount; counter++){
			wordArray[counter] = (char *)malloc(longestString+1);
		}
		int *counts = malloc(sizeof(int) * wordCount);
		for (int x = 0; x<wordCount; x++){
			counts[x] = 0;
		}
		int indexCounter = 0;//Counts the index to add to the counts value at that index, and adds the word at that index so they match up
		if (wordCount>0){
			ch = 'h';
		}
		int d = 0;//Used for a for loop
		while (ch != EOF){
			i = 0; 
			j = 1;
			str = (char*)malloc(sizeof(char));
			while (ch != ' ' && ch != '.' && ch != '?' && ch != '!' && ch != EOF && ch != '\n'){
				ch = fgetc(ptr);
				if (ch != ' ' && ch != '.' && ch != '?' && ch != '!' && ch != EOF && ch != '\n'){
					str = (char*)realloc(str, j * sizeof(char));
                                	str[i] = tolower(ch);
                                	j++;
                                	i++;
				}	
				charCount++;
			}
			str[i] = '\0';//Ends the string because there is a non letter character at the current index
			if (strlen(str) != 0){
				//printf("String: %s \n", str);
				int flag = 0;
				for (d = 0; d<wordCount;d++){
					//printf("Current value of str: %s      Current value of wordArray[d]:%s\n",str, wordArray[d]);
					if (strcmp(str, wordArray[d])==0){
						counts[d] = counts[d]+1;
						flag = 1;
						break;
					}
				}
				if (flag == 0){//Flag is just used to check if its in the wordArray after the for loop
					strcpy(wordArray[indexCounter],str);
					counts[indexCounter] = counts[indexCounter] +1;
					indexCounter++;
					
				}
				fflush(stdout);
			}
			free(str);
			if (ch == ' ' || ch == '.' || ch == '?' || ch == '!' || ch == '\n'){
				ch = 'n';
			}
		}
		printf("Word usage report:\n");
		for (int h = 0; h<wordCount; h++){
			if (counts[h] != 0){
				printf("%s  --  %i\n", wordArray[h], counts[h]);
        		}
		}
		free(counts);//Freeing the dynamically allocated memories
		for (int u = 0; u<wordCount; u++){
                	free(wordArray[u]);
        	}
	}
	printf("Characters in file: %i\n", charCount);
	printf("Words in file: %i\n", wordCount);
	fclose(ptr);//Close the file
	ptr = NULL; //Setting the file ptr to Null, freeing the memory
	return (0);
}
