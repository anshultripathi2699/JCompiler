typedef struct stack_tag {
	int number;
	struct stack_tag *next;
}stack;

void push(stack** uppermost, int number);
int pop(stack** uppermost);