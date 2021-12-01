#include<stdio.h>

int main()
{
  int n,i;
  scanf(" %d",&n);
  int values[n];
  for (i = 0; i<n;i++)
  {
    scanf(" %d", &values[i]);
  }
  int results[n];
  results[0] = values[0];
  int somme;
  for (i = 1; i<n;i++)
  {
    somme = results[i-1] + values[i];
    results[i] = (somme<values[i])?values[i]:somme;
  }
  int max = results[0];
  for (i = 1;i<n;i++)
  {
    if(results[i] > max)
    {
      max = results[i];
    }
  }
  printf("%d\r\n", max);
}