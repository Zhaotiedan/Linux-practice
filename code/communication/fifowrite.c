#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  //先打开管道（文件）
  int fd=open("./myfifo",O_WRONLY);
  if(fd<0)
  {
    perror("write open");
    return 1;
  }

  //写数据
  while(1)
  {
    //提示用户输入一个数据
    printf("enter>:");
    fflush(stdout);
    char buf[1024]={0};
    ssize_t n=read(0,buf,sizeof(buf)-1);//0--是stdin的文件描述符
    if(n<0)
    {
      perror("write");
      return 1;
    }
    buf[n]='\0';
    write(fd,buf,strlen(buf));
  }
  close(fd);
  return 0;
}
