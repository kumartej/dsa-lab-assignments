#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long long int

int ind=0,n;
struct binary_node{
	int sym;
	struct binary_node * left;
	struct binary_node *right;
};

#define node struct binary_node
int find_node(int *ir,int a,int p,int q);
node* newnode(int ch){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->sym=ch;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int find_node(int *ir,int a,int p,int q){
	int i=0;
	for(i=p;i<=q;i++){
	   if(ir[i]==a){
	   //printf("%d",i);
	   return i;}
	}
}

node* construct_tree(int *pr,int *ir,int p,int q){
	if(p<q){
	 // printf("%d",pr[ind]);
	    node * temp=newnode(pr[ind]);
	    int si=find_node(ir,pr[ind],p,q);
	    ind++;
	    temp->left=construct_tree(pr,ir,p,si-1);
	     if(temp->left==NULL)
	       ind--;
	    ind++;
	    temp->right=construct_tree(pr,ir,si+1,q);
	     if(temp->right==NULL)
	       ind--;
	    return temp;
	}
	else if(p==q && pr[ind]==ir[p]){
	    node *temp=newnode(pr[ind]);
	    return temp;
	}
	else
	return NULL;
}
void preorder(node *root){
	if(root!=NULL){
	  printf("( ");
	   printf("%d ",root->sym);
	   preorder(root->left);
	   preorder(root->right);
	  printf(") ");
	  return;
	}
	else{
	   printf("( ) ");
	}
	return;
}


int main(){
	int *pr,*ir,i;
	if(scanf("%d",&n)!=1 || n<=0){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	pr=(int*)malloc(n*sizeof(int));
	ir=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
	    if(scanf("%d",&pr[i])!=1){
	       printf("INVALID INPUT\n");
	       return 0;
	    }
	}
	for(i=0;i<n;i++){
	    if(scanf("%d",&ir[i])!=1){
	       printf("INVALID INPUT\n");
	       return 0;
	    }
	}
	node* head;
	head=construct_tree(pr,ir,0,n-1);
//	printf("\n"); 	
	preorder(head);
	printf("\n");
}
