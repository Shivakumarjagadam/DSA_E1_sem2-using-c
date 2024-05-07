//4.stacks_array...

#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
void display();
//#define N 5;
int stack[5];
int top=-1;
void main(){
int op;
do{
printf("\n\n---MAIN--MENU---\n1.display...\n2.push\n3.pop\n4.peek|top\n");
printf("\nenter an operation\n");
scanf("%d",&op);
switch(op){
    case 2:push();
    break;
    case 3:pop();
    break;
    case 4:peek();
    break;
    case 1:display();
    break;
    default:
    printf("'\n***try again***");
}
}while(op!=0);



}
void push(){
    int x;
    printf("enter data:");
    scanf("%d",&x);
    if(top==5-1){
        printf("stack is full:");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    int item;
    if(top==-1){
        printf("stack is empty:");
    }
    else{
        item=stack[top];
        top--;
     printf("%d-deleted\n",item);
    }
   
}
void peek(){
    if(top==-1){
        printf("under flow");
    }
    else{
        printf("\ntop-%d",stack[top]);
    }
}
void display(){
    int i;
    printf("the values: ");
    for(i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
}