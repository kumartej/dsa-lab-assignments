#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define ll long long int
struct student{
	char roll[10];
	char name[20];
	int mark;
};
#define std struct student
void swap(std *,std *);
int getascii(char ch){
	if(ch>=65 && ch<=90)
		return ch-0;
	if(ch>=48 && ch<=57)
		return ch-0;
	return -1;
}
void quicksort(std *ls,int l,int h){
	if(l<h){
	  int a;
	  a=part(ls,l,h);
	  quicksort(ls,l,a);
	  quicksort(ls,a+1,h);
	  return;
	}
	else
	return;
}
int part(std *lst,int l,int h){
	int i,j,fix;
	fix=lst[l].mark;
	i=l-1;
	j=h+1;
	while(1){
	   do{
	      j=j-1;
	   }while(lst[j].mark<fix);
	   do{
	   i=i+1;
	   }while(lst[i].mark>fix);
	   if(i<j)
	   swap(&lst[i],&lst[j]);
	   else{
	     swap(&lst[l],&lst[j]);
	     return j;
	   }
	}
}
void swap(std *s1,std *s2){
	std  temp;
	temp=*s1;
	*s1=*s2;
	*s2=temp;
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
		if(getascii(list[i].roll[j])==-1){
		   printf("INVALID INPUT\n");
		   return 0;
		}
		if(j==0 || j>=7){
		   if(getascii(list[i].roll[j])<65 || getascii(list[i].roll[j])>90){
			printf("INVALID INPUT\n");
			return 0;
			}
		}
		else{
			if(getascii(list[i].roll[j])<48 || getascii(list[i].roll[j])>57){
			printf("INVALID INPUT\n");
			return 0;
			}
		}
	   }
	}
	  int q;
	   q=part(list,0,n-1);
	  quicksort(list,0,n-1);
	for(i=0;i<n;i++)
	  printf("%s  %s  %d\n",list[i].roll,list[i].name,list[i].mark);
}
