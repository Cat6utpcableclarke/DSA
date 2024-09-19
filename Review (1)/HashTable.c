#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>

#define MAX 20
//use 65% as the packing density;
typedef struct {
	int studID;
	char studName[30];
	char program[10];
	int year;
}Student;

typedef struct Node {
	Student stud;
	struct Node *link;
}Nodetype, *NodePtr;
typedef struct {
	NodePtr elems[MAX];
	int count;
}HashTable;

int getHash (Student s);
/*
Get the hash based on the summation of the first 3 letter of the name plush the letters int the program and must be able to retrun a value from 0-19.*/
void initDictionary(HashTable *ht);

bool insert(HashTable *ht, Student s);
/*use insert sorted if multiple data are already in the list*/
bool deletes(HashTable *ht, Student s);

void visualizetable (HashTable ht);


int main(){
	
	Student s1 = {123,"JackCole","BSIT",2};
	Student s2 = {124,"PabloJab","BSIT",2};
	Student s5 = {125,"Skibidi","BSIT",2};
	Student s3 = {126,"Skibidi","BSIT",2};
	Student s4 = {126,"APIPA","BSIT",2};
	Student s6 = {127,"APIPA","BSIT",2};	
	HashTable ht;
	initDictionary(&ht);
	insert(&ht,s1);
	insert(&ht,s2);
	insert(&ht,s3);
	insert(&ht,s4);
	insert(&ht,s5);
	insert(&ht,s6);
	deletes(&ht,s1);
	visualizetable(ht);
	
}
int getHash (Student s){
	int i;
	int sum= 0;
	
	for(i=0;s.program[i]!='\0';i++){
		sum+=s.program[i];
	};
	int hash = ((sum+s.studName[0]+s.studName[1]+s.studName[2])%MAX);
	
	
	return hash;
}
void initDictionary(HashTable *ht){
	
	int i =0;
	ht->count = 0;
	for(i=0; i<MAX; i++){
		ht->elems[i] = NULL;
	};
}

bool insert(HashTable *ht, Student s){
	NodePtr temp = malloc(sizeof(Nodetype));
	temp->stud = s;
	
	NodePtr*trav;
	int i = getHash(s),j;
	
		for(j=0; j<20;j++){
			
			for(trav=&(ht->elems[j]);(*trav)!=NULL;trav=&(*trav)->link){
				if((*trav)->stud.studID == s.studID){
					return false;
				}
		}
	}
				
	for(trav=&(ht->elems[i]);(*trav)!=NULL && strcmp(s.studName,(*trav)->stud.studName)>0;trav=&(*trav)->link){
	}
	
	temp->link = (*trav);
	(*trav) = temp;
	ht->count++;
		return true;
	
}

bool deletes(HashTable *ht, Student s){
	
	NodePtr*trav;
	NodePtr temp;
	int i = getHash(s);
	for(trav=&(ht->elems[i]);(*trav)!=NULL && (*trav)->stud.studID!=s.studID;trav=&(*trav)->link){				
	}
	
	temp = *trav;
	*trav = temp->link;
	ht->count--;
		return true;
	
}

void visualizetable(HashTable ht){
		int i;
		
		for(i=0; i<MAX;i++){
			printf("index %d:",i);
			if(!ht.elems[i]){
				printf("--\n");
			}else{
				while(ht.elems[i]){
					printf("%d ",ht.elems[i]->stud.studID);
					ht.elems[i] = ht.elems[i]->link;
				}
					printf("\n");
			}
		
		}
		
	
}
