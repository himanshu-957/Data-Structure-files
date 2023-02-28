#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node* next;
 struct node* prev;
};
struct node* start = NULL;
//-----------------------------------------------------------------------------------------------------------------------------------
struct node *create_node()
{
 int x;
 struct node *new = malloc(sizeof(struct node));
 printf("Enter the data of new node: ");
 scanf("%d",&new->data);
 new->next = NULL;
 new->prev = NULL;
 return new;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void insert_front()
{
 struct node *new;
 new = create_node();
 new->next = start;
 start->prev = new;
 start = new;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void insert_back()
{
 struct node *new;
 new = create_node();
 struct node* ptr;
 ptr = start;
 while(ptr->next != NULL)
 {
  ptr = ptr->next;
 }
 ptr->next = new;
 new->prev = ptr;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void insert_before()
{
 struct node *new;
 new = create_node();
 int data;
 printf("Enter the value before which data is to inserted: ");
 scanf("%d",&data);
 struct node* ptr;
 ptr = start;
 struct node* ptr1;
 if(data == start->data)
 {
  insert_front();
 }
 else
 {
  while(ptr->next->data != data)
  {
   ptr = ptr->next;
  }
  ptr1 = ptr->next;
  ptr->next = new;
  new->prev = ptr;
  ptr1->prev = new;
  new->next = ptr1;
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void insert_after()
{
 struct node *new;
 new = create_node();
 int data;
 printf("Enter the value after which data is to inserted: ");
 scanf("%d",&data);
 struct node* ptr;
 ptr = start;
 struct node* ptr1;
 while(ptr->data != data)
 {
  ptr = ptr->next;
 }
 ptr1 = ptr->next;
 ptr->next = new;
 new->prev = ptr;
 ptr1->prev = new;
 new->next = ptr1;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void delete_front()
{
 start = start->next;
 start->prev = NULL;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void delete_back()
{
 struct node* ptr;
 ptr = start;
 while(ptr->next->next != NULL)
 {
  ptr = ptr->next;
 }
 ptr->next = NULL;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void delete_element()
{
 printf("Enter which element you want to delete: ");
 int data;
 scanf("%d",&data);
 struct node* ptr;
 ptr = start;
 if(ptr->data == data)
 {
  delete_front();
 }
 else
 {
  while(ptr->next->data != data)
  {
   ptr = ptr->next;
  }
  ptr->next = ptr->next->next;
  ptr->next->prev = ptr;
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void createList()
{
 int n;
 printf("Enter number of nodes: ");
 scanf("%d",&n);
 struct node *new;
 struct node *last;
 new = create_node();
 start = new;
 last = new;
 for(int i = 1; i < n; i++)
 {
  new = create_node();
  last->next = new;
  new->prev = last;
  last = new;
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void display()
{
 struct node* ptr;
 ptr = start;
 while(ptr != NULL)
 {
  printf("%d\n",ptr->data);
  ptr = ptr->next;
 }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void main()
{
  createList();
  display();
  insert_front();
  display();
  insert_back();
  display();
  insert_before();
  display();
  insert_after();
  display();
  delete_front();
  printf("\n");
  display();
  delete_back();
  printf("\n");
  display();
  delete_element();
  printf("\n");
  display();
}
