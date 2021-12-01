#include<stdio.h>

int factorielle(int n)
{
  int result = 1;
  for(int i = 1; i<=n;i++)
  {
    result = result*i;
  }
  return result;
}

int main()
{
  int a;
  scanf(" %d",&a);
  printf("%d\r\n", factorielle(a));
}