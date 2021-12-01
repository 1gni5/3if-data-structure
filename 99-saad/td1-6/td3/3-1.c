#include<stdio.h>

int filling(int capacity, int nbObjects, int tab[][capacity+1], int objects[])
{
  int i, j, k;
  for (i = 0; i<nbObjects+1; i++)
  {
    for(j = 0; j<capacity+1; j++)
    {
      tab[i][j] = 0;
    }
  }
  tab[0][0] = 1;

  // filling 
  for (i = 1; i< nbObjects+1;i++)
  {
    for (j = 0; j<capacity+1;j++)
    {
      if(tab[i-1][j] == 1) {
        tab[i][j] = 1;
      }
      if((j-objects[i-1]) >= 0 && tab[i-1][j-objects[i-1]] == 1){
        tab[i][j] = 1;
      }
    }
  }
  
  // imprimer knapsack
  for(i = 0; i<nbObjects+1;i++)
  {
    for(j = 0; j<capacity+1; j++)
    {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  //

  return tab[nbObjects][capacity];
}

int main()
{
  int capacity, in, nbObjects = 0, objects[100];
  scanf(" %d", &capacity);
  scanf(" %d", &in);
  while(in != -1)
  {
    objects[nbObjects] = in;
    nbObjects++;
    scanf(" %d", &in);
  }
  int knapsack[nbObjects+1][capacity+1];

  if(filling(capacity, nbObjects, knapsack, objects))
    printf("OUI\r\n");
  else 
    printf("NON\r\n");
}