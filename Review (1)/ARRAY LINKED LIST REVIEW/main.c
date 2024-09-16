#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListStatic.h"
#include "ArrayListStatic.c"
#include "ArrayListDynamic.h"
#include "ArrayListDynamic.c"
#include "LinkedList.c"
#include "LinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("Static Array List \n");
	List l = create();
	
	insertFront(&l,100);
	insertFront(&l,20);
	insertFront(&l,30);
	insertRear(&l,101);
	insertAt(&l,25,2);
	disp(l);
		printf("\n");
	delFront(&l);
	printf("\n");
		disp(l);
		printf("\n");
	delRear(&l);
		disp(l);
		printf("\n");
	delAt(&l,1);
		disp(l);
	//////
	/////
	printf("\n");
	
	printf("Dynamic Array List \n");
	DList dl=createDList();
	DaddFront(&dl,1);
	DaddFront(&dl,2);
	DaddFront(&dl,3);
	DaddRear(&dl,3);
	
	DaddAt(&dl,4,1);
		Ddisp(dl);
		printf("\n");
	DdelFront(&dl);
		Ddisp(dl);
		printf("\n");
	DdelRear(&dl);
		Ddisp(dl);
		printf("\n");
	DdelAt(&dl,2);
		Ddisp(dl);
		printf("\n");
	///////
	///////
	printf("Linked List \n");
	ListN list = NULL;
	
	addl(&list,1);
	addl(&list,2);
	addl(&list,3);
	addf(&list,90);
	addat(&list,24,2);
		Ndisp(&list);
	deletef(&list);
		printf("\n");
		Ndisp(&list);	
	deleteEnd(&list);
		printf("\n");
		Ndisp(&list);	
	deleteAt(&list,3);
		printf("\n");
		Ndisp(&list);
	return 0;
}
