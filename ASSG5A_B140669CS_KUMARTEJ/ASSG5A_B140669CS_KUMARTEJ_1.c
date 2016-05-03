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
       printf("%d ",temp->vt);
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

/*priority queue */

int maxsize=10000;
struct elementdata{
	int e;
	float pt;
};

#define data struct elementdata
struct priorityque{
	data * que;
	int size;
};

#define pque struct priorityque
void swap(data *ar1,data *ar2){
	data temp;
	temp=*ar1;
	*ar1=*ar2;
	*ar2=temp;
}

void heapify(pque *pq,int i){
	int min=i;
	if(2*i<=pq->size){
	  if(pq->que[2*i].pt<pq->que[i].pt)
	    min=2*i;
	  if(2*i+1<=pq->size){
		if(pq->que[2*i+1].pt<pq->que[min].pt)
		  min=2*i+1;
	   }
	  if(min!=i){
		swap(&pq->que[i],&pq->que[min]);
		heapify(pq,min);
	   }
	}
}

int search(pque *pq,int ele,float newpr){
	if(pq->size==0)
	  return -1;
	int i=0;
	for(i=1;i<=pq->size;i++)
	if(pq->que[i].e==ele && pq->que[i].pt>=newpr)
	  return i;
	return -1;
}

int search_priority(pque *pq,float pr){
	if(pq->size==0)
	  return -1;
	int i=0;
	for(i=1;i<=pq->size;i++)
	if(pq->que[i].pt==pr)
	  return 1;
	return -1;
}

pque* intpque(){
	pque * temp;
	temp=(pque *)malloc(sizeof(pque));
	temp->que=(data *)malloc(maxsize*sizeof(data));
	temp->size=0;
	return temp;
}

void insert(pque *pq,int ele,float pr){
	if(pq->size>=maxsize){
	  maxsize+=100;
	  pq->que=(data *)realloc(pq->que,maxsize*sizeof(data));
	}
	if(pq->size==0){
	   pq->que[1].e=ele;
	   pq->que[1].pt=pr;
	   pq->size++;
	   return;
	}
	pq->size++;
	int i=pq->size;
	pq->que[pq->size].e=ele;
	pq->que[pq->size].pt=pr;
	while(i>1 && pq->que[i/2].pt>pq->que[i].pt){
		swap(&pq->que[i/2],&pq->que[i]);
		i=i/2;
	}
	return;
}
void printque(pque *pq){
	int i=1;
	if(pq->size==0){
	  printf("EMPTY\n");
	  return;
	}
	while(i<=pq->size){
		printf("%g ",pq->que[i].pt);
		i++;
	}
	printf("\n");
	return;
}

data* get_min(pque* pq){
	if(pq->size==0)
	  return NULL;
	return &pq->que[1];
}

data* extract_min(pque * pq){
	if(pq->size==0)
	  return NULL;
	data *temp;
	temp=(data*)malloc(sizeof(data));
	temp->e=pq->que[1].e;
	temp->pt=pq->que[1].pt;
	pq->que[1]=pq->que[pq->size];
	pq->size--;
	heapify(pq,1);
	return temp;
}

void decrease_priority(pque *pq, int elem, float newpr){
	int pos;
	pos=search(pq,elem,newpr);
	if(pos==-1){
	   printf("INVALID INPUT\n");
	   return;
	}
	if(pq->que[pos].pt<=newpr){
	   printf("INVALID INPUT\n");
	   return;
	}
	pq->que[pos].pt=newpr;
	while(pos>1 && pq->que[pos/2].pt>pq->que[pos].pt){
	   swap(&pq->que[pos/2],&pq->que[pos]);
	   pos/=2;
	}
	return;
}

/*end of priority queue */
float d[10010];
void dis(array *ar,int src,int n){
	int min,ver,i,j=0;
	list *p,*q;
	pque *pq;
	pq=intpque();
	for(i=0;i<n;i++){
	   d[i]=(float)INT_MAX;
	   pq->que[i+1].e=i;
	   pq->que[i+1].pt=(float)INT_MAX;
	}
	pq->size=n;
	d[src]=0;
//		printque(pq);
	decrease_priority(pq,src,d[src]);
	while(pq->size!=0){
	    ver=extract_min(pq)->e;
	    p=ar[ver].head;
	    while(p!=NULL){
	    	if(d[ver]!=INT_MAX && d[ver]+p->edge<d[p->vt]){
	    	   d[p->vt]=d[ver]+p->edge;
	    	   decrease_priority(pq,p->vt,d[p->vt]);
	    	}
	    	p=p->next;
	    }
	}
	print(d,n);
	return;
}

void betnodes(array *ar,int src,int dest,int n){
	int min,ver,i,j=0;
	list *p,*q;
	pque *pq;
	pq=intpque();
	for(i=0;i<n;i++){
	   d[i]=INT_MAX;
	   pq->que[i+1].e=i;
	   pq->que[i+1].pt=INT_MAX;
	}
	pq->size=n;
	d[src]=0;
	decrease_priority(pq,src,d[src]);
	while(pq->size!=0){
	    ver=extract_min(pq)->e;
	    p=ar[ver].head;
	    while(p!=NULL){
	    	if(d[ver]!=INT_MAX && d[ver]+p->edge<d[p->vt]){
	    	   d[p->vt]=d[ver]+p->edge;
	    	   decrease_priority(pq,p->vt,d[p->vt]);
	    	}
	    	p=p->next;
	    }
	}
	if(d[dest]==INT_MAX)
	    printf("UNREACHABLE\n");
	else
	    printf("%g\n",d[dest]);
	return;
}
	array ar[1010];
int main(){

	int n,i,j,src,dest,a=0,k,prev;
	char ch,str[10],num[1000];
	float fn,div=10,dec=0;
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
       j=0;prev=INT_MIN;
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
//           printf("%d ",a);
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
//          printf("%d ",a);
//          print(&ar[i]);
           a=0;j++;     
        }
    }
//    	printf("hello\n");
 /* for(i=0;i<n;i++){
      fn=0;div=10;dec=0;
       j=0;k=0;
       scanf("%c",&ch);
       while(ch!='\n'){
          j++;
        if(ch=='.')
             dec=1;
        else if(ch>=48 && ch<=57 && dec==0)
           fn=fn*10+ch-48;
        else if(ch>=48 && ch<=57 && dec==1){
           fn=fn*10+ch-48;
           div*=10;
        }
        else if(ch==' '){
           if(fn/(div/10)<0 || fn/(div/10)>10000){
              printf("INVALID INPUT\n");
              return 0;
           }
           insert_edge(&ar[i],fn/(div/10),k);
           fn=0;k++;div=10;dec=0;
        }
        else if(ch!='\n'){
           printf("INVALID INPUT\n");
           return 0;
        }
        scanf("%c",&ch);
       }
       if(j>0){
          if(fn/(div/10)<0 || fn(div/10)>10000){
             printf("INVALID INPUT\n");
             return 0;
          }
          insert_edge(&ar[i],fn/(div/10),k);
        //  printf("%g ",fn/(div/10));
           a=0;j++;     
        }
    }*/
    for(i=0;i<n;i++){
    j=0;k=0;
       scanf("%c",&ch);
       while(ch!='\n'){
          //j++;
          if(ch=='.')
            num[j++]=ch;
           else if(ch>=48 && ch<=57)
             num[j++]=ch;
           else if(ch==' '){
             num[j]='\n';
//             printf("%d ",k);
             if(atof(num)<0 || atof(num)>10000){
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
          if(atof(num)<0 || atof(num)>10000){
                printf("INVALID INPUT\n");
                return 0;
          }
          insert_edge(&ar[i],atof(num),k);
          j++;
       }
    }
    
 /*   for(i=0;i<n;i++){
       print_list(&ar[i]);
       printf("\n");}/*
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
