
stack.o	: stack.h stack.c
	clang -c stack.h stack.c

token.o	: token.h token.c
	clang -c token.h token.c

jc	: stack.o token.o compiler.c
	clang -o jc stack.o token.o compiler.c

clean	: 
	rm -f jc *.o
