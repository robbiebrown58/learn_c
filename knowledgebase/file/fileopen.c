#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv){
  /*
  //fcntl.h
  printf("fcntl.h O_RDWR %d\n", O_RDWR);
  printf("fcntl.h O_RDONLY %d\n", O_RDONLY);
  printf("fcntl.h O_WRONLY %d\n", O_WRONLY);

  //sys/stat.h
  printf("sys/stat.h S_IRUSR %d\n", S_IRUSR);
  printf("sys/stat.h S_IWUSR %d\n", S_IWUSR);
  printf("sys/stat.h S_IXUSR %d\n", S_IXUSR);
  */

  struct stat statbuf;

  int fd;

  if(argc < 2){
    printf("%s\n", "filename required");
    exit(8);
  }

  fd = open (argv[1], O_RDWR|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
  if(fd == -1){
    perror("failed to open file");
    exit(9);
  }

  int offset_loc;

  offset_loc = lseek(fd, 100, SEEK_SET);
  if(offset_loc == -1){
    perror("failed to set length");
    exit(10);
  }

  write(fd, "", 1);

  //mode_t st_mode
  printf("st_mode: %zd\n", statbuf.st_mode);
  //ino_t st_ino
  printf("st_ino: %zd\n", statbuf.st_ino);
  //dev_t st_dev
  printf("st_dev: %zd\n", statbuf.st_dev);
  //nlink_t st_nlink
  printf("st_nlink: %zd\n", statbuf.st_nlink);
  //uid_t st_uid
  printf("st_uid: %zd\n", statbuf.st_uid);
  //gid_t st_gid
  printf("st_gid: %zd\n", statbuf.st_gid);
  //off_t st_size
  printf("st_size: %zd\n", statbuf.st_size);
  //time_t st_atime
  printf("st_atime: %zd\n", statbuf.st_atime);
  //unsigned long int st_atime_usec
  //printf("st_atime_usec: %lu\n", statbuf.st_atime_usec);
  //time_t st_mtime
  printf("st_mtime: %zd\n", statbuf.st_mtime);
  //unsigned long int st_mtime_usec
  //printf("st_mtime_usec: %lu\n", st_mtime_usec);
  //time_t st_ctime
  printf("st_ctime: %zd\n", statbuf.st_ctime);
  //unsigned long int st_ctime_usec
  //printf("st_ctime_usec: %lu\n", statbuf.st_ctime_usec);
  //blkcnt_t st_blocks
  printf("st_blocks: %zd\n", statbuf.st_blocks);
  //unsigned int st_blksize
  printf("st_blksize: %zd\n", statbuf.st_blksize);

  exit(EXIT_SUCCESS);
}
