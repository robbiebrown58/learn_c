#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int inputDone(char *buf){
 
  for(int i = 0; i < sizeof(buf); i++){
    if( *(buf + i) == '\n'){
      return TRUE;
    }
  }
  return FALSE;
}

float getOperand(void){

  int BUFSIZE = 4;
  char buffer[BUFSIZE];
  int count = 0;
  float choice = 0;

  while(count == 0 || count == EOF || choice < 0){

    printf("%s", "Input a float >> ");
    fflush(stdout);
    
    if(NULL != fgets(buffer, BUFSIZE, stdin)){
      count = sscanf(buffer, "%f", &choice);
      if(inputDone(buffer) == FALSE){
	while(getchar() != '\n');
      }
    }
  }
  return choice;
}

char ops[] = "*-+/=";

char getOperator(void){

  int BUFSIZE = 3;
  char buffer[BUFSIZE];
  int count = 0;
  char choice = 0;

  while(count == 0 || count == EOF || choice < 0 || !strchr(ops, choice)){

    printf("%s", "Input op >> ");
    fflush(stdout);
    
    if(NULL != fgets(buffer, BUFSIZE, stdin)){
      count = sscanf(buffer, "%c", &choice);
      if(inputDone(buffer) == FALSE){
	while(getchar() != '\n');
      }
    }
  }
  return choice;
}
