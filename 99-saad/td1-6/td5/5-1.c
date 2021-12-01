#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int size;
  int begin;
  int end;
  int* array;
} File;

File* Init(int size);

void Destroy(File* file);

int Queue(File* file, int value);

int Dequeue(File * file, int * val);

int main(void) 
{
  char lecture[100];
  int val;
  File * f;
  f = Init(100);

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

File* Init(int size)
{
  File * file = (File*)malloc(sizeof(File));
  file->array = (int*)malloc(sizeof(int)*size);
  file->size = size;
  file->begin = 0;
  file->end = 0;
  return file;
}

int Queue(File* file, int value)
{
  if((file->end+1)%file->size != file->begin)
  {
    file->array[file->end] = value;
    file->end = (file->end + 1)%file->size;
    return 0;
  }
  return 1;
}

int Dequeue(File* file, int* val)
{
  if(file->end == file->begin)
    return 0;
  *val = file->array[file->begin];
  file->begin = (file->begin+1)%file->size;
  return 1;
}

void Destroy(File* file)
{
  free(file->array);
  free(file);
}
