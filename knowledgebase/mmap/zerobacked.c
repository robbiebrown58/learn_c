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
creates a mapping on /dev/zero and then forks.
The forked process requests a string which it 
then writes to the mapped memory. The parent process
sleeps until a value appears in the memory when it
reads and outputs the value then exits.
No robust error checking on input 
*/

int main(void){

  char buffer[MAP_SIZE];

  char *zero_backed;
  int fd = -1;

  int parentpid, childpid;
  parentpid = getpid();

  /* get a file descriptor on /dev/zero */
  if ((fd = open("/dev/zero", O_RDWR)) == -1){
    perror("open failed on /dev/zero");
    exit(OPEN_FAIL);
  }

  /* the cast doesn't appear to be needed but included as documentation */
  if ((zero_backed = (char*)mmap(NULL, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_FILE|MAP_SHARED, fd, 0)) == MAP_FAILED){
    perror("mmap failed for zero_backed");
    exit(MAP_FAIL);
  }

  /* closing the descriptor doesn't unmap the memory */
  if(close(fd) == -1){
    perror("close failed on /dev/zero");
    exit(CLOSE_FAIL);
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
      /* copy the value input into mapped memory */
      strcpy(zero_backed, buffer);
      munmap(zero_backed, MAP_SIZE);
  }

  /* while mapped memory empty, sleep */
  while(strlen(zero_backed) == 0){
    sleep(1);
  }
  
  /* print contents of mapped memory to stdout but only in the parent process */
  if(getpid() == parentpid){
    printf("%s%d%s%s", "In parent process (pid = ", parentpid, ") the string you entered was :>> ", zero_backed);
  }

  munmap(zero_backed, MAP_SIZE);

  return EXIT_SUCCESS;

}
