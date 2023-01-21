#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
  int data;
  struct treenode *left, *right;
} node;

int count =0;

void preorder(node *current_node)   // Preorder Traversal using Recursive function
{
     if (current_node)
    {
     printf("%d\n",current_node->data);
     if(current_node->left == NULL && current_node->right == NULL)
        count = count + 1;
     preorder(current_node->left);
     preorder(current_node->right);
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

node *delete(node *tree){
    node *temp = tree;
    if(tree->left == NULL && tree->right){
        temp = tree;
        free(temp);
        return NULL;
    }
    tree->left = delete(tree->left);
    tree->right = delete(tree->right);
    return tree; 
}

void main()
{
    node *current_node=NULL;
    int x,key;
    while (1)
    {
     printf("Enter data or -1 to exit \n");
     scanf("%d", &x);
     if (x == -1) break;

     current_node=insert(current_node,x);
    }

    printf ("----------Binary Tree Traversals output-------------- \n");

    printf("--------Preorder---------- \n");
    preorder(current_node);

    printf("The number of leaf nodes are %d",count);

    current_node = delete(current_node);
    
    printf("\nPREORDER after deleting leaf node\n");
    preorder(current_node);

}
