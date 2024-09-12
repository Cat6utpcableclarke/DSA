#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Untitled3.h"
typedef struct {
	int elems[MAX];
	int count;
};
Stack createStack(){
	Stack s;
	s.count = 0;
	return s;
}
void initStack(Stack *s){
	s->count =0;
}
bool push(Stack *s){
}
bool pop (Stack *s){
	
	return (s->count--);
}
int peek (Stack s){
	return s.elems[s->count-1];
}
