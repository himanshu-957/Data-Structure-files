#include<stdio.h>
int size = 0;
//------------------------------------------------------------------------------------------------------------------------------------
void swap(int* i, int* j)
{
 int temp;
 temp = *i;
 *i = *j;
 *j = temp;
}
//------------------------------------------------------------------------------------------------------------------------------------
void insert(int array[], int newNum)
{
 if(size == 0)
 {
  array[0] = newNum;
  size += 1;
 }
 else
 {
  array[size] = newNum;
  size += 1;
  for(int i = size/2 - 1; i >= 0; i--)
  {
   heapify(array, size, i);
  }
 }
}
//------------------------------------------------------------------------------------------------------------------------------------
void heapify(int array[], int size, int i)
{
 if(size == 1)
 {
  printf("Single element in the heap\n")
 }
 else
 {
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;
  if(l < size && array[l] > array[largest])
  {
   largest = l;
  }
  if(r < size && array[r] > array[largest])
  {
   largest = r;
  }
  if(largest != i)
  {
   swap(&array[i], &array[largest]);
   heapify(array, size, largest);
  }
 }
}
//------------------------------------------------------------------------------------------------------------------------------------
void main()
{
 
}
