#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

//creating linked list
struct node *add(struct node **first){
    struct node *newnode, *temp;
    int x;
    while(1){
        printf("Enter the Data : ");
        scanf("%d",&x);
        if(x == -1){
            break;
        }
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->link = NULL;
        if(*first == NULL){
            *first = newnode;
        }
        else{
            temp = *first;
            while(temp->link){
                temp = temp->link;
            }
            temp->link = newnode;
        }
    }
    return *first;
}

//reversing
struct node *reverse(struct node **first){
    struct node *previous = NULL, *current = *first, *next;
    while(current != NULL){
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    *first = previous;
    return *first;
}

int main(){
    struct node *first = NULL,*temp ;
    first = add(&first);
  
    //printing before reversing
    printf("list of contents\n");
    temp = first;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->link;
    }
    //reversing by call by reference method
    first = reverse(&first);
  
    //printing after reversing
    printf("list of contents after reverse\n");
    temp = first;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->link;
    }
    return 0;
}
