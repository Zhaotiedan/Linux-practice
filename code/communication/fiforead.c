#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  //操作命名管道，与文件一样
  
  //1.先打开命名管道，只读
  int fd =open("./myfifo",O_RDONLY);
  if(fd<0)
  {
    perror("read open");
    return 1;
  }

  //2.读数据
  while(1)
  {
    char buf[1024]={0};
    ssize_t n=read(fd,buf,sizeof(buf)-1);
    if(n<0)
    {
      perror("read");
      return 1;
    }
    if(n==0)//所有写端关闭，读端已经结束
    {
      printf("read over\n");
      return 0;
    }
    buf[n]='\0';
    printf("readbuf:%s\n",buf);
  }
  close(fd);
  return 0;
}
