#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
  close(1);
  int fd =open("1.txt",O_WRONLY);//只写
  fprintf(stderr,"fd=%d\n",fd);//stderr是文件指针
  printf("new print:%d\n",stdout->_fileno);
  fprintf(stdout,"new print:%d\n",stdout->_fileno);
  return 0;
}
