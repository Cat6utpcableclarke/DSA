#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 20
typedef struct {
	int elems[MAX];
	int count;
}BinaryHeap;

void Insert(BinaryHeap *heap, int num){
	
	int idx = heap->count;
	
	heap->elems[idx] = num;
	heap->count++;
	while(idx>0){
		int parent = (idx-1)/2;
		
		if(heap->elems[idx] > heap->elems[parent]){
			int temp = heap->elems[idx];
			heap->elems[idx] = heap->elems[parent];
			heap->elems[parent] = temp;
			idx = parent;
		}else{
			break;
		}
		
	}
	return;	
}

void Delete(BinaryHeap *heap){
	
	int temp = heap->elems[heap->count-1];
	heap->elems[heap->count-1] = heap->elems[0];
	heap->elems[0] = temp;
	
	
	int idx = heap->count-2;
	while(idx>0){
		int parent = (idx -1)/2;
		
		if(heap->elems[idx] > heap->elems[parent]){
			int temp = heap->elems[idx];
			heap->elems[idx] = heap->elems[parent];
			heap->elems[parent] = temp;
			idx = parent;
		}else{
			break;
		}
		
	}
	
	
}

void display(BinaryHeap heap){
	int i;
	for( i=0; i< heap.count;i++){
		printf("%d",heap.elems[i]);
	}
}


int main(){
	
	
	BinaryHeap heap;
	heap.count = 0;
	Insert(&heap,3);
	Insert(&heap,4);
	Insert(&heap,5);
	Insert(&heap,2);
	Insert(&heap,1);
	
	Delete(&heap);
	
	display(heap);
	
}

