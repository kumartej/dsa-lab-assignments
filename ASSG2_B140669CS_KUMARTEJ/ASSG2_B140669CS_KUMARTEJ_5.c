#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define ll long long int
int main(){
	int n,i,j,k;
	if(!(scanf("%d",&n)) || n<=0){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	ll ar[n];
	for(i=0;i<n;i++){
	   if(!(scanf("%lld",&ar[i])) || ar[i]<0 || ar[i]>2147483648){
	     printf("INVALID INPUT\n");
	     return 0;
	   }
	   
	}
	for(i=1;i<n;i++){
	  k=ar[i];
	  for(j=i-1;j>=0 && k<ar[j];j--)
	     ar[j+1]=ar[j];
	  ar[j+1]=k;
	}
	for(i=0;i<n;i++)
	   printf("%lld  ",ar[i]);
	printf("\n");
}
