#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define ll long long int
int main(){
	ll n,k,j=INT_MIN,i;
	if(!(scanf("%lld",&n)) || n<2){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	ll num[n];
	for(i=0;i<n;i++){
	   if(!(scanf("%lld",&num[i])) || num[i]<j){
	       printf("INVALID INPUT\n");
	       return 0;
	   }
	   j=num[i];
	}
	if(!(scanf("%lld",&k))){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	i=0;j=n-1;
	while(i<j){
	   if(num[i]+num[j]==k){
	     printf("%lld  %lld\n",num[i],num[j]);
	     return 0;
	   }
	   else if(num[i]+num[j]<k)
	     i++;
	   else
	     j--;
	}
	printf("No two elements sum up to %lld\n",k);
	return 0;
}
