#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){

  int parent_pid = getpid(), child_pid;
  
  printf("%s %d\n", "parent_pid =", parent_pid);

  child_pid = fork();

  if(child_pid == -1){
    //if child_pid == -1 then error and no child process is created
    perror("fork error");
  }
  //else a new process is created. BOTH processes exec the following code
  //there is a way to stop this apparently
  else if(child_pid == 0){
    //on success, 0 is returned to the child process
    printf("%s %d\n", "in child process child_pid =", child_pid);
    child_pid = getpid();
    printf("%s %d\n", "in child process child_pid is now =", child_pid);
    if(execl("/usr/bin/gedit", "", (char*)NULL) == -1){
      perror("execl failed");
    }
    //printf("sleeping for 10 in child\n");
    //sleep(10);
    printf("waking in child\n");
  }
  else{
    //if child_pid > 0 (it will always be less that parent_pid) then we are in the parent thread
    printf("%s %d\n", "in parent process child_pid =", child_pid);
    printf("sleeping for 50 in parent\n");
    sleep(50);
    printf("waking in parent\n");
  }
}
