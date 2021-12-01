#include<stdio.h>

void filling(int tab[], int Sol, int Vol)
{
  tab[Sol] = 1;
  if(Sol*3 <= Vol && tab[Sol*3] != 1 ) filling(tab,Sol*3,Vol);
  if(Sol*2 <= Vol && tab[Sol*2] != 1 ) filling(tab,Sol*2,Vol);
  if(tab[Sol/5] != 1) filling(tab, Sol/5, Vol);
}

int findMax (int tab[], int Vol)
{
  int i, max = tab[0];
  for (i=0; i<Vol;i++)
  {
    if(tab[i] == 1) max = i;
  }
  return max;
}

int main()
{
  int V, S, i;
  scanf(" %d", &V);
  scanf(" %d", &S);
  int tab[V+1];
  for(i = 0; i<V+1;i++) tab[i] = 0;
  filling(tab, S,V+1);
  printf("%d\r\n", findMax(tab, V));
}