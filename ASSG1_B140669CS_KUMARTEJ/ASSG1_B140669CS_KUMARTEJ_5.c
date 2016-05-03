#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float add(float a,float b){return a+b;}
float sub(float a,float b){
return a-b;}
float mul(float a,float b){
return a*b;}
float divi(float a,float b){
return a/b;}
int main(){
	int ch,q=1;
	char str[20];
	float a,b;
	float (*p)(float,float);
	printf("INPUT:\n  Enter the numbers: ");
	if(scanf("%f%f",&a,&b)!=2){
	    printf("INVALID INPUT\n");
		return 0;
	}
	while(q!=0){
	   printf("Menu:\n  1.Addition\n  2.Subtraction\n  3.Multiplication\n  4.Division\n  5.Exit\nEnter the choice:" );
	   scanf("%d",&ch);
	   if(ch==1){
	   p=&add;
	   printf("%g\n",p(a,b));
	   }
	   else if(ch==2){
	   p=&sub;
	   printf("%g\n",p(a,b));
	   }
	   else if(ch==3){
	   p=&mul;
	   printf("%g\n",p(a,b));}
	   else if(ch==4){
	   p=&divi;
	   printf("%g\n",p(a,b));
	   }
	   else if(ch==5)
	       q=0;
	   else
	   printf("invalid choice\n");
	}
}
