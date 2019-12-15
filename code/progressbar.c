#include <stdio.h>
#include <stdlib.h>

//只有在Linux下才有的头文件
#include <unistd.h>
//颜色
#define red "\e[0;31m"
#define blue "\e[0;34m"
int main()
{
  const char* label="/-\\|";  
  char buf[1024]={0};
  int i=0;
  for(;i<100;i++)
  {
    buf[i]='#';
    if(i<50)
    {
      printf(red"[%d%%][%c][%s]\r",i,label[i%4],buf);
    }
    else
    {
      printf(blue"[%d%%][%c][%s]\r",i,label[i%4],buf);
    }
    fflush(stdout);//刷新缓冲区
    usleep(100*1000);//单位是微秒 0.1秒 sleep只能有整型
  }
  printf("\n");
  return 0;
}
