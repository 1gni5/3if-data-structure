#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// AddRight()
// AddLeft()
// PopRight()
// PopLeft()

typedef struct node
{
  int value;
  struct node* next;
  struct node* previous;
} node;

typedef struct
{
  node* head;
  node* tail;
} Deque;

Deque* Init();

int AddRight(Deque * d, int value);

int AddLeft(Deque *d, int value);

int PopRight(Deque *d, int* val);

int PopLeft(Deque *d, int* val);

void Destroy(Deque *d);

int main(void) 
{
  char lecture[100];
  int val;
  Deque * d;
  d = Init();

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"addleft")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      AddLeft(d,val);
    } else if (strcmp(lecture,"addright")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      AddRight(d,val);
    }else if (strcmp(lecture,"popleft")==0) {
      if(PopLeft(d,&val))
      {
        printf("%d\r\n",val);
      }
    }else if (strcmp(lecture,"popright")==0) {
      if(PopRight(d,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(d);
  return 0;
}

Deque* Init()
{
  Deque* deq = (Deque*)malloc(sizeof(Deque));
  deq->head = (node*)malloc(sizeof(node));
  deq->tail = (node*)malloc(sizeof(node));
  deq->head->next =deq->tail;
  deq->head->previous = NULL;
  deq->head->value = (int)NULL;
  deq->tail->next =NULL;
  deq->tail->previous = deq->head;
  deq->tail->value = (int)NULL;
  return deq;
}

int AddLeft(Deque *d, int value)
{
  node* toAdd = (node*)malloc(sizeof(node));
  toAdd->value = value;
  toAdd->next = d->head->next;
  toAdd->previous = d->head;
  d->head->next->previous = toAdd;
  d->head->next = toAdd;
  return 1;
}

int AddRight(Deque *d, int value)
{
  node* toAdd = (node*)malloc(sizeof(node));
  toAdd->value = value;
  toAdd->next = d->tail;
  toAdd->previous = d->tail->previous;
  d->tail->previous->next = toAdd;
  d->tail->previous = toAdd;
  return 1;
}

int PopLeft(Deque *d, int *val)
{
  if(d->head->next == d->tail)
    return 0;
  *val = d->head->next->value;
  node* tmp = d->head->next;
  tmp->next->previous = d->head;
  d->head->next = d->head->next->next;
  free(tmp);
  return 1;
}

int PopRight(Deque *d, int *val)
{
  if(d->head->next == d->tail)
    return 0;
  *val = d->tail->previous->value;
  node* tmp = d->tail->previous;
  tmp->previous->next = d->tail;
  d->tail->previous = d->tail->previous->previous;
  free(tmp);
  return 1;
}

void Destroy(Deque *d)
{
  free(d->head);
  free(d->tail);
  free(d);
}