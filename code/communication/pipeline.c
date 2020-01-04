#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
  //pipe
  int fd[2];
  int ret=pipe(fd);
  if(ret<0)
  {
    perror("pipe");
    return 1;
  }

  pid_t ret1=fork();
  if(ret1>0)
  {
    //father 写数据
    char buf_write[1024]="hell0,father!\n";
    write(fd[1],buf_write,strlen(buf_write));

    sleep(1);

    char buf_read[1024]={0};                              
    ssize_t n=read(fd[0],buf_read,sizeof(buf_read)-1);
    buf_read[n]='\0';                                     
    printf("father read:%s\n",buf_read);  
  }
  else if (ret==0)
  {
    //child 读数据
    char buf_read[1024]={0};
    ssize_t n=read(fd[0],buf_read,sizeof(buf_read)-1);
    buf_read[n]='\0';
    printf("child read:%s\n",buf_read);
  }
  else{
    perror("fork");
  }

/*
  //反复写管道,只写不读
  int count=0;
  while(1)
  {
    write(fd[1],"a",1);
    printf("count:%d\n",count);
    count++;
  }
*/
  //close fd
  close(fd[0]);
  close(fd[1]);
  return 0;
}
