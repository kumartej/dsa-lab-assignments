#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long int
int p=0;

struct binary_node{
	char sym;
	struct binary_node * left;
	struct binary_node *right;
};

#define node struct binary_node

struct stacknode{
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
}

node* newnode(char ch){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->sym=ch;
	temp->left=NULL;
	temp->right=NULL;
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
node* construct_tree(char * str){
	if(p<strlen(str)){
	    node *t;
	    t=newnode(str[p]);
	    if(is_operator(str[p])){
	       p++;
	       t->left=construct_tree(str);
	       p++;
	       t->right=construct_tree(str);
	       return t;
	    }
	    return t;
	}
	return NULL;
}

void preorder(node *root){
	if(root!=NULL){
	   stack *s=intstack();
	   node *temp=root;
	   snode *t2;
	   do{
	    while(temp!=NULL){
	       printf("%c",temp->sym);
	       push(s,createnode(temp));
	       temp=temp->left;
	    }
	    if(!isempty(s)){
	       t2=pop(s);
	       temp=t2->data;
	       temp=temp->right;
	    }
	   }while(!isempty(s) || temp!=NULL);
	}
	return;
}

/*void inorder(node *root){
	if(root!=NULL){
	   int i=0,b=0,ch=0;
	   stack *s=intstack();
	   node *temp=root,*tp;
	   snode *t2;
	   while(temp!=NULL || !isempty(s)){
	       if(temp!=NULL){
	          push(s,createnode(temp));
	          if(i>0){
	          ch=0;printf("(");}
	          i++;
	          temp=temp->left;
	       }
	       else{
	          t2=pop(s);
	          temp=t2->data;
	          printf("%c",temp->sym);
	          temp=temp->right;
	          if(temp!=NULL){
	          b++;ch=1;
	          //printf("%d %d",b,ch);
	          }
	          if (ch==1 && temp==NULL){
	             for(i=0;i<b;i++)
	               printf(")");
	             b=0;
	          }
	          i=0;
	       }
	   }
	}
	return;
}*/

void inorder(node *root){
	if(root!=NULL){
	   int i=0;
	   stack *s=intstack();
	   node *temp=root,*prev=NULL;
	   snode *t2;
	   do{
	        while(temp!=NULL){
	          push(s,createnode(temp));
	          if(i>0)
	            printf("(");
	          i++;
	          temp=temp->left;
	        }
	        while(temp==NULL && !isempty(s)){
	           t2=s->tail;
	           temp=t2->data;
//	           printf("%c",temp->sym);
	           if(temp->right==NULL || temp->right==prev){
	           if(temp->right==NULL)
	             printf("%c",temp->sym);
	           else
	             printf(")");
	             t2=pop(s);
	             temp=t2->data;
	             prev=temp;
	             temp=NULL;
	           }
	           else{
	             printf("%c",temp->sym);
	             temp=temp->right;}
	        }
	        i=0;
	   }while(!isempty(s));
	}
	return;
}

void postorder(node *root){
	if(root!=NULL){
	   stack *s=intstack();
	   node *temp=root,*prev=NULL;
	   snode *t2;
	   do{
	        while(temp!=NULL){
	          push(s,createnode(temp));
	          temp=temp->left;
	        }
	        while(temp==NULL && !isempty(s)){
	           t2=s->tail;
	           temp=t2->data;
	           if(temp->right==NULL || temp->right==prev){
	             printf("%c",temp->sym);
	             t2=pop(s);
	             temp=t2->data;
	             prev=temp;
	             temp=NULL;
	           }
	           else
	             temp=temp->right;
	        }
	   }while(!isempty(s));
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
	head=construct_tree(str);
	inorder(head);
	printf("\n");
	preorder(head);
	printf("\n");
	postorder(head);
	printf("\n");
}
