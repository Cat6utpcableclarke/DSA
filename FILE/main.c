#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct {
    int priority;
    char Movement[20];
    float time;
} Lane;

typedef struct {
    Lane lanes[8];
    int count;
} Heap;

int calcTime(Heap heap);
void add(Heap *heap, char *Name, int prio, float time);

int main() {
    Heap heap;
    heap.count = 0; 

    add(&heap, "MainLaneLeft",2, 20);
    add(&heap, "MainLaneRight",3, 20);
    add(&heap, "MainLane",1, 20);
    add(&heap, "DivLane",4, 20);
    add(&heap, "PedLaneMain",7, 20);
    add(&heap, "PedLaneDiv",8, 20);
    add(&heap, "DivLaneLeft",5, 20);
    add(&heap, "DivLaneRight",6, 20);

	int totaltime = calcTime(heap);
	
	
	FILE *file = fopen("traffic.dat","wb");
	
	fwrite(heap.lanes,sizeof(Lane),heap.count,file);
	
	fwrite(&totaltime,sizeof(int),1,file);
	
	fclose(file);
	
	printf("total time before main ped can cross: %d", totaltime);
    return 0;
}

void add(Heap *heap, char *Name, int prio, float time) {
    int index = heap->count;
    int parent = (index - 1)/2;
    Lane newlane = {prio,"",time};
    strcpy(newlane.Movement,Name);

    
    while (index>0 && prio<heap->lanes[parent].priority) {
        heap->lanes[index] = heap->lanes[parent];
        index = parent;
        parent = (index - 1)/2;
    }

    heap->lanes[index] = newlane;
    heap->count++; 

}

void delete(Heap *heap){
	
	heap->lanes[0] = heap->lanes[heap->count-1];
	heap->count--;
	int parent=0;
	while(true){
		int idx=parent, left = 2*parent+1,right =2*parent+2;
		
		if(left < heap->count && heap->lanes[left].priority < heap->lanes[idx].priority){
			idx = left;
		}
		
		if(right < heap->count&&heap->lanes[right].priority<heap->lanes[idx].priority){
			idx = right;
		}
		
		if(idx == parent){
			break;
		}
		
		Lane temp = heap->lanes[idx];
		heap->lanes[idx] = heap->lanes[parent];
		heap->lanes[parent] = temp;
		
		parent = idx;
	}
}


int calcTime(Heap heap){
	int totaltime = 0 ;
	while(strcmp(heap.lanes[0].Movement,"PedLaneMain")!=0){
		totaltime+= heap.lanes[0].time;
		delete(&heap);
	}
	printf("%d",totaltime);
	
	return totaltime;
}



