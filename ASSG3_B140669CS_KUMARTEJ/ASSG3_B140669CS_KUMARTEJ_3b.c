#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long int

struct structnode{
	int data;
	struct structnode * next;
};

#define node struct structnode
struct queue{
	node * head;
	node * tail;
};
#define que struct queue

int isempty(que *q){
	if(q->head==NULL)
	  return 1;
	else
	  return 0;
}

void enque(que *q, node* nd){
	if(isempty(q)){
	   q->head=nd;
	   q->tail=nd;
	}
	else{
	   q->tail->next=nd;
	   q->tail=nd;
	}
}

node* deque(que *q){
	if(isempty(q)) return NULL;
	node *x;
	x=q->head;
	q->head=x->next;
	if(q->tail==x)
	q->tail=q->tail->next;
	return x;
}

void print_queue(que *q){
	if(isempty(q)){
		printf("EMPTY\n");
		return;
	}
	node* temp;
	temp=q->head;
	while(temp!=NULL){
		   if(temp->data==-pow(2,31))
			printf("%ld ",(ll)-1*(temp->data));
		   else
		   printf("%d ",temp->data);
	   //printf("%d ",temp->data);
	   temp=temp->next;
	}
	printf("\n");
	return;
}

void intializeque(que *q){
	q->head=NULL;
	q->tail=NULL;
}

node* createnode(int val){
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=val;
	temp->next=NULL;
	return temp;
}
int main(){
	que *q;
	char ch;
	ll a;
	q=(que*)malloc(sizeof(que));
	intializeque(q);
	//scanf("%c",&ch);
	scanf("%c",&ch);
	while(ch!='s'){
	   if(ch=='e'){
		if(scanf("%ld",&a)!=1 || a<0 || a>pow(2,31)){
		  printf("INVALID INPUT\n");
		  return 0;
		}
		node *t;
		t=createnode(a);
	        enque(q,t);
	   }
	   else if(ch=='d'){
		node *an;
		an=deque(q);
		if(an==NULL)
		   printf("EMPTY\n");
		else{
		   {
		   if(an->data==-pow(2,31))
			printf("%ld\n",(ll)-1*(an->data));
		   else
		   printf("%d\n",an->data);
		}
		   //printf("%d\n",an->data);
		}
	   }
	   else if(ch=='p'){
		print_queue(q);}
	   else if(ch!='s'){
		printf("INVALID INPUT\n");
		return 0;
	   }
	scanf("%c",&ch);
	scanf("%c",&ch);
	}
}
