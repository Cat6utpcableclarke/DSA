#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct {
    char fname[20];
    char lname[20];
}Name;


typedef struct {
    int StudId;
    Name studName;
    char sex; //f- fmale m-male
    char program[6];
}Student;

typedef Student Data;

typedef struct node{
    Data elem;
    struct node* link;
    
}Nodetype, *NodePtr;

typedef struct {
    NodePtr head;
    NodePtr tail;
    
}Queue;


void initQueue(Queue *q);
Queue createqueue();
bool isEmpty(Queue q);
bool isFull(Queue q);
void DisplayQ(Queue q);
bool enqueue(Queue *q, Data d);
bool dequeue(Queue *q);
Data front(Queue q);
void makeNull(Queue *q);
Name*getStudent(Queue q, char program[6], char sex);
Data createStudData(int id, char fname[20], char lname [20], char sex, char program[6]);
void insertSorted(Queue *q , Data data);


#endif

