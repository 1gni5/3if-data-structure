#include<stdio.h>

int main()
{
  int X[1000];
  int in,size=0;
  scanf(" %d",&in);
  while(in!=-1)
  {
    X[size]=in;
    size++;
    scanf(" %d",&in);
  }
  int parcours = 0;
  while(parcours < size/2)
  {
    if(X[parcours] != X[size-1-parcours])
    {
      printf("%d\r\n",0);
      return 0;
    }
    parcours++;
  }
  printf("%d\r\n",1);
  return 0;
}