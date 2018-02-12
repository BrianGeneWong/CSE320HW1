#include <stdio.h>
#include <malloc.h>

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
  /*
  * Dummy values
  */
  int id;
  char* first_name;
  char* last_name;
  float gpa;
  char* major;
  //start with the first argument 
  argv++;
  //first we will parse through all argvs see if incorrect flags and stuff
  int count=0;
  int  hasV=0;
  int  hasO=0;
  int  hasF=0;
  int  hasM=0;
  int  hasI=0;
  int hasFlags=0;
  char** input;
  input=argv;
  while (count<argc){
    
 	 count++;
 	 input++;
  } 
  if(hasFlags==0){
	printf("NO QUERY PROVIDED");
	return -1;
  }
  //check if file exists, if not print correct Error Message and exit
    
  //initialize linked list
 // student_records list;
  /*
  * This formatting for the string
  * that you are expected to follow
  */
 // printf("%d %s %s %.2f %s\n", id, first_name, last_name, gpa, major);
  printf("just testing stuff rn \n"); 
 return 0;
}
