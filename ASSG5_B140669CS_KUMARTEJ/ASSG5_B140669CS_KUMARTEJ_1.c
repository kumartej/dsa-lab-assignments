#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long long int

struct disjoint_set{
	int data;
	struct disjoint_set *parent;
	int rank;
};

#define node struct disjoint_set

struct arra{
	node* ele;
};

#define array struct arra

node* makeset(int x){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->parent=temp;
	temp->rank=0;
	temp->data=x;
	return temp;
}

int i,j;

node* find(node* x){
    if(x!=NULL && x->parent!=x){
      i++;
      return find(x->parent);   
    }
    return x;
}

node* path_find(node* x){
    if(x!=NULL && x->parent!=x){
       i++;
       x->parent=find(x->parent);
       if(x->parent->rank<x->rank+1)
          x->parent->rank=x->rank+1;
       return x->parent;
    }
    return x;
}

node* union_rank_path(node* x,node* y){
    j=0;
    i=0;
    node *a,*b;
    a=path_find(x);j+=i;i=0;j++;
    b=path_find(y);j+=i;i=0;j++;
    if(a->data!=b->data){
       if(a->rank<b->rank){
          a->parent=b;return b;}
       else{
          b->parent=a;
          if(a->rank==b->rank)
            a->rank+=1;
          return a;
       }
    }
    return a;   
}

node* union_rank(node* x,node* y){
    j=0;
    i=0;
    node *a,*b;
    a=find(x);j+=i;i=0;j++;
    b=find(y);j+=i;i=0;j++;
    if(a->data!=b->data){
       if(a->rank<b->rank){
          a->parent=b;return b;}
       else{
          b->parent=a;
          if(a->rank==b->rank)
            a->rank+=1;
          return a;
       }
    }
    return a;   
}

node* union_no_rank_path(node *x,node *y){
    j=0;
    i=0;
    node *a,*b;
    a=path_find(x);j+=i;i=0;j++;
    b=path_find(y);j+=i;i=0;j++;
    if(a->data!=b->data)
       b->parent=a;
    return a;
}

node* union_no_rank(node *x,node *y){
    j=0;
    i=0;
    node *a,*b;
    a=find(x);j+=i;i=0;j++;
    b=find(y);j+=i;i=0;j++;
    if(a->data!=b->data)
       b->parent=a;
    return a;
}

int main(){
    char ch;
    array a1[10010],a2[10010],a3[10010],a4[10010];
    int cn=0;
    for(cn=0;cn<=10000;cn++){
       a1[cn].ele=NULL;a2[cn].ele=NULL;a3[cn].ele=NULL;a4[cn].ele=NULL;
    }
    int f1=0,f2=0,f3=0,f4=0,d,d2,g1,g2,g3,g4;
    scanf("%c",&ch);
//    scanf("%c",&ch);
    while(ch!='s'){
//    printf("%c\n",ch);
       if(ch=='m'){
         if(scanf("%d",&d)!=1 || d<0 || d>10000){
            printf("INVALID INPUT\n");
            return 0;
         }
         if(a1[d].ele==NULL){
            a1[d].ele=makeset(d);
            a2[d].ele=makeset(d);
            a3[d].ele=makeset(d);
            a4[d].ele=makeset(d);
            printf("%d\n",d);
         }
         else
           printf("PRESENT\n");
       }
       else if(ch=='f'){
         if(scanf("%d",&d)!=1 || d<0 || d>10000){
            printf("INVALID INPUT\n");
            return 0;
         }
         if(a1[d].ele!=NULL){
            i=0;
            g1=find(a1[d].ele)->data;f1=f1+i+1;i=0;
            g2=find(a2[d].ele)->data;f2=f2+i+1;i=0;
            g3=path_find(a3[d].ele)->data;f3=f3+i+1;i=0;
            g4=path_find(a4[d].ele)->data;f4=f4+i+1;i=0;
            printf("%d %d %d %d\n",g1,g2,g3,g4);
         }
         else
            printf("NOT FOUND\n");
       }
       else if(ch=='u'){
          if(scanf("%d%d",&d,&d2)!=2 || d<0 || d>10000 || d2<0 || d2>10000){
             printf("INVALID INPUT\n");
             return 0;
          } 
          if(a1[d].ele!=NULL && a1[d2].ele!=NULL){
            i=0;
            g1=union_no_rank(a1[d].ele,a1[d2].ele)->data;f1=f1+j;i=0;
            g2=union_rank(a2[d].ele,a2[d2].ele)->data;f2=f2+j;i=0;
            g3=union_no_rank_path(a3[d].ele,a3[d2].ele)->data;f3=f3+j;i=0;
            g4=union_rank_path(a4[d].ele,a4[d2].ele)->data;f4=f4+j;i=0;
            printf("%d %d %d %d\n",g1,g2,g3,g4);
         }
         else
            printf("ERROR\n");
       }
       else{
         printf("INVALID INPUT\n");
         return 0;
       }
       scanf("%c",&ch);
       scanf("%c",&ch);
    }
    printf("%d %d %d %d\n",f1,f2,f3,f4);
}
