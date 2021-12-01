#include<stdio.h>

int main()
{
  int a;
  scanf(" %d",&a);
  while(a!=1)
  {
    printf("%d\r\n", a);
    if(a%2==0){
      a /=2;
    } else if(a%2==1){
      a = a*3+1;
    }
  }
  printf("%d\r\n",a);
}