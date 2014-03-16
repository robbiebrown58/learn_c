#include <stdio.h>

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

float getFloat(void){

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

int getInt(){

  int BUFSIZE = 4;
  char buffer[BUFSIZE];
  int count = 0, choice = 0;

  while(count == 0 || count == EOF || choice < 0){

    printf("%s", "Input an integer >> ");
    fflush(stdout);
    
    if(NULL != fgets(buffer, BUFSIZE, stdin)){
      count = sscanf(buffer, "%d", &choice);
      if(inputDone(buffer) == FALSE){
	while(getchar() != '\n');
      }
    }
  }

  return choice;
}

char getChar(void){

  int BUFSIZE = 3;
  char buffer[BUFSIZE];
  int count = 0;
  char choice = 0;

  while(count == 0 || count == EOF || choice < 0){

    printf("%s", "Input a char >> ");
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
