#include<stdio.h>
int n= 10;
int top = -1;
int a[10];
int push(int data)
{
 if(top == n-1)
 {
  printf("stack is full\n");
 }
 else
 {
  top += 1;
  a[top] = data;
  printf("%d is pushed in stack\n",a[top]);
 } 
}

int pop()
{
 if(top == -1)
 {
  return -1; 
 }
 top -= 1;
 return a[top+1];
}

void sortinsert(int data)
{
 if(a[top] <= data)
 {
  push(data);
 }
 else
 {
  int x = pop();
  sortinsert(data);
  push(x);
 }
}

void insertAtBottom(int Data)
{
 if(top == -1)
 {
  push(Data);
 }
 else
 {
  int x = pop();
  insertAtBottom(Data);
  push(x);
 }
}

void sortstack()
{
 if(top == 0)
 {
  
 }
 else
 {
  int x = pop();
  sortstack();
  sortinsert(x);
 }
}

void reversestack()
{
 if(top == -1)
 {
 }
 else
 {
  int x = pop();
  reversestack();
  insertAtBottom(x);
 }
}

void main()
{
 push(10);
 push(20);
 push(30);
 push(40);
 push(50);
 push(60);
 push(70);
 push(80);
 push(90);
 printf("Now insertion\n");
 reversestack();
 printf("After insertion\n");
 int x;
 do
 {
  x = pop();
  if(x != -1)
  printf("%d ",x); 
 }while(x != -1);
 printf("\n");
}
