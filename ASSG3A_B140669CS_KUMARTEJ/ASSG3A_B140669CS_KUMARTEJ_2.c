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

int sumlist(nodem *head1,nodem *head2){
	int a;	
	if(head1->next==NULL && head2->next==NULL){
	     a=head1->data+head2->data;
	     head1->data=a%10;
		  return a/10;
	}
	int c=sumlist(head1->next,head2->next);
	a=c+head1->data+head2->data;
	head1->data=a%10;
	return a/10;
}

void print_list(nodem *head){
	nodem* temp;
	temp=head;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	int i,b;
	char a;
	ll n;
	char ch;
	nodem* temp,*head1,*head2;
	head1=NULL;
	head2=NULL;
	if(scanf("%lld",&n)!=1 || n<1 || n>10000){
		printf("INVALID INPUT\n");
		return 0;
	}
	scanf("%c",&a);
	for(i=0;i<n;i++){
		if(scanf("%c",&a)!=1 || a<48 || a>57){
		  printf("INVALID INPUT\n");
		  return 0;
		}
		temp=intnode(atoi(&a));
		if(temp==NULL){
	 	  printf("node cannot be created\n");
		  return 0;
		}
		head1=insert(head1,temp);
	}
	if(scanf("%c",&a)!=1 || a!='\n'){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	for(i=0;i<n;i++){
		if(scanf("%c",&a)!=1 || a<48 || a>57){
		  printf("INVALID INPUT\n");
		  return 0;
		}
		temp=intnode(atoi(&a));
		if(temp==NULL){
	 	  printf("node cannot be created\n");
		  return 0;
		}
		head2=insert(head2,temp);
	}
	if(scanf("%c",&a)!=1 || a!='\n'){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	i=sumlist(head1,head2);
	if(i==1){
		temp=intnode(1);
		temp->next=head1;
		head1=temp;
	}
	print_list(head1);
}
