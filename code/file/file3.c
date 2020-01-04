#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  printf("hello printf\n");
  fprintf(stdout,"hello fprintf\n");
  write(1,"I love my family\n",strlen("I love my family\n"));
  //fflush()//要传file*
  //fork();
  return 0;
}
