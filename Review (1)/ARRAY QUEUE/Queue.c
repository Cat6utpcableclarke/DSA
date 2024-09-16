#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char String[20];
typedef struct {
	String fname , lname;
}Name;

typedef struct {
	int studID;
	Name studName;
	bool sex; //true-male ; false -female
	String program;
	int year;
}Student;

typedef struct {
	Student *studList;
	int max;
	int rear;
	int front;
}QueueADT;

void intQueue(QueueADT *q,int max){
	q->max = max;
	q->studList =malloc(sizeof(Student)* max);
}

QueueADT createQueue(int max){
	QueueADT q;
	
	q.max = max;
	q.studList = malloc(sizeof(Student)* max);
	q.front = (max+1)%max;
	q.rear=max%max;
	return q;
}

bool qisEmpty(QueueADT q){
	if((q.rear+1)%q.max == q.front){
		return true;
	};
	return false;
}

bool qisFull(QueueADT q){
	if((q.rear+2)%q.max == q.front){
		return true;
	};
	return false;
}

void makeEmpty(QueueADT *q){
	q->front = (q->max+1)%q->max;
	q->rear = q->max%q->max;
}


bool equeue(QueueADT *q, Student s){
	if(!qisFull(*q)){
		q->rear =(q->rear+1) %q->max;
		q->studList[q->rear]=s;
		return true;
	}
	return false;
}

bool dqueue (QueueADT *q){
	if(!qisEmpty(*q)){
		q->front =(q->front+1) %q->max;
		return true;
	}
	return false;
}

Student front (QueueADT q){
	return q.studList[q.front];
}

void visualize(QueueADT q ){
	int i;
		printf("INDEX ||| VALUE ||| indicator\n");
		for(i=0; i<q.max+1; i++){
		
		printf("%d         ",i);
		if(q.front ==i){
			printf("%s  ",q.studList[i].studName);
			printf("Front",q.studList[i].studID);
		}else if(q.rear == i){
				printf("%s  ",q.studList[i].studName);
				printf("REAR",q.studList[i].studID);
		}else{
			printf("");
		}
		
		printf("\n");
	}
	

}// will alow traversal

void display (QueueADT q){
		Student temp;
	while(!qisEmpty(q)){
		temp=front(q);
	
			printf("%d| %s| %s\n",q.studList[q.front].studID,q.studList[q.front].studName.fname, q.studList[q.front].program);
				
		dqueue(&q); 
	}
	
	
} //without traversal

Student qcreatestud(int ID,String fname, String lname, bool sex, String program, int year){
	Student n;
	n.studID = ID;
	strcpy(n.studName.fname,fname);
	strcpy(n.studName.lname,lname);
	n.sex = sex;
	strcpy(n.program,program);
	n.year = year;
	return n;
}

int main(){
	
	QueueADT q = createQueue(6);

	equeue(&q, qcreatestud(213,"WEWE","canal",true,"BSIT",2));
	
	 
	equeue(&q,qcreatestud(214,"A","canal",true,"BSCS",2));
	
	  
	equeue(&q,qcreatestud(215,"Vad","canal",true,"BSCS",2));
	
	  Student s = qcreatestud(216,"dadad","canal",true,"BSIT",2);
	equeue(&q,s);
	   
	 s = qcreatestud(217,"hgfng","canal",true,"BSIT",2);
	equeue(&q,s);
	
	
	dqueue(&q);
	printf("%d\n",q.front);
	printf("%d\n",q.rear);
	display(q);
	visualize(q);
	
}
