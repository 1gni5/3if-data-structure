#include<stdio.h>

int main()
{
  int capacity, in, nbObjects = 0, objects[100], i, j, k;
  scanf(" %d", &capacity);
  scanf(" %d", &in);
  while(in != -1)
  {
    objects[nbObjects] = in;
    nbObjects++;
    scanf(" %d", &in);
  }

  int knapsack[nbObjects+1][capacity+1];
  for (i = 0; i<nbObjects+1; i++)
  {
    for(j = 0; j<capacity+1; j++)
    {
      knapsack[i][j] = 0;
    }
  }
  for (i = 0; i< nbObjects+1; i++) knapsack[i][0] = 1;
  //for (i = 0; i< nbObjects;i++) knapsack[1][objects[i]] =1; 

  // filling : complexite = O (capacity*nbObjects²)

  for (i = 0; i<nbObjects+1; i++)
  {
    for (j = 0; j<capacity+1; j++)
    {
      if( knapsack[i][j] == 1 )
      {
        if(i+1<nbObjects+1) knapsack[i+1][j] = 1;
        for( k = 0; k < nbObjects;k++ )
        {
          if(i+1<nbObjects+1 && (j + objects[k])<capacity+1) knapsack[i+1][j+objects[k]] = 1;
        }
      }
    }
  }

  // imprimer knapsack, a enlever pour domjudge
  for(i = 0; i<nbObjects+1;i++)
  {
    for(j = 0; j<capacity+1; j++)
    {
      printf("%d ", knapsack[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // 

  if(knapsack[nbObjects][capacity] == 1)
  {
    printf("OUI\r\n");
  } else {
    printf("NON\r\n");
  }
  return 0;
}