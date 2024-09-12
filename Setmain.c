#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct {
	int *elems; // p = 1 a =0;
	int count;
	int max;
}Set;
// typedef char Set

Set createSet(int max);
void initSet(Set *s, int max);
bool addelem(Set*s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);
bool isElement(Set s, int item);
bool isSubset(Set a, Set b);
int cardinality(Set s);
Set unionSet(Set a, Set b);
Set intersection (Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDifference( Set a, Set b);

int main() {
	
	Set a = createSet(10);
	addelem(&a, 4);
	addelem(&a, 1);
	addelem(&a, 2);
	
	Set b = createSet(10);
	addelem(&b, 2);
	addelem(&b, 4);
	removeElement(&b,4);
	addelem(&b, 5);
	displaySet(a);
	printf("\n");
	
	displaySet(b);
	isSubset(a,b);
	
	printf("\nunion Set: ");
	Set un = unionSet(a,b);
	displaySet(un);
	printf("\n");
	
	printf("intersect Set: ");
	Set in = intersection(a,b);
	displaySet(in);
	printf("\n");
	
	printf("difference Set: ");
	Set dif = differenceSet(a,b);
	displaySet(dif);
	printf("\n");
	
	printf("symmetricdifference Set: ");
	
	Set sym = symmetricDifference(a,b);
	displaySet(sym);
	printf("\n");
	return 0;
}

Set createSet(int max){
	
	Set a;
	a.elems = (int*)calloc(max,sizeof(int));
	a.count =0;
	a.max = max+1;
	return a;	
}


//void initSet(Set *s, int max){
//}

int cardinality(Set s){
	
	return s.count;
	
}
bool addelem(Set *s, int item){
	
	if(s->count < s->max && item < s->max && item >=0){
	
	s->elems[item] = 1;
	s->count ++;
	return true;
	}
	return false;
}

bool removeElement(Set *s, int item){
	
	s->elems[item] = 0;
	s->count --;
	return true;
}

void displaySet(Set s){
	int i;
	for(i=0 ; i<s.max; i++){
		if(s.elems[i] == 1){
			printf("%d ",i);
		}
	}
	
}

bool isElement(Set s, int item){	
	return s.elems[item] == 1 && item>=0 && item <s.max;
}

bool isSubset(Set a, Set b){
	int i;
	bool isSubset = false;
	
	for(i=0 ; i< b.max; i++){
		if(a.elems[i] ==1  && b.elems[i]==1){
			isSubset = true;
		}
		if(a.elems[i] == 0 && b.elems[i]==1){
			isSubset = false;
		}	
	}
	if(isSubset){
		printf("\nis Subset");
		return true;
	}else{
		printf("\nnot Subset");
		return false;
	}
}


Set unionSet(Set a, Set b){
	int i, max = (a.max >b.max)? a.max : b.max; 
	Set un = createSet(max);
	 
	 for(i = 0; i<un.max ;i++){
	 	if(isElement(a,i) || isElement(b,i)){
	 		addelem(&un,i);
		 }
	 }
	
	return un;
	
}

Set intersection (Set a, Set b){
	int i, max = (a.max >b.max)? a.max : b.max; 
	Set in = createSet(max); 
	 for(i = 0; i<in.max ;i++){
	 	if(isElement(a,i) && isElement(b ,i)){
	 		addelem(&in,i);
		 }
	 }
	
	return in;
	
}

Set differenceSet(Set a, Set b){
	
	int i, max = (a.max >b.max)? a.max : b.max; 
	
	Set dif = createSet(max); 
	 for(i = 0; i<dif.max ;i++){
	 	if(isElement(a,i) && !isElement(b,i)){
	 		addelem(&dif,i);
		 }
	 }
	 
	 
	
	return dif;
	
}

Set symmetricDifference( Set a, Set b){
	return unionSet(differenceSet(a,b),differenceSet(b,a));
}

