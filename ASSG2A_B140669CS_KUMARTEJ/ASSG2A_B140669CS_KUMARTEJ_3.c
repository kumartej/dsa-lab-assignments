#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>
#include <string.h>
#define INT_MAX 1100
char filename[65][10]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt","9.txt","10.txt",
                           "11.txt","12.txt","13.txt","14.txt","15.txt","16.txt","17.txt","18.txt","19.txt","20.txt",
                            "21.txt","22.txt","23.txt","24.txt","25.txt","26.txt","27.txt","28.txt","29.txt","30.txt",
                            "31.txt","32.txt","33.txt","34.txt","35.txt","36.txt","37.txt","38.txt","39.txt","40.txt",
                            "41.txt","42.txt","43.txt","44.txt","45.txt","46.txt","47.txt","48.txt","49.txt","50.txt",
                            "51.txt","52.txt","53.txt","54.txt","55.txt","56.txt","57.txt","58.txt","59.txt","60.txt",
                            "61.txt","62.txt","63.txt","64.txt","65.txt"};
void merge(int arr[], int l, int m, int r);
void Merge_sort(int a[],int p,int r);
void split(int *ar,int n,int fnum);
char * getfilename(int fnum);
char * getmerfile(int tfn);
int min_array(int a[], int num_elements);
char totfiles[15][10]={"f1.txt","f2.txt","f3.txt","f4.txt","f5.txt","f6.txt","f7.txt","f8.txt","f9.txt","f10.txt","f11.txt","f12.txt","f13.txt","f14.txt","f15.txt"};
int m1count=0;
char m4files[6][10]={"d1.txt","d2.txt","d3.txt","d4.txt","d5.txt","d6.txt"};
int m4count=0;
char * getm4file(int n){
return m4files[n];}
char * getmerfile(int tfn){
return totfiles[tfn];}
int fnum=0;
int arr[1048676];
int l[1048578],ri[1048578];
int given=1024*1024;

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
    for ( k = p; k <= r ; k++){
        if(l[i] <= ri[j]){
            a[k] = l[i];
            i++;
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
	while(a!=EOF && i<given){
	   a=fscanf(fp,"%d",&arr[i]);
	    if(a>0)
	     i++;
	}
	n=i;
	if(n!=0){
	Merge_sort(arr,0,n-1);
	split(arr,n,fnum);
	fnum++;}
	} 
	fcloseall();
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
char * getfilename(int fnum){
return filename[fnum];
}
void randomfile(){
	int i;
	time_t t;
	FILE *fp;
	fp=fopen("NUMBERS.txt","w");
	//srand((unsigned) time(&t));
	for(i=0;i<1024*1024*64;i++)
	   fprintf(fp,"%d\n",rand()%600);
	fclose(fp);
}
int min_array(int a[], int num_elements)
{
   int i, min=INT_MAX;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i]<min)
	 {
	    min=a[i];
	 }
   }
   return(min);
}

void merge_8(int n1,int n2){
	FILE *fp[10];
	FILE *f2,*f3;
	int i,j=0;
	char *fname;
	for( i = 0; i <8 ; i++) {
            char filename[50];
            sprintf(filename, "%d.txt", ++n1);
            fp[i] = fopen(filename, "r");
	    if(fp[i]==NULL){
	      printf("FILE CANNOT BE OPENED");
	      exit(0);}
        }
	f2=fopen(getmerfile(m1count),"w");
	m1count++;
	int num[10],count[10];j=n1;
	for(i=0;i<10;i++)
	   count[i]=0;
	for(i=0;i<8;i++){
	    fscanf(fp[i],"%d",&num[i]);
	    count[i]++;
	}
	
	for(i=0;i<(1024*1024*8);i++) {
	   int fmin=min_array(num,8);
	   if(fmin==num[0]){
	      fprintf(f2,"%d\n",num[0]);
	      count[0]++; 
	      fscanf(fp[0],"%d",&num[0]);
		if(count[0]>= 1024*1024){
		   num[0]=INT_MAX;}
	   }
	   else if(fmin==num[1]){
	      fprintf(f2,"%d\n",num[1]);
	      count[1]++; 
	      fscanf(fp[1],"%d",&num[1]);
		if(count[1]>= 1024*1024){
		   num[1]=INT_MAX;}
	   }
	  else if(fmin==num[2]){
	      fprintf(f2,"%d\n",num[2]);
	      count[2]++;
	      fscanf(fp[2],"%d",&num[2]);
		if(count[2]>= 1024*1024){
		   num[2]=INT_MAX;}
	   }
	   else if(fmin==num[3]){
	      fprintf(f2,"%d\n",num[3]);
	      count[3]++; 
	      fscanf(fp[3],"%d",&num[3]);
		if(count[3]>= 1024*1024){
		   num[3]=INT_MAX;}
	   }
	   else if(fmin==num[4]){
	      fprintf(f2,"%d\n",num[4]);
	      count[4]++; 
	      fscanf(fp[4],"%d",&num[4]);
		if(count[4]>= 1024*1024){
		   num[4]=INT_MAX;}
	   }
	   else if(fmin==num[5]){
	      fprintf(f2,"%d\n",num[5]);
	      count[5]++;
	      fscanf(fp[5],"%d",&num[5]);
		if(count[5]== 1024*1024)
		   num[5]=INT_MAX;
	   }
	   else if(fmin==num[6]){
	      fprintf(f2,"%d\n",num[6]);
	      count[6]++;
	      fscanf(fp[6],"%d",&num[6]);
		if(count[6]== 1024*1024)
		   num[6]=INT_MAX;
	   }
	   else if(fmin==num[7]){
	      fprintf(f2,"%d\n",num[7]);
	      count[7]++; 
	      fscanf(fp[7],"%d",&num[7]);
		if(count[7]== 1024*1024)
		   num[7]=INT_MAX;
	   }
	}
	fcloseall();
	
}
void merge_4(int n1,int n2){
	FILE *fp[10];
	FILE *f2,*f3;
	int i,j=0;
	char *fname;
	for( i = 0; i <4 ; i++) {
            char filename[50];
            sprintf(filename, "f%d.txt", ++n1);
            fp[i] = fopen(filename, "r");
	    if(fp[i]==NULL){
	      printf("FILE CANNOT BE OPENED");
	      exit(0);}
        }
	f2=fopen(getm4file(m4count),"w");
	m4count++;
	int num[6],count[6];j=n1;
	for(i=0;i<6;i++)
	   count[i]=0;
	for(i=0;i<4;i++){
	    fscanf(fp[i],"%d",&num[i]);
	    count[i]++;
	}
	
	for(i=0;i<(1024*1024*32);i++) {
	   int fmin=min_array(num,4);
	   if(fmin==num[0]){
	      fprintf(f2,"%d\n",num[0]);
	      count[0]++;
	      fscanf(fp[0],"%d",&num[0]);
		if(count[0]== 1024*1024*8)
		   num[0]=INT_MAX;
	   }
	   else if(fmin==num[1]){
	      fprintf(f2,"%d\n",num[1]);
	      count[1]++; 
	      fscanf(fp[1],"%d",&num[1]);
		if(count[1]== 1024*1024*8)
		   num[1]=INT_MAX;
	   }
	  else if(fmin==num[2]){
	      fprintf(f2,"%d\n",num[2]);
	      count[2]++; 
	      fscanf(fp[2],"%d",&num[2]);
		if(count[2]== 1024*1024*8)
		   num[2]=INT_MAX;
	   }
	   else if(fmin==num[3]){
	      fprintf(f2,"%d\n",num[3]);
	      count[3]++; 
	      fscanf(fp[3],"%d",&num[3]);
		if(count[3]== 1024*1024*8)
		   num[3]=INT_MAX;
	   }
	}
	fcloseall();
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
}
int main(){
	char src[20]="NUMBERS.txt";
	randomfile();
	readbig(src);
	int i;
	for(i=0;i<64;i+=8)
	merge_8(i,i+8);
	for(i=0;i<8;i+=4)
	merge_4(i,i+4);
	mergefiles("d1.txt","d2.txt","sorted_file.txt");
}
