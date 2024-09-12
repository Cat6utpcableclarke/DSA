#ifndef MY_STACK_H
#define MY_STACK_H
#define MAX 5
#include <stdbool.h>

typedef struct {
	int elems[MAX];
	int count;
} Stack;

Stack createStack()
void initStack(Stack *s)
bool push (Stack *s, int elem);
bool pop (Stack *s);
int peek(Stack s);
#endif
