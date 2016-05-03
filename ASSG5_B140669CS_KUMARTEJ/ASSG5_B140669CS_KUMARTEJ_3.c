#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

//#define INT_MAX 100000

struct node{
	int vt;
	int edge;
	struct node *next;
};

#define list struct node

struct adjacency_list{
	struct node *head;
	struct node *tail;
};

#define array struct adjacency_list

void insert(array *ar,int vertex){
    list *temp;
    temp=(list*)malloc(sizeof(list));
    temp->vt=vertex;
    temp->edge=0;
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

void insert_edge(array *ar,int edg,int j){
    int i=0;
    list *temp;
    temp=ar->head;
    for(i=0;i<j;i++){
       temp=temp->next;
    }   
     temp->edge=edg;
    return;
}

void print_list(array *ar){
    list *temp;
    temp=ar->head;
    while(temp!=NULL){
       printf("%d ",temp->edge);
       temp=temp->next;
    }
}
void print(int *ar,int n){
    int i=0;
    for(i=0;i<n;i++)
      if(ar[i]==INT_MAX)
        printf("INF ");
      else
         printf("%d ",ar[i]);
     printf("\n");
     return;
}

int check(int *ar,int n){
    int i=0;
    for(i=0;i<n;i++)
      if(ar[i]==0)
        return 0;
    return 1;
}
void dis(array *ar,int src,int n){
	int v[n],d[n],min,ver,i,j=0;
	list *p,*q;
	for(i=0;i<n;i++){
	   v[i]=0;
	   d[i]=INT_MAX;
	}
	d[src]=0;
	while(!check(v,n)){
	   min=INT_MAX;
	   for(i=0;i<n;i++){
	      if(d[i]<min && v[i]==0){
	        min=d[i];ver=i;
	      }
	   }
	   if(min==INT_MAX)
	     break;
	   v[ver]=1;
	   p=ar[ver].head;
	   while(p!=NULL){
	      if(min+p->edge<d[p->vt])
	        d[p->vt]=min+p->edge;
	        p=p->next;
	   }
	}
	print(d,n);
	return;
}

void betnodes(array *ar,int src,int dest,int n){
    int v[n],d[n],min,ver,i,j=0;
	list *p,*q;
	for(i=0;i<n;i++){
	   v[i]=0;
	   d[i]=INT_MAX;
	}
	d[src]=0;
	while(!check(v,n)){
	   min=INT_MAX;
	   for(i=0;i<n;i++){
	      if(d[i]<min && v[i]==0){
	        min=d[i];ver=i;}}
	   if(ver==dest){
	      printf("%d\n",d[ver]);
	      return;
	   }
	   if(min==INT_MAX)
	     break;
	   v[ver]=1;
	   p=ar[ver].head;
	   while(p!=NULL){
	      if(min+p->edge<d[p->vt])
	        d[p->vt]=min+p->edge;
	        p=p->next;
	   }
	}
	printf("UNREACHABLE\n");
	return;
}

int main(){
	array ar[10010];
	int n,i,j,src,dest,a=0,k,prev=INT_MIN;
	char ch,str[10];
	if(scanf("%d",&n)!=1 || n<1 || n>1000){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	for(i=0;i<n;i++){
	   ar[i].head=NULL;
	   ar[i].tail=NULL;
	}
	//printf("hello\n");
	scanf("%c",&ch);
	
    for(i=0;i<n;i++){
       j=0;
       scanf("%c",&ch);
       prev=INT_MIN;
       while(ch!='\n'){
          j++;
          if(ch>=48 && ch<=57)
           a=a*10+ch-48;
        else if(ch==' '){
           if(a<0 || a>=n || a<prev){
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
          if(a<0 || a>=n || a<prev){
              printf("INVALID INPUT\n");
              return 0;
           }
          insert(&ar[i],a);
//          printf("%d ",a);
//          print(&ar[i]);
           a=0;j++;     
        }
    }
//    	printf("hello\n");
    for(i=0;i<n;i++){
       j=0;k=0;
       scanf("%c",&ch);
       while(ch!='\n'){
          j++;
          if(ch>=48 && ch<=57)
           a=a*10+ch-48;
        else if(ch==' '){
           if(a<0 || a>10000){
              printf("INVALID INPUT\n");
              return 0;
           }
           insert_edge(&ar[i],a,k);
//           printf("%d ",a);
           a=0;k++;
        }
        else if(ch!='\n'){
           printf("INVALID INPUT\n");
           return 0;
        }
        scanf("%c",&ch);
       }
       if(j>0){
          if(a<0 || a>10000){
             printf("INVALID INPUT\n");
             return 0;
          }
          insert_edge(&ar[i],a,k);
//          printf("%d ",a);
//          print(&ar[i]);
           a=0;j++;     
        }
    }
    
/*    for(i=0;i<n;i++){
       print_list(&ar[i]);
       printf("\n");}
    printf("aa%d\n",ar[0].head->vt);*/
    scanf("%s",str);
    while(strcmp(str,"stop")!=0){
       if(strcmp(str,"apsp")==0){
          if(scanf("%d",&src)!=1 || src<0 || src>=n){
             printf("INVALID INPUT\n");
             return 0;
          }
          dis(ar,src,n);
       }
       else if(strcmp(str,"sssp")==0){
          if(scanf("%d%d",&src,&dest)!=2 || src<0 || src>=n || dest<0 || dest>=n){
             printf("INVALID INPUT\n");
             return 0;
          }
          betnodes(ar,src,dest,n);
       }
       else{
          printf("INVALID INPUT\n");
          return 0;
       }
      scanf("%s",str);
    }
}
