#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//1.熟悉线程控制相关函数

#if 0
void* ThreadEntry(void* arg)
{
  (void) arg;
  while(1)
  {
    printf("In ThreadEntry\n");
    sleep(1);
  }
  return NULL;
}

int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  pthread_detach(tid);
  printf("In MainThread");
  //pthread_cancel(tid);
  return 0;
}
#endif



#if 0
//2.线程之间能够共享虚拟内存地址空间

//int g_val=0;全局变量
void* ThreadEntry(void* arg)
{
  int *p=(int*)arg;//记得转换类型
  (void)arg;
  while(1)
  {
    printf("In ThreadEntry\n");
    (*p)++;
    sleep(1);
  }
  return NULL;
}
int main()
{
  //int val=0;//局部变量
  
  int* p=(int*)malloc(4);
  *p=0;
  pthread_t tid;
  //pthread_create(&tid,NULL,ThreadEntry,NULL);
  //pthread_create(&tid,NULL,ThreadEntry,&val);
  
  pthread_create(&tid,NULL,ThreadEntry,p);
  pthread_detach(tid);
  while(1)
  {
    printf("In MainThread:%d\n",*p);
    sleep(1);
  }
  return 0;
}
#endif



#if 0
//3.线程异常终止的情况

void* ThreadEntry(void* arg)
{
  (void)arg;
  while(1)
  {
    sleep(1);
    int* p=NULL;
    *p=10;
  }
  return NULL;
}
int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  while(1)
  {
    printf("In ThreadEntry\n");
    sleep(1);
  }
  return 0;
}
#endif

//4,多线程如何利用cpu的多核资源
#if 0
void* ThreadEntry(void* arg)
{
  (void)arg;
  while(1);
  return NULL;
}
int main()
{
  pthread_t tid1;
  pthread_t tid2;
  pthread_create(&tid1,NULL,ThreadEntry,NULL);
  pthread_create(&tid2,NULL,ThreadEntry,NULL);
  while(1);
  return 0;
}
#endif

//5.通过多线程提高程序执行效率
//  场景：假设存在一个很大的数组，将数组中每个元素都进行一个乘方运算，
//        再赋值回数组

#include <sys/time.h>

#define SIZE 100000000

int64_t GetUs()
{
  //获得当前精确时间
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec*1000000+tv.tv_usec;
}

void Calu(int* arr,int begin,int end)
{
  int i=begin;
  for(;i<end;i++)
  {
    arr[i]=arr[i]*arr[i];
  }
}
//单线程
#if 0
int  main()
{
  srand(time(NULL));//时间种子
  //由于在栈上无法开辟一个很大的数组，所有在堆上开辟
  int* arr=(int*)malloc(sizeof(int)*SIZE);
  //当前想计算从这个程序的执行时间
  //用时间戳
  //先记录开始的时间
  int begin=GetUs();
  Calu(arr,0,SIZE);
  //再记录结束的时间
  int end=GetUs();

  //两个时间做差得到执行时间
  printf("time=%ld\n",end-begin);
  return 0;
}
#endif

//多线程

#define THREAD_NUM 4

//定义一个arg结构体，里面包含当前的任务数组、一个线程执行的起点和结束
typedef struct Arg
{
  int begin;
  int end;
  int* arr;
}Arg;

void* ThreadEntry(void* arg)
{
  Arg* p=(Arg*)arg;
  Calu(p->arr,p->begin,p->end);
  return NULL;
}
int main()
{
  int* arr=(int*)malloc(sizeof(int)*SIZE);
  Arg args[THREAD_NUM];
  int i=0;
  int base=0;
  for(;i<THREAD_NUM;i++)
  {
    args[i].begin=base;
    args[i].end=base+SIZE/THREAD_NUM;
    args[i].arr=arr;
    base+=SIZE /THREAD_NUM;
  }
  pthread_t tid[THREAD_NUM];
  int64_t begin=GetUs();
  i=0;
  for(;i<THREAD_NUM;i++)
  {
    pthread_create(&tid[i],NULL,ThreadEntry,&args[i]);
  }
  i=0; 
  for(;i<THREAD_NUM;i++)
  {
    pthread_join(tid[i],NULL);
  }
  int64_t end=GetUs();
  printf("time= %ld\n",end-begin);
  return 0;
}

