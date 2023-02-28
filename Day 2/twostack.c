#include<stdio.h>
int a[10];
int top1 = -1;
int top2 = 10;
int n = 10;

void push1(int data)
{
 if(top2 - top1 > 1)
 {
  top1 += 1;
  a[top1] = data;
  printf("%d is inserted in stack1\n",a[top1]);
 }
 else
 {
  printf("Stack full\n");
 }
}

void push2(int data)
{
 if(top2 - top1 > 1)
 {
  top2 -= 1;
  a[top2] = data;
  printf("%d is inserted in stack2\n",a[top2]);
 }
 else
 {
  printf("Stack full\n");
 }
}

int pop1()
{
 if(top1 > -1)
 {
  top1 -= 1;
  return a[top1 + 1];
 }
 else
 {
  return -1;
 }
}

int pop2()
{
 if(top2 < 10)
 {
  top2 += 1;
  return a[top2-1];
 }
 else
 {
  return -1;
 }
}

void main()
{
 push1(10);
 push1(20);
 push1(30);
 push1(40);
 push1(50);
 push1(60);
 push2(70);
 push2(80);
 push2(90);
 push2(100);
 push2(110);
 int x = pop1();
 printf("%d popped from stack1\n",x);
 push2(110);
 x = pop1();
 printf("%d popped from stack1\n",x);
 x = pop1();
 printf("%d popped from stack1\n",x);
 x = pop1();
 printf("%d popped from stack1\n",x);
 x = pop1();
 printf("%d popped from stack1\n",x);
 x= pop1();
 printf("%d popped from stack1\n",x);
 x = pop2();
 printf("%d popped from stack2\n",x);
 x = pop2();
 printf("%d popped from stack2\n",x);
 x = pop2();
 printf("%d popped from stack2\n",x);
 x = pop2();
 printf("%d popped from stack2\n",x);
 x = pop2();
 printf("%d popped from stack2\n",x);
}
