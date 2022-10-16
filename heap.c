#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    if (pq->capac == 0 || pq->size == 0) return NULL;
    void * dato = pq->heapArray[0].data;
    return dato;
}



void heap_push(Heap* pq, void* data, int priority){
   if(pq -> capac == pq -> size){
      pq -> capac = (2 * pq -> capac) + 1;
      pq -> heapArray = (heapElem*) realloc (pq -> heapArray, pq -> capac * sizeof(heapElem));
   }
   pq -> heapArray[pq -> size].data = data;
	 pq -> heapArray[pq -> size].priority = priority;
   int auxPrio;
   void * auxData;
   for (int i = pq -> size; i > 0; i--){
     int parent = (i - 1)/2;
     if(pq -> heapArray[i].priority > pq -> heapArray[parent].priority){
        auxPrio = pq -> heapArray[parent].priority;
        auxData = pq -> heapArray[parent].data;
        pq -> heapArray[parent].data = pq -> heapArray[i].data;
        pq -> heapArray[parent].priority = pq -> heapArray[i].priority;
        pq -> heapArray[i].priority = auxPrio;
        pq -> heapArray[i].data = auxData;
     }
  }
   pq -> size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * heap=(Heap*)malloc(sizeof(Heap*));
  if(heap==NULL) return NULL;
  heap->heapArray = (heapElem*)malloc(sizeof(heapElem)*3);
  heap->size = 0;
  heap->capac = 3;
  return heap;
}
