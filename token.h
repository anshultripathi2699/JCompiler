#define MAX_TOKEN_LENGTH 250

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	enum{
		DEFUN, IDENT, RETURN,
		PLUS, MINUS, MUL, DIV, MOD,
		AND, OR, NOT,
		LT, LE, EQ, GE, GT,
		IF, ELSE, ENDIF, 
		DROP, DUP, SWAP, ROT, 
		ARG, 
		LITERAL,
		BROKEN_TOKEN
	}type;

	int literal_value;
	int arg_no;
	char str[MAX_TOKEN_LENGTH];

} token;

extern int line_number;

void readTokens(char* line, FILE* outputFile);

const char *token_type_to_string(int type);

void print_token(token *theToken);

void freestack();