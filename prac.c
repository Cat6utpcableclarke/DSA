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

void convert (ProdDict *pd, Stack *s);
void initDict(ProdDict *pd, int max);
int getHash(ProdDict pd, int prodID, char prodName[]);
bool add(ProdDict *pd, Product p);
bool removes(ProdDict *pd,Product p);
void displayDick(ProdDict pd);
Product get(int id,char prodName[], int idx);

void initStack(Stack *s);
bool isEmpty(Stack s);
bool push(Stack *s, Product p);
bool  pop(Stack *s);
Product peek(Stack s);
void displayStack(Stack s);
int main(){
	Stack s;
	initStack(&s);
	
	ProdDict pd;
	initDict(&pd,20);
	Product p1 = {123,"cornedbeef",105,10.25};
	Product p2 = {124,"Sinigang",11,10.25};
	Product p3 = {125,"Neto",10,10.25};
	Product p4 = {126,"Dragon",12,10.25};

	push(&s,p1);
	push(&s,p2);
	push(&s,p3);
	push(&s,p4);
	displayStack(s);
	
	
//	add(&pd,p1);
//	add(&pd,p2);
//	add(&pd,p3);
//	add(&pd,p4);
	
	convert(&pd,&s);
		
			displayDick(pd);
}

void convert (ProdDict *pd, Stack *s){
	
	while(!isEmpty(*s)){
		add(pd, (*s)->prod);
		(*s) = (*s)->link;
	}
	
}

Product get(int id,char prodName[], int idx){
	
	
}
void initDict(ProdDict *pd, int max){
	int i;
	pd->count =0;
	pd->max = max;
	pd->data = malloc(sizeof(NodeType) * max);
	for(i=0; i<pd->max;++i){
		pd->data[i] = NULL;
	};
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

void displayStack(Stack s){
	
	while(s!= NULL){
		printf("%d\n",s->prod.prodID);
		s = s->link;
	}
}

void displayDick(ProdDict pd){
	int i;
	
	
		
		for(i=0; i<pd.max;i++){
			printf("index %d:",i);
			if(!pd.data[i]){
				printf("--\n");
			}else{
				while(pd.data[i]){
					printf("%d ",pd.data[i]->prod.prodID);
					pd.data[i] = pd.data[i]->link;
				}
					printf("\n");
			}
		
		}
}
