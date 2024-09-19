#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
//use 65% as the packing density;
typedef struct {
	int studID;
	char studName[30];
	char program[10];
	int year;
}Student;

typedef struct Node {
	Student stud;
	struct node *link;
}Nodetype, *NodePtr;
typedef struct {
	NodePtr elems[20];
	int count;
}HashTable;

int getHash (Student s);
/*
Get the hash based on the summation of the first 3 letter of the name plush the letters int the program and must be able to retrun a value from 0-19.*/
void initDictionary(HashTable *ht);

bool insert(HashTable *ht, Student s);
/*use insert sorted if multiple data are already in the list*/
bool delete(HashTable *ht, Student s);

void visualizetable (HashTable ht);


int main(){
	
	Student s1 = {123,"JackCole","BSIT",2};
	Student s2 = {124,"PabloJab","BSIT",2};
	Student s3 = {125,"Skibidi","BSIT",2};
	Student s4 = {126,"APIPA","BSIT",2};
	
	HashTable ht;
//	getHash(s1);
//	printf("\n");
//	getHash(s2);
//	printf("\n");
//	getHash(s3);
//	printf("\n");
//	getHash(s4);
//	printf("\n");
	initDictionary(&ht);
	insert(&ht,s1);
	insert(&ht,s2);
	insert(&ht,s3);
	insert(&ht,s4);
	visualizetable(ht);
	
}
int getHash (Student s){
	int i;
	int sum= 0;
	
	for(i=0;s.program[i]!='\0';i++){
		sum+=s.program[i];
	};
	printf("%d",sum);
	int hash = ((sum+s.studName[0]+s.studName[1]+s.studName[2])%20);
	printf(" %d",hash);
	
	return hash;
}
void initDictionary(HashTable *ht){
	
	int i =0;
	ht->count = 0;
	for(i=0; i<20; i++){
		ht->elems[i] = NULL;
	};
}

bool insert(HashTable *ht, Student s){
	NodePtr temp = malloc(sizeof(Nodetype));
	temp->stud = s;
	temp->link = NULL;
	int i = getHash(s);
	NodePtr hld= ht->elems[i];
	
	if(ht->elems[i] != NULL){
		while(ht->elems[i]!=NULL && ht->elems[i]->stud.studID < s.studID){
			ht->elems[i] = ht->elems[i]->link;
		};
	};
	
			temp->link=ht->elems[i];
			ht->elems[i] = temp;
			ht->elems[i] = hld;
			ht->count ++;
		return true;
	
}

bool delete(HashTable *ht, Student s){
	
	
}

void visualizetable(HashTable ht){
		int i;
		printf("%d\n",ht.elems[0]->stud.studID);

	
	
}
