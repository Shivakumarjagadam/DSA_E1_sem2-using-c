#include<stdio.h>
#include<stdlib.h>  //circular queues in linked list...
struct node{
    int data;
    struct node *next;

} *front=0,*rear=0;
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
    printf("enter insertion data / -1 to stop\n");
    scanf("%d",&in);
    while(in!=-1){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=in;
    newnode->next=front;
    if(rear==0){
        front=rear=newnode;
        //rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        //rear->next=front;
    }
    printf("enter -1 to stop\n");
    scanf("%d",&in);
}

}
void dequeue(){
    
    if(front==0&& rear==0)
    printf("queue is empty\n");
    else if(front==rear)
    front=rear=0;
    else{struct node *temp;
    temp=front;
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void peek(){
    if(front==0&& rear==0)
    printf("queue is empty:\n");
    else{
        printf("the peek value:\n%d\n",front->data);
    }
}
void display(){
    struct node *temp;
    temp=front;
    if(front==0&& rear==0)
     printf("queue is empty:\n");
     else{
        while(temp->next!=front){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
     }

}
