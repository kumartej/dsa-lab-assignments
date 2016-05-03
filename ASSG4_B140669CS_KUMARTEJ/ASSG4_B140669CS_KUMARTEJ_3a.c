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
	   printf("%c",root->sym);
	   preorder(root->left);
	   preorder(root->right);
	}
	return;
}

void inorder(node *root){
	if(root!=NULL){
	  if(root->left!=NULL)
	   printf("(");
	   inorder(root->left);
	   printf("%c",root->sym);
	   inorder(root->right);
	  if(root->right!=NULL)
	   printf(")");
	}
	return;
}

void postorder(node *root){
	if(root!=NULL){
	   //printf("%c",root->sym);
	   postorder(root->left);
	   postorder(root->right);
	   printf("%c",root->sym);
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
