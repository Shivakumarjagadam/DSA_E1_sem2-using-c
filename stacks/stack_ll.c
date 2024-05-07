//5.stacks_linked....

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*top=0;
void push();
void display();
void pop();
void peek();
void main(){
    printf("\n1.display\n2.push\n3.pop\n4.peek...\n");
 int op;
 do{
printf("enter choice2\n");
scanf("%d",&op);
switch(op){
case 1:display();
break;
case 2:push();
break;
case 3:pop();
break;
case 4:peek();
break;
default:printf("try again\n");
        }
    }while(op!=0);
}
void push(int x){
  //  int x;
    printf("enter data\n");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;


}
void display(){
    struct node *temp;
    temp=top;
    if(top==0)
    printf("its empty");
    else{
        while(temp!=0){
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}
void pop(){
    struct node *temp;
    temp=top;
    if(top==0)
    printf("list is empty");
    else{
        printf("deleted:%d\n",top->data);
        top=top->link;
    }
}
void peek(){
    printf("top:%d\n",top->data);
}