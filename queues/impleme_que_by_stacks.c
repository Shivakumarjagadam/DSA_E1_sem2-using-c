#include<stdio.h>//implementation of queues by using stacks...
#include<stdlib.h>
#define N 4
int s1[N],s2[N];
int top1=-1,top2=-1,count=0;
void enqueue();
void dequeue();
void push1();
void push2();
int pop1();
int pop2();
void display();
void main(){
    enqueue();
    enqueue();
    enqueue();
    //enqueue();
 dequeue();
    display();
}
void enqueue(){
 push1();
 count++;
}
void dequeue(){
    int i;
    if(top1==-1&& top2==-1)
    printf("stacks are empty:\n");
    else{
        for(i=0;i<count;i++){
            int a=pop1();
        push2(a);
    }
    int b=pop2();
    count--;
    printf("1st element was deleted:%d\n",b);
    for(i=0;i<count;i++){
        int a=pop2();
        push1(a);
    }
    }
}


void push1(){
    int data;
    printf("enter insert data\n");
    scanf("%d",&data);
    if(top1==N-1)
    printf("stack1 is full\n");
    else{
        top1++;
        s1[top1]=data;
    }
}
int pop1(){
    return s1[top1--];
}

void push2(){
    int data;
    // printf("enter insert data\n");
    // scanf("%d",&data);
    if(top2==N-1)
    printf("stack1 is full\n");
    else{
        top2++;
        s2[top2]=data;
    }
}
int pop2(){
    return s2[top2--];
}

void display(){
    int i;
    if(top1==-1)
    printf("que is empty\n");
    else{
    for(i=0;i<=top1;i++){
        printf("%d\t",s1[i]);
    }
    printf("\n");
    }
}