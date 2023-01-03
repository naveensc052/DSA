#include<stdio.h>
#include<stdlib.h>

// Inserting node to the end of the list

struct node
{
   int data;
   int power;
   struct node *link;
};


struct node *listinsert(struct node *l, int x,int p)
{
       struct node *temp, *newnode;

       // Traverse the list to last node

       newnode = (struct node*)malloc(sizeof(struct node));
       newnode->data=x; newnode->link = NULL;
       newnode->power = p;

       if (l==NULL)
        l=newnode;
       else
       {
       temp = l;

       while (temp->link != NULL)
       temp=temp->link; //Change the temp to next node of the list

       temp->link = newnode;  // Insert the new node in the end
       }
       return l;
}


void listdisplay(struct node *l)
{
    struct node *temp;

    printf("\nThe polynomial is : ");
    temp=l;
    while(temp)
    {
      printf("%dx^%d ", temp->data,temp->power);
      temp=temp->link;
      if(temp){
        printf("+ ");
      }
    }
}


void main()
{

   struct node *l1, *l2, *l3, *newnode,*temp1, *temp2;
   int x,p;

   l1=l2=l3=NULL;

   printf("Creating first polynomial list \n");
   while(1)
   {
      printf("Enter the data \n"); scanf("%d %d",&x,&p);
      if (x == -1) break;
      l1=listinsert(l1, x, p);
    }

    printf("First list \n");
    listdisplay(l1);

    printf("\nCreating second polynomial list \n");
    while(1)
   {
      printf("Enter the data power \n"); scanf("%d %d",&x,&p);
      if (x == -1) break;
      l2=listinsert(l2, x, p);
    }

    printf("Second ploynomial \n");
    listdisplay(l2);

    // Adding coeff logic

    temp1=l1;
    temp2=l2;

    while (temp1 && temp2)
    {
      if(temp1->power > temp2->power ){
        
        l3 = listinsert(l3,temp1->data,temp1->power);
        temp1 = temp1->link;
      }
      else if(temp1->power < temp2->power){
        l3 = listinsert(l3,temp2->data,temp2->power);
        temp2 = temp2->link;
      }
      else{
        l3 = listinsert(l3,temp1->data + temp2->data,temp2->power);
        temp1 = temp1->link;
        temp2 = temp2->link;
      }
    }
    while(temp1){
      l3 = listinsert(l3,temp1->data,temp1->power);
      temp1 = temp1->link;
    }
    while(temp2){
      l3 = listinsert(l3,temp2->data,temp2->power);
      temp2 = temp2->link;
    }

    printf("\nFinal polynomial");
    listdisplay(l3);
}