//ArrayListDynamic.h

#ifndef ARRAY_LIST_DYNAMIC_H
#define ARRAY_LIST_DYNAMIC_H
#include <stdbool.h>
#include <string.h>

#define MAX 10
typedef struct {
	int *elems;
	int count;
}DList;



 void initDList(DList *dList);
 DList createDList();
 bool DaddFront(DList *dlist,int item);
 bool DaddRear(DList *dlist,int item);
 bool DaddAt(DList *dlist,int item,int pos);
 bool DdelFront(DList *dlist);
 bool DdelRear(DList *dlist);
 bool DdelAt(DList *dlist,int pos);
#endif
