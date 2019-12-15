#include <stdio.h>

void Fun1()
{
  int *p=NULL;
  *p=10;
  printf("%d",*p);
  printf("I love you!\n");
  printf("I love you!\n");
}
int main()
{
  Fun1();
  return 0;
}
