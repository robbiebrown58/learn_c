#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "maptypes.h"

/*
creates an anonymous mapping and then forks.
The forked process requests a string which it 
then writes to the mapped memory. The parent process
sleeps until a value appears in the memory when it
reads and outputs the value then exits.
No robust error checking on input 
*/

int main(void){

  char buffer[MAP_SIZE];

  char *anon_backed;
  int fd = -1;

  int parentpid, childpid;
  parentpid = getpid();

  /* compiles and runs without the cast */
  if ((anon_backed = (char*)mmap(NULL, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0)) == MAP_FAILED){
    perror("mmap failed for anon_backed");
    exit(MAP_FAIL);
  }

  /* fork a new process, this 'clones' the mapping */
  switch ((childpid = fork())) {
    case -1:
      perror("fork failed");
    case 0:
      /* get a string in the child process */
      childpid = getpid();
      printf("%s%d%s", "In child process (pid = ", childpid, ") enter a string :>> ");
      fflush(stdout);
      fgets(buffer, MAP_SIZE, stdin);
      strcpy(anon_backed, buffer);
      munmap(anon_backed, MAP_SIZE); 
  }

  /* while mapped memory empty, sleep */
  while(strlen(anon_backed) == 0){
    sleep(1);
  }
  
  /* print contents of mapped memory to stdout but only in the parent process */
  if(getpid() == parentpid){
    printf("%s%d%s%s", "In parent process (pid = ", parentpid, ") the string you entered was :>> ", anon_backed);
  }

  munmap(anon_backed, MAP_SIZE); 

  return EXIT_SUCCESS;

}
