#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *last = NULL;
    int x;
    struct node *newnode, *temp;
    
    while(1){
        printf("Enter the data : ");
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->link = last;
        last = newnode;
    }
    printf("The list of contents :\n");
    temp = last;
    while(temp){
        printf("%d\n",temp->data);
        temp = temp->link;
    }
    return 0;
}
