#include<stdio.h>
#include <unistd.h>

//env也是一个字符串数组
//表示当前的环境变量都有啥
//env 数组中也有一个结束标记NULL
//argc：命令行参数的个数
//argv:命令行参数的内容
int main(int argc,char* argv[],char* env[])
{
  (void) argc;
  (void) argv;
  printf("argc:%d\n",argc);
  int i=0;
  for(i=0;env[i];++i)
  {
    printf("%s\n",env[i]);
  }
  return 0;
}
