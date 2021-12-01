#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int value;
  struct node* next;
} node;

typedef struct{
  node* first;
  node* last;
} File;

File* Init();

void Destroy(File* file);

int Queue(File* file, int value);

int Dequeue(File * file, int * val);

int main(void) 
{
  char lecture[100];
  int val;
  File * f;
  f = Init();

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"queue")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      Queue(f,val);
    } else if (strcmp(lecture,"dequeue")==0) {
      if(Dequeue(f,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(f);
  return 0;
}

File* Init()
{
  File* file = (File*)malloc(sizeof(File));
  file->first = NULL;
  file->last = NULL;
  return file;
}

int Queue(File * file, int value)
{
  node* toAdd = (node*)malloc(sizeof(node));
  toAdd->value = value;
  toAdd->next = NULL;
  if(file->last == NULL)
  {
    file->first = toAdd;
    file->last = toAdd;
    return 0;
  } 
  file->last->next = toAdd;
  file->last = toAdd;
  return 0;
}

int Dequeue(File * file, int * val)
{
  if(file->last == NULL)
    return 0;
  *val = file->first->value;
  if(file->first == file->last)
  {
    file->first = NULL;
    file->last = NULL;
    return 1;
  }
  node* toFree = file->first;
  file->first = file->first->next;
  free(toFree);
  return 1;
}

void Destroy(File* file)
{
  free(file);
}