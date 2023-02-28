#include<stdio.h>
int n= 5;
int top = -1;
char a[10];
void push(int data)
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

void main()
{
 push(10);
 push(20);
 push(30);
 insertAtBottom(40);
}
