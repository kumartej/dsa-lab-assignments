#include <stdio.h>
#include <limits.h>
#define ll long long int
int main(){
	ll n,m,i,j;
	if(!(scanf("%lld%lld",&n,&m)) || n<=0 || m<=0){
	  printf("INVALID INNPUT\n");
	  return 0;
	}
	ll ar[n][m+2],high=INT_MIN,low=INT_MAX;
	for(i=0;i<n;i++){
	 high=INT_MAX;low=INT_MIN;
	  for(j=0;j<m;j++){
	    if(!(scanf("%lld",&ar[i][j]))){
	       printf("INVALID INPUT\n");
	       return 0;
	    }
	    if(i==0 && j==0){
	      high=ar[i][j];low=ar[i][j];}
	    if(ar[i][j]>=high)
	    high=ar[i][j];
	    if(ar[i][j]<=low)
	    low=ar[i][j];
	  }
	  ar[i][m]=low;ar[i][m+1]=high;
		//printf("%lld  %lld\n",ar[i][m],ar[i][m+1]);
	}
	ll k;
	int check=0;
	char term;
	if(scanf("%lld%c",&k,&term) != 2 || term != '\n'){
	  printf("INVALID INPUT\n");
	  return 0;
	}
	for(i=0;i<n;i++){
	  if(k>=ar[i][m] && k<=ar[i][m+1]){
	     for(j=0;j<m;j++){
	       if(ar[i][j]==k){
	       printf("%lld  %lld\n",i+1,j+1);
	       check++;
	       }
	     }
	  }
	}
	if(check==0)
	printf("NOT FOUND\n");
	return 0;
}
