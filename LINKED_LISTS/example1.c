#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *first = NULL;                  //starting node of linked list
    int x;
    struct node *newnode, *temp;                //temp for traversing in linked list and newnode for temperary node creation
    
    while(1){
        printf("Enter the data : ");
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data = x;
        newnode -> link = NULL;
        if(first == NULL){
            first = newnode;
        }
        else{
            temp = first;
            while(temp -> link != NULL){   //till temp == NULL as we are assigning first to temp 
                temp = temp ->link;
            }
            temp -> link = newnode;
        }
    }
    printf("The list of contents :\n");
    temp = first;
    while(temp){
        printf("%d\n",temp->data);
        temp = temp->link;
    }
}
