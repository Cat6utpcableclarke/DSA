#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListStatic.h"


void initList(List *list){
	list->count = 0;
};
List create(){
	List list;
	initList(&list);
	return list; 
};
void disp(List list){
	
	int i;
	printf("List:{");
		for(i=0; i<list.count;i++){
			printf("%d ",list.elems[i]);	
		}
	printf("}");
};


bool insertFront(List *list, int item){
	
	int i;
	if(list->count<= 10){
	if(list->count !=0){
	for(i=list->count; i>0;i--){
		list->elems[i]=list->elems[i-1];
		}
	}
	list->elems[0]=item;
	list->count++;
		return true;
	}else{
		return false;
	}
}



bool insertRear(List *list, int item){
	if(list->count <10){
	
	 list->elems[list->count] = item;
	 list->count++;
	 return true;
	 }else{
	 	return false;
	 }
}


bool insertAt(List *list, int item, int pos){
	 int i;
		if(list->count<10){
	  for(i=list->count;i>pos-1; i--){
	  	list->elems[i]=list->elems[i-1];
	  }
	  list->elems[i] = item;
	  list->count++;
	  return true;
	  }else{
	  	return false;
	  }
}


bool delFront(List *list){
	int i;
	
	for(i=0; i<list->count;i++){
		list->elems[i]=list->elems[i+1];
	}
	list->count--;
	
	return true;
};
bool delRear(List *list){
	
	list->elems[(list->count)-1]=0;
	list->count--;
	return true;	
};
bool delAt(List *list, int pos){
	int i;
	for(i=pos-1; i<list->count;i++){
		list->elems[i]=list->elems[i+1];
	}
	list->count--;
	return true;
};

//bool insertFront(List *lsit, int item);


