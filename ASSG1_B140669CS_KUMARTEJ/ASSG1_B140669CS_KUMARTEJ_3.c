#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
struct student{
	char name[100];
	char id[20];
	char marks[3];
};
int mark(char* a) {
  int l=strlen(a);
	int i;
  for(i=0; i<l;i++) {
    if(!(isdigit(a[i]))) 
      return 0;
  }
  return 1;
}
#define std struct student
int check(FILE *pt){
   std s1;
   return (fscanf(pt,"%s%s%s",s1.id,s1.name,s1.marks)==EOF);
}

void addrec(char ar[]){
	FILE* fp;
	std s1;
	fp=fopen(ar,"a");
	printf("Enter	name, id and mark:\n");
	scanf("%s%s%s",s1.name,s1.id,s1.marks);
	if(s1.marks[0]=='I' || s1.marks[0]=='A'){
	   if(strcmp(s1.marks,"I")==0 || strcmp(s1.marks,"A")==0)
	       fprintf(fp,"%s %s %s\n",s1.id,s1.name,s1.marks);
	   else
		printf("Invalid Input\n");
	   }
	else if(mark(s1.marks)){
	    if(atoi(s1.marks)>=0 && atoi(s1.marks)<=100)
		fprintf(fp,"%s %s %s\n",s1.id,s1.name,s1.marks);
	    else
		printf("Invalid Input\n");
	    }
	else
	printf("invalid input\n");
	fclose(fp);
	return;
}
void lessmarks(char ar[]){
	FILE *fp;
	std s1;
	int n=0;
	char cmp1='A',cmp='I';
	int c=1;
	fp=fopen(ar,"r");
	if(fp==NULL){
	printf("File does not exist\n");
	return;}
	struct stat st;
	if(check(fp)){
	    printf("NO data\n");
	return;}
	else{
	fseek(fp,0,SEEK_SET);
	printf("Students who scored less than 30:\n");
	while(!feof(fp)){
	c=fscanf(fp,"%s%s%s",s1.id,s1.name,s1.marks);
	if(c>0 && 'I'!=s1.marks[0] && 'A'!=s1.marks[0])
	if(atoi(s1.marks)<30){
	printf("%s\n",s1.name);
	n++;}
	}
	if(n==0)
	printf("No Students have marks less than 30\n");}
	return;
}
void attendance(char ar[]){
	FILE *fp;
	std s1;
	char cmp1='I';
	int c=1,n=0;
	fp=fopen(ar,"r");
	if(fp==NULL){
	printf("File does not exist\n");
	return;}
	if(check(fp)){
	    printf("NO data\n");
	return;}
	fseek(fp,0,SEEK_SET);
	struct stat st;
	printf("Students with insufficient attendance:\n");
	while(!feof(fp)){
	   c=fscanf(fp,"%s%s%s",s1.id,s1.name,s1.marks);
	   if(c>0 && 'I'==s1.marks[0]){
	   printf("%s\n",s1.name);
	   n++;}
	}
	if(n==0)
	printf("No students have Insufficient Attendance\n");
	return;
}
void print(char ar[]){
	FILE *fp;
	std s1;
	int c=1;
	fp=fopen(ar,"r");
	if(fp==NULL){
	printf("File does not exist\n");
	return;}
	struct stat st;
	if(check(fp)){
	    printf("NO data\n");
	return;}
	else{
	fseek(fp,0,SEEK_SET);
	printf("Details of all Students\n");
	printf("+----------+------------+----+\n");
	printf("|Student_ID|Student_Name|Mark|\n");
	printf("+----------+------------+----+\n");
	while(!feof(fp)){
	   c=fscanf(fp,"%s%s%s",s1.id,s1.name,s1.marks);
	   if(c>0)
	   printf("|%-10s|%-12s|%-4s|\n",s1.id,s1.name,s1.marks);
	}
	printf("+----------+------------+----+\n");
	}
	return;
}
int main(int argc,char *argv[]){
	int ch,lp=1;
	if(argc!=2){
	printf("Command line arguments are to be given correctly\n");
	return 0;
	}
	FILE *fp;
	fp=fopen(argv[1],"w");
	while(lp){
	  printf("   1.Add student details\n   2.Display the names of students who obtained less than 30 marks\n   3.Display the names of students who have insufficient attendance\n   4.Display all the records in the file\n   5.exit\n    Enter a choice:");
	  scanf("%d",&ch);
	     if(ch==1)
	     addrec(argv[1]);
	     else if(ch==2)
	     lessmarks(argv[1]);
	     else if(ch==3)
	     attendance(argv[1]);
	     else if(ch==4)
	     print(argv[1]);
	     else if(ch==5)
	     lp=0;
	     else
	     printf("Enter a valid choice\n");
	}
}
