#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long int
int p=0;
struct binary_node{
	int sym;
	struct binary_node * left;
	struct binary_node *right;
};

#define node struct binary_node

/*que starts here*/


struct structnode{
	node* data;
	struct structnode * next;
};

#define quenode struct structnode
struct queue{
	quenode * head;
	quenode * tail;
};
#define que struct queue

int isempty_queue(que *q){
	if(q->head==NULL)
	  return 1;
	else
	  return 0;
}

quenode* create_quenode(node* val){
	quenode* temp;
	temp=(quenode*)malloc(sizeof(quenode));
	temp->data=val;
	temp->next=NULL;
	return temp;
}

void enque(que *q, quenode* nd){
	if(isempty_queue(q)){
	   q->head=nd;
	   q->tail=nd;
	}
	else{
	   q->tail->next=nd;
	   q->tail=nd;
	}
}

quenode* deque(que *q){
	if(isempty_queue(q)) return NULL;
	quenode *x;
	x=q->head;
	q->head=x->next;
	if(q->tail==x)
	q->tail=q->tail->next;
	return x;
}

que* intializeque(){
	que *q;
	q=(que*)malloc(sizeof(que));
	q->head=NULL;
	q->tail=NULL;
	return q;
}


/*que ends here*/
/*stack starts here*/

struct stacknode{
	node* data;
	struct stacknode * next;
};

#define snode struct stacknode

struct structstack{
	snode * tail;
};

#define stack struct structstack

int isempty_stack(stack *s){
	if(s->tail==NULL)
		return 1;
		return 0;
}

void push(stack *s,snode *nd){
	nd->next=s->tail;
	s->tail=nd;
}

snode * pop(stack *s){
	if(isempty_stack(s))
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
	return s;
}
/* stack end here*/

node* newnode(int ch){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->sym=ch;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int getval(char *str){
	int ct,val=0,i=2,check=0;
	if(str[i]=='-'){
	   check=1;i++;}
	while(str[i]!=' '){
	    ct=str[i];
	    ct=ct-48;
	    val*=10;
	    val+=ct;i++;
	}
	if(check==1)
	  return -1*val;
	return val;
}

char * getleft(char *str){
	int i=1;
	while(str[i]!='(')
	   i++;
	return &str[i];
}

char* getright(char *str){
	int i=0,b=0;
	str=getleft(str);
	do{
	   if(str[i]=='('){b++;}
	   else if(str[i]==')'){b--;}
	   i++;
	}while(b!=0);
	return &str[i+1];
}

int isempty_bst(char* str){
	if(str[0]=='(' && str[1]==' ' && str[2]==')')
	   return 1;
	 return 0;
}

node* build_tree(char *str){
	if(isempty_bst(str))
	return NULL;
	int val=getval(str);
	char *lf=getleft(str),*rt=getright(str);
	node* root=newnode(val);
	root->left=build_tree(lf);
	root->right=build_tree(rt);
	return root;
}

void zigzag_order(node *root){
	stack *s=intstack();
	que *q=intializeque();
	if(root!=NULL){
	    quenode *q1;
	    snode *s1;
	    node *temp=root;
	    push(s,createnode(temp));
	    printf("%d ",temp->sym);
	    while(!isempty_stack(s) || !isempty_queue(q)){
	    	if(isempty_stack(s)){
	    	   while(!isempty_queue(q)){
	    		q1=deque(q);
	    		temp=q1->data;
	    		//printf("%d ",temp->sym);
	    		if(temp->left!=NULL){
	    		printf("%d ",temp->left->sym);
	    		push(s,createnode(temp->left));}
	    		if(temp->right!=NULL){printf("%d ",temp->right->sym);
	    		    push(s,createnode(temp->right));}
	    	   }
	    	}
	    	else if(isempty_queue(q)){
	    	    while(!isempty_stack(s)){
	    		s1=pop(s);
	    		temp=s1->data;
	    		//printf("%d ",temp->sym);
	    		if(temp->right!=NULL && temp->left!=NULL){
	    		    enque(q,create_quenode(temp->left));
	    		    enque(q,create_quenode(temp->right));
	    		    printf("%d ",temp->right->sym);
	    		    printf("%d ",temp->left->sym);
	    		}
	    		else if(temp->right!=NULL){printf("%d ",temp->right->sym);
	    		    enque(q,create_quenode(temp->right));}
	    		else if(temp->left!=NULL){printf("%d ",temp->left->sym);
	    		      enque(q,create_quenode(temp->left));}
	    	     }
	    	}
	    }
	}
}

int issymbol(char ch){
	if(ch =='(' || ch==')' || ch ==' ' || ch=='-')
	   return 1;
	else if(ch>=48 && ch<=57)
	   return 1;
	else
	   return 0; 
}

int main(){
	char str[10000],ch,*pt;
	int i=0,ob=0,cb;
	scanf("%c",&ch);
	while(ch!='\n'){
	  if(!issymbol(ch)){
	     printf("INVALID INPUT\n");
	     return 0;
	   }
	   if(ch=='(')
	     ob++;
	   else if (ch==')')
	     ob--;
	   str[i++]=ch;
	   scanf("%c",&ch);
	}
	str[i]='\0';
	if(i==0 || ob!=0){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	node* head=build_tree(str);
	zigzag_order(head);
	printf("\n");
}
