#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *top=0;
struct node *push(struct node*);
struct node *display(struct node*);
struct node *pop(struct node*);
struct node *peek(struct node*);
int main(){
int x,op;  
do{
printf("\n1.display\n2.push\n3.pop\n4.peek...\n");
 
//printf("enter data\n");
scanf("%d",&op);
switch(op){
case 1:top=display(top);
break;
case 2:top=push(top);
break;
case 3:top=pop(top);
break;
case 4:top=peek(top);
break;
default:printf("try again\n");
        }
    }while(op!=0);
    return 0;
}
struct node *push(struct node *top){
    struct node *newnode;
       int x;
    newnode=(struct node*)malloc(sizeof(struct node));
    //printf("entre data");
     printf("enter x:\n");
   scanf("%d",&x);
    newnode->data=x;
    newnode->link=top;
    top=newnode;
    return top;
}
struct node *display(struct node *top){
    struct node *temp;
    temp=top;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    return top;
}
struct node *pop(struct node *top){
    struct node *temp;
    temp=top;
    printf("top deleted:%d\n",top->data);
    top=top->link;
    free(temp);
    return top;

}
struct node *peek(struct node *top){
    if(top==0){
        printf("list is empty\n");

    }
    else{
        printf("top is:%d\n",top->data);
    }
    return top;
}