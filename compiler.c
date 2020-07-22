#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "token.h"
#include "stack.h"

int maxLength = 200;

int main(int argc, char** argv){

	FILE* inputFile = fopen(argv[1], "r");

	char* outputFileName = malloc(sizeof(argv[1]) + 3);
	strncpy(outputFileName, argv[1], strlen(argv[1])-2);
	strcat(outputFileName, ".asm");


	FILE* outputFile = fopen(outputFileName, "w");

	if(inputFile == NULL || outputFile == NULL){
		printf("Sorry, wrong chat\n");
		return 1;
	}

	

	while(!feof(inputFile)){
		char inputLine[maxLength];
		fgets(inputLine, maxLength, inputFile);

		if(inputLine[0] != ';'){
			readTokens(inputLine, outputFile);
		}
	}

	free(outputFileName);
	freestack();
	return 0;
}