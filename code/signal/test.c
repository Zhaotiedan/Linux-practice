#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc,char* argv[])//argc--命令行参数个数  argv[]---以空格为分隔符，代表指令中字符串 的数目
{
  //只处理一个进程
  if(argc!=3)
  {
    printf("参数有误！./mykill.c[signal][pid]");
    return 1;
  }
  //假设输入的指令是kill -9  110，那么-9是放在argv[1]处
  int signo=atoi(argv[1]+1);//得把argv中的字符串转化为整数
  pid_t pid=atoi(argv[2]);
  int ret=kill(pid,signo);
  if(ret<0)
  {
    perror("kill");
    return 1;
  }
  return 0;
}
