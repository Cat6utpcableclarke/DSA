#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
	int prodID;
	char prodName[16];
	int prodQty;
	float prodPrice;
}Product;

typedef struct node{
	Product prod;
	struct node *link;
}NodeType, *NodePtr, *Stack;


typedef struct {
	NodePtr *data; //dynamic
	int count;
	int max;
}ProdDict;

void convert (ProdDict *pd, Stack s);
void initDict(ProdDict *pd, int max);
int getHash(ProdDict pd, int prodID, char prodName[]);
bool add(ProdDict *pd, Product p);
bool removes(ProdDict *pd,Product p);

void initStack(Stack *s);
bool isEmpty(Stack s);
bool push(Stack *s, Product p);
bool  pop(Stack *s);
Product peek(Stack s);
int main(){
	
	Product p1 = {123,"cornedbeef",10,10.25};
	Stack s;
	initStack(&s);
	push(&s,p1);
	
		
}

void convert (ProdDict *pd, Stack s){
	
	while(!isEmpty(s)){
		add(pd, s->prod);
		s = s->link;
	}
	
}
void initDict(ProdDict *pd, int max){
	pd->count =0;
	pd->max = max;
	pd->data = malloc(sizeof(NodeType) * max);
}
int getHash(ProdDict pd, int prodID, char prodName[]){
	int sum =0;	
	sum = (prodID + prodName[0] +prodName[1] +prodName[2] +prodName[3]+prodName[4]) %pd.max;
	return sum;
}


bool add(ProdDict *pd, Product p){
	NodePtr neww = malloc(sizeof(NodeType));
	neww->prod = p;
	int idx = getHash(*pd,p.prodID,p.prodName);
	
	NodePtr *temp;
	
	for(temp = &(pd->data[idx]); (*temp)!= NULL; temp =&(*temp)->link){
		
		if((*temp)->prod.prodID == p.prodID && strcmp((*temp)->prod.prodName, p.prodName) == 0 && (*temp)->prod.prodPrice == p.prodPrice){
			(*temp)->prod.prodQty+=p.prodQty;
			return true;
		}
	}
	
	
	neww->link = (*temp);
	(*temp) = neww;
	pd->count++;
	
	return true;
	
	
	
}
bool removes(ProdDict *pd, Product p){
	
	int idx = getHash(*pd,p.prodID,p.prodName);
	NodePtr *temp;
	NodePtr t;
	for(temp = &(pd->data[idx]); (*temp)!= NULL; temp =&(*temp)->link){
				
			if((*temp)->prod.prodID == p.prodID && strcmp((*temp)->prod.prodName, p.prodName) == 0 && (*temp)->prod.prodPrice == p.prodPrice){
			(*temp)->prod.prodQty-=p.prodQty;
			return true;
		}
	}
	t = (*temp);
	(*temp) = (*temp)->link;
	pd->count --;
	free(t);
	return true;
}

void initStack(Stack *s){
	*s = NULL;
}
bool isEmpty(Stack s){
	return s == NULL;
}
bool push(Stack *s, Product p){
	
	NodePtr neww = malloc(sizeof(NodeType)); 
	neww->prod = p;
	neww->link = (*s);
	(*s) = neww;
	return true;
}
bool pop(Stack *s){
	
	if(isEmpty(*s)){
		return false;
	}
	NodePtr temp;
	temp = (*s);
	(*s) = (*s)->link;
	free(temp);
	return true;
}
Product peek(Stack s){
	return s->prod;
}
