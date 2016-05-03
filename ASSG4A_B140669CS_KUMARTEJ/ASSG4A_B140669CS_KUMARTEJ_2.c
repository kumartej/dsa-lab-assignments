#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long int
int p;

struct binary_node{
	char sym;
	struct binary_node * left;
	struct binary_node *right;
	struct binary_node *parent;
};

#define node struct binary_node

/*struct stacknode{
	node* data;
	struct stacknode * next;
};

#define snode struct stacknode

struct structstack{
	snode * tail;
};

#define stack struct structstack

int isempty(stack *s){
	if(s->tail==NULL)
		return 1;
		return 0;
}

void push(stack *s,snode *nd){
	nd->next=s->tail;
	s->tail=nd;
}

snode * pop(stack *s){
	if(isempty(s))
		return NULL;
	snode* t=s->tail;
	s->tail=t->next;
	return t;
}

snode* createnode(node *val){
	snode *temp;
	temp=(snode *)malloc(sizeof(snode));
	temp->data=val;
	temp->next=NULL;
	return temp;
}
stack* intstack(){
	stack *s;
	s=(stack *)malloc(sizeof(stack));
	s->tail=NULL;
}*/

node* newnode(char ch){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->sym=ch;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	return temp;
}

int is_operator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
	   return 1;
	return 0;
}
int isin(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
	  return 1;
	else if (ch>=97 && ch<=122)
	  return 1;
	return 0;
}

/*node* build_tree(char *str){
	node *temp1,*temp2,*temp3;
	stack *s=intstack();
	snode *t2;
	int i=0;
	do{
	   if(is_operator(str[i])){
	      t2=pop(s);
	      temp1=t2->data;
	      t2=pop(s);
	      temp2=t2->data;
	      temp3=newnode(str[i]);
	      temp3->left=temp2;
	      temp3->right=temp1;
	      temp2->parent=temp3;
	      temp1->parent=temp3;
	      push(s,createnode(temp3));
	   }
	   else{
	      temp3=newnode(str[i]);
	      push(s,createnode(temp3));
	   }
	   i++;
	}while(i<strlen(str));
	t2=pop(s);
	temp3=t2->data;
	return temp3;
}*/

node* build_tree(char * str){
	if(p>=0){
	    node *t;
	    t=newnode(str[p]);
	    if(is_operator(str[p])){
	       p--;
	       t->right=build_tree(str);
	       p--;
	       t->left=build_tree(str);
	       t->left->parent=t;
	       t->right->parent=t;
	       return t;
	    }
	    return t;
	}
	return NULL;
}


void preorder(node *root){
	if(root!=NULL){
	node *temp=root,*prev=NULL;
	   do{
	      while(temp->left!=NULL){
	         printf("%c",temp->sym);
	         temp=temp->left;
	      }
	      printf("%c",temp->sym);
	      if(temp->right==NULL){
	         prev=temp;
	         temp=temp->parent;
	         while(temp!=NULL && temp->right==prev ){
	            prev=temp;
	            temp=temp->parent;
	         }
	         if(temp!=NULL){
	         temp=temp->right;
	         prev=NULL;
	         }
	      }
	      else{
	         temp=temp->right;
	      }
	   }while(temp!=NULL);
	}
	return;
}

void inorder(node *root){
	if(root!=NULL){
	node *temp=root,*prev=NULL;
	   do{
	      while(temp->left!=NULL){
	         printf("(");
	         temp=temp->left;
	      }
	      printf("%c",temp->sym);
	      if(temp->right==NULL){
	         prev=temp;
	         temp=temp->parent;
	         while(temp!=NULL && temp->right==prev ){
	            printf(")");
	            prev=temp;
	            temp=temp->parent;
	         }
	         if(temp!=NULL){
	         printf("%c",temp->sym);
	         temp=temp->right;
	         prev=NULL;
	         }
	      }
	      else{
	         temp=temp->right;
	      }
	   }while(temp!=NULL);
	}
	return;
}

void postorder(node *root){
	if(root!=NULL){
	node *temp=root,*prev=NULL;
	   do{
	      while(temp->left!=NULL){
	         temp=temp->left;
	      }
	      printf("%c",temp->sym);
	      if(temp->right==NULL){
	         prev=temp;
	         temp=temp->parent;
	         while(temp!=NULL && temp->right==prev ){
	            printf("%c",temp->sym);
	            prev=temp;
	            temp=temp->parent;
	         }
	         if(temp!=NULL){
	         temp=temp->right;
	         prev=NULL;
	         }
	      }
	      else{
	         temp=temp->right;
	      }
	   }while(temp!=NULL);
	}
	return;
}
int main(){
	char str[10000],ch;
	int i=0;
//	scanf("%s",str);
	scanf("%c",&ch);
//	scanf("%c",&ch);
	while(ch!='\n'){
	   if(!is_operator(ch)){
	     if(ch<97 || ch>122){
	        printf("INVALID INPUT\n");
	        return 0;
	     }
	   }
	   str[i++]=ch;
	   scanf("%c",&ch);
	}
	if(i==0){
	  printf("INVALID INPUT\n");
	  return 0;
	}
	str[i]='\0';
	node *head;
	p=strlen(str)-1;
//	printf("%d",p);
	head=build_tree(str);
	inorder(head);
	printf("\n");
	preorder(head);
	printf("\n");
	postorder(head);
	printf("\n");
}
