#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ll long long int
void swap(double *n1,double *n2){
	double temp;
	temp=*n1;
	*n1=*n2;
	*n2=temp;
}
int main(){
	ll n;
	if(!(scanf("%lld",&n)) || n<=0){
	  printf("INVALID INPUT\n");
	  return 0;
	}
	ll i,j;
	double ar[n];
	for(i=0;i<n;i++){
	   if(!(scanf("%lf",&ar[i]))){
	     printf("INVALID INPUT\n");
	     return 0;
	   }
	}
	for(i=0;i<n-1;i++){
	  for(j=i;j<n;j++){
	    if(ar[i]>ar[j])
	    swap(&ar[i],&ar[j]);
	  }
	  printf("%g ",ar[i]);
	}
	printf("%g\n",ar[i]);

}
