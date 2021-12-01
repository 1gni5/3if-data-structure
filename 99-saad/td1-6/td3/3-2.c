#include<stdio.h>

int main()
{
  int N, i, j;
  scanf(" %d", &N);
  int tab[N][N];

  // initialisation de la grille
  for (i = 0; i<N;i++)
  {
    for (j = 0; j<N; j++)
    {
      scanf(" %d", &tab[i][j]);
    }
  }
  
  if(tab[0][0] == -1 ){ // obstacle dans la case de depart =  ne peut pas bouger
    printf("%d\r\n", 0);
    return 0;
  }

  // initialisation de la matrice NxN representant le nb de chemins possible pour aller à chaque case de la grille
  int nbWays[N][N];
  for (i = 0; i<N;i++)
  {
    for(j = 0; j<N;j++)
    {
      nbWays[i][j] = 0;
    }
  }

  nbWays[0][0] = 1; // 1 seul chemin pour aller de la case de depart a la case de depart

  for (i = 0; i<N;i++)
  {
    for (j = 0; j<N;j++)
    {
      if(tab[i][j] == -1)
      {
        nbWays[i][j] = 0;
      } else {
        if( i > 0) nbWays[i][j] += nbWays[i-1][j];
        if( j > 0) nbWays[i][j] += nbWays[i][j-1];
      }
    }
  }

  // programme pour imprimer le nb de chemins, a enlever pour domjudge 
  for (i = 0; i<N;i++)
  {
    for(j = 0; j<N;j++)
    {
      printf("%d ", nbWays[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  //

  printf("%d\r\n", nbWays[N-1][N-1]);
}