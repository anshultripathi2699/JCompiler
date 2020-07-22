#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "token.h"
#include "stack.h"


int comparisonIdentifier = 0;
int ifIdentifier = 0;
int identBool = 0;

stack* myStack;

void readTokens(char* line, FILE* outputFile){
	char* token = strtok(line, " \t \n ; \r \f \v");

	if(token == NULL){
		//printf("Empty Line\n");
		goto ending;
	}

	int i;




	while(token != NULL && strcmp(token, ";;") != 0 && strcmp(token, ";") != 0 && strcmp(token, ";;\n") != 0 && strcmp(token, ";\n") != 0 && strcmp(token, "\n") != 0
		&& strcmp(token, "\t") != 0 && strcmp(token, "") != 0){

		if(strcmp(token, ";;") == 0){
			break;
		}



		if(strcmp(token, "+") == 0 ||strcmp(token, "+\t") == 0 || strcmp(token, "+\n") == 0){
			fprintf(outputFile, ";; + ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tADD R0 R0 R1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");


		}else if(strcmp(token, "-") == 0 || strcmp(token, "-\t") == 0 || strcmp(token, "-\n") == 0){
			fprintf(outputFile, ";; - ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tSUB R0 R0 R1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "*") == 0 || strcmp(token, "*\t") == 0 || strcmp(token, "*\n") == 0){
			fprintf(outputFile, ";; * ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tMUL R0 R0 R1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "/") == 0 ||strcmp(token, "/\t") == 0 || strcmp(token, "/\n") == 0){
			fprintf(outputFile, ";; / ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tDIV R0 R0 R1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "%") == 0 ||strcmp(token, "%\t") == 0 || strcmp(token, "%\n") == 0){
			fprintf(outputFile, ";; mod ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tMOD R0 R0 R1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "and") == 0||strcmp(token, "and\t") == 0 || strcmp(token, "and\n") == 0){
			fprintf(outputFile, ";; and ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tAND R0 R0 R1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "or") == 0 || strcmp(token, "or\t") == 0 || strcmp(token, "or\n") == 0){
			fprintf(outputFile, ";; or ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tOR R0 R0 R1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "not") == 0 || strcmp(token, "not\t") == 0 || strcmp(token, "not\n") == 0){
			fprintf(outputFile, ";; not ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tNOT R0 R0 R1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "drop") == 0 ||strcmp(token, "drop\t") == 0 || strcmp(token, "drop\n") == 0){
			fprintf(outputFile, ";; drop ;;\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "dup") == 0 ||strcmp(token, "dup\t") == 0 || strcmp(token, "dup\n") == 0){
			fprintf(outputFile, ";; dup ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "swap") == 0 ||strcmp(token, "swap\t") == 0 || strcmp(token, "swap\n") == 0){
			fprintf(outputFile, ";; swap ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\tSTR R1 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "rot") == 0 ||strcmp(token, "rot\t") == 0 || strcmp(token, "rot\n") == 0){
			fprintf(outputFile, ";; rot ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tLDR R1 R6 #1\n");
			fprintf(outputFile, "\tLDR R2 R6 #2\n");

			fprintf(outputFile, "\tSTR R1 R6 #2\n");
			fprintf(outputFile, "\tSTR R0 R6 #1\n");
			fprintf(outputFile, "\tSTR R2 R6 #0\n");
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "lt") == 0 || strcmp(token, "lt\t") == 0 || strcmp(token, "lt\n") == 0){
			fprintf(outputFile, ";; lt ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tCMP R0 R1\n");
			fprintf(outputFile, "\tBRn isLT%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tCONST R3 #0\n");
			fprintf(outputFile, "\tBRnzp isNotLT%d\n", comparisonIdentifier);

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isLT%d\n", comparisonIdentifier);
			fprintf(outputFile, "\tCONST R3 #1\n");

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isNotLT%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tSTR R3 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");

			comparisonIdentifier = comparisonIdentifier + 1;

			fprintf(outputFile, "\n");

		}else if(strcmp(token, "le") == 0 || strcmp(token, "le\t") == 0 || strcmp(token, "le\n") == 0){

			fprintf(outputFile, ";; le ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tCMP R0 R1\n");
			fprintf(outputFile, "\tBRnz isLE%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tCONST R3 #0\n");
			fprintf(outputFile, "\tBRnzp isNotLE%d\n", comparisonIdentifier);

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isLE%d\n", comparisonIdentifier);
			fprintf(outputFile, "\tCONST R3 #1\n");

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isNotLE%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tSTR R3 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");

			comparisonIdentifier = comparisonIdentifier + 1;


			fprintf(outputFile, "\n");

		}else if(strcmp(token, "eq") == 0 || strcmp(token, "eq\t") == 0 || strcmp(token, "eq\n") == 0){
			fprintf(outputFile, ";; eq ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tCMP R0 R1\n");
			fprintf(outputFile, "\tBRz isEQ%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tCONST R3 #0\n");
			fprintf(outputFile, "\tBRnzp isNotEQ%d\n", comparisonIdentifier);

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isEQ%d\n", comparisonIdentifier);
			fprintf(outputFile, "\tCONST R3 #1\n");

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isNotEQ%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tSTR R3 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");

			comparisonIdentifier = comparisonIdentifier + 1;

			fprintf(outputFile, "\n");

		}else if(strcmp(token, "ge") == 0|| strcmp(token, "ge\t") == 0 || strcmp(token, "ge\n") == 0){
			fprintf(outputFile, ";; ge ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tCMP R0 R1\n");
			fprintf(outputFile, "\tBRzp isGE%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tCONST R3 #0\n");
			fprintf(outputFile, "\tBRnzp isNotGE%d\n", comparisonIdentifier);

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isGE%d\n", comparisonIdentifier);
			fprintf(outputFile, "\tCONST R3 #1\n");

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isNotGE%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tSTR R3 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");

			comparisonIdentifier = comparisonIdentifier + 1;

			fprintf(outputFile, "\n");

		}else if(strcmp(token, "gt") == 0 ||strcmp(token, "gt\t") == 0 || strcmp(token, "gt\n") == 0){
			fprintf(outputFile, ";; gt ;;\n");
			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");
			fprintf(outputFile, "\tLDR R1 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tCMP R0 R1\n");
			fprintf(outputFile, "\tBRp isGT%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tCONST R3 #0\n");
			fprintf(outputFile, "\tBRnzp isNotGT%d\n", comparisonIdentifier);

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isGT%d\n", comparisonIdentifier);
			fprintf(outputFile, "\tCONST R3 #1\n");

			fprintf(outputFile, ".FALIGN\n");
			fprintf(outputFile, "isNotGT%d\n", comparisonIdentifier);

			fprintf(outputFile, "\tSTR R3 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");

			comparisonIdentifier = comparisonIdentifier + 1;

			fprintf(outputFile, "\n");

		}else if(strcmp(token, "if") == 0 ||strcmp(token, "+\t") == 0 || strcmp(token, "+\n") == 0){
			fprintf(outputFile, ";; if ;;\n");

			ifIdentifier = ifIdentifier + 1;
			push(&myStack, ifIdentifier);


			fprintf(outputFile, "\tLDR R0 R6 #0\n");
			fprintf(outputFile, "\tADD R6 R6 #1\n");

			fprintf(outputFile, "\tCMPI R0 #0\n");
			fprintf(outputFile, "\tBRnz label%d\n", ifIdentifier);

			

			fprintf(outputFile, "\n");

		}else if(strcmp(token, "else") == 0 ||strcmp(token, "else\t") == 0 || strcmp(token, "else\n") == 0){
			fprintf(outputFile, ";; else ;;\n");
			int topStack = pop(&myStack);
			ifIdentifier = ifIdentifier + 1;
			push(&myStack, ifIdentifier);
			fprintf(outputFile, "\tBRnzp label%d\n", ifIdentifier);

			fprintf(outputFile, "label%d\n", topStack);


			fprintf(outputFile, "\n");

		}else if(strcmp(token, "endif") == 0 ||strcmp(token, "endif\t") == 0 || strcmp(token, "endif\n") == 0){
			fprintf(outputFile, ";; endif ;;\n");
			
			int topStack = pop(&myStack);
			fprintf(outputFile, "label%d\n", topStack);
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "defun") == 0 ||strcmp(token, "defun\t") == 0 || strcmp(token, "defun\n") == 0){
			fprintf(outputFile, ";; defun ;;\n");
			identBool = 1;
			fprintf(outputFile, "\n");

		}else if(strcmp(token, "return") == 0 || strcmp(token, "return\t") == 0 || strcmp(token, "return\n") == 0){
			fprintf(outputFile, ";; return ;;\n");

			fprintf(outputFile, "\tLDR R7 R6 #0\n");
			fprintf(outputFile, "\tSTR R7 R5 #2\n");
			fprintf(outputFile, "\tADD R6 R5 #0\n");
			fprintf(outputFile, "\tLDR R5 R6 #0\n");
			fprintf(outputFile, "\tLDR R7 R6 #1\n");
			fprintf(outputFile, "\tADD R6 R6 #3\n");
			fprintf(outputFile, "\tRET\n");

			fprintf(outputFile, "\n");

		}else if(token[0] == 'a' && token[1] == 'r' && token[2] == 'g'){
			fprintf(outputFile, ";; arg ;;\n");
			int argnumber;
			sscanf(token + 3, "%d", &argnumber);
			fprintf(outputFile, "\tLDR R0 R5 #%d\n", argnumber+2);
			fprintf(outputFile, "\tSTR R0 R6 #-1\n");
			fprintf(outputFile, "\tADD R6 R6 #-1\n");

			fprintf(outputFile, "\n");

		}else if(token[0] == '0' && token[1] == 'x'){
			fprintf(outputFile, ";; hex ;;\n");
			int num;
			sscanf(token, "0x%x", &num);

			fprintf(outputFile, "\tCONST R0 #%d\n", num & 0x00FF);
			fprintf(outputFile, "\tHICONST R0 #%d\n", (num & 0xFF00) >> 8);
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\tSTR R0 R6 #0\n");


			fprintf(outputFile, "\n");


		}else if(token[0] == '-' || isdigit(token[0]) ){
			fprintf(outputFile, ";; number ;;\n");
			int num;
			sscanf(token, "%d", &num);

			fprintf(outputFile, "\tCONST R0 #%d\n", num & 0x00FF);
			fprintf(outputFile, "\tHICONST R0 #%d\n", (num & 0xFF00) >> 8);
			fprintf(outputFile, "\tADD R6 R6 #-1\n");
			fprintf(outputFile, "\tSTR R0 R6 #0\n");

			fprintf(outputFile, "\n");

		}else if(strcmp(token, "\n") == 0){
			//do nothing
		}else{
			
			if(identBool == 1){
				//IDENT
				identBool = 0;
				fprintf(outputFile, ";;Identifier %s;;\n", token);
				//strcpy(function, token);

				fprintf(outputFile, ".CODE\n");
				fprintf(outputFile, ".FALIGN\n");
				fprintf(outputFile, "%s\n", token);
				
				fprintf(outputFile, "\tADD R6 R6 #-3\n");
				fprintf(outputFile, "\tSTR R7 R6 #1\n");
				fprintf(outputFile, "\tSTR R5 R6 #0\n");
				fprintf(outputFile, "\tADD R5 R6 #0\n");

				fprintf(outputFile, "\n");
			}else{
				fprintf(outputFile, ";;Call %s;;\n", token);
				//call
				fprintf(outputFile, "\tJSR %s\n", token);
				fprintf(outputFile, "\tADD R6 R6 #-1\n");

				fprintf(outputFile, "\n");
			}

		}

		ending: token = strtok(NULL, " \t \n \r \f \v ");

		if(token == NULL || strcmp(token, ";") == 0 || strcmp(token, ";;") == 0){
			break;
		}


	}

	

}

stack *tempPointer =  NULL;

	void freestack(){
		while(myStack != NULL){
			tempPointer = myStack->next;
			free(myStack);
			myStack = tempPointer;
		}
	}