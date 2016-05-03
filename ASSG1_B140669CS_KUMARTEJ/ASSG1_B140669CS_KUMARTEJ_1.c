#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
int ar[26][2],n1=0,n2=0,i,t=1,p=1;
char c,d;
for(i=0;i<26;i++)
ar[i][0]=ar[i][1]=0;
printf("Enter str1: ");
scanf("%c",&c);
while(c!='\n'){
	if(!(c>=97 && c<=122) && c!=' ')
	t=0;
	else
	ar[c-97][0]=ar[c-97][0]+1;
	n1++;
	scanf("%c",&c);
}
printf("Enter str2: ");
scanf("%c",&d);
while(d!='\n'){
	if(!(d>=97 && d<=122) && d!=' ')
	p=0;
	else
	ar[d-97][1]=ar[d-97][1]+1;
	n2++;
	scanf("%c",&d);
}
if(n1>100000 || n2>100000){
	printf("data exceeds limits\n");
	return 0;}
if(n1<=0 || n2<=0){
	printf("string is empty\n");
	return 0;}
if(t!=1 || p!=1)
printf("INVALID INPUT\n");
else{
if(n1==n2){
	for(i=0;i<26;i++){
		if(ar[i][0]!=ar[i][1])
		break;
	}
	if(i==26)
	printf("YES\n");
else
	printf("NO\n");
}
else{
	printf("NO\n");
}
}
}
