#include<stdio.h>
#include<math.h>

#define max(a, b) (((a)>(b))?(a):(b))

int main()
{
  int A, B,i,j,noSol = 1;
  scanf(" %d", &A);
  scanf(" %d", &B);
  int valMax = max(sqrt(A),sqrt(B));
  for (i= -valMax; i<valMax;i++)
  {
    for(j = -valMax; j<valMax;j++)
    {
      if(pow(i,2)+pow(j,2) == A && pow(i,3)+pow(j,3) == B)
      {
        printf("%d %d\r\n", i, j);
        noSol = 0;
      }
    }
  }
  if(noSol)
    printf("-\r\n");
}