#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t ret=fork();
  if(ret==0){
    //child
  printf("before execl\n");
  //execl("/usr/bin/ls","/usr/bin/ls","/",NULL);//可执行程序的路径ls,最后一个参数必须是NULL
  execlp("ls","ls","/",NULL);
  }
  //father
  wait(NULL);//为了先执行子进程再执行父进程
  printf("after execl\n");
  return 0;
}
