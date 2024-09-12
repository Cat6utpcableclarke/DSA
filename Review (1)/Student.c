#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Student.h"
Stack createStack(){
	Stack s;
	s.count = 0;
	return s;
};
void initStack(Stack *s){
	s->count = 0;
};
bool isEmpty (Stack s){
	return s.count == 0;
};
bool isFull(Stack s){
	return s.count == MAX;
};
void visualise (Stack s){
	int i;
	for(i=0 ;i<s.count;++i){
	
	printf("%d , %s, %s, %s \n",s.elems[i].studID, s.elems[i].fname,s.elems[i].lname,s.elems[i].program);
	}
};

bool push (Stack *s, Student stud){
	if (!isFull(*s)){
		s->elems[(s->count)++] = stud;
		return true;
	}
		return false;	
};
bool pop (Stack *s){
	if(!isEmpty(*s)){
		(s->count)--;
		return true;
	}
		return false;	
};
Student createstud(int ID ,String fname, String lname, String program){
	Student x;
	x.studID = ID;
	strcpy(x.fname, fname);
	strcpy(x.lname, lname);
	strcpy(x.program, program);
	return x;
};
Student peek (Stack s){

	
	return s.elems[s.count-1];
	
};
Stack getStudent(String program, Stack s){
	Stack temp = createStack();
	
	while(!isEmpty(s)){
		Student x = peek(s);
		if(strcmp(x.program, program)==0){
			push(&temp,x);
		}
		pop(&s);
	}
	return temp;
};

void sortStack(Stack *s){
	
	Stack temp =createStack();
	
	while(!isEmpty(*s)){
		Student Stemp1 = peek(*s);
		pop(s);
		Student Stemp2 = peek(temp);
		while(!isEmpty(temp) && strcmp(Stemp1.fname,Stemp2.fname)>0){
			push(s,peek(temp));
			pop(&temp);
		}
		
		push(&temp,Stemp1);
	}
	
	

	while(!isEmpty(temp)){
		push(s,peek(temp));
		pop(&temp);
	}
}



