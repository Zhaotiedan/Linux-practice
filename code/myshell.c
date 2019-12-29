#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

//input--待切分命令
//output--表示切分u结果（字符串数组）
//返回值为数组中有效的指令个数
int Split(char input[],char* output[])
{
  //借助strtok
  char* p=strtok(input," ");//以空格来切分，返回的是指向第一个字符串的指针
  int i=0;
  while(p!=NULL)
  {
    //字符串放入output
    output[i]=p;
    i++;
    p=strtok(NULL," ");
  }
  output[i]=NULL;//必须以空指针来结尾
  return i;
}

void CreateProcess(char* argv[],int n)
{
  (void)n;
  //1.创建子进程
  int ret=fork();
  //2.父进程进行进程等待，子进程进行程序替换
  if(ret>0)
  {
    //father
    wait(NULL);
  }
  else if(ret==0)
  {
    //child
    ret=execvp(argv[0],argv);//敲入的指令只有一个名字，没有路径，得去path中找
    //出错的判定if可省略，如果替换成功，肯定不会再执行后面这些代码
    perror("exec");
    exit(0);
  }
  else{
    perror("fork");
  }
}

int main()
{
  while(1)
  {
    //1.打印一个提示符，用缓冲区刷新输出到显示器上
    printf("[zhaotiedan@localhost myshell]$ ");
    fflush(stdout);
    //fflush(stdout);
    //2.用户输入一个指令,遇到回车读取结束
    char command[1024]={0};
    //scanf("%s",command);//scanf遇到空格会返回，所以不能用它
    gets(command);//一次读一行数据
    //3.解析指令,把要执行哪个程序识别出来，哪些是命令，哪些是参数
    char *argv[1024]={0};//放切分结果
    int n=Split(command,argv);
    //4.创建子进程，进行程序替换
    CreateProcess(argv,n);
  }
  return 0;
}
