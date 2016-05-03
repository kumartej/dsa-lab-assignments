#include <stdio.h>
#include <math.h>
#define ll long long int
int count(ll n){
	if (n<=0)
	return 0;
	if(n & 1)
	return 1+count(n>>1);
	else 
	return count(n>>1);
}
int main(){
	ll n,i;
	char c;
	printf("INPUT:\nEnter a positive decimal number: ");
	if((i=scanf("%lld%c",&n,&c))!=2 || c != '\n'){
	printf("NOT A VALID INPUT\n");
	return 0;}
	printf("OUTPUT:\n");
	if(n<0 || n>pow(2,31))
	printf("data out of limits\n");
	else
	printf("The binary representation of %lld contains %d  1s\n",n,count(n));
}
