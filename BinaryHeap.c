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
//	heap->elems[idx] = num;
//	heap->count++;
	while(idx>0){
		int parent = (idx-1)/2;
		if(num > heap->elems[parent]){
			heap->elems[idx] = heap->elems[parent];
			idx = parent;
		}else{
			break;
		}
	}
	heap->elems[idx] = num;
	heap->count++;
	return;	
}

void Delete(BinaryHeap *heap) {
    int temp;
    heap->elems[0] =heap->elems[heap->count - 1];
    heap->count--;
    int parent = 0;
    while (true) {
        int tempidx = parent,left = 2 * parent + 1,right = 2 * parent + 2;
        if (left < heap->count && heap->elems[left] > heap->elems[tempidx]) {
            tempidx = left;
        }  
        if (right < heap->count && heap->elems[right] > heap->elems[tempidx]) {
            tempidx = right;
        }
        if (tempidx == parent) {
            break;
    	}
        temp = heap->elems[tempidx];
        heap->elems[tempidx] = heap->elems[parent];
        heap->elems[parent] = temp;

        parent = tempidx;
    }
}


void display(BinaryHeap heap){
	int i;
	for( i=0; i< heap.count;i++){
		printf("%d",heap.elems[i]);
		
	}
	printf("\n");
}


int main(){
	
	
	BinaryHeap heap;
	heap.count = 0;
	Insert(&heap,3);
	Insert(&heap,4);
	Insert(&heap,5);
	Insert(&heap,2);
	Insert(&heap,1);
	
	display(heap);
	Delete(&heap);
	
	display(heap);
	Insert(&heap,6);
	display(heap);
	
}

