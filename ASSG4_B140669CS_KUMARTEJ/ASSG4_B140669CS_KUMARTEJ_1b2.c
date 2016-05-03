#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long long int
int c;
struct keydata{
	int *key;
};
#define data struct keydata

#define hashar struct array

int hash_function(int key,int probe){
	if(key>=0)
	return (key+probe*probe)%c;
	return (c+(key+probe*probe)%c)%c;
}

data* intialise(int n){
	data* temp;
	int i;
	temp=(data *)malloc(n*sizeof(data));
	for(i=0;i<n;i++)
	   temp[i].key=NULL;	
	return temp;
}

int* intkey(int k){
	int* a;
	a=(int*)malloc(sizeof(int));
	a[0]=k;
	return a;
}

void print_ar(data* ar){
	int i;
	for(i=0;i<c;i++){
	   if(ar[i].key!=NULL)
	     printf("%d-%d",i,*ar[i].key);
	}
	return;
}

data* insert(data * h,int k){
	int hkey=hash_function(k,0),j=1;
	printf("%d ",hkey);
	while(j<c && h[hkey].key!=NULL){
	    hkey=hash_function(k,j);j++;
	    printf("%d ",hkey);
	}
	//printf("\n");
	if(h[hkey].key==NULL){
	    h[hkey].key=intkey(k);
	    printf("\n");
	    return h;
	}
	else 
	return NULL;
}

int* search(data* h,int k){
	int hkey=hash_function(k,0),j=1;
	printf("%d ",hkey);
	while(j<c && h[hkey].key!=NULL && *h[hkey].key!=k){
	    hkey=hash_function(k,j);j++;
	    printf("%d ",hkey);
	}
	if(h[hkey].key!=NULL && *h[hkey].key==k)
	    return h[hkey].key;
	else
	    return NULL;
}
int main(){
	if(scanf("%d",&c)!=1 || c<=0){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	data *h,*t;
	h=intialise(c);
	int i,n,a,*temp;
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	while(ch!='s'){
	   if(ch=='i'){
	      if(scanf("%d",&a)!=1){
	         printf("INVALID INPUT\n");
	         return 0;
	      }
	      t=insert(h,a);
	   if(t==NULL)
	      printf("CANNOT INSERT\n");
	   else
	      h=t;
	      //print_ar(h);
	   }
	   else if(ch=='f'){
	      if(scanf("%d",&a)!=1){
	         printf("INVALID INPUT\n");
	         return 0;
	      }
	      temp=search(h,a);
	   if(temp==NULL)
	      printf("NOT FOUND\n");
	   else
	      printf("FOUND\n");
	   }
	   else{
	      printf("INVALID INPUT\n");
	      return 0;
	   }
	   scanf("%c",&ch);
	   scanf("%c",&ch);
	}
}
