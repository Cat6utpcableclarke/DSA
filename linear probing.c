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
	int status; //-1 del 0 empt 1 occpied
	int year;
}Student;

typedef struct {
	Student elems[MAX];
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
	Student s3 = {125,"Skibidi","BSIT",2};
	Student s4 = {126,"Skibidi","BSIT",2};
	Student s5 = {126,"APIPA","BSIT",2};
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
	int i;
	
	for(i=0; i<MAX; ++i){
		ht->elems[i].status = 0;
	}
	ht->count = 0;

}

bool insert(HashTable *ht, Student s){
	
	int idx = getHash(s);
	
	if((ht->count +1) > (MAX * 0.8)){
		return false;
	};
	for(;ht->elems[idx].status != 0; idx = (idx+1)%MAX){}
	ht->elems[idx] = s;
	ht->elems[idx].status = 1;
	ht->count ++;
	return true;

}

bool deletes(HashTable *ht, Student s){
	
	int idx = getHash(s);
	
	ht->elems[idx].status = -1;
	ht->count --;
	
}

void visualizetable(HashTable ht){
	
	int i;
	for(i=0;i<MAX;++i){
		printf("INDEX %d:",i);
		if(ht.elems[i].status == 0 || ht.elems[i].status == -1){
			printf("----\n");
		}else{
			printf("%d ,hashvalue:%d \n",ht.elems[i].studID,getHash(ht.elems[i]));
		}
	}	
	
}
