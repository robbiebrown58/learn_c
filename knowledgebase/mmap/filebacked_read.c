#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "maptypes.h"

int main(int argc, char **argv){

  char buffer[1];
  char *file_memory;
  int fd = -1;

  if(argc < 2){
    printf("%s\n", "Usage: fileread.out <filename>");
    exit(MISSING_ARG);
  }

  if ((fd = open(argv[1], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR)) == -1){
    perror("open failed in filebacked_read");
    exit(OPEN_FAIL);
  }  
 
  if ((file_memory = (char*)mmap(NULL, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED){
    perror("mmap failed for output file_memory");
    exit(MAP_FAIL);
  }

  /* closing the descriptor doesn't unmap the memory */
  if(close(fd) == -1){
    perror("close failed");
    exit(CLOSE_FAIL);
  }
  
  /* print out file contents */
  while(1){
    sleep(2);
    printf("%s", file_memory);
  }
}
