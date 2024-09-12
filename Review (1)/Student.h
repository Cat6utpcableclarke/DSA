#ifndef STUDENT_H
#define STUDENT_H
#define MAX 5
#include <string.h>
typedef char String[20];

typedef struct{
	int studID;
	String fname;
	String lname;
	String program;
}Student;

typedef struct{
	Student elems[MAX];
	int count;
}Stack;

Stack createStack();
void initStack(Stack *s);
bool isEmpty (Stack s);
bool isFull(Stack s);
void visualise (Stack s);

bool push (Stack *s, Student stud);
bool pop (Stack *s);
Student peek (Stack s);

Student createstud(int ID ,String fname, String lname, String program);
Stack getStudent(String program, Stack s);
 void sortStack(Stack *s);
#endif
