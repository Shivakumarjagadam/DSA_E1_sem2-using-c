#include<stdio.h> // circular queues in array...
#define N 10 
int que[N];
int front=-1,rear=-1;
void enqueue();
void dequeue();
void peek();
void display();
void main(){
int op;
do{
    printf("\n(---MAIN--MENU---)\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.enter '0' to stop\n");
    scanf("%d",&op);
    switch(op){
        case 1:enqueue();//insertion
        break;
        case 2:dequeue();//deletiion
        break;
        case 3:peek();//1st value(front)
        break;
        case 4:display();//printing values...
        break;
        default:printf("TRY AGAIN\n");
        
    }
}while(op!=0); //enter 0 to stop the function...

}


void enqueue(){
    int in;
    printf("enter insertion data\n");
    scanf("%d",&in);
    if((rear+1)%N==front)
    printf("queue is full\n");
    else if(front==-1 &&rear==-1){
    front=rear=0;
    que[rear]=in;
    }
    else{
        rear=(rear+1)%N;
        que[rear]=in;
    }

}
void dequeue(){
    if(front==-1 && rear==-1)
    printf("que is empty\n");
    else if(front==rear)
    front=rear=-1;
    else{
        front=(front+1)%N;
    }

}
void peek(){
    if(front==-1 && rear==-1)
    printf("que is empty\n");
    else{
        printf("the peek element is:\n%d\n",que[front]);
    }

}
void display(){
    if(front==-1 && rear==-1)
    printf("que is empty\n");
    else{
        int i=front;
        printf("display the values are:\n");
        while(i!=rear){
            printf("%d\t",que[i]);
            i=(i+1)%N;
        }
        printf("%d\n",que[rear]);
    }
}