#include <stdio.h>
#define size 10
int front =- 1;
int rear =- 1;
int q[size];

void insert(int item)
{
    if( front == -1 && rear == -1 )
    {
        front = rear = 0;
        q[rear] == item;
        
    }
    else if ( (rear + 1) % size == front )
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = ( rear + 1 ) % size;
        q[rear] = item;
    }
}

void delete(){
    if( front == -1 && rear == -1 )
    {
        printf("Queue is empty\n");
    }
    else if( front == rear )
    {
        printf("deleted item is %d\n",q[front]);
    }
    else
    {
        printf("deleted item is %d\n",q[front]);
        front=(front+1)%size;
        
    }
}

void display()
{
    int i = front;
    if( front == -1 && rear == -1 )
    {
        printf("queue is empty\n");
        
    }
    else 
    {
        printf("Queue is: ");
        while( i != rear){
            printf("%d ", q[i]);
            i=(i + 1) % size;
        }
        printf("%d",q[rear]);
        
    }
}

int main()
{
  display();
  insert(0);
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	display();
	delete();
	delete();
	display();
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	insert(9);
	insert(10);
	insert(11);
	display();
	insert(12);
	display();
	return 0;
}
