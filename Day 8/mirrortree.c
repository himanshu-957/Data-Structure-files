#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *left;
 struct node *right;
};

struct node *root = NULL;
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
struct node *create_Tree(struct node *temp)
{
 int data;
 printf("Enter data for node: ");
 scanf("%d",&data);

 if(data == -1)
 {
  return NULL;
 }

 temp = createNode(data);

 //left subtree
 temp->left = create_Tree(temp->left);

 //right subtree
 temp->right = create_Tree(temp->right);
 
 return temp;
}
//------------------------------------------------------------------------------------------------------------------------------------
struct node *mirror_tree(struct node *root)
{
 if(root == NULL)
 {
  return NULL;
 }
 struct node* temp;
 temp = root->left;
 root->left = root->right;
 root->right = temp;
 root->left = mirror_tree(root->left);
 root->right = mirror_tree(root->right);
 return root;
}
//------------------------------------------------------------------------------------------------------------------------------------
int height_Tree(struct node *root)
{
 int height;
 if(root == NULL)
 {
  height = 0;
  return height;
 }
 int hl = height_Tree(root->left);
 int hr = height_Tree(root->right);
 if(hl > hr)
 {
  return hl+1;
 }
 return hr+1;
}
//------------------------------------------------------------------------------------------------------------------------------------
int is_balanced(struct node *root)
{
 int height;
 if(root == NULL)
 {
  height = 0;
  return height;
 }
 int hl = height_Tree(root->left);
 int hr = height_Tree(root->right);
 if(hl - hr == 0 || hl - hr == -1 || hl - hr == 1)
 {
  return 1;
 }
 return 0;
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
 root = create_Tree(root);
 inorder(root);
 printf("\n");
 root = mirror_tree(root);
 inorder(root);
 printf("\n");
 /*preorder(root);
 printf("\n");
 postorder(root);
 printf("\nHeight is %d\n",height_Tree(root));
 if(is_balanced(root))
 {
  printf("Balanced\n");
 }
 else
 {
  printf("Unbalanced\n");
 }*/
}
