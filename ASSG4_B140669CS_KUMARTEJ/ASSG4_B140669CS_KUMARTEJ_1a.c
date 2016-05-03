#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long long int

int c;
struct linkedlist{
	int data;
	struct linkedlist *next;
};

#define node struct linkedlist

struct array{
	node * head;
};
#define hashar struct array

node * createnode(int key){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=key;
	temp->next=NULL;
	return temp;
}

int hash_function(int key){
	if(key>=0)
	return key%c;
	return (c+(key%c))%c;
}

hashar* intialise_hash(int n){
	hashar *ar;
	int i;
	ar=(hashar *)malloc(n*sizeof(hashar));
	for(i=0;i<n;i++){
	   ar[i].head=NULL;
	}
	return ar;
}

void print_list(node *head){
	node* temp;
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void hash_print(hashar *ar){
	int i;
	for(i=0;i<c;i++){
	    printf("aa%d  ",i);
	    print_list(ar[i].head);
	    //printf("\n");
	}
}

hashar* chain_insert(hashar *h,int key){
	int hkey=hash_function(key);
	node * nd;
	nd=createnode(key);
	printf("%d\n",hkey);
	nd->next=h[hkey].head;
	h[hkey].head=nd;
	return h;
}

node * search(hashar * h,int key){
	int hkey=hash_function(key);
	node *nd;
	printf("%d ",hkey);
	if(h[hkey].head==NULL)
	 return NULL;
	nd=h[hkey].head;
	while(nd!=NULL && nd->data!=key){
	  //printf("%d ",nd->data);
	  nd=nd->next;
	}
	return nd;
}

int main(){
	if(scanf("%d",&c)!=1 || c<=0){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	hashar *h=intialise_hash(c);
	int i,n,a,q;
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	while(ch!='s'){
	   if(ch=='i'){
	      if(scanf("%d",&a)!=1){
	         printf("INVALID INPUT\n");
	         return 0;
	      }
	      h=chain_insert(h,a);
	   }
	   else if(ch=='f'){
	      if(scanf("%d",&a)!=1){
	         printf("INVALID INPUT\n");
	         return 0;
	      }
	      node *temp;
	      temp=search(h,a);
	      if(temp==NULL)
	        printf("NOT FOUND\n");
	      else
	        printf("FOUND\n");
	   }
	   else{
	      printf("INVALID INPUT\n");
	      return 0;
	   }
	   scanf("%c",&ch);
	   scanf("%c",&ch);
	}
return 0;
}
