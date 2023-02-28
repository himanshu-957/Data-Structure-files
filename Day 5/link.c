#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

struct node* start;

void delete_data(int data)
{
 struct node* ptr;
 struct node* temp;
 ptr = start;
 temp = start;
 temp = temp->next;
 while(temp->data!=data)
 {
  ptr = ptr->next;
  temp = temp->next;
 }
 ptr->next = temp->next;
}

void delete_front()
{
 struct node* ptr;
 ptr = start;
 ptr = ptr->next;
 start = ptr;
}

void delete_back()
{
 struct node* ptr;
 ptr = start;
 while(ptr->next->next != NULL)
 {
  ptr = ptr->next;
 }
 ptr->next=NULL;
}

void insert_after(int data)
{
 struct node* ptr;
 struct node* temp;
 ptr = start;
 while(ptr->data!=data && ptr->next != NULL)
 {
  ptr = ptr->next;
  temp = ptr->next;
 }
 struct node* new = malloc(sizeof(struct node));
 printf("Enter data to be inserted after %d: ",data);
 scanf("%d",&new->data);
 ptr->next = new;
 new->next = temp;
}

void insert_before(int data)
{
 struct node* ptr;
 struct node* temp;
 ptr = start;
 if(ptr->data==data)
 {
  insert_front();
  return;
 }
 while(ptr->next->data!=data && ptr->next != NULL)
 {
  ptr = ptr->next;
  temp = ptr->next;
 }
 struct node* new = malloc(sizeof(struct node));
 printf("Enter data to be inserted after %d: ",data);
 scanf("%d",&new->data);
 ptr->next = new;
 new->next = temp;
}

void insert_front()
{
 struct node* new = malloc(sizeof(struct node));
 printf("Enter data to be inserted at front: ");
 scanf("%d",&new->data);
 new->next = start;
 start = new;
}

void insert_end()
{
 struct node* ptr;
 ptr = start;
 while(ptr->next != NULL)
 {
  ptr = ptr->next;
 }
 int data;
 printf("Enter data to be inserted at end: ");
 scanf("%d",&data);
 struct node* new = malloc(sizeof(struct node));
 ptr->next = new;
 new->data = data;
 new->next=NULL;
}

void createList()
{
 int n;
 printf("Enter no of nodes=");
 scanf("%d",&n);
 struct node* new = malloc(sizeof(struct node));
 start = new;
 printf("Enter data of first node: ");
 scanf("%d",&(new->data));
 new->next = NULL;
 struct node* temp;
 temp = new;
 for(int i = 1; i < n ; i++)
 {
  new = malloc(sizeof(struct node));
  temp->next = new;
  printf("Enter data of %d node: ",i+1);
  scanf("%d",&(new->data));
  new->next = NULL;
  temp=new;
 }
}

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

void main()
{
 createList();
 display();
 insert_end();
 display();
 insert_front();
 display();
 /*int n;
 printf("Enter data after which you want to insert: ");
 scanf("%d",&n);
 insert_after(n);
 display();
 printf("Enter data before which you want to insert: ");
 scanf("%d",&n);
 insert_before(n);
 display();*/
 delete_front();
 printf("\n");
 display();
 printf("\n");
 delete_back();
 display();
 printf("\n");
 delete_data(30);
 display();
}
