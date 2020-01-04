#include "myshm.h"
#include <string.h>

int main()
{
  //往共享内存中写数据
  
  //1.创建共享内存
  int shmid=CreateShm();
  //2.附加进程到共享内存上
  char*p=(char*)shmat(shmid,NULL,0);
  //3.使用该空间
  strcpy(p,"hello sharespace!");
  return 0;
}
