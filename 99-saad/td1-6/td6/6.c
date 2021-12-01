#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* mettez ici vos déclarations de fonctions et types */

/* état d’une case (peut être fait aussi avec un enum) */
#define EMPTY 0
#define SET 1
#define REMOVED 2

/* raccourcis vers les types clé et valeur */
typedef char *Key;
typedef char *Value;

/* utile pour l’affichage */
const char *Labels[] = {"Empty", "Set", "Removed"};

/* une cellule de la table */
typedef struct
{
  Key key;
  unsigned char status;
  Value val;
} Data;

/* la table de hachage elle-même */
typedef struct
{
  Data *tab;
  int size;
} HashTable;

void error(void);

HashTable *Init(int size);

void Destroy(HashTable *ht);

void Stats(HashTable *ht);

int Query(Key key, HashTable *ht, int *ifree);

void Add(Key key, Value val, HashTable *ht);

void Remove(Key key, HashTable *ht);

int main(void)
{
  int size;
  char lecture[100];
  char *key;
  char *val;
  HashTable* ht;

  if (fscanf(stdin, "%99s", lecture) != 1)
    error();
  while (strcmp(lecture, "bye") != 0)
  {
    if (strcmp(lecture, "init") == 0)
    {
      if (fscanf(stdin, "%99s", lecture) != 1)
        error();
      size = atoi(lecture);
      /* mettre le code d'initialisation ici */
      ht = Init(size);
    }
    else if (strcmp(lecture, "insert") == 0)
    {
      if (fscanf(stdin, "%99s", lecture) != 1)
        error();
      key = strdup(lecture);
      if (fscanf(stdin, "%99s", lecture) != 1)
        error();
      val = strdup(lecture);
      /* mettre ici le code d'insertion */
      Add(key,val,ht);
    }
    else if (strcmp(lecture, "delete") == 0)
    {
      if (fscanf(stdin, "%99s", lecture) != 1)
        error();
      key = strdup(lecture);
      /* mettre ici le code de suppression */
      Remove(key, ht);
    }
    else if (strcmp(lecture, "query") == 0)
    {
      if (fscanf(stdin, "%99s", lecture) != 1)
        error();
      /* mettre ici le code de recherche et traitement/affichage du résultat */
      int i;
      int res = Query(lecture, ht, &i);
      if(res != -1)
      {
        printf("%s\r\n", ht->tab[res].val);
      } else {
        printf("Not found\r\n");
      }
    }
    else if (strcmp(lecture, "destroy") == 0)
    {
      /* mettre ici le code de destruction */
      Destroy(ht);
    }
    else if (strcmp(lecture, "stats") == 0)
    {
      /* mettre ici le code de statistiques */
      Stats(ht);
    }

    if (fscanf(stdin, "%99s", lecture) != 1)
      error();
  }
  return 0;
}

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
  n = n % (sizeof(unsigned int) * 8);
  return (val << n) | (val >> (sizeof(unsigned int) * 8 - n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
  unsigned int i;
  unsigned int val = 0;
  unsigned int power = 0;
  for (i = 0; i < strlen(key); i++)
  {
    val += shift_rotate(key[i], power * 7);
    power++;
  }
  return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size)
{
  return val % size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
  return hash(Encode(key), size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */

void error(void)
{
  printf("input error\r\n");
  exit(0);
}

HashTable *Init(int size)
{
  HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
  ht->size = size;
  ht->tab = (Data *)malloc(sizeof(Data) * size);
  int i;
  for (i = 0; i < size; i++)
  {
    ht->tab[i].status = EMPTY;
  }
  return ht;
}

void Destroy(HashTable *ht)
{
  int i;
  for (i = 0; i < ht->size; i++)
  {
    if (ht->tab[i].status == SET)
    {
      free(ht->tab[i].key);
      free(ht->tab[i].val);
    }
  }
  free(ht->tab);
  free(ht);
}

void Stats(HashTable *ht)
{
  int stats[3] = {0, 0, 0};
  int i;
  for (i = 0; i < ht->size; i++)
  {
    stats[ht->tab[i].status]++;
  }
  printf("size    : %d\r\n", ht->size);
  printf("empty   : %d\r\n", stats[EMPTY]);
  printf("deleted : %d\r\n", stats[REMOVED]);
  printf("used    : %d\r\n", stats[SET]);
}

#define I ((hi + i) % s)

int Query(Key key, HashTable *ht, int *ifree) //retourne la position de la cle si elle est deja presente dans le tableau, sinon retourne -1
{                                             //ifree retourne soit une position vide si il y en a, sinon une position supprimeée s'il y'en a, sinon -1
  int hi = HashFunction(key, ht->size);
  int i = 0;
  int s = ht->size;
  Data *t = ht->tab;
  *ifree = -1;
  while (i < s && t[I].status != EMPTY)
  {
    if (t[I].status == SET && !strcmp(t[I].key, key))
    {
      return I;
    }
    if (t[I].status == REMOVED && *ifree == -1)
    {
      *ifree = I;
    }
    i++;
  }
  if (i != s)
  {
    *ifree = I;
  }
  return -1;
}

void Add(Key key, Value val, HashTable *ht)
{
  int i;
  int query = Query(key, ht, &i);
  if (query != -1) // mis a jour de la valeur dans la case key
  {
    free(ht->tab[query].val);
    free(key); // liberation de la cle donnee en argument car non utilisee
    ht->tab[query].val = val;
  }
  else if (i != -1)
  { // si i == -1 il n y a pas de position vide ni de position supprimee
    ht->tab[i].key = key;
    ht->tab[i].val = val;
    ht->tab[i].status = SET;
  }
}

void Remove(Key key, HashTable *ht)
{
  int i;
  int query = Query(key, ht, &i);
  if (query != -1) // la cle est trouvee donc il faut liberer la valeur et la cle
  {
    free(ht->tab[query].val);
    free(ht->tab[query].key);
    ht->tab[query].status = REMOVED;
  }
}