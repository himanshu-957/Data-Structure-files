#include<stdio.h>
int n = 5;
int q[5];
int f = -1;
int r = -1;
void fenqueue(int data)
{
 if((f == 0 && r == n-1) || (r == f-1))
 {
  printf("Queue Overflow\n");
 }
 else
 {
  if(f == -1)
  {
   f = 0;
   r = 0;
  }
  else if(f == 0)
  {
   f = n-1;
  }
  else
  {
   f -= 1;
  }
  q[f] = data;
  printf("Data enqueued at front is %d\n",data);
 } 
}

void benqueue(int data)
{
 if((r == n-1 && f == 0) || (r == f - 1))
 {
  printf("Queue overflow\n");
 }
 else if(r == n-1 && f!= 0)
 {
  r = 0;
  q[r] = data;
  printf("Enqueued element at back is %d\n",data);
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

void fdequeue()
{
 if(f== -1 || r == -1)
 {
  printf("Queue underflow\n");
 }
 else if(f == r)
 {
  printf("Dequeued element at front is %d\n",q[f]);
  f = -1;
  r = -1;
 }
 else if(f == n-1)
 {
  f = 0;
  printf("Dequeued element at front is %d\n",q[n-1]);
 }
 else
 {
  f += 1;
  printf("Dequeued element at front is %d\n",q[f-1]);
 }
}

void bdequeue()
{
 if(f == -1 || r == -1)
 {
  printf("Queue underflow\n");
 }
 else
 {
  if(f == r)
  {
   printf("Dequeued element at back is %d\n",q[f]);
   f = -1;
   r = -1;
  }
  else if(r == 0)
  {
   r = n-1;
   printf("Dequeued element at back is %d\n",q[0]);
  }
  else
  {
   r -= 1;
   printf("Dequeued element at back is %d\n",q[r+1]);
  }
 }
}

void display()
{
 int count = 0;
 for(int i = f; (i!=r+1 || count ==0);i++)
 {
  count++;
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
 fenqueue(1);
 fenqueue(2);
 display();
 benqueue(3);
 benqueue(4);
 display();
 fenqueue(5);
 fenqueue(6);
 display();
 benqueue(7);
 display();
 fdequeue();
 display();
 bdequeue();
 display();
 bdequeue();
 bdequeue();
 fdequeue();
 fdequeue();
}
