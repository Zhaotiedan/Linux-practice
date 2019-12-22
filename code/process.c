#include<stdio.h>
#include<unistd.h>

int main()
{
  pid_t ret=fork();//创建进程
  //getpid():获取进程的pid
  //getppid():获取父进程的pid
  
  if(ret>0)//父进程
  {
    int count=5;
    while(count>5)
    {
      printf("father %d\n",getpid());
      --count;
      sleep(1);
    }
  }
  else if(ret==0)//子进程
  {
    while(1)
    {
      printf("child %d.%d\n",getpid(),getppid());
      sleep(1);
    }
  }
  else//创建失败
  {
    perror("fork");
  }
  return 0;
}
