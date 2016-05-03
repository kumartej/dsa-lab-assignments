#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long int

struct bstnode{
	int val;
	struct bstnode *left;
	struct bstnode *right;
};

int check;
#define node struct bstnode
node* intialise(int val){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node * insert(node *root,node *child){
	if(root==NULL)
	   return child;
	if(root->val>child->val)
	   root->left=insert(root->left,child);
	else if(root->val<child->val)
	   root->right=insert(root->right,child);
	else
	   check=1;
	return root;
}

node* search(node *root,int key){
	if(root!=NULL){
	    if(root->val==key)
	      return root;
	    else if(root->val<key)
	      return search(root->right,key);
	    else
	      return search(root->left,key); 
	}
	return NULL;
}
node* min_tree(node *root){
	if(root!=NULL){
	   if(root->left==NULL)
	    return root;
	   //printf("%d",root->val);
	   return min_tree(root->left);
	}
	return NULL;
}

node* max_tree(node *root){
	if(root!=NULL){
	   if(root->right==NULL)
	    return root;
	   return max_tree(root->right);
	}
	return NULL;
}

void inorder(node *root){
	if(root!=NULL){
	   inorder(root->left);
	   printf("%d ",root->val);
	   inorder(root->right);
	}
}

node* successor(node *root,int key){
	if(root==NULL)
	   return NULL;
	if(root->val==key){
	   if(root->right!=NULL)
	      return min_tree(root->right);
	   return NULL;
	}
	if(root->val>key){
	   node *su;
	   su=successor(root->left,key);
	   if(su!=NULL)
	      return su;
	    return root;
	}
	else
	  return successor(root->right,key);
}

node* predecessor(node *root,int key){
	if(root==NULL)
	  return NULL;
	if(root->val==key){
	   if(root->left!=NULL)
	      return max_tree(root->left);
	   return NULL;
	}
	if(root->val<key){
	   node *su;
	   su=predecessor(root->right,key);
	   if(su!=NULL)
	      return su;
	    return root;
	}
	else
	  return predecessor(root->left,key);
}

node* delete(node *root,int key){
	if(root==NULL)
	  return NULL;
	if(root->val==key){
	   if(root->left==NULL)
	     return root->right;
	   if(root->right==NULL)
	     return root->left;
	   node *temp=min_tree(root->right);
	   root->val=temp->val;
	   root->right=delete(root->right,temp->val);
	   return root;
	}
	else if(root->val>key){
	   root->left=delete(root->left,key);
	   return root;
	}
	else {
	   root->right=delete(root->right,key);
	   return root;
	}
}

void preorder(node *root){
	if(root!=NULL){
	  printf("%d ",root->val);
	  preorder(root->left);
	  preorder(root->right);
	}
}

void postorder(node *root){
	if(root!=NULL){
	  postorder(root->left);
	  postorder(root->right);
	  printf("%d ",root->val);
	}
}

int main(){
	node *tree,*temp;
	tree=NULL;
	int a;
	char str[10];
	scanf("%s",str);
	while(strcmp(str,"stop")!=0){
	   if(strcmp(str,"insr")==0){
	      if(scanf("%d",&a)!=1 || a<0){
	        printf("INVALID INPUT\n");
		return 0;
	      }
	      if(search(tree,a)==NULL){
	      temp=intialise(a);
	      tree=insert(tree,temp);}
	      else{
	         printf("INVALID INPUT\n");
	         return 0;
	      }
	   }
	   else if(strcmp(str,"inor")==0){
	       inorder(tree);
	       printf("\n");
	   }
	   else if(strcmp(str,"prer")==0){
		preorder(tree);
		printf("\n");
	   }
	   else if(strcmp(str,"post")==0){
		postorder(tree);
		printf("\n");
	   }
	   else if(strcmp(str,"srch")==0){
	   	if(scanf("%d",&a)!=1 || a<0){
		   printf("INVALID INPUT\n");
		   return 0;
		}
		temp=search(tree,a);
		if(temp==NULL)
		    printf("NOT FOUND\n");
		else
		    printf("FOUND\n");
	   }
	   else if(strcmp(str,"minm")==0){
	   	temp=min_tree(tree);
		if(temp==NULL)
		   printf("NIL\n");
		else
		   printf("%d\n",temp->val);
	   }
	   else if(strcmp(str,"maxm")==0){
	   	temp=max_tree(tree);
		if(temp==NULL)
		   printf("NIL\n");
		else
		   printf("%d\n",temp->val);
	   }
	   else if(strcmp(str,"succ")==0){
	   	if(scanf("%d",&a)!=1 || a<0){
	   	   printf("INVALID INPUT\n");
	   	   return 0;
	   	}
	   	if(search(tree,a)==NULL)
	   	  printf("NOT FOUND\n");
	   	else{
	   	temp=successor(tree,a);
	   	if(temp==NULL)
	   	   printf("NIL\n");
	   	else
	   	   printf("%d\n",temp->val);}
	   }
	   else if(strcmp(str,"pred")==0){
	   	if(scanf("%d",&a)!=1 || a<0){
	   	   printf("INVALID INPUT\n");
	   	   return 0;
	   	}
	   	if(search(tree,a)==NULL)
	   	  printf("NOT FOUND\n");
	   	else{
	   	temp=predecessor(tree,a);
	   	if(temp==NULL)
	   	   printf("NIL\n");
	   	else
	   	   printf("%d\n",temp->val);}
	   }
	   else if(strcmp(str,"delt")==0){
	   	if(scanf("%d",&a)!=1 || a<0){
	   	    printf("INVALID INPUT\n");
	   	    return 0;
	   	}
	   	if(search(tree,a)==NULL)
	   	   printf("NOT FOUND\n");
	   	else
	   	   tree=delete(tree,a);
	   }
	   else{
	       printf("INVALID INPUT\n");
	       return 0;
	   }
	scanf("%s",str);
	}
}
