#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated;
  int filled;
  int* array;
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);


int main(void) 
{
  char lecture[100];
  int val;
  BinaryHeap * heap;
  heap = Init(10);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"insert")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(heap,val);
    } else if (strcmp(lecture,"extract")==0) {
      if(ExtractMax(heap,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap;
  heap = (BinaryHeap*)malloc(sizeof(heap));
  heap->allocated = size;
  heap->filled = 0;
  heap->array = (int*)malloc(sizeof(int)*size);
  return heap;
}

void InsertValue(BinaryHeap * heap, int value)
{
  /* put your insert code here */
  if(heap->filled == heap->allocated)
  {
    heap = (BinaryHeap*)realloc(heap, 2*heap->allocated);
  }
  heap->array[heap->filled] = value;
  if(heap->filled > 0) {
    int father = (heap->filled -1)/2;
    int son = heap->filled;
    while(heap->array[son] > heap->array[father])
    {
      int tmp = heap->array[son];
      heap->array[son] = heap->array[father];
      heap->array[father] = tmp;
      son = father;
      father = (son-1)/2;
    }
  }
  heap->filled +=1;
}

int ExtractMax(BinaryHeap * heap, int *res)
{
  /* put your extraction code here */
  if(heap->filled == 0)
    return 0;
  *res = heap->array[0];
  //printf("%d\n", *res);
  heap->array[0] = heap->array[heap->filled-1];
  heap->filled -= 1;
  int father = 0;
  int leftson = 2*father+1;
  int rightson = 2*father +2;
  int tmp;
  while((leftson < heap->filled &&  heap->array[father] < heap->array[leftson]))
  {
    if( rightson < heap->filled && heap->array[leftson] < heap->array[rightson]) // le pere a une feuille a droite et une a gauche et celle a droite est plus grande que celle a droite
    {
      tmp = heap->array[rightson];
      heap->array[rightson] = heap->array[father];
      heap->array[father] = tmp;
      father = rightson;
    } else { // le pere a une seule feuille, a gauche 
      tmp = heap->array[leftson];
      heap->array[leftson] = heap->array[father];
      heap->array[father] = tmp;
      father = leftson;
    }
    leftson = 2*father+1;
    rightson = 2*father+2;
  }
  return 1;
}

void Destroy(BinaryHeap * heap)
{
  free(heap->array);
  free(heap);
}