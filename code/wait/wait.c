#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t ret=fork();
  if(ret>0)
  {
    //father
    printf("father %d\n",getpid());
    int status=0;
    //阻塞式函数
    pid_t result=wait(&status);//status是一个输出型变量
    printf("result %d status %d\n",result,status);
  if(status & 0xff)//获取最低4位
  {
    printf("异常终止，信号为 %d\n",status & 0x7f);//取低7位
  }
  else{
    printf("正常退出，退出码为%d\n",(status>>8) & 0xff);
  }
  }
  else if(ret==0)
  {
    //child
    int count=10000000;//count=1000000是为了中途干掉进程
    while(count>0)
    {
      printf("child %d\n",getpid());
      sleep(1);
      count--;
    }
    exit(3);
  }
  else{
    //error
    perror("fork");
  }
  return 0;
}
