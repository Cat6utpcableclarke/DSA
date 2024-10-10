#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NodeType,*NodePtr;


 NodePtr InitBST(){
	NodePtr temp = NULL;
	return temp;
}

bool addNode(NodePtr*headref,int data){
	NodePtr temp = malloc(sizeof(NodeType));
	if(temp==NULL){
		return false;
	}
	temp->data = data;
	temp->left=NULL;
	temp->right = NULL;
	while((*headref)!=NULL && (*headref)->data !=data){
		headref = ((*headref)->data >data)? &(*headref)->left : &(*headref)->right;
	}
	
	(*headref) = temp;

	return true;
}


void display(NodePtr head){
	NodePtr trav;
	trav =head;
	if(trav!=NULL){
		printf("%d,",trav->data);
		display(trav->left);
		display(trav->right);
	}
}


void INORDER(NodePtr head){
	NodePtr trav;
	trav =head;
	if(trav!=NULL){
		INORDER(trav->left);
		printf("%d,",trav->data);
		INORDER(trav->right);
		
	}
}

void postorder(NodePtr head){
	
	NodePtr trav;
	trav =head;
	if(trav!=NULL){
		postorder(trav->left);
		postorder(trav->right);
		printf("%d,",trav->data);
		
	}
}

void bfs(NodePtr head){
	
	NodePtr q[100];
	int fr = 0;
	int rear = 0;
	q[rear++] = head;
	
	while(fr < rear){
		NodePtr trav = q[fr++];
		printf("%d ",trav->data);
		if(trav->left){
			q[rear++] = trav->left;
		}
		
		if(trav->right){
			q[rear++] = trav->right;
		}
		  
	}
}
int main(){
	
	NodePtr head = NULL;
	addNode(&head,45);
	addNode(&head,30);
	addNode(&head,80);
	addNode(&head,20);
	addNode(&head,40);
	addNode(&head,50);
	addNode(&head,70);
	
//   display(head);
    
//   INORDER(head);
//	postorder(head);
	bfs(head);
}
