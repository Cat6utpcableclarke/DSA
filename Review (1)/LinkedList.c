#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "LinkedList.h"
#define MAX 10


void addl(ListN *list, int data){
	ListN newl = malloc(sizeof(Node));
	newl->data = data;
	newl->next = NULL;
	
	while(*list!=NULL){
		list = &(*list)->next;
	}
	
	*list = newl;
};

void addf(ListN *list, int data){
	ListN newl = malloc(sizeof(Node));
	newl->data = data;
	newl->next = *list;
	*list=newl;
	
	
};
void addat(ListN *list, int data,int pos){
	int i;
	ListN newl = malloc(sizeof(Node));
	newl->data = data;
	
	for(i=1; *list!=NULL && i<pos-1 ;i++){
		list = &(*list)->next;
	}
	newl->next = (*list)->next;
	(*list)->next = newl;
};

void Ndisp(ListN *list){
	while(*list!=NULL){
		printf("%d ",(*list)->data);
		list = &(*list)->next;
	}
}
void deletef(ListN *list){
	
	ListN temp = *list;
	*list=(*list)->next;
	free(temp);	
};

void deleteEnd(ListN *list){
	
	while((*list)->next->next!=NULL){
		list = &(*list)->next;
	}
	(*list)->next = NULL;
	
	
};
void deleteAt(ListN *list, int pos){
	int i;
	for(i=1; *list!=NULL && i<pos-1 ;i++){
		list = &(*list)->next;
	}
	ListN temp = (*list)->next;
	(*list)->next = (*list)->next->next;
	free(temp);
}
