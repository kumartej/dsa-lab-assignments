#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
void swap(char *s1,char *s2){
	char temp[10];
	strcpy(temp,s1);
	strcpy(s1,s2);
	strcpy(s2,temp);
}
int main(){
	int n;
	if(!(scanf("%d",&n)) || n<=0){
	  printf("INVALID INPUT\n");
	  return 0;
	}
	char words[n][15],ch[15];
	int i,j,m;
	//scanf("%c",&ch);
	for(i=0;i<n;i++){
		scanf("%s",words[i]);
		if(strlen(words[i])>10){
		printf("INVALID INPUT\n");
		for(j=0;j<strlen(words[i]);j++){
		   if(words[i][j]<97 || words[i][j]>122){
			printf("INVALID INPUT\n");
			return 0;
		   }
		}
		return 0;}
	}
	for(i=0;i<n-1;i++){
	 m=i;
	   for(j=i+1;j<n;j++){
	       if(strcmp(words[i],words[j])>=0)
		swap(words[i],words[j]);
		//m=j;
	   }
		swap(words[i],words[m]);
	}
	for(i=0;i<n;i++)
	printf("%s ",words[i]);
	printf("\n");
}
