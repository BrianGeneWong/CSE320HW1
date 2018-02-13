#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>

typedef struct {
  char id;
  char* firstName;
  char* lastName;
  char* major;
  float  gpa;
}student_info;

typedef struct student_node student_node;

struct student_node{
  student_info student;
  student_node* next;
  student_node* prev;
};

struct student_records{
  student_node *head;
 // student_node *tail;
};
void stringCopy(char *str1, char *str2){
   printf(" %s  ",  str2);
   do{
	*str1=*str2;
	str1++;
	str2++;
   }while(*str2!='\0');
}


int addNode(struct student_records *list,int id,char* f_name, char* l_name,float gpa, char* major ){
   //check if id is unique first
   //if list is empty, easy
	printf("in add node function\n");
   if (list->head==NULL){
	printf("list head is null\n");
	//make node
        student_node *node=malloc(sizeof(student_node));
	node->student.firstName=malloc(sizeof(f_name));
	node->student.lastName=malloc(sizeof(l_name));
	node->student.major=malloc(sizeof(major));
	node->next=NULL;
	node->prev=NULL;
	node->student.id=id;
	stringCopy(node->student.firstName,f_name);
        stringCopy(node->student.lastName,l_name);
	node->student.gpa=gpa;	
        stringCopy(node->student.major,major);
	list->head=node;
	return 0;
    }
   student_node *currNode=list->head;
   while(currNode!=NULL){
	if(currNode->student.id==id);
		return -1;	
	 if(currNode->student.id>id){		
       		student_node *node=malloc(sizeof(student_node));
		node->student.firstName=malloc(sizeof(f_name));
		node->student.lastName=malloc(sizeof(l_name));
		node->student.major=malloc(sizeof(major));
		node->student.id=id;
		stringCopy(node->student.firstName,f_name);
		 stringCopy(node->student.lastName,l_name);
		node->student.gpa=gpa;	
	        stringCopy(node->student.major,major);
		if(currNode==list->head){
			list->head=node;
		node->prev=currNode->prev;
		node->next=currNode;
		currNode->prev=node;
        	 } 
	  } 
     currNode=currNode->next;
    }
   return 0;
}
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
 printf("checkStrigs method\n");
 printf ("str1 : %s , str2: %s \n", str1,str2);
 while(*str1!='\0'){
  	if(toupper(*str1)!=toupper(*str2))
		return 0;
	str1++;
	str2++;
  }
  if (*str2!='\0')
  	return 0;
  return 1;
}
//copy str2 into str1
 int fieldCheck(){
	
    return 0;
}
int main(int argc, char** argv) {
  
  int id;
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
	   id=atoi(optarg);
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
	   if (optopt=='i' || optopt=='o' || optopt=='f' || optopt=='m'){
		printf("OTHER ERROR\n");
		return -1;
	   }
	default:
	   printf("default \n");
     }	
}
 
  if(hasFlags==0){
	printf("NO QUERY PROVIDED\n");
	return -1;
  }
	

  //if v flag is set, and any flag that isnt O is set, error
  if (vFlag==1){
	if(fFlag==1 || mFlag==1 || iFlag==1){
		printf("OTHER ERROR\n");
		return -1;
	}
  }
 
  char *inputFile;
  argv+=optind;
  inputFile=*argv;
  FILE *fp;
  if ((fp=fopen(inputFile,"r"))== NULL){
	printf("FAILED TO PARSE FILE\n");
	return -1;	

  } 
  //initialize linked list
  struct  student_records *list=malloc(sizeof(struct student_records));
   list->head=NULL;
   
   //lets read file line by line
   
//   getline(buf,0,fp);
   char *command=malloc(10);
   int f_id;
   char* f_fname=malloc(11);
   char* f_lname=malloc(11);
   float f_gpa;
   char* f_major=malloc(5);

   while ( fscanf(fp,"%s %d %s %s %f %s",command,&f_id,f_fname,f_lname,&f_gpa,f_major) !=EOF){
	 printf("%d %s %s %.2f %s\n", f_id, f_fname, f_lname, f_gpa,f_major);
//	printf("in scan loop \n");
//	printf("command= %s\n", command);
	if(checkStrings(command,"ADD")==1){
		printf("head pointer: %p \n",list->head);
		if(addNode(list,f_id,f_fname,f_lname,f_gpa,f_major)==-1){
			printf("ID NOT UNIQUE\n");
			return-1;
		}
	}
	else if (checkStrings(command, "DELETE")==1){
	}
	else if (checkStrings(command, "UPDATE")==1){
	}
	else{
		printf("FAILED TO PARSE FILE\n");
		return -1;
	}
	//create the nodes
	student_node *curr_node=malloc(sizeof(student_node));

   }

  /*
  * This formatting for the string
  * that you are expected to follow
  */
   printf("%d %s %s %.2f %s\n", f_id, f_fname, f_lname, f_gpa,f_major);
   free(command);
   free(f_fname);
   free(f_lname);
   free(f_major);
 return 0;
}
