#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define ll long long int
void merge(int arr[], int l, int m, int r);
void Merge_sort(int a[],int p,int r);
void printArray(int A[], int size);
void split(int *ar,int n,int fnum);
char * getfilename(int fnum);
int arr[2000],fnum;
int l[1048578],ri[1048578];
char filename[64][10]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt","9.txt","10.txt",
                           "11.txt","12.txt","13.txt","14.txt","15.txt","16.txt","17.txt","18.txt","19.txt","20.txt",
                            "21.txt","22.txt","23.txt","24.txt","25.txt","26.txt","27.txt","28.txt","29.txt","30.txt",
                            "31.txt","32.txt","33.txt","34.txt","35.txt","36.txt","37.txt","38.txt","39.txt","40.txt",
                            "41.txt","42.txt","43.txt","44.txt","45.txt","46.txt","47.txt","48.txt","49.txt","50.txt",
                            "51.txt","52.txt","53.txt","54.txt","55.txt","56.txt","57.txt","58.txt","59.txt","60.txt",
                            "61.txt","62.txt","63.txt","64.txt"};
void filecopy(char *f1,char *f2){
FILE *fp1,*fp2;
fp1=fopen(f1,"r");
fp2=fopen(f2,"w");
char c;
c = fgetc(fp1);
    while (c != EOF)
    {
        fputc(c, fp2);
        c = fgetc(fp1);
    }
fclose(fp1);
fclose(fp2);
 }
void mergefiles(char *f1,char *f2,char *f3){
	FILE *fp1,*fp2,*fp3;
	fp1=fopen(f1,"r");
	fp2=fopen(f2,"r");
	fp3=fopen(f3,"w");
	if(fp1==NULL || fp2==NULL || fp3==NULL){
	printf("FILES CANNOT BE OPENED\n");
	return;}
	int a,b,n1,n2;
	b=fscanf(fp2,"%d",&n2);
	a=fscanf(fp1,"%d",&n1);
	while (!feof(fp1) && !feof(fp2))
    {
        if ( n1<n2)
        {
            fprintf(fp3,"%d\n",n1);
	    a=fscanf(fp1,"%d",&n1);
        }
        else if(n1>n2)
        {
            fprintf(fp3,"%d\n",n2);
	    b=fscanf(fp2,"%d",&n2);
        }
        else{
	    fprintf(fp3,"%d\n",n2);
	    fprintf(fp3,"%d\n",n1);
	    b=fscanf(fp2,"%d",&n2);
	    a=fscanf(fp1,"%d",&n1);
	}
    }
    while (a!=EOF)
    {
	fprintf(fp3,"%d\n",n1);
	a=fscanf(fp1,"%d",&n1);

	            
    }
 
    while (b!=EOF)
    {
	//b=fscanf(fp2,"%d",&n2);
        fprintf(fp3,"%d\n",n2);
	b=fscanf(fp2,"%d",&n2);
	 
    }
	fcloseall();
}
void readbig(char *src){
	FILE *fp;
	int i=0,n;fnum=0;
	fp=fopen(src,"r");
	if(fp==NULL){
	printf("FILE CANNOT BE OPENED\n");
	return;}
	int a=0;
	while(a!=EOF){
	i=0;
	while(a!=EOF && i<15){
	   a=fscanf(fp,"%d",&arr[i]);
	    if(a>0)
	     i++;
	}
	n=i;
	Merge_sort(arr,0,n-1);
	split(arr,n,fnum);
	fnum++;
	}
	fcloseall();
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
char * getfilename(int fnum){
return filename[fnum];
}
void split(int *ar,int n,int fnum){
	FILE *pt;
	char *str;
	str=getfilename(fnum);
	pt=fopen(str,"w");
	if(pt==NULL){
	printf("FILE CANNOT BE OPENED IN SPLIT\n");
	return;}
	int i;
	for(i=0;i<n;i++){
	fprintf(pt,"%d\n",ar[i]);
	}
	fcloseall();
}
void allmerge(int fnum){
	if(fnum==5){
	     mergefiles(getfilename(0),getfilename(1),getfilename(5));
	     mergefiles(getfilename(2),getfilename(3),getfilename(6));
	     mergefiles(getfilename(4),getfilename(6),getfilename(7));
	     mergefiles(getfilename(5),getfilename(7),"sorted_file.txt");
	}
	else if(fnum==4){
	     mergefiles(getfilename(0),getfilename(1),getfilename(4));
	     mergefiles(getfilename(2),getfilename(3),getfilename(5));
	     mergefiles(getfilename(4),getfilename(5),"sorted_file.txt");
	}
	else if(fnum==3){
	     mergefiles(getfilename(0),getfilename(1),getfilename(3));
	     mergefiles(getfilename(2),getfilename(3),"sorted_file.txt");
	}
	else if(fnum==2){
	     mergefiles(getfilename(0),getfilename(1),"sorted_file.txt");
	}
	else if(fnum==1){
	     filecopy(getfilename(0),"sorted_file.txt");;
	}
}
int main(){
	//printf("ENTER THE FILE\n");
	char f[20]="NUMBERS";
	//scanf("%s",f);
	readbig(f);
	//printf("\n%d\n",fnum);
	allmerge(fnum);
}

void merge(int a[],int p,int q,int r)
{
    int i,j;
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
            i++;
        }
        else
        {
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
