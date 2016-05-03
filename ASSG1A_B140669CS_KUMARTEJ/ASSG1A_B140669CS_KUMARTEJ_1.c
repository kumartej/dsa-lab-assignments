#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long int
int main(){
	ll ar[100][100],temp;
	int i,j,n,valid=1;
	printf("INPUT\n   Enter the order of matrix:\n");
	if(!(scanf("%d",&n))){
	    printf("Invalid Input\n");
	    return 0;
	}
	if(n<=0 || n>100){
	    printf("Invalid Input\n");
	    return 0;
	}
	printf("  Enter the matrix\n");
	for(i=0;i<n;i++){
	   for(j=0;j<n;j++){
	      if(!(scanf("%lld",&ar[i][j])) || ar[i][j]<0 || ar[i][j]>2147483648){
	      valid=0;
	      }
	    }
	}
	if(valid==0){
	printf("Invalid Input\n");
	return 0;
	}
	for(i=0;i<n;i++)
	  for(j=i;j<n;j++){
	    temp=ar[i][j];
	    ar[i][j]=ar[j][i];
	    ar[j][i]=temp;
	  }
	for(i=0;i<n/2;i++)
	   for(j=0;j<n;j++){
	      temp=ar[j][i];
	      ar[j][i]=ar[j][n-i-1];
	      ar[j][n-i-1]=temp;
	   }
	printf("OUTPUT:\n");
	for(i=0;i<n;i++){
	   for(j=0;j<n;j++)
	     printf("%lld ",ar[i][j]);
	   printf("\n");
	}
	return 0;
}
