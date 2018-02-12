#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
typedef struct {
  char* id;
  char* firstName;
  char* lastName;
  char* major;
  float  gpa;
}student_info;

typedef struct{
  student_info student;
  struct student_node* next;
  struct student_node* prev;
}student_node;

struct student_records{
  student_node *head;
  student_node *tail;
};

int getStringLength(char* str){
  int count=0;
  char c = *str;
  while(c!='\0'){
	count++;
	str++;
	c=*str;
  }
  return count;
}
//function to check if 2 strings are equal
//returns 0 if strings are not equal, 1 if they are
int checkStrings(char *str1,char *str2){
  while(*str1!='\0'){
  	if(*str1!=*str2)
		return 0;
	str1++;
	str2++;
  }
  if (str2!='\0')
  	return 0;
  return 1;
}
int main(int argc, char** argv) {
  
  char* id;
  char* first_name;
  char* last_name;
  float gpa;
  char* major;
  char* outputFile;
  //first we will parse through all argvs see if incorrect flags and stuff
  int count=0;
  int  vFlag=0;
  int  oFlag=0;
  int  iFlag=0;
  int  mFlag=0;
  int  fFlag=0;
  int hasFlags=0;
  int c;
  extern int opterr;
  opterr=0;
  while((c=getopt(argc, argv,"vi:f:m:o:" ))!=-1){
     switch(c){
	case 'v':
	   hasFlags=1;
	   vFlag=1;
	   break;
	case 'i':
	   iFlag=1;
	   hasFlags=1;
	   id=optarg;
	   break;
	case 'f':
	   fFlag=1;
	   hasFlags=1;
	   last_name=optarg;
	   break;
	case 'm':
	   mFlag=1;
	   hasFlags=1;
	   major=optarg;
	   break;
	case 'o':
	   oFlag=1;
           hasFlags=1;
	   outputFile=optarg;
           break;
	case '?':
	   if (optopt=='i'){
		printf("OTHER ERROR");
		return -1;
	   }
	default:
	   printf("default \n");
     }	
}
 	
  printf("last name %s", last_name);
  if(hasFlags==0){
	printf("NO QUERY PROVIDED");
	return -1;
  }
	
/*
  //if v flag is set, and any flag that isnt O is set, error
  if (vFlag==1){
	if(fFlag==1 || mFlag==1 || iFlag==0){
		printf("OTHER ERROR");
		return -1;
	}
  }

 argv++;
  char *inputFile= *argv;
  FILE *fp;
  fp=fopen(inputFile,"r+");
  //check if file exists, if not print correct Error Message and exit
    
  //initialize linked list
   struct student_records list;
   list.head=NULL;
   list.head=NULL;
*/
  /*
  * This formatting for the string
  * that you are expected to follow
  */
 // printf("%d %s %s %.2f %s\n", id, first_name, last_name, gpa, major); 
 printf("just testing stuff out xd\n");
 return 0;
}
