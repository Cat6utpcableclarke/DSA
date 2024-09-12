#ifndef ARRAY_LIST_STATIC_H
#define ARRAY_LIST_STATIC_H
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {

	int elems [MAX];
	int count;
}List;


//typedef struct{
//	int elems*;
//	int count;
//};

void initList(List *list);
List create();
void disp(List list);
bool insertFront(List *list, int item);
bool insertRear(List *list, int item);
bool insertAt(List *list, int item,int pos);
bool delFront(List *list);
bool delRear(List *list);
bool delAt(List *list, int pos);

//void insE(List *list);
//void insB

#endif
