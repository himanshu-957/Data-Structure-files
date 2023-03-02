//---------------------------------------------------Reversing a Linked List----------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

struct node* start;

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
  printf("%d ",ptr->data);
  ptr = ptr->next;
 }
 printf("\n");
}

void Reverse()
{
 struct node* ptr;
 struct node* ptr1;
 ptr = start;
 int temp;
 while(ptr != NULL)
 {
  ptr1 = ptr->next;
  while(ptr1 != NULL)
  {
   temp = ptr->data;
   ptr->data = ptr1->data;
   ptr1->data = temp;
   ptr1=ptr1->next;
  }
  ptr=ptr->next;
 }
}
void main()
{
 createList();
 display();
 Reverse();
 printf("Reversed List: ");
 display();
}
