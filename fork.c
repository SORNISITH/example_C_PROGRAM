#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  pid_t p = fork();

  if (p < 0) {
    perror("fork fail");
    exit(1);
  }
  
  printf("hello world\n = %d\n", getpid());
  
  return 0;
}
