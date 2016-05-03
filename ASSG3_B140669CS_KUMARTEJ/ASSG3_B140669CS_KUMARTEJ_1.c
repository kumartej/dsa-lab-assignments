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

void swap(nodem** head,int x,int y){
	nodem* x1,*y1,*t1,*t2,*t3,*p,*h=*head;
	if(h->data==x){
		if(h->data==y)
		   return;
		t1=h;
		while(t1->next!=NULL && t1->next->data!=y)
		  t1=t1->next;
		x1=h;
		y1=t1->next;
		t1->next=x1;
		p=x1->next;
		x1->next=y1->next;
		y1->next=p;
		h=y1;
		*head=h;
		return;
	}
	if(h->data==y){
		t1=h;
		while(t1->next!=NULL && t1->next->data!=x)
		  t1=t1->next;
		x1=h;
		y1=t1->next;
		t1->next=x1;
		p=x1->next;
		x1->next=y1->next;
		y1->next=p;
		h=y1;
		*head=h;
		return ;
	}
	t1=h;t2=h;
	while(t1->next!=NULL && t1->next->data!=x)
		t1=t1->next;
	while(t2->next!=NULL && t2->next->data!=y)
		t2=t2->next;
	
	x1=t1->next;
	y1=t2->next;
	t1->next=y1;
	t2->next=x1;
	p=x1->next;
	x1->next=y1->next;
	y1->next=p;
	return;
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
	char ch;
	nodem* temp,*head;
	head=NULL;
	if(scanf("%lld",&n)!=1 || n<=1){
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
	if(scanf("%d%d%c",&a,&b,&ch)!=3 || a>1073741824 || a<-1073741824 || b>1073741824 || b<-1073741824 || ch!='\n'){
		printf("INVALID INPUT\n");
		return 0;
	}
	if(search(head,a)==NULL){
		printf("%d not found\n",a);
		return 0;
	}
	if(search(head,b)==NULL){
		printf("%d not found\n",b);
		return 0;
	}
	swap(&head,a,b);
	print_list(head);
}
