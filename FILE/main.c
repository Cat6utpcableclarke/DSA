#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typdef struct{
	int priority;
	char Movement[20];
	float time;
}Lane;


Lane add(char *Name, int prio, float time);

int main(){
	
	Lane lane[6];
	
	lane[0] = add("LeftMain",1,20);
	lane[1] = add("RightMain",2,15);
	lane[2] = add("LeftDiv",3,20);
	lane[3] = add("RightDiv",4,20);
	lane[4] = add("MainPed",5,20);
	lane[5] = add("DivPed",6,20);
	
	
	
	
	
}

Lane add(char *Name, int prio, float time){
	
	Lane lane;
	strcpy(lane.Movement,Name);
	lane.priority = prio;
	lane.time = time;
	return lane;
}
