#include <stdio.h>

//function to check if 2 strings are equal
//returns 0 if strings are not equal, 1 if they are
int checkStrings(char *str1.char *str2){
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
  /*
  * This formatting for the string
  * that you are expected to follow
  */
  printf("%d %s %s %.2f %s\n", id, first_name, last_name, gpa, major);
  return 0;
}
