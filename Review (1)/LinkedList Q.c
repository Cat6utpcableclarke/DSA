#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedListQ.h"
// #include "Queue.h"

//typedef struct {
//    char fname[20];
//    char lname[20];
//}Name;
//
//
//typedef struct {
//    int StudId;
//    Name studName;
//    char sex; //f- fmale m-male
//    char program[6];
//}Student;
//
//typedef Student Data;
//
//typedef struct node{
//    Data elem;
//    struct node* link;
//    
//}Nodetype, *NodePtr;
//
//typedef struct {
//    NodePtr head;
//    NodePtr tail;
//    
//}Queue;
//
//void initQueue(Queue *q);
//Queue createqueue();
//bool isEmpty(Queue q);
//bool isFull(Queue q);
//void DisplayQ(Queue q);
//bool enqueue(Queue *q, Data d);
//bool dequeue(Queue *q);
//Data front(Queue q);
//void makeNull(Queue *q);
//Name *getStudent(Queue q, char program[6], char sex);
//Data createStudData(int id, char fname[20], char lname [20], char sex, char program[6]);

void main(){
    
   	
	Queue q = createqueue();
	Name *list;
	
	insertSorted(&q,createStudData(123,"calasd","bdad",'f',"BSIT"));
		insertSorted(&q,createStudData(123,"calasd","adad",'f',"BSIT"));
//	enqueue(&q, createStudData(123,"calasd","adad",'f',"BSIT"));
//	enqueue(&q, createStudData(12123,"clarke","adad",'f',"BSIT"));
//	enqueue(&q, createStudData(111231,"steven","adad",'m',"BSIT"));
	DisplayQ(q);
	printf("---------------------------------------------\n");
	
//	enqueue(&q, createStudData(12123,"cl","adad",'f',"BSIT"));
//	enqueue(&q, createStudData(111231,"st","adad",'m',"BSIT"));
	
	DisplayQ(q);
	printf("---------------------------------------------\n");
	dequeue(&q);
	DisplayQ(q);
	printf("---------------------------------------------\n");
//	enqueue(&q, createStudData(12123,"hehe","adad",'f',"BSIT"));
//	enqueue(&q, createStudData(111231,"haha","adad",'m',"BSIT"));
	DisplayQ(q);
	printf("---------------------------------------------\n");
//	makeNull(&q);
//	DisplayQ(q);
	printf("---------------------------------------------\n");


//	char gender = 'm';
//	char program[] = "BSIT";
//	list = getStudent(q,program,gender);
//	int i=0;
//	
//	for(i=0;strcmp(list[i].fname,"/0")!=0;i++){
//		
//		printf("%s\n",list[i].fname);
//	}


}
void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}
Queue createqueue(){
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    
    return q;
}
bool isEmpty(Queue q){
    return (q.head == NULL && q.tail == NULL);
}

void DisplayQ(Queue q){
	

//   
//   NodePtr tmp;
//      tmp = q->head;
    while(q.head!=NULL){
        Data temp = front(q);
        printf("%d, %s, %s, %c, %s\n",temp.StudId,temp.studName.fname,temp.studName.lname,temp.sex,temp.program);
        
        q.head = q.head->link;    
    }
    
//    q->head = tmp;
    
   
}
bool enqueue(Queue *q, Data d){
	
    NodePtr temp = malloc(sizeof(Nodetype));
    temp->elem=d;
    temp->link =NULL;
    
   
    
    if(q->tail == NULL){
	    q->head = temp;
	    q->tail = temp;
    }else{
	    q->tail->link = temp;
	    q->tail = temp;
   	 }
    
    return true;
    
}
bool dequeue(Queue *q){
    
    if(!isEmpty(*q)){
    NodePtr temp; 
    temp = q->head;
    q->head = q->head->link;
    free(temp);
    
    if(q->head == NULL){
    	q->tail = NULL;
	}
    return true;
    }
    return false;
    
}
Data front(Queue q){
    
    return q.head->elem;
}
void makeNull(Queue *q){
    
    while(!isEmpty(*q)){
	dequeue(q);
		
		}
    
}



Data createStudData(int id, char fname[20], char lname [20], char sex, char program[6]){
	Data stud;
	
	stud.StudId = id;
	strcpy(stud.studName.fname,fname);
	strcpy(stud.studName.lname,lname);
	stud.sex = sex;
	strcpy(stud.program,program);
	
	return stud;
}

Name* getStudent(Queue q, char program[6], char sex){
	
	Name* list = malloc(sizeof(Name)*10);
	int i = 0;
	
//	NodePtr temp;
	
	while(q.head!=NULL){
	 if(strcmp(q.head->elem.program, program)== 0 && q.head->elem.sex == sex){
		strcpy(list[i].fname,q.head->elem.studName.fname);
		strcpy(list[i].lname,q.head->elem.studName.lname);
//		 list[i] = q.head->elem.studName;
	 	i++;
	 }
//	 	printf("%d",q.head->elem.StudId);
		q.head = q.head->link;
	}
	
//		printf("%d",q.head->elem.StudId);
	
	strcpy(list[i++].fname,"/0");
	strcpy(list[i].lname,"/0");
	
	return list;
}


void insertSorted(Queue *q, Data data) {
    NodePtr newNode = malloc(sizeof(Nodetype));
    newNode->elem = data;
    newNode->link = NULL;
	
	NodePtr holder = q->head;
    if (q->head == NULL || strcmp(data.studName.lname, q->head->elem.studName.lname) <= 0) {
        // Insert at the beginning
        newNode->link = q->head;
        q->head = newNode;
        if (q->tail == NULL) {
            q->tail = newNode;
        }
        
        return;
    } else {
        // Insert somewhere after the head
        while (q->head->link != NULL && strcmp(data.studName.lname, q->head->link->elem.studName.lname) > 0) {
            q->head = q->head->link;
        }
        newNode->link = q->head->link;
        q->head->link = newNode;

        // Update tail if newNode is inserted at the end
       	 if (newNode->link == NULL) {
            q->tail = newNode;
        }
        
         q->head = holder;
         return;
    }
    
   
}

