#include <stdio.h>
#include <stdlib.h>

//char* _IO_read_ptr;	/* Current read pointer */
//char* _IO_read_end;	/* End of get area. */
//char* _IO_read_base;	/* Start of putback+get area. */
//char* _IO_write_base;	/* Start of put area. */
//char* _IO_write_ptr;	/* Current put pointer. */
//char* _IO_write_end;	/* End of put area. */
//char* _IO_buf_base;	/* Start of reserve area. */
//char* _IO_buf_end;	/* End of reserve area. */


int getChoice(void){
  
  int num = 0, choice = 0;
  char c;

  do{
    printf("%s", "Enter an integer >> ");
    num = scanf("%d", &choice);
    while(c = getchar() != '\n');
  }
  while(num == 0);

  return choice;
}

int getChoice2(void){

  int BUFSIZE = 4;
  char buffer[BUFSIZE];
  int count = 0, choice = 0;

  while(count == 0 || count == EOF){
    
    printf("%s", "Input an integer >> ");
    fflush(stdout);
    if(NULL != fgets(buffer, BUFSIZE, stdin)){
      count = sscanf(buffer, "%d", &choice);
      stdin[0]._IO_read_ptr = stdin[0]._IO_read_end;
    }
  }

  return choice;
}

//Input an integer >> a
//p buffer                 "a\n0x00"
//p stdin[0]._IO_read_ptr  ""

//Input an integer >> ab
//p buffer                 "ab\n0x00"
//p stdin[0]._IO_read_ptr  ""

//Input an integer >> abc
//p buffer                 "abc0x00"
//p stdin[0]._IO_read_ptr  "\n"

//Input an integer >> abcd
//p buffer                 "abc0x00"
//p stdin[0]._IO_read_ptr  "d\n"

//Input an integer >> abcde
//p buffer                 "abc0x00"
//p stdin[0]._IO_read_ptr  "de\n"

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

int getChoice3(){

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


int main(int argc, char **argv){

  int choice = getChoice3();

  while(choice){
    printf("\n%s %d\n", "You chose", choice);
    choice = getChoice3();
  }
  
  

}
