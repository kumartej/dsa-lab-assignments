#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long int

struct stacknode{
	int data;
	struct stacknode * next;
};

#define node struct stacknode

struct structstack{
	node * tail;
};

#define stack struct structstack

int isempty(stack *s){
	if(s->tail==NULL)
		return 1;
		return 0;
}

void push(stack *s,node *nd){
	nd->next=s->tail;
	s->tail=nd;
}

node * pop(stack *s){
	if(isempty(s))
		return NULL;
	node* t=s->tail;
	s->tail=t->next;
	return t;
}

void print_stack(stack *s){
	if(isempty(s)){
	  printf("EMPTY\n");
	  return;
	}
	node* t=s->tail;
	while(t!=NULL){
		if(t->data==-pow(2,31))
			printf("%ld ",(ll)-1*(t->data));
		   else
		   printf("%d ",t->data);
	   //printf("%d ",t->data);
	   t=t->next;
	}
	printf("\n");
	return;
}

node* createnode(int val){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=val;
	temp->next=NULL;
	return temp;
}
stack* intstack(){
	stack *s;
	s=(stack *)malloc(sizeof(stack));
	s->tail=NULL;
}
int main(){
	stack *s;
	char ch;
	ll a;
	s=intstack();
	//s=(stack *)malloc(sizeof(stack));
	//s->tail=NULL;
	scanf("%c",&ch);
	//printf("%c",ch);
	while(ch!='s'){
	   if(ch=='a'){
		if(scanf("%ld",&a)!=1 || a<0 || a>pow(2,31)){
		  printf("INVALID INPUT\n");
		  return 0;
		}
		node *t;
		t=createnode((int)a);
	        push(s,t);
	   }
	   else if(ch=='r'){
		node *an;
		an=pop(s);
		if(an==NULL)
		   printf("EMPTY\n");
		else{
		   if(an->data==-pow(2,31))
			printf("%ld\n",(ll)-1*(an->data));
		   else
		   printf("%d\n",an->data);
		   //printf("%d\n",an->data);
		}
	   }
	   else if(ch=='p'){
		print_stack(s);}
	   else if(ch!='s'){
		printf("INVALID INPUT\n");
		return 0;
	   }
	scanf("%c",&ch);
	scanf("%c",&ch);
	}

}
