#include<stdio.h>

int q[5];
int f = -1;
int r = -1;
int n = 5;

void enqueue(int data)
{
 if(r == n-1)
 {
  printf("Queue overflow\n");
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
 else
 {
  f += 1;
  printf("Dequeued element is %d\n",q[f-1]);
 }
}

void display()
{
 for(int i = f; (i<=r) && (r != -1);i++)
 {
  printf("%d ",q[i]);
 }
 printf("\n");
}

void main()
{
 dequeue();
 enqueue(5);
 enqueue(1);
 enqueue(2);
 enqueue(3);
 enqueue(4);
 display();
 enqueue(6);
 dequeue();
 dequeue();
 dequeue();
 dequeue();
 display();
 dequeue();
 dequeue();
 display();
}
