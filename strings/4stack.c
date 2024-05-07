#include<stdio.h>//stacks with linked list...
struct node{
    int data;
    struct node*next;
}*top=0;
void push();
void pop();
void peek();
void display();
void main(){
push();
push();
push();
push();
push();
display();
pop();
// pop();
// display();
peek();
}
void push(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop(){
    if(top==0){
        printf("stack is empty");
    }
    else{
        printf("pop element is %d\n",top->data);
        top=top->next;
    }
}
void peek(){
    printf("peek element is %d\n",top->data);
}
void display(){
    struct node*temp;
    temp=top;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;

    }
}