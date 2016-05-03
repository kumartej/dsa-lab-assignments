#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long int
struct queue{
	int head;
	int tail;
	int n;
	int* ar;
	
};

#define que struct queue

int isempty(que *q){
	if(q->head==q->tail)
	  return 1;
	else
	  return 0;
}
int isfull(que *q){
	if(q->tail!=q->n){
	  if(q->head==q->tail+1)
		return 1;
	  else
		return 0;
	}
	else{
	  if(q->head==1)
	   return 1;
	  else
	   return 0;
	}
}

int enque(que *q,int val){
	if(isfull(q))
	  return 0;
	q->ar[q->tail]=val;
	if(q->tail==q->n)
	  q->tail=1;
	else
	  q->tail=q->tail+1;
	return 1;
}

int* deque(que *q){
	if(isempty(q))
	  return NULL;
	int*p =&q->ar[q->head];
	if(q->head==q->n)
	  q->head=1;
	else
	  q->head=q->head+1;
	return p;
}
void print_queue(que *q){
	if(isempty(q)){
	   printf("EMPTY\n");
	   return;
	}
	int temp;
	temp=q->head;
	while(temp!=q->tail){
	  if(q->ar[temp]==-pow(2,31))
		printf("%ld ",(ll)-1*(q->ar[temp]));
	  else
		printf("%d ",q->ar[temp]);
	  if(temp==q->n)
	    temp=1;
	  else
	  temp++;
	}
	printf("\n");
	return;
}
int main(){
	que *q;
	int *pt,n;
	q=(que *)malloc(sizeof(que));
	if(scanf("%d",&n)!=1 || n<=0 || n>=100){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	pt=(int *)malloc(n*sizeof(int));
	q->ar=pt;
	q->head=1;
	q->tail=1;
	q->n=n;
	int i,p;
	ll a;
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	while(ch!='s'){
	   if(ch=='e'){
		if(scanf("%ld",&a)!=1 || a<0 || a>pow(2,31)){
		  printf("INVALID INPUT\n");
		  return 0;
		}
	        if(enque(q,(int)a)==0){
		   printf("OVERFLOW\n");
		}
	   }
	   else if(ch=='d'){
		int *an;
		an=deque(q);
		if(an==NULL)
		   printf("EMPTY\n");
		else{
		   if(*an==-pow(2,31))
			printf("%ld\n",(ll)-1*(*an));
		   else
		   printf("%d\n",*an);
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
