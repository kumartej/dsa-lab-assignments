#include <stdio.h>
#include <stdlib.h>
#define ll long long int
ll ar[100][100];
void spiral(int a,int b);
void trans(int a,int b){
	int i,j,temp;
	for(i=0;i<a;i++)
	  for(j=i;j<b;j++){
	    temp=ar[i][j];
	    ar[i][j]=ar[j][i];
	    ar[j][i]=temp;
	  }
	if(a>b){
	for(i=b;i<a;i++)
	   for(j=0;j<b;j++)
		ar[j][i]=ar[i][j];
	}
	return;
}

int main(){
	int n,m,i,j,g=1,valid=1;
	char ch,a;
	printf("Enter the order of matrix\n");
	if(scanf("%d%d",&n,&m)!=2){
	printf("INVALID INPUT\n");
	return 0;}
	else if(n<=0 || n>100 || m<=0 || m>100){
	printf("INVALID INPUT\n");
	return 0;}
	else{
	printf("Enter the elements of matrix\n");
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	     if(!(scanf("%lld",&ar[i][j])) || ar[i][j]<0 || ar[i][j]>2147483648){
	         valid=0; 
	     }
	if(valid==0){
	printf("INVALID INPUT\n");
	return 0;}
	while(g!=0){
	  printf("Menu:\na. Clockwise spiral-order traversal\nb. Anti-clockwise spiral-order traversal\nc. Exit\n");
	  scanf("%c",&a);
	  scanf("%c",&ch);
	  if(ch=='a')
	     spiral(n-1,m-1);
	  else if(ch=='b'){
	     trans(n,m);
	     spiral(m-1,n-1);
	     trans(m,n);
	  }
	  else if(ch=='c')
	     g=0;
	  else
	    printf("Invalid Input\n");
	}
}
}
void spiral(int a,int b){
	int u=0,l=0,i;
	char m='r';
	while(u<=a && l<=b){
	   if(m=='r'){
	     for(i=l;i<=b;i++)
	     printf("%lld ",ar[u][i]);
	     u++;
	     m='d';}
	   else if(m=='d'){
	     for(i=u;i<=a;i++)
	     printf("%lld ",ar[i][b]);
	     b--;
	     m='l';
	   }
	   else if(m=='l'){
	     for(i=b;i>=l;i--)
	       printf("%lld ",ar[a][i]);
	     a--;
	     m='u';
	   }
	   else if(m=='u'){
	      for(i=a;i>=u;i--)
	        printf("%lld ",ar[i][l]);
	      l++;
	      m='r';
	   }
	}
	printf("\n");
	return;
}
