/*  C version of the -wc command in Linux.
 *  Yes, this does not work completely as intended
 *  IMPORTANT: Professor Roberts told me to submit as is, instead of trying to work out the bug fixes after watching me struggle for an entire class period on one error.
 *  *************************************************
 * Date: Sunday April 28th, 2022
 * Jonathan Wells
 */
#include <ctype.h> //Used to make chars lowercase
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Word{
	char * word;
	int count;
	int locations[18];
};




int main(int args, char * input[]){
	if (args<=1){
		fprintf(stderr, "Invalid number of arguments\n");
	}
	int argsCount = 0;
	for(int i=1;i<args;i++){
		if (strcmp(input[i], "-c")==0 || strcmp(input[i], "-w")==0 || strcmp(input[i], "-p") ==0){
			argsCount++;
		}
		else{
			if (!(strcmp(input[i], "-s")==0 || strcmp(input[1], "-v")==0)){
				fprintf(stderr, "Invalid input encountered\n");
				return 1;
			}
		}
	}
	fprintf(stderr, "Got past the initial input\n");
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
		struct Word word_array[wordCount];
		for (int r = 0; r<wordCount; r++){
			word_array[r].count = 0;
		}
		fprintf(stderr, "Got past the first run through of the file\n");
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
			//printf("don with while 97\n");
			str[i] = '\0';//Ends the string because there is a non letter character at the current index
			if (strlen(str) != 0){
				//printf("String: %s \n", str);
				int flag = 0;
				for (int d = 0; d<indexCounter;d++){
					//puts("line 103");
					//printf("Current value of str: %s      Current value of wordArray[d]:%s\n",str, wordArray[d]);
					//printf("%s   %i  %i   %s\n", str,d,indexCounter, word_array[0].word);
					if (strcmp(str, word_array[d].word)==0){
						//printf("%i\n", d);
						word_array[d].count = word_array->count+1;
						word_array[d].locations[word_array[d].count] = charCount-strlen(str);
						flag = 1;
						break;
					}
				}
				if (flag == 0){//Flag is just used to check if its in the wordArray after the for loop
					word_array[indexCounter].word = str;
					//printf("Flag %i\n", indexCounter);
					printf("String equals - %s\n", str);
					//printf("%s\n", word_array[indexCounter].word);
					word_array[indexCounter].count = 1;
					word_array[indexCounter].locations[word_array[indexCounter].count] = charCount-strlen(str);
					indexCounter++;
					
				}
			}
			//free(str);
			if (ch == ' ' || ch == '.' || ch == '?' || ch == '!' || ch == '\n'){
				ch = 'n';
			}
		}
		fprintf(stderr, "Got past the second run through of the file\n");
		printf("Word usage report:\n");
		for (int h = 0; h<wordCount; h++){
			if (word_array[h].count != 0){
				printf("%s  --  %i\n", word_array[h].word, word_array[h].count);
        		}
		}
		free(counts);//Freeing the dynamically allocated memories
		for (int u = 0; u<wordCount; u++){
                	free(wordArray[u]);
        	}
	}
	fprintf(stderr, "Freed memory\n");
	printf("Characters in file: %i\n", charCount);
	printf("Words in file: %i\n", wordCount);
	fclose(ptr);//Close the file
	ptr = NULL; //Setting the file ptr to Null, freeing the memory
	return (0);
}
