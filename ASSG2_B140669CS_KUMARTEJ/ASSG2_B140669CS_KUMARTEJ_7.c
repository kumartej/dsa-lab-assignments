#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#define ll long long int

ll heapsize;
void swap(ll *ar1,ll *ar2){
	ll temp;
	temp=*ar1;
	*ar1=*ar2;
	*ar2=temp;
}
void heapify(ll *ar,ll i){
	ll max=i;
	if(2*i+1<heapsize){
	  if(ar[2*i+1]>ar[i]){
	    max=2*i+1;}
	  if(2*i+2<heapsize){
	     if(ar[2*i+2]>ar[max])
	       max=2*i+2;
	    }
	  if(max!=i){
	     swap(&ar[i],&ar[max]);
	     heapify(ar,max);
	  }
	}
}
void buildheap(ll *ar){
	ll i;
	for(i=(heapsize-1)/2;i>=0;i--)
	   heapify(ar,i);
}

void heapsort(ll *ar){
	buildheap(ar);
	int i=0;
	for(;heapsize>0;){
	   swap(&ar[heapsize-1],&ar[0]);
	   heapsize--;
	   heapify(ar,0);
	}
}
int main(){
	ll n,i;
	if(!scanf("%lld",&n) || n<=0){
	  printf("INVALID INPUT\n");
	  return 0;
	}
	heapsize=n;
	ll ar[n];
	for(i=0;i<n;i++){
	  if(!(scanf("%lld",&ar[i]))){
	    printf("INVALID CHOICE\n");
	    return 0;
	  }
	}
	heapsort(ar);
	for(i=0;i<n;i++){
	  printf("%lld ",ar[i]);
	}
	printf("\n");
}
