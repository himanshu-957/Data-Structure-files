#include<stdio.h>

int q[5];
int f = -1;
int r = -1;
int n = 5;

void enqueue(int data)
{
 if((r == n-1 && f == 0) || (r == f - 1))
 {
  printf("Queue overflow\n");
 }
 else if(r == n-1 && f!= 0)
 {
  r = 0;
  q[r] = data;
  printf("Enqueued element is %d\n",data);
 }
 else
 {
  r += 1;
  q[r] = data;
  if(f == -1)
  {
   f = 0;
  }
  printf("Enqueued element is %d\n",data);
 }
}

void dequeue()
{
 if(f== -1 || r == -1)
 {
  printf("Queue underflow\n");
 }
 else if(f == r)
 {
  printf("Dequeued element is %d\n",q[f]);
  f = -1;
  r = -1;
 }
 else if(f == n-1)
 {
  f = 0;
  printf("Dequeued element is %d\n",q[n-1]);
 }
 else
 {
  f += 1;
  printf("Dequeued element is %d\n",q[f-1]);
 }
}

void display()
{
 for(int i = f; (i!=r+1);i++)
 {
  printf("%d ",q[i]);
  if(i == n-1 && r!= n-1)
  {
   i = -1;
  }
  
 }
 printf("\n");
}

void main()
{
 enqueue(1);
 enqueue(2);
 enqueue(3);
 enqueue(4);
 enqueue(5);
 display();
 dequeue();
 dequeue();
 dequeue();
 dequeue();
 display();
 enqueue(6);
 dequeue();
 dequeue();
 enqueue(7);
 display();
}
