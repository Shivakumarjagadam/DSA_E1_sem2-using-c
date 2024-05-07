#include<stdio.h>
#define max 15      //stacks in arrays/
int stack[max];
int top=-1;
void push();
void peek();
void pop();
void display();
void main(){
int op;
do{printf("\nmain menu\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n\n");
printf("enter choice\n");
scanf("%d",&op);
switch(op){
    case 1: push();
           break;
    case 2:pop();
            break;
    case 3:peek();
        break;
    case 4: display();
            break;
    default:printf("try again");
}

}while(op!=0);

}
void push(){
    int x;
    printf("enter data:");
    scanf("%d",&x);
    if(top==max-1)
    printf("stack is full");
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("top element is deleted:%d\n",stack[top]);
        top--;

    }
}
void peek(){
    printf("the top element is %d\n",stack[top]);
}
void display(){
    int i;
    for(i=top;i>=0;i--){
printf("%d\t",stack[i]);
    }
}