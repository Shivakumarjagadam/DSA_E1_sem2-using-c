#include<stdio.h>//circular qeues with arrays...
int que[20];
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
    if(rear==20-1)//when rear+1 is divides by its size que is full...
    printf("stack full");
    else if(front==-1&rear==-1){
        front=rear=0;
        que[rear]=x;
    }
    else{
        rear++;
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
        front++;
    }
}
void peek(){
    printf("peek element is %d\n",que[front]);
}
void display(){
    if(front==-1&&rear==-1)
    printf("stack empty");
    else{
        int i=0;
        for(i=front;i<=rear;i++){
            printf("%d\t",que[i]);
        }
    }
}