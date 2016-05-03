#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll long long int
int main(){
	int n,i,j,cm=1,t,cmp;
	char c,ch;
	printf("enter the order of matrix\n");
	scanf("%d",&n);
	int ar[105][105];
	double res[105][105];
	memset(ar,0,n+1);
	if(n<=0 || n>100){
	printf("INVALID ORDER OF MATRIX\n");
	return 0;
	}
	printf("Enter the matrix\n");
	for(i=1;i<=n;i++){
	  for(j=1;j<=n;j++){
	    t=scanf("%d%c",&ar[i][j],&ch);
		if(t!=2)
		cm=0;
	  }}
	if(n==1){
	printf("OUTPUT:\n%d\n",ar[1][1]);
	return 0;
	}
	if(cm==0){
	printf("INVALID INPUT\n");
	return 0;
	}
	printf("OUTPUT:\n");
	for(i=1;i<=n;i++){
	  for(j=1;j<=n;j++){
	    res[i][j]=ar[i][j]+ar[i-1][j-1]+ar[i][j-1]+ar[i+1][j-1]+ar[i+1][j]+ar[i-1][j]+ar[i-1][j+1]+ar[i][j+1]+ar[i+1][j+1];
	    if((i==1 && j==1) || (i==n && j==n) || (i==1 && j==n) || (i==n && j==1))
	      res[i][j]=res[i][j]/4.0;
	    else if(i==1 || j==1 || i==n || j==n)
	      res[i][j]=res[i][j]/6.0;
	    else
	      res[i][j]=res[i][j]/9.0;
	    printf("%d ",(int)round(res[i][j]));
	  }
	  printf("\n");
	}
	return 0;
}
