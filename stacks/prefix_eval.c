//evaluation of prefix...
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int stack[10],top=-1;
void push();
int pop();
void display();


void main(){
    char ex[10],ch;
    int i,a,b,res;
    printf("entre an prefix expresion\n");
    scanf("%s",ex);
    for(i=strlen(ex);i>=0;i--){
        //scanf("%c",ex[i]);
        ch=ex[i];
        if(isdigit(ch))
        push(ch-'0');
        else{
            a=pop();
            b=pop();
            switch(ch){
                case '+':res=a+b;
                break;
                case '-':res=a-b;
                break;
                case '*':res=a*b;
                break;
                case '/':res=a/b;
                break;
                case '^':res=pow(a,b);
                break;
            }
            push(res);
        }
        display();
        }
        printf("\neval=%d\n",pop());
}
void push(int ch){
    if(top==10-1)
    printf("stack is full\n");
    else {
        top++;
        stack[top]=ch;
    }
}
int pop(int val){

    if(top==-1)
    printf("stack is empty\n");
    else{
        val=stack[top];
        top--;
    }
    return val;
}
void display(){
    int i=0;
    printf("\nthe stack is\n");
    for(i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
}