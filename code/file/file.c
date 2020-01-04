#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{ 
  int fd=open("./1.txt",O_RDWR);//读和写
  printf("fd=%d\n",fd);
  if(fd<0)
  {
    perror("open");
    return 1;
  }
  //读文件
  char buf[1024]={0};
  ssize_t ret=read(fd,buf,sizeof(buf)-1);//C风格字符串，留一个位置放'\0'
  buf[ret]='\0';
  printf("%s\n",buf);

  //写文件
  char buf1[1024]="hello 1.txt"; 
  ssize_t n=write(fd,buf1,strlen(buf1));
  printf("%ld\n",n);
  perror("write");
  close(fd);
  return 0;
}
