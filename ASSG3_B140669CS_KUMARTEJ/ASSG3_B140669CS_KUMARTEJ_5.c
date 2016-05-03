#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define maxsize 10000
#define ll long long int
int maxsize=10000;
struct elementdata{
	int e;
	int pt;
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
/*void heapify(ll *ar,ll i){
	ll min=i;
	if(2*i+1<heapsize){
	  if(ar[2*i+1]<ar[i]){
	    min=2*i+1;}
	  if(2*i+2<heapsize){
	     if(ar[2*i+2]<ar[min])
	       min=2*i+2;
	    }
	  if(min!=i){
	     swap(&ar[i],&ar[min]);
	     heapify(ar,min);
	  }
	}
}*/

void heapify(pque *pq,int i){
	int min=i;
	if(2*i<pq->size){
	  if(pq->que[2*i].pt<pq->que[i].pt)
	    min=2*i;
	  if(2*i+1<pq->size){
		if(pq->que[2*i+1].pt<pq->que[min].pt)
		  min=2*i+1;
	   }
	  if(min!=i){
		swap(&pq->que[i],&pq->que[min]);
		heapify(pq,min);
	   }
	}
}

int search(pque *pq,int ele,int newpr){
	if(pq->size==0)
	  return -1;
	int i=0;
	for(i=1;i<=pq->size;i++)
	if(pq->que[i].e==ele && pq->que[i].pt>=newpr)
	  return i;
	return -1;
}

int search_priority(pque *pq,int pr){
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

void insert(pque *pq,int ele,int pr){
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
		printf("%d ",pq->que[i].e);
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

void decrease_priority(pque *pq, int elem, int newpr){
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

int main(){
	ll c,d;
	int a,b;
	pque* pq;
	pq=intpque();
	char ch;
	//scanf("%c",&ch);
	scanf("%c",&ch);
	//ch='a';
	while(ch!='s'){
	  //printf("%c\n",ch);
	    if(ch=='a'){
	       if(scanf("%lld%lld",&c,&d)!=2 || c<0 || d<=0 || c>pow(2,30) || d>pow(2,30)){
		   printf("INVALID INPUT\n");
		   return 0;
		}
		a=(int)c;b=(int)d;
		if(search_priority(pq,b)==-1)
	       insert(pq,a,b);
		else{
		    printf("INVALID INPUT\n");
		    return 0;
		}
	    }
	    else if(ch=='e'){
	    	data *temp;
		temp=extract_min(pq);
		if(temp==NULL)
		printf("EMPTY\n");
		else
		printf("%d (%d)\n",temp->e,temp->pt);
	    }
	    else if(ch=='g'){
	    	data *temp;
		temp=get_min(pq);
		if(temp==NULL)
		printf("EMPTY\n");
		else
		printf("%d (%d)\n",temp->e,temp->pt);
	    }
	    else if(ch=='d'){
	        if(scanf("%lld%lld",&c,&d)!=2 || c<0 || d<=0 || c>pow(2,30) || d>pow(2,30)){
		   printf("INVALID INPUT\n");
		   return 0;
		}
		a=(int)c;b=(int)d;
		if(search_priority(pq,b)==-1)
	       decrease_priority(pq,a,b);
		else{
		    printf("INVALID INPUT\n");
		    return 0;
		}
	    }
	    else if(ch!='s'){
	      printf("INVALID INPUT\n");
	      return 0;
	    }
	      scanf("%c",&ch);
	      scanf("%c",&ch);
	}
return 0;
}
