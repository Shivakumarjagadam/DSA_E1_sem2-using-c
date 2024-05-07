#include<stdio.h>
//#define N 10 ;
// int N;
// printf("enter size:\n");
// scanf("%d",&N);
int que[5];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void peek();
void display();
void main(){
    int op;
//scanf("%d",&op);
do{    
 printf("\n***MAIN MENU***\n1.enqueue\n2.dequeue\n3.peek/top\n4.display\n");
 scanf("%d",&op);
 if(op==1)
 enqueue();
 else if(op==2)
 dequeue();
 else if(op==3)
 peek();
 else if(op==4)
 display();
 else
 printf("invalid number");

}while(op!=0);

}
void enqueue(){
    int in;
    printf("enter insertion");
    scanf("%d",&in);
    if(rear==5-1)
    printf("queue is full\n");
    else if(front==-1 && rear==-1){
    front=rear=0;
    que[rear]=in;
    }
    else{
        rear++;
        que[rear]=in;
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("que is empty\n");
    }
    else if(front==rear){
    front=rear=-1;
    }
    else{
        front++;
    }
}
void peek(){
    if(front==-1&&rear==-1){
        printf("que is empty\n");
    }
    else
    printf("%d\n",que[front]);
}
void display(){
    int i=front;
    if(front==-1)
    printf("queue is empty\n");
    else{
    for(i=front;i<=rear;i++){
        printf("%d\t",que[i]);
    }
    }
}