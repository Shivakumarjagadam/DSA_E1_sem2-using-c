#include<stdio.h>//queues by linked list...(rear->next=0)
struct node {
    int data;
    struct node *next;
}*front=0,*rear=0;
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
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("enter data");
    scanf("%d",&x);
    newnode->data=x;
    if(front==0&&rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    rear->next=0;
}
void dequeue(){
    if(front==0&&rear==0)
    printf("que empty");
    else if(front==rear){
        front=rear=0;
    }
    else{
        struct node *temp;
        temp=front;
        front=front->next;
        free(temp);
    }
}
void peek(){
    printf("peek elements is %d\n",front->data);
}
void display(){
    struct node *temp;
    temp=front;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}