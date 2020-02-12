#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* ThreadEntry(void* arg)
{
  while(1)
  {
    printf("In ThreadEntry:%lu\n",pthread_self());
    sleep(1);
  }
}

int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  while(1)
  {
    printf("In MainThread:%lu\n",pthread_self());
    sleep(1);
  }
  return 0;
}