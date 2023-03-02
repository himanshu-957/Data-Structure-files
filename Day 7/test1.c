#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node* next;
};
struct node* start = NULL;

struct node *create_node()
{
 int x;
 struct node *new = malloc(sizeof(struct node));
 printf("Enter the data for new element in queue: ");
 scanf("%d",&new->data);
 new->next = NULL;
 return new;
}
//------------------------------------------------------------------------------------------------------------------------------------
void enqueue()
{
 struct node* new;
 new = create_node();
 struct node* ptr;
 ptr = start;
 if(start == NULL)
 {
  start = new;
 }
 else
 {
  while(ptr->next!=NULL)
  {
   ptr = ptr->next;
  }
  ptr->next = new;
 }
}
//------------------------------------------------------------------------------------------------------------------------------------
void dequeue()
{
 struct node* new;
 if(start == NULL)
 {
  printf("Queue is empty\n");
 }
 else
 {
 printf("dequeued element is: %d\n",start->data);
 start = start->next;
 }
}
//------------------------------------------------------------------------------------------------------------------------------------
void display()
{
 struct node* ptr;
 ptr = start;
 while(ptr != NULL)
 {
  printf("%d ",ptr->data);
  ptr = ptr->next;
 }
 printf("\n");
}
//------------------------------------------------------------------------------------------------------------------------------------
void main()
{
 enqueue();
 enqueue();
 enqueue();
 display();
 dequeue();
 display();
 dequeue();
 display();
 dequeue();
 display();
 dequeue();
}
