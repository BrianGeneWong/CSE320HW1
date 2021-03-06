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
  // printf(" %s  ",  str2);
   do{
	*str1=*str2;
	str1++;
	str2++;
   }while(*str2!='\0');
}

void copyName(char*str1,char*str2){
	//first char is capital
	*str1=toupper(*str2);
	str1++;
	str2++;
	
  	 do{
		*str1=tolower(*str2);
		str1++;
		str2++;
   	}while(*str2!='\0');
}

void copyMajor(char *str1, char *str2){
  // printf(" %s  ",  str2);
   do{
	*str1=toupper(*str2);
	str1++;
	str2++;
   }while(*str2!='\0');
}
int addNode(struct student_records *list,int id,char* f_name, char* l_name,float gpa, char* major ){
   //check if id is unique first
   //if list is empty, easy
//	printf("id= %d\n", id);
   if (list->head==NULL){
//	printf("list head is null\n");
	//make node
        student_node *node=malloc(sizeof(student_node));
	node->student.firstName=malloc(sizeof(f_name));
	node->student.lastName=malloc(sizeof(l_name));
	node->student.major=malloc(sizeof(major));
	node->next=NULL;
	node->prev=NULL;
	node->student.id=id;
	copyName(node->student.firstName,f_name);
        copyName(node->student.lastName,l_name);
	node->student.gpa=gpa;	
        copyMajor(node->student.major,major);
	list->head=node;
	return 0;
    }
   student_node *currNode=list->head;
   while(currNode!=NULL){
	if(currNode->student.id==id)
		return -1;	
	 if(currNode->student.id>id){		
       		student_node *node=malloc(sizeof(student_node));
		node->student.firstName=malloc(sizeof(f_name));
		node->student.lastName=malloc(sizeof(l_name));
		node->student.major=malloc(sizeof(major));
		node->student.id=id;
		copyName(node->student.firstName,f_name);
		copyName(node->student.lastName,l_name);
		node->student.gpa=gpa;	
	        copyMajor(node->student.major,major);
		if(currNode==list->head){
			list->head=node;
		node->prev=currNode->prev;
		node->next=currNode;
		currNode->prev=node;
		return 0;
        	 } 
	  }
	if(currNode->next==NULL){
		
       		student_node *node=malloc(sizeof(student_node));
		node->student.firstName=malloc(sizeof(f_name));
		node->student.lastName=malloc(sizeof(l_name));
		node->student.major=malloc(sizeof(major));
		node->student.id=id;
		copyName(node->student.firstName,f_name);
		copyName(node->student.lastName,l_name);
		node->student.gpa=gpa;	
	        copyMajor(node->student.major,major);
		currNode->next=node;
		node->next=NULL;
		node->prev=currNode;
		return 0;
	} 
     currNode=currNode->next;
    }
    //if reaaches the end and currNode==NULL
	
   return 0;
}

int deleteNode(struct student_records *list ,int id){
	if(list->head==NULL)
		return -1;
	student_node* currNode=list->head;
	while(currNode!=NULL){
//	printf("name : %s\n",currNode->student.firstName);
		if(currNode->student.id==id){
			if (currNode==list->head){
				if (currNode->next==NULL){
					free(currNode);
					list->head=NULL;
					return 0;
				}
				else{
					list->head=currNode->next;
					list->head->prev=NULL;
					free(currNode);
					return 0;
				}
			}
			else{
				if(currNode->next==NULL){
					currNode->prev->next=NULL;
					free(currNode);
					return 0;
				}
				else{
					currNode->prev->next=currNode->next;
					currNode->next->prev=currNode->prev;
					free(currNode);
					return 0;
				}
				
			}
		}
		currNode=currNode->next;
	}
	return -1;
}

int updateNode(struct student_records *list,int id,char* f_name, char* l_name,float gpa, char* major ){
	if(list->head==NULL)
		return -1;	
	//search for the id
	student_node *currNode=list->head;
	while(currNode!=NULL){
	//	printf("%d   %d\n",currNode->student.id, id);
		if(currNode->student.id==id){
//			printf("found a matching update id\n");
			currNode->student.gpa=gpa;	
			copyName(currNode->student.firstName,f_name);	
			copyName(currNode->student.lastName,l_name);
			copyMajor(currNode->student.major,major);
			return 0;
		}
		currNode=currNode->next;
	}
	return -1;
}

void freeList(struct student_records *list){
	student_node* currNode=list->head;
	student_node* temp;
	while(currNode!=NULL){
		//go through each node and free 
		student_info stu= currNode->student;
		free(stu.firstName);
		free(stu.lastName);
		free(stu.major);
		temp=currNode->next;
		free(currNode);
		currNode=temp;
	}
	free(list);
}
student_node* getStudentID(struct student_records *list,int id){
	
	student_node* currNode=list->head;
	student_node* temp;
	while(currNode!=NULL){
		if(currNode->student.id==id)
			return currNode;
		currNode=currNode->next;
	}
	return NULL;
}
void printStudent(student_node *node){
	student_info student=node->student;
  	 printf("%d %s %s %.2f %s\n",student.id , student.firstName, student.lastName,student.gpa,student.major);

}

void fprintStudent(FILE *fp,student_node *node){
	
	student_info student=node->student;
  	 fprintf(fp,"%d %s %s %.2f %s\n",student.id , student.firstName, student.lastName,student.gpa,student.major);

}
void printList(struct student_records *list){
  student_node* currNode=list->head;
   while(currNode!=NULL){
	student_info student=currNode->student;
  	 printf("%d %s %s %.2f %s\n",student.id , student.firstName, student.lastName,student.gpa,student.major);
  	currNode=currNode->next;
   }
}
//also checks to see that all chars are alphabet
int getStringLength(char* str){
 // printf("str : %s\n", str);
  int count=0;
  if(str==NULL)
	return 0;
  char c = *str;
  while(c!='\0'){
	if(c<'a'|| c>'z'){
		if(c<'A'|| c>'Z') 
		return -1;
	}
	count++;
	str++;
	c=*str;
  }
 // printf("end of getstrlenght count : %d\n",count);
  return count;
}

int outputToFile(char* output, struct student_records *list){
	FILE *fp;
	char choice;
	if (access(output,F_OK)==0){
		//ask user if they want to overwrite
		printf("do you want to overwrite the file? y/n :  ");
		scanf("%c",&choice);
		if (choice=='n'){
			printf("FILE EXISTS\n");
			return -1;
		}
	}
	fp=fopen(output,"w");
	student_node* currNode=list->head;
	while(currNode!=NULL){
		student_info stu=currNode->student;
		int id=stu.id;
		char* firstName=stu.firstName;
		char* lastName=stu.lastName;
		char* major=stu.major;
		float gpa=stu.gpa;
		fprintf(fp,"%d %s %s %.2f %s\n",id,firstName,lastName,gpa,major);
		currNode=currNode->next;
	}
	return 0;
}
//function to check if 2 strings are equal
//returns 0 if strings are not equal, 1 if they are
int checkStrings(char *str1,char *str2){
// printf("checkStrigs method\n");
// printf ("str1 : %s , str2: %s \n", str1,str2);
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
int checkArgs(int id, char* firstName, char* lastName, float GPA, char* major){
//	printf("%d %s %s %.2f %s\n",id,firstName,lastName,GPA,major);
	if (id<=0)
		return -1;
	int l=getStringLength(firstName);
//	printf("l equals %d",l);
	if (l<3 || l>10)
		return -1;
	l=getStringLength(lastName);
//	printf("l equals %d",l);
	if(l<3 || l>10)
		return -1;
	if (GPA<0 || GPA>4)
		return -1;
	l=getStringLength(major);
//	printf("l equals %d",l);
	if(l!=3)
		return -1;
	
	return 0;
}

int checkNum(char* num){
	int c;
	while(*num!='\0'){
		if((c=isalpha(*num)!=0))
			return -1;
		num++;
	}
	return 0;
}

int main(int argc, char** argv) {
  
  int id=0;
  char* first_name=NULL;
  char* last_name=NULL;
  float gpa;
  char* major=NULL;
  char* outputFile=NULL;
  //first we will parse through all argvs see if incorrect flags and stuff
  int count=0;
  int  vFlag=0;
  int  oFlag=0;
  int  iFlag=0;
  int  mFlag=0;
  int  fFlag=0;
  int hasFlags=0;
  int c;
  int l;
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
	   if(checkNum(optarg)==-1){
		printf("OTHER ERROR\n");
		return -1;
	   }
	   id=atoi(optarg);
	   break;
	case 'f':
	   fFlag=1;
	   hasFlags=1;
	   last_name=optarg;
	   l=getStringLength(optarg);
	   if(l<3 || l>10){
		printf("OTHER ERROR\n");
		return -1;
	   }
	   break;
	case 'm':
	   mFlag=1;
	   hasFlags=1;
	   major=optarg;
	   l=getStringLength(optarg);
	   if(l!=3){
		printf("OTHER ERROR\n");
		return -1;
	   }
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
	   printf("OTHER ERROR\n");
	   return -1;
     }	
}
//  printf("id: %d\n", id); 
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
  if(oFlag==1 && vFlag==0 && mFlag==0 && iFlag==0 && fFlag==0){
	printf("OTHER ERROR\n");
		return -1;
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

 //  while ( fscanf(fp,"%s %d %s %s %f %s",command,&f_id,f_fname,f_lname,&f_gpa,f_major) !=EOF){
	
     while (fscanf(fp,"%s",command)!=EOF){
	// printf("%s %d %s %s %.2f %s\n",command, f_id, f_fname, f_lname, f_gpa,f_major);
//	printf("in scan loop \n");

	if(checkStrings(command,"ADD")==1){
		fscanf(fp,"%d %s %s %f %s",&f_id,f_fname,f_lname,&f_gpa,f_major); 
		if(checkArgs(f_id,f_fname,f_lname,f_gpa,f_major)==-1){
		printf("FAILED TO PARSE FILE\n");
		return -1;
	}
	
//		printf("head pointer: %p \n",list->head);
		if(addNode(list,f_id,f_fname,f_lname,f_gpa,f_major)==-1){
			printf("ID NOT UNIQUE\n");
			return-1;
		}
	}
	else if (checkStrings(command, "DELETE")==1){
		fscanf(fp,"%d",&f_id);
		if (f_id<=0){	
		printf("FAILED TO PARSE FILE\n");
		} 
		if(deleteNode(list,f_id)==-1){
			printf("STUDENT RECORD CANNOT BE DELETED NOR UPDATED\n");
			return -1;
		}
	}
	else if (checkStrings(command, "UPDATE")==1){
		fscanf(fp,"%d %s %s %f %s",&f_id,f_fname,f_lname,&f_gpa,f_major); 
		if(updateNode(list,f_id,f_fname,f_lname,f_gpa,f_major)==-1){
			printf("STUDENT RECORD CANNOT BE DELETED NOR UPDATED\n");
			return -1;
		}
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
   if(vFlag==1){
	printList(list);
   	if(oFlag==1)
	outputToFile(outputFile,list);
   }
   else{	
        struct student_records* newList=NULL;
	if(oFlag==0){
		student_node *node;
		if(iFlag==1){
		//it will find one at max
			node=getStudentID(list, id);
			if (node==NULL){
				printf("STUDENT RECORD NOT FOUND\n");
				return -1;
			}
			if(fFlag==1){
				if(checkStrings(node->student.lastName,last_name)==0){
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
			if(mFlag==1){
				if(checkStrings(node->student.major,major)==0){
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
			//print student node;
			printStudent(node);
		}
		else{
			//since no id, there might be multiple people with the same last name and major
			int found=0;
			if(mFlag==1 && fFlag==1){
				node=list->head;
				while(node!=NULL){
					if (checkStrings(node->student.lastName,last_name)==1 && checkStrings(node->student.major,major)==1){
						found=1;
						printStudent(node);
					}
					node=node->next;
				}	
				if(found==0){	
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
			else if(mFlag==1){	
				node=list->head;
				while(node!=NULL){
					if (checkStrings(node->student.major,major)==1){
						found=1;
						printStudent(node);
					}
					node=node->next;
				}	
				if(found==0){	
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
			else if(fFlag==1){
				node=list->head;
				while(node!=NULL){
					if (checkStrings(node->student.lastName,last_name)==1){
						found=1;
						printStudent(node);
					}
					node=node->next;
				}	
				if(found==0){	
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
		}	
	}
	//OUTPUT QUERY TO FILE
	else{
		
		FILE *fp;
		char choice;
		if (access(outputFile,F_OK)==0){
		//ask user if they want to overwrite
		printf("do you want to overwrite the file? y/n :  ");
		scanf("%c",&choice);
		if (choice=='n'){
			printf("FILE EXISTS\n");
			return -1;
			}
		}
		
		fp=fopen(outputFile,"w");
		student_node *node;
		if(iFlag==1){
		//it will find one at max
			node=getStudentID(list, id);
			if (node==NULL){
				printf("STUDENT RECORD NOT FOUND\n");
				return -1;
			}
			if(fFlag==1){
				if(checkStrings(node->student.lastName,last_name)==0){
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
			if(mFlag==1){
				if(checkStrings(node->student.major,major)==0){
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
			//print student fp,node;
			fprintStudent(fp,node);
		}
		else{

			int found=0;
			if(mFlag==1 && fFlag==1){
				node=list->head;
				while(node!=NULL){
					if (checkStrings(node->student.lastName,last_name)==1 && checkStrings(node->student.major,major)==1){
						found=1;
						fprintStudent(fp,node);
					}
					node=node->next;
				}	
				if(found==0){	
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
			else if(mFlag==1){	
				node=list->head;
				while(node!=NULL){
					if (checkStrings(node->student.major,major)==1){
						found=1;	
						fprintStudent(fp,node);
					}
					node=node->next;
				}	
				if(found==0){	
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}
			else if(fFlag==1){
				node=list->head;
				while(node!=NULL){
					if (checkStrings(node->student.lastName,last_name)==1){
						found=1;
						fprintStudent(fp,node);
					}
					node=node->next;
				}	
				if(found==0){	
					printf("STUDENT RECORD NOT FOUND\n");
					return -1;
				}
			}

		}
		
	}
  }
  // printf("%d %s %s %.2f %s\n", f_id, f_fname, f_lname, f_gpa,f_major);
   free(command);
   free(f_fname);
   free(f_lname);
   free(f_major);
  //might need to write a function to iterate through list and free individually
   freeList(list);
 //  free(list);
 return 0;
}
