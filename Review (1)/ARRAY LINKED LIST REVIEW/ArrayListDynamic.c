#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListDynamic.h"


void Ddisp(DList dList){
	int i;
	printf("{");
	for(i=0; i<dList.count;i++){
		printf("%d ",dList.elems[i]);
	}
	printf("}");
}
void initDList(DList *dList){
	
	dList->count = 0;
	dList->elems = malloc(sizeof(int)*MAX);
};
DList createDList(){
	DList Dl;
	initDList(&Dl);
	return Dl;
 };
 
 
 bool DaddFront(DList *dlist,int item){
 	int i;
 	
	 dlist->elems = realloc (dlist->elems, sizeof(int)*dlist->count+1);
 	
	 for(i=dlist->count; i>0;i--){
		dlist->elems[i]=dlist->elems[i-1];
		}
		dlist->elems[0]=item;
		dlist->count++;
	 	return true;
 };
 
 bool DaddRear(DList *dlist,int item){
 	dlist->elems = realloc (dlist->elems, sizeof(int)*dlist->count+1);
 	dlist->elems[dlist->count]=item;
 	dlist->count++;
 	return true;
 };
 
 bool DaddAt(DList *dlist,int item, int pos){
 	int i;
 	dlist->elems = realloc (dlist->elems, sizeof(int)*dlist->count+1);
 	
 	for(i=dlist->count;i>pos-1; i--){
	  	dlist->elems[i]=dlist->elems[i-1];
	  }
	  dlist->elems[i] = item;
	  dlist->count++;
	  return true;
 };
 
 bool DdelFront(DList *dlist){
	int i;
	dlist->elems = realloc (dlist->elems, sizeof(int)*dlist->count-1);
	
	for(i=0; i<dlist->count;i++){
		dlist->elems[i]=dlist->elems[i+1];
	}
	dlist->count--;
	return true;
 };
 
 bool DdelRear(DList *dlist){
 		dlist->elems = realloc (dlist->elems, sizeof(int)*dlist->count-1);
 		dlist->count--;
 	return true;
 };
 
 bool DdelAt(DList *dlist,int pos){
 	int i;
 	for(i=pos-1; i<dlist->count;i++){
		dlist->elems[i]=dlist->elems[i+1];
	}
	dlist->count--;
	return true;
 };
 
