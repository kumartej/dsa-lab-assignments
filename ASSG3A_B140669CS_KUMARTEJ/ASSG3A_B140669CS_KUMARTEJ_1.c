#include <stdio.h>
#include <stdlib.h>
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
	nodem *temp;
	temp=head;
	if(head==NULL){
		head=nd;
		return head;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=nd;
	return head;
}

nodem* search(nodem* h,int val){
	//nodem *t=h;
	while(h!=NULL && h->data!=val)
		h=h->next;
	return h;
}

nodem* recursive_reverse(nodem *p,nodem *q,nodem *r){
	if(r==NULL){
	   q->next=p;
	   return q;
	}
	q->next=p;
	return recursive_reverse(q,r,r->next);
}

nodem* reverse(nodem *head){
	if(head==NULL || head->next==NULL)
	   return head;
	else
	   return recursive_reverse(NULL,head,head->next);
}

void print_list(nodem *head){
	nodem* temp;
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	int a,i,b;
	ll n;
	nodem* temp,*head;
	head=NULL;
	if(scanf("%lld",&n)!=1 || n<1){
		printf("INVALID INPUT\n");
		return 0;
	}
	for(i=0;i<n;i++){
		if(scanf("%d",&a)!=1 || a>1073741824 || a<-1073741824){
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
	head=reverse(head);
	print_list(head);
}
