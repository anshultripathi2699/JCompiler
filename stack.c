#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"
void push (stack **uppermost, int number){

  stack *elt = malloc (sizeof(*elt));

  if (elt == NULL) {

    printf ("Couldn't allocate a new stack element\n");

    exit (1);

  }

  elt->number = number;
  elt->next = *uppermost;
  *uppermost = elt;

}

int pop(stack **uppermost){

  int poppedNumber = (*uppermost)->number;

	stack *newTop = (*uppermost)->next;

  free(*uppermost);

	*uppermost = newTop;

	return poppedNumber;

}