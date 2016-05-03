#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

//#define INT_MAX 100000

struct node{
	int vt;
	float edge;
	struct node *next;
};

#define list struct node

struct adjacency_list{
	struct node *head;
	struct node *tail;
};

#define array struct adjacency_list

void insert_vertex(array *ar,int vertex){
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

void insert_edge(array *ar,float edg,int j){
    int i=0;
    list *temp;
    temp=ar->head;
    for(i=0;i<j;i++)
       temp=temp->next;
     temp->edge=edg;
    return;
}

void print_list(array *ar){
    list *temp;
    temp=ar->head;
    while(temp!=NULL){
       printf("%g ",temp->edge);
       temp=temp->next;
    }
}

void print(float *ar,int n){
    int i=0;
    for(i=0;i<n;i++)
      if(ar[i]==INT_MAX)
        printf("INF ");
      else
         printf("%g ",ar[i]);
     printf("\n");
     return;
}


float d[1000][1000];

void print2darray(int n){
    int i,j;
    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
         if(d[i][j]==INT_MAX)
            printf("INF ");
         else
            printf("%g ",d[i][j]);
       }
       printf("\n");
    }
}

float min(float x, float y)
{
  return (x < y) ? x : y;
}

void distanceset(array *ar,int n){
	int i,j,k;
	list *temp;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++){
	    if(i==j)
	     d[i][j]=0;
	    else
	     d[i][j]=(float)INT_MAX;
	  }
	for(i=0;i<n;i++){
	  temp=ar[i].head;
	  while(temp!=NULL){
	     d[i][temp->vt]=temp->edge;
	     temp=temp->next;
	  }
	}
//	print2darray(n);
	for(i=0;i<n;i++){
	   for(j=0;j<n;j++){
	      for(k=0;k<n;k++){
	             if(d[j][i]!=INT_MAX && d[i][k]!=INT_MAX)
	             d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	      }
	   }
	}
	print2darray(n);	
}
array ar[1010];
int main(){
	
	int n,i,j,src,dest,a=0,k,negat,intial;char num[100];int prev;
	char ch,str[10];
	if(scanf("%d",&n)!=1 || n<=0 || n>1000){
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
       prev=INT_MIN;
       scanf("%c",&ch);
       while(ch!='\n'){
          j++;
          if(ch>=48 && ch<=57)
               a=a*10+ch-48;
           else if(ch==' '){
               if(a<0 || a>=n || a<=prev){
                  printf("INVALID INPUT\n");
                  return 0;
               }
               insert_vertex(&ar[i],a);
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
          if(a<0 || a>=n || a<=prev){
             printf("INVALID INPUT\n");
             return 0;
          }
          insert_vertex(&ar[i],a);
		    prev=a;
           a=0;j++;     
        }
    }
//    	printf("hello\n");
/*    for(i=0;i<n;i++){
       j=0;k=0;negat=0;intial=0;
       scanf("%c",&ch);
       while(ch!='\n'){
          j++;
          if(ch=='-' && intial==0){
              negat=1;
          }
          else if(ch>=48 && ch<=57)
              a=a*10+ch-48;
          else if(ch==' '){
              if(negat==1)
                 a=-1*a;
              insert_edge(&ar[i],a,k);
              intial=-1;
              negat=0;
//           printf("%d ",a);
              a=0;k++;
          }
          else if(ch!='\n'){
              printf("INVALID INPUT\n");
              return 0;
          }
          intial++;
          scanf("%c",&ch);
       }
       if(j>0){
          if(negat==1)
                 a=-1*a;
          insert_edge(&ar[i],a,k);
          intial=-1;
          insert_edge(&ar[i],a,k);
//          printf("%d ",a);
//          print(&ar[i]);
           a=0;j++;     
        }
    }*/
    
    for(i=0;i<n;i++){
    j=0;k=0;
       scanf("%c",&ch);
       while(ch!='\n'){
          //j++;
          if(ch=='.' || ch=='-')
            num[j++]=ch;
           else if(ch>=48 && ch<=57)
             num[j++]=ch;
           else if(ch==' '){
             num[j]='\n';
//             printf("%d ",k);
             if(atof(num)<-10000 || atof(num)>10000){
                printf("INVALID INPUT\n");
                return 0;
             }
             insert_edge(&ar[i],atof(num),k);
             k++;j=0;
           }
           else if(ch!='\n'){
             printf("INVALID INPUT\n");
             return 0;
           }
           scanf("%c",&ch);
       }
       if(j>0){
          num[j]='\n';
          if(atof(num)<-10000 || atof(num)>10000){
                printf("INVALID INPUT\n");
                return 0;
          }
          insert_edge(&ar[i],atof(num),k);
          j++;
       }
    }
    
/*    for(i=0;i<n;i++){
       print_list(&ar[i]);
       printf("\n");}*/
//    printf("aa%d\n",ar[0].head->vt);
    distanceset(ar,n);
}
