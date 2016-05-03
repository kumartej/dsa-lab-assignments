#include <stdio.h>
#include <limits.h>
#define ll long long int
ll bsearch(ll l,ll h,ll * a,ll k){
	ll m;
	if(l>h)
	return -1;
	   m=(l+h)/2;
	   if(a[m]==k)
	   return m;
	   else if(a[m]<k)
	   bsearch(m+1,h,a,k);
	   else
	    bsearch(l,m-1,a,k);
}
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
	ll l;
	l=bsearch(0,n,ar,k);
	if(l==-1)
	printf("NOT FOUND\n");
	else
	printf("%lld\n",l+1);
	return 0;
}
