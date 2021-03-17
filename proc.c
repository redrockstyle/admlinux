#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char **envp){
  FILE *logfile = fopen("logfile", "a");
  int *pid;
  int current_pid;
  char message[255];
  int proc_count;
  int iter_count;
  int wstatus;
  int fork_counter;

  if (argc < 3) {
      printf("Not enough parameters\n");
      return -1;
    }

  strncpy(message, argv[1], 255);
  proc_count = atoi(argv[2]);
  iter_count = atoi(argv[3]);


  pid = (int*)malloc(sizeof(int)*proc_count);

  for (int i = 0, fork_counter = 1;i < proc_count;i++, fork_counter++) {
    switch(pid[i] = fork()) {
    case -1:
      perror("error in fork");
      exit(-1);
    case 0:
      printf("I'm a child process! My PID is: %d\n", getpid());
      printf("My parents' PID is:%d\n", getppid());
      fprintf(logfile, "%s, %d\n", message, fork_counter*iter_count);
      exit(0);
    default:
      printf("I'm a parent process! My PID is: %d\n", getpid());
      printf("My child's PID is:%d\n", pid[i]);
      printf("and I'm waiting...\n");
      wait(&wstatus);
      printf("I'm a parent and I'm exiting!\n");
    }
  }

  return 0;
}
