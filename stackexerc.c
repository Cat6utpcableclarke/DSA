#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    char name[30];
    int age;
    char sex;
} Person;

typedef struct node{
    Person data;
    struct node *link;
} NodeType, *NodePtr, *Stack;

void initStack(Stack *s);
bool isEmpty(Stack s);
void displayStack(Stack s);

bool push(Stack *s, Person p);
bool pop(Stack *s);
Person peek(Stack s);

/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p);

/*Insert sorted base on lastname. Rember to use the property 
  of the stack but without using push, pop, and peek functions.*/
bool insertSorted2(Stack *s, Person p);

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack(Stack *s, bool flag);


void main(){
	
	Stack s;
	initStack(&s);
	
	Person p1 = {"Clarke",12,'m'};
	Person p2 = {"Neo",12,'f'};
	Person p3 = {"Jamal",12,'m'};
	Person p4 = {"Lamar",12,'f'};

	push(&s,p1);
	push(&s,p2);
	push(&s,p3);
	push(&s,p4);	
	
	sortStack(&s , false);
	displayStack(s);
	
}

void initStack(Stack *s){
	
	*s = NULL;
	
}
bool isEmpty(Stack s){
	return s==NULL;
}
void displayStack(Stack s){
	
	while(!isEmpty(s)){
		printf("%s\n",s->data.name);
		s = s->link;
	};
	
}

bool push(Stack *s, Person p){
	
	NodePtr newn = malloc(sizeof(NodeType));
	newn->data = p;
	newn->link = NULL;
	
	
	if(*s != NULL){
	newn->link = *s;
	}
	*s = newn;
	
	 return true;
		
}
bool pop(Stack *s){
	
	NodePtr temp = *s;
	
	*s = (*s)->link;
	
	free(temp);
	return true;
	
}
Person peek(Stack s){
	
	Person p = {"",0,'0'};
	return (s!=NULL)? s->data : p;
}


/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p) {
	
	Stack temp;
	initStack(&temp);
	
	while(!isEmpty(*s)){
		Person pp = peek(*s);
		if(strcmp(pp.name , p.name)<0){
			push(&temp,pp);
			pop(s);
		}else{
			break;
		}
	}
	
	push(s,p);
	
	while(!isEmpty(temp)){
		push(s,peek(temp));
		pop(&temp);
	}
	return true;
}


///*Insert sorted base on lastname. Rember to use the property 
//  of the stack but without using push, pop, and peek functions.*/
bool insertSorted2(Stack *s, Person p){
	NodePtr temp = malloc(sizeof(NodeType));
	temp->data = p;
	temp->link = NULL;
	NodePtr hld = *s;
	
	if(*s == NULL || strcmp((*s)->data.name,p.name)>0){
		temp->link = *s;
		*s = temp;
		return true;
	}
	
	while(!isEmpty(*s) && strcmp((*s)->link->data.name,p.name)<0){
		*s = (*s)->link;
	}
		temp->link = (*s)->link;
		(*s)->link = temp;
		
		*s = hld;
		return true;	
}

///*Sort the values based on name. Use flag for ascending 
//  or descending. */
void sortStack(Stack *s, bool flag){
	
	Stack temp;
	initStack(&temp);
	
	
	while(!isEmpty(*s)){
		Person p1 = peek(*s);
		pop(s);
		Person p2 = peek(temp);
		
		if(flag){
			while(!isEmpty(temp) && strcmp(p1.name,p2.name) < 0 ){
				push(s,peek(temp));
				pop(&temp);
				}
		}else if(!flag){
			while(!isEmpty(temp) && strcmp(p1.name,p2.name) > 0 ){
				push(s,peek(temp));
				pop(&temp);
				}
		}
		push(&temp,p1);
	}
	
	while(!isEmpty(temp)){
		push(s,peek(temp));
		pop(&temp);
	}

}
