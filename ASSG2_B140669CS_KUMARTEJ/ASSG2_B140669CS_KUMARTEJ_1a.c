#include <stdio.h>
#include <limits.h>
#define ll long long int
int main(){
	ll n,valid=1;
	if(!(scanf("%lld",&n)) || n<=0){
	printf("INVALID INPUT\n");
	return 0;
	}
	ll k,i,j,ar[n],high=INT_MIN;
	for(i=0;i<n;i++){
	  if(!(scanf("%lld",&ar[i])))
	    valid=0;
	  else if(high>=ar[i]){
	    valid=0;
	  }
	  high=ar[i];
	}
	if(valid==0){
	  printf("INVALID INPUT\n");
	  return 0;
	}
	if(!(scanf("%lld",&k))){
	printf("INVALID INPUT\n");
	return 0;
	}
	ll l,m,h;
	l=0;h=n;
	while(l<=h){
	   m=(l+h)/2;
	   if(ar[m]==k){
	   printf("%lld\n",m+1);
	   return 0;}
	   else if(ar[m]<k)
	   l=m+1;
	   else
	    h=m-1;
	}
//	if(l>h)
	printf("NOT FOUND\n");
	return 0;
}
