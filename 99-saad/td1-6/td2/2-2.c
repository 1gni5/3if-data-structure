#include<stdio.h>

int main()
{
  int capacity,size = 0,in,i,j, objects[100];
  scanf(" %d",&capacity);
  scanf(" %d",&in);
  while(in != -1)
  {
    objects[size] = in;
    scanf(" %d", &in);
    size++;
  }
  // declaration et initialization du tableau 
  int tab[capacity+1];
  tab[0] = 1;
  for(i = 1; i<capacity+1; i++) tab[i] = 0;
  for(i = 0; i<size;i++)
  {
    tab[objects[i]] = 1;
  }

  // remplissage du tableau, version non dynamique mais même complexité, i.e O(size*capacity)
  for(i=0;i<capacity+1;i++)
  {
    if(tab[i] == 1)
    {
      for(j = 0; j<size;j++)
      {
        tab[i+objects[j]] = 1;
      }
    }
  }
  
  // impression de tab, à enlever pour domjudge
  for(i = 0;i<capacity+1;i++)
  {
    printf("%d ", tab[i]);
  }
  printf("\n");
  //

  if(tab[capacity]==1)
  {
    printf("OUI\r\n");
  } else {
    printf("NON\r\n");
  }
  return 0;
}