#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int count=0;

int main()
{
  pid_t ret=fork();
  if(ret>0)
  {
    printf("father %p %d\n",&count,count);//打印全局变量的地址
  }
  else if(ret==0)
  {
    printf("child %p %d\n",&count,count);
  }
  else{
    perror("fork");
  }
  return 0;
}
