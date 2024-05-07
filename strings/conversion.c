#include<stdio.h>//conversion of infix to postfix...
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
//#define max 15
char infix[15],postfix[15];
char stack[15];
int top=-1;
void intopost();
void push(char symbol);
char pop();
int isEmpty();
int precedence(char symbol);
void display();

void main(){
    intopost();
    display();
}
void intopost(){
    printf("enter an infix expression:");
    scanf("%s",infix);
    char symbol,next;
    int i,j=0;
    for(i=0;i<strlen(infix);i++){
    symbol=infix[i];
    switch(symbol){
        case '(':push(symbol); break;
        case ')':while(next=pop()!='('){
            postfix[j++]=next;
        }
        break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':while(!isEmpty()&& precedence(stack[top])>=precedence(symbol)){
            postfix[j++]=pop();
        }
        push(symbol);
        break;
        default: 
         postfix[j++]=symbol;
    

    }
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';


    
}
void push(char symbol){
    if(top>=15-1)
    printf("stack is full");
    else{
        top++;
        stack[top]=symbol;
    }
}
char pop(){
    if(top==-1)
    printf("stack is empty");
    else{
        return stack[top--];
    }
}
int isEmpty(){
    if(top==-1)
    return 1;
    else return 0;
}
int precedence(char symbol){
    switch(symbol){
        case '^':return 3;
        case'*':
        case'/':return 2;
        case '+':
        case '-':return 1;
        default:return 0;
    }
}
void display(){
    int i=0;
    printf("\n...after conversion into postfix...\n");
    while(postfix[i]){
        printf("%c",postfix[i++]);
    }
}