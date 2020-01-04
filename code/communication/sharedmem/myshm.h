#pragma once//避免头文件重复报引用
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

static int CreateShm()//static:把该函数复制到不同的地方，避免多文件用这个头文件时会重复定义该函数
{
  key_t key=ftok(".",0x3);
  if(key==-1)
  {
    perror("ftok");
    return 1;              
  }
  printf("key:%d\n",key);
  int ret=shmget(key,1024,IPC_CREAT | 0666);//0666--权限
  if(ret<0)
  {
    perror("shmget");
    return 1;           
  }
  printf("ret:%d\n",ret);
  return ret;
}
