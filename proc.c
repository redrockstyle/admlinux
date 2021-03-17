#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char **envp){
  FILE *logfile = fopen("logfile.txt", "a");
  int *pid;
  char message[255];
  int pcount, icount, fcount, stat;

  if (argc < 3) {
      printf("Wrong args\n");
      return -1;
    }

  strncpy(message, argv[1], 255);
  pcount = atoi(argv[2]);
  icount = atoi(argv[3]);

  pid = (int*)malloc(sizeof(int)*pcount);

  for (int i = 0, fcounter = 1;i < pcount;i++, fcounter++) {
    switch(pid[i] = fork()) {
    case -1:
      perror("error in fork");
      exit(-1);
    case 0:
      printf("I'm a child process! My PID is: %d\n", getpid());
      printf("My parents' PID is: %d\n", getppid());
      fprintf(logfile, "%s, %d\n", message, fcounter*icount);
      exit(0);
    default:
      printf("I'm a parent process! My PID is: %d\n", getpid());
      printf("My child's PID is: %d\n", pid[i]);
      printf("and I'm waiting...\n");
      wait(&stat);
      printf("I'm a parent and I'm exiting!\n");
    }
  }

  return 0;
}
