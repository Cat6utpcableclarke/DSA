#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int priority;
    char Movement[20];
    float time;
} Lane;

typedef struct {
    Lane lanes[8];
    int count;
} Heap;

void readDataFromFile(const char *filename);

int main() {
   
    readDataFromFile("traffic.dat");
    return 0;
}

void readDataFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    Heap heap;
    fread(heap.lanes, sizeof(Lane), 8, file);
    heap.count = 8; 
    int totaltime,i;
    fread(&totaltime, sizeof(int), 1, file);
    fclose(file);

    printf("Lanes data:\n");
    for ( i = 0; i < heap.count; i++) {
        printf("Lane %d: Movement = %s, Priority = %d, Time = %.2f\n",i + 1, heap.lanes[i].Movement, heap.lanes[i].priority, heap.lanes[i].time);
    }
    printf("Total time before main pedestrian can cross: %d\n", totaltime);
}

