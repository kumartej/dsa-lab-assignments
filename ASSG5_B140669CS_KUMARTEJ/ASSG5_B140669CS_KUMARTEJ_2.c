#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

//#define INT_MAX 100000

struct node{
	int vt;
	struct node *next;
};

#define list struct node

struct adjacency_list{
	struct node *head;
	struct node *tail;
};

#define array struct adjacency_list

    array ar[10010];

void insert(array *ar,int vertex){
    list *temp;
    temp=(list*)malloc(sizeof(list));
    temp->vt=vertex;
    temp->next=NULL;
    
    if(ar->head==NULL){
       ar->head=temp;
       ar->tail=temp;
    }
    else{
       ar->tail->next=temp;
       ar->tail=temp;
    }
    return;
}

/*que fuctions*/

struct structnode{
	int data;
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

quenode* create_quenode(int val){
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
/*end of que*/

void print_list(array *ar){
    list *temp;
    temp=ar->head;
    while(temp!=NULL){
       printf("%d ",temp->vt);
       temp=temp->next;
    }
}

int check=0,v[10000];

void bfs(array *ar,int x,int y,int n){
	int i=0,a;
	list *temp,*u;
	int p,t;
	que *q;
	q=intializeque();
	for(i=0;i<n;i++)
	  v[i]=0;
	temp=ar[x].head;a=x;
	printf("%d ",x);
	if(x==y)
	return;
	enque(q,create_quenode(x));
	while(!isempty_queue(q)){
	    p=q->head->data;
	    temp=ar[p].head;
	    while(temp!=NULL){
	       if(v[temp->vt]==0){
              printf("%d ",temp->vt);
	          if(temp->vt==y)
	             return;
	          v[temp->vt]=1;
	          enque(q,create_quenode(temp->vt));
	       }
	       temp=temp->next;
	    }
	    deque(q)->data;
	    v[p]=1;
	}
}

void dfsrecurse(array *ar,int x,int y,int n){
    list *temp,*u;
    temp=ar[x].head;
    int a;
    while(temp!=NULL && check==0){
       if(v[temp->vt]==0){
           printf("%d ",temp->vt);
           if(temp->vt==y)
              check=1;
           v[temp->vt]=1;
           a=temp->vt;
           u=ar[a].head;
           if(u!=NULL)
              dfsrecurse(ar,a,y,n);
       }
       temp=temp->next;
    }
}

void dfs(array *ar,int x,int y,int n){
    int i=0,a;
    list *temp,*u;
    int p,t;
    for(i==0;i<n;i++)
       v[i]=0;
    check=0;
    printf("%d ",x);
    v[x]=1;
    if(x==y)
    return;
    dfsrecurse(ar,x,y,n);
}

int main(){
    int n,i,j,a=0,x,y,prev=INT_MIN;;
    if(scanf("%d",&n)!=1 || n<1 || n>10000){
        printf("INVALID INPUT\n");
        return 0;
    }
    char ch,str[5];
    for(i=0;i<n;i++){
       ar[i].head=NULL;
       ar[i].tail=NULL;
    }
    scanf("%c",&ch);
    for(i=0;i<n;i++){
       j=0;
       prev=INT_MIN;
       scanf("%c",&ch);
       while(ch!='\n'){
          j++;
          if(ch>=48 && ch<=57)
           a=a*10+ch-48;
        else if(ch==' '){
           if(a<0 || a>=n || a<prev || a==i){
              printf("INVALID INPUT\n");
              return 0;
           }
           insert(&ar[i],a);
           prev=a;
           a=0;
        }
        else if(ch!='\n'){
           printf("INVALID INPUT\n");
           return 0;
        }
        scanf("%c",&ch);
       }
       if(j>0){
          if(a<0 || a>=n || a<prev || a==i){
             printf("INVALID INPUT\n");
             return 0;
          }
          insert(&ar[i],a);
          prev=a;
//          printf("%d ",a);
//          print(&ar[i]);
           a=0;j++;     
        }
    }
/*    for(i=0;i<n;i++){
       print_list(&ar[i]);
       printf("\n");
    }*/
    scanf("%s",str);
    while(strcmp(str,"stp")!=0){
       if(strcmp(str,"bfs")==0){
          if(scanf("%d%d",&x,&y)!=2 || x<0 || x>=n || y<0 || y>=n){
              printf("INVALID INPUT\n");
              return 0;
          }
          bfs(ar,x,y,n);
          printf("\n");
       }
       else if(strcmp(str,"dfs")==0){
          if(scanf("%d%d",&x,&y)!=2 || x<0 || x>=n || y<0 || y>=n){
              printf("INVALID INPUT\n");
              return 0;
          }
          dfs(ar,x,y,n);
          printf("\n");
       }
       else{
          printf("INVALID INPUT\n");
          return 0;
       }
       scanf("%s",str);
    }
}
