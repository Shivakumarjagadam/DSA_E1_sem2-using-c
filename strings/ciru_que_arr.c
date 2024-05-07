#include<stdio.h>//circular qeues with arrays...
#define N 10
int que[N];
int front=-1,rear=-1;
void enqueue();
void dequeue();
void peek();
void display();

void main(){
enqueue();
enqueue();
enqueue();
dequeue();
//display();
peek();

}
void enqueue(){
    int x;
    printf("enter data:");
    scanf("%d",&x);
    if((rear+1)%N==front)//when rear+1 is divides by its size que is full...
    printf("stack full");
    else if(front==-1&rear==-1){
        front=rear=0;
        que[rear]=x;
    }
    else{
        rear=(rear+1)%N;
        que[rear]=x;
    }
}
void dequeue(){
    if(front==-1&&rear==-1)
    printf("stack empty");
    else if(front==rear){
        front=rear=0;
    }
    else{
        front=(front+1)%N;
    }
}
void peek(){
    printf("peek element is %d\n",que[front]);
}
void display(){
    if(front==-1&&rear==-1)
    printf("stack empty");
    else{
      int i=front;
      while(i!=rear){
        printf("%d\t",que[i]);
        i=(i+1)%N;
      }  
      printf("%d\n",que[rear]);
}
}