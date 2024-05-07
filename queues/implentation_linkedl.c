#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front=0,*rear=0;
void enqueue();
void dequeue();
void peek();
void display();
void main(){
 int op;
 do{
printf("\n___MAIN MENU___\n...queues in linked list...\n1.enqueue\n2.dequeue\n3.peek\n4.display\n");
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
printf("INVALID CHIOCE\n");

 }while(op!=0);
}
void enqueue(){
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("entre data:\n");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=0;
    if(front==0&&rear ==0){
        front=rear=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    if(front==0 && rear==0)
    printf("queue is empty:\n");
    else{
        struct node *temp;
        temp=front;
        front=front->next;
        free(temp);
    }
}
void display(){
    struct node *temp;
    temp=front;
    if(front==0 && rear==0)
    printf("queue is empty\n");
    else{
        printf("values in queue:\n");
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    }
}
void peek(){
    if(front==0 && rear==0)
    printf("\nqueue is empty\n");
    else{
        printf("peek value in queue:\n");
        printf("%d\n",front->data);
    }
}