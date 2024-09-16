#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct node{
	int data;
	struct node* next;
}*ListN, Node;


void addl(ListN *list, int data);
void addf(ListN *list, int data);
void addat(ListN *list, int data,int pos);
void deletef(ListN *list);
void deleteEnd(ListN *list);
void deleteAt(ListN *list,int pos);
void Ndisp(ListN *list);
#endif
