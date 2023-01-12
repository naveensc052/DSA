#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
  int data;
  struct treenode *left, *right;
} node;

void inorder(node * current_node)  // Inorder Traversal using Recursive function
{
    if (current_node)
    {
    inorder(current_node->left);
    printf("%d\n",current_node->data);
    inorder(current_node->right);
    }
}

node *insert(node *current_node, int value)  // Tree Insertion Logic using Recursion
{
    node *tmp = NULL;

    printf("Address on the Stack INSERT logic= %u\n", current_node);
    if(current_node == NULL)
    {
        tmp = (node *)malloc(sizeof(node));
        tmp->left = tmp->right = NULL;
        tmp->data = value;
        return tmp;
    }

    if(value <= current_node->data) // Insert lower and equal values to left and higher values to right
    current_node->left=insert(current_node->left, value);
    else
    current_node->right=insert(current_node->right, value);
    return current_node;
}


void main()
{
    node *current_node=NULL;
    int x;
    while (1)
    {
     printf("Enter data or -1 to exit \n");
     scanf("%d", &x);
     if (x == -1) 
      break;
     current_node=insert(current_node,x);
    }

    printf ("----------Binary Tree Traversals output-------------- \n");

    printf("--------Inorder--------- \n");
    inorder(current_node);

}
