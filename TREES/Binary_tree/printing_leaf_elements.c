#include<stdio.h>
#include<stdlib.h>

int a[100],i=0;     //array a for storing leaf elements 

struct node{
    int data;
    struct node *right, *left;
};

struct node *insert(struct node *tree, int x){
    struct node *newnode = NULL;
    newnode = (struct node*) malloc(sizeof(struct node));
    if(tree == NULL){
        newnode->data = x;
        newnode->right=newnode->left = NULL;
        return newnode;
    }
    if(tree->data > x){
        tree->left = insert(tree->left,x);
    }
    else{
        tree->right = insert(tree->right,x);
    }
    return tree;
}

void preorder(struct node *l){
    if(l){
        printf("%d ",l->data);
        preorder(l->left);
        preorder(l->right);
    }
}

void inorder(struct node *l){
    if(l){
        inorder(l->left);
        printf("%d ",l->data);
        if(l->left==NULL && l->right==NULL){      //Search for Leaf elements
            a[i++] = l->data;
        }
        inorder(l->right);
    }
}

void postorder(struct node *l){
    if(l){
        postorder(l->left);
        postorder(l->right);
        printf("%d ",l->data);
    }
}

void main(){
    struct node *tree = NULL;
    int key;
    while(1){
        printf("Enter the data : ");
        scanf("%d",&key);
        if(key==-1){
            break;
        }
        tree = insert(tree,key);
    }
    preorder(tree);
    printf("\n");
    inorder(tree);
    printf("\n");
    postorder(tree);
    printf("\nleaf elements : ");
    for(int j=0;j<i;j++){
        printf("%d ", a[j]);
    }
}
