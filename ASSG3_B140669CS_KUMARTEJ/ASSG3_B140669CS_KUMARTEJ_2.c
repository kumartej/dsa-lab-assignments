#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//nodem* search(nodem* h,int val);
struct node{
	int data;
	struct node* next;
};
#define ll long long int
#define nodem struct node

nodem* search(nodem* h,int val);
nodem* intnode(int a){
	nodem* new;
	new=(nodem*)malloc(sizeof(nodem));
	new->data=a;
	new->next=NULL;
	return new;
}

nodem* insert(nodem* head,nodem* nd){
	nd->next=head;
	head=nd;
	return head;
}

nodem* search(nodem* h,int val){
	//nodem *t=h;
	while(h!=NULL && h->data!=val)
		h=h->next;
	return h;
}

int k_last(nodem* head, int k){
	if(k==1)
	   return head->data;
	return k_last(head->next,k-1);
}



int main(){
	int i;
	ll n,a,b;
	char ch;
	nodem* temp,*head;
	head=NULL;
	if(scanf("%lld",&n)!=1 || n<1){
		printf("INVALID INPUT\n");
		return 0;
	}
	for(i=0;i<n;i++){
		if(scanf("%lld",&a)!=1 || a>pow(2,30) || a<-pow(2,30)){
		  printf("INVALID INPUT\n");
		  return 0;
		}
		temp=intnode(a);
		if(temp==NULL){
	 	  printf("node cannot be created\n");
		  return 0;
		}
		head=insert(head,temp);
	}
	temp=head;
	if(scanf("%lld%c",&a,&ch)!=2 || a>pow(2,30) || a<=0 || a>n || ch!='\n'){
		printf("INVALID INPUT\n");
		return 0;
	}
	/*temp=head;
	for(i=0;i<n;i++){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");*/
	printf("%d\n",k_last(head,a));
}
