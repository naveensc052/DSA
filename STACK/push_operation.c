#include<stdio.h>
#define MAXSIZE 5

int stack[MAXSIZE]
int top = -1;

void push(int data){
  if( top > MAXSIZE - 1){
    printf("STACK IS FULL,Cannot push %d\n",data);
  }
  else{
    top++;
    stack[top] = data;
  }
}

int main(){
  push(0);
  push(3);
  push(5);
  push(9);
  push(0);
  push(32);
  push(45);
  return 0;
}
