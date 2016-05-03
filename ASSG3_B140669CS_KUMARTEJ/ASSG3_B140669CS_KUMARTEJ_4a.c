#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long int

struct structstack{
	int tail;
	int *ar;
	int n;
};

#define stack struct structstack

int isempty(stack *s){
	if(s->tail==0)
	  return 1;
	return 0;
}

int isfull(stack *s){
	if(s->tail==s->n)
	  return 1;
	else
	  return 0;
}

int push(stack *s,int val){
	if(isfull(s))
	  return 0;
	s->tail+=1;
	s->ar[s->tail]=val;
	return 1;
}

int* pop(stack *s){
	if(isempty(s))
	  return NULL;
	int *pt;
	pt=&s->ar[s->tail];
	s->tail--;
	return pt;
}

void print_stack(stack *s){
	if(isempty(s)){
	  printf("EMPTY\n");
	  return;
	}
	int t;
	t=s->tail;
	for(;t>0;t--){
	  if(s->ar[t]==-pow(2,31))
		printf("%ld ",(ll)-1*(s->ar[t]));
	  else
		printf("%d ",s->ar[t]);
	 // printf("%d ",s->ar[t]);
	}
	printf("\n");
	return;
}

void initialisestack(stack *s,int n){
	s->tail=0;
	s->ar=(int *)malloc((n+1)*sizeof(int));
	s->n=n;
}
int main(){
	int n;
	if(scanf("%d",&n)!=1 || n<=0 || n>=1000){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	stack *s;
	s=(stack *)malloc(sizeof(stack));
	initialisestack(s,n);
	int a,i,p;
	ll c;
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	while(ch!='s'){
	   if(ch=='a'){
		if(scanf("%ld",&c)!=1 || c<0 || c>pow(2,31)){
		  printf("INVALID INPUT\n");
		  return 0;
		}
		a=(int)c;
	        if(push(s,a)==0){
		   printf("OVERFLOW\n");
		}
	   }
	   else if(ch=='r'){
		int *an;
		an=pop(s);
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
		print_stack(s);}
	   else if(ch!='s'){
		printf("INVALID INPUT\n");
		return 0;
	   }
	scanf("%c",&ch);
	scanf("%c",&ch);
	}
}
