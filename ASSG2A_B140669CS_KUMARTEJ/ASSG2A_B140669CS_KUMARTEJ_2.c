#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int l[100],ri[100];
int count=0;

void merge(int a[],int p,int q,int r)
{
    int i,j,t=p;
    int n1 = q-p+1;
    int n2 = r-q;
    for(i=1;i <= n1 ;i++)
    {
        l[i] = a[p+i-1];
    }
    l[i] = INT_MAX;
    for(j=1;j <= n2 ;j++)
    {
        ri[j] = a[q+j];
    }
    ri[j] = INT_MAX;
    i = 1;
    j = 1;
    int k;
    for ( k = p; k <= r ; k++)
    {
        if(l[i] <= ri[j])
        {
            a[k] = l[i];
            i++;t++;
        }
        else if(i<=n1)
        {
            count += (q-t+1);
	    //count+=q-i+1;
            a[k] = ri[j];
            j++;
        }
	else{
	    a[k] = ri[j];
            j++;
	}
    }

}

void Merge_sort(int a[],int p,int r)
{
    if (p < r)
    {
        int q = p+(r-p)/2;
        Merge_sort(a,p,q);
        Merge_sort(a,q+1,r);
        merge(a,p,q,r);

    }
}

int main(){
	int n,i,j;
	if(!(scanf("%d",&n)) || n<=0){
	   printf("INVALID INPUT\n");
	   return 0;
	}
	int ar[n];
	for(i=0;i<n;i++){
	   if(!(scanf("%d",&ar[i]))){
	     printf("INVALID INPUT\n");
	     return 0;
	   }
	}
	Merge_sort(ar,0,n-1);
	//for(i=0;i<n;i++)
	  // printf("%d ",ar[i]);
	printf("%d\n",count);
	return 0;
}
