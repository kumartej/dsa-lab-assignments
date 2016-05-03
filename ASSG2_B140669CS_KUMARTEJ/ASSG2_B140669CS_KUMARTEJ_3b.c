#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define ll long long int
struct student{
	char roll[10];
	int mark;
	char name[20];
	
};
#define std struct student
int getascii(char ch){
	if(ch>=65 && ch<=90)
		return ch-55;
	if(ch>=97 && ch<=122)
		return ch-61;
	if(ch>=48 && ch<=57)
		return ch-48;
	return -1;
}
void copy(std *s1,std *s2){
	std temp;
	temp=*s2;
	*s1=temp;
}
void charsort(std *ls,int n,int d){
	std outls[n];
	int ar[62],i,j,asc;
	for(i=0;i<62;i++)
		ar[i]=0;
	for(i=0;i<n;i++){
	   asc=getascii(ls[i].roll[d-1]);
	   ar[asc]++;
	}
	for(i=1;i<62;i++){
	   ar[i]+=ar[i-1];
	   
	}
	int b;
	for(i=n-1;i>=0;i--){
	   asc=getascii(ls[i].roll[d-1]);
	   b=ar[asc]-1;
	   outls[b]=ls[i];
	   ar[asc]--;
	}
	for(i=0;i<n;i++){
	ls[i]=outls[i];
	}
}
void radixsort(std * ls,int n){
	int i,j;
	for(i=9;i>0;i--)
	  charsort(ls,n,i);
}
int main(){
	int n;
	if(!(scanf("%d",&n)) || n<=0){
	  printf("INVALID INPUT\n");
	  return 0;
	}
	std list[10];
	char rl[9],nm[20];
	int i,j,mrk;
	for(i=0;i<n;i++){
	  scanf("%s%s%d",rl,nm,&mrk);
	  if(mrk<0 || mrk>100 || strlen(rl)!=9){
	    printf("INVALID INPUT\n");
	    return 0;
	  }
	  strcpy(list[i].roll,rl);
	  strcpy(list[i].name,nm);
	  list[i].mark=mrk;
	  }
	for(i=0;i<n;i++){
	   for(j=0;j<9;j++){
		if(j==0 || j>=7){
		   if(list[i].roll[j]<65 || list[i].roll[j]>90){
			printf("INVALID INPUT\n");
			return 0;
			}
		}
		else{
			if(list[i].roll[j]<48 || list[i].roll[j]>57){
			printf("INVALID INPUT\n");
			return 0;
			}
		}
	   }
	}
	radixsort(list,n);
	for(i=0;i<n;i++)
	  printf("%s  %s  %d\n",list[i].roll,list[i].name,list[i].mark);
}
