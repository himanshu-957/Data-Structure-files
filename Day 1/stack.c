#include<stdio.h>
int n= 10;
int top = -1;
char a[10];
void push(char data)
{
 if(top == n-1)
 {
  printf("stack is full\n");
 }
 else
 {
  top += 1;
  a[top] = data;
  printf("%c is pushed in stack\n",a[top]);
 }
 
}

char pop()
{
 if(top == -1)
 {
  return -1; 
 }
 top -= 1;
 return a[top+1];
}

void main()
{
 
 /*char c[9] = "[{()}]]{}";
 int t = 0;
 char y;
 int count = 0,flag = 0;
 while(top < n-1 && t < 9)
 {
  if(c[t] == '[' || c[t] == '{' || c[t] == '(')
  {
   push(c[t]);
   count++;
  }
  else if(c[t] == ']' || c[t] == '}' || c[t] == ')')
  {
   y = pop();
   count--;
   if((c[t] == ']' && y == '[') || (c[t] == ')' && y == '(') || (c[t] == '}' && y == '{'))
   {
   }
   else
   {
    flag = 1;
    break;
   }
  }
  
  t++;
 }
 if(flag == 1 || count != 0)
 {
  printf("UnBalanced\n");
 }
 else
 {
  printf("Balanced\n");
 }*/
}
