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
  printf("%d\n",ptr->data);
  ptr = ptr->next;
 }
}

void main()
{
 /*struct node* n1 = malloc(sizeof(struct node));
 struct node* n2 = malloc(sizeof(struct node));
 struct node* n3 = malloc(sizeof(struct node));
 
 n1->data = 10;
 n1->next = n2;
 
 start = n1;
 
 n2->data = 20;
 n2->next = n3;
 
 n3->data = 30;
 n3->next = NULL;*/
 createList();
 display();
}
