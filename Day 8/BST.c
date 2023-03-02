#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *left;
 struct node *right;
};

//------------------------------------------------------------------------------------------------------------------------------------
struct node *createNode(int data)
{
 struct node *new = malloc(sizeof(struct node));
 new->data = data;
 new->left = NULL;
 new->right = NULL;

 return new;
}
//------------------------------------------------------------------------------------------------------------------------------------
struct node* insert_data(struct node *root, int data)
{
 if(data == -1)
 {
  return NULL;
 }
 if(root == NULL)
 {
  root = createNode(data);
 }
 else
 {
  if(data < root->data)
  {
   root->left = insert_data(root->left,data);
  }
  else
  {
   root->right = insert_data(root->right,data);
  }
 }
 return root;

}
//------------------------------------------------------------------------------------------------------------------------------------
struct node* takeinput(struct node* root)
{
 int no;
 printf("Enter first data for BST: ");
 scanf("%d",&no);
 while(no != -1)
 {
  root = insert_data(root,no);
  printf("Enter data for BST: ");
  scanf("%d",&no);
 }
 return root;
}
//------------------------------------------------------------------------------------------------------------------------------------
void inorder(struct node *root)
{
 if(root == NULL)
 {
  return;
 }
 inorder(root->left);
 printf("%d",root->data);
 inorder(root->right);
}
//------------------------------------------------------------------------------------------------------------------------------------
void find_max(struct node *root)
{
 if(root->right == NULL)
 {
  printf("Maximum %d\n", root->data);
 }
 else
 {
  find_max(root->right);
 }
}
//------------------------------------------------------------------------------------------------------------------------------------
int find_min(struct node *root)
{
 if(root->left == NULL)
 {
  return root->data;
 }
 else
 {
  find_min(root->left);
 }
}
//------------------------------------------------------------------------------------------------------------------------------------
struct node* delete(struct node* root, int data)
{
 if(root == NULL)
 {
  return NULL;
 }
 else
 {
  if(data < root->data)
  {
   root->left = delete(root->left, data);
  }
  else if(data > root->data)
  {
   root->right = delete(root->right, data);
  }
  else
  {
   if(root->left == NULL)
   {
    struct node* temp = root->right;
    free(root);
    return temp; 
   }
   else if(root->right == NULL)
   {
    struct node* temp1 = root->left;
    free(root);
    return temp1;
   }
   else
   {
    int data = find_min(root->right);
    delete(root,data);
    root->data = data;
    return root;
   }
  }
 }
}
//------------------------------------------------------------------------------------------------------------------------------------
void preorder(struct node *root)
{
 if(root == NULL)
 {
  return;
 }
 printf("%d",root->data);
 preorder(root->left);
 preorder(root->right);
}
//------------------------------------------------------------------------------------------------------------------------------------
void postorder(struct node *root)
{
 if(root == NULL)
 {
  return;
 }
 postorder(root->left);
 postorder(root->right);
 printf("%d",root->data);
}
//------------------------------------------------------------------------------------------------------------------------------------
void main()
{
 
 struct node *root = NULL;
 root = takeinput(root);
 inorder(root);
 printf("\n");
 delete(root, 3);
 inorder(root);
 printf("\n");
}
