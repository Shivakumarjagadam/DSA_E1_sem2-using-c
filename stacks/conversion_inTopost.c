//neso academy....
//conversion of infix  to postfix....
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
// int MAX;
// printf("enter size:")
char stack[15];
char infix[15],postfix[15];
int top=-1;
void push(char symbol);
char pop();
void inTopost();
void display();
int  precedence(char symbol);
int isEmpty();
//void print();
void main(){
    printf("enter infix expression:\n");
    // gets(infix);
    scanf("%s",infix);
    inTopost();
    display();
    
}
void inTopost(){
    int i,j=0;
    char next,symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        switch(symbol){
            case '(':push(symbol);
            break;
            case ')':while((next=pop())!='(')
            postfix[j++]=next;
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            while(!isEmpty() && precedence(stack[top])>=precedence(symbol)){
            postfix[j++]=pop();
            }
            push(symbol);
            break;
    

            default:
            postfix[j++]=symbol;  //if symbols are values..
        }
        //print();
    }
    while(!isEmpty()){
    postfix[j++]=pop();
    }
    postfix[j]='\0';
   

}
void push(char symbol){
    if(top==15-1)
        printf("stack is full\n");
    else{
        top++;
        stack[top]=symbol;
    }
}
char pop(){
      if(top==-1){
        printf("stack is empty\n");
       // exit(1);
    }
    else
       return stack[top--];
}
int  precedence(char symbol){
    switch(symbol){
        case '^':
        return 3;
        case '*':
        case '/':
        return 2;
        case '+':
        case '-':
        return 1;
        default:
        return 0;
    }
}
void display(){
    printf("conversion of infix to postfix expres..\n");
    int i=0;
    while(postfix[i]){
        printf("%c",postfix[i++]);
    }
    printf("\n");
}
int isEmpty(){
    if(top==-1)
    return 1;
    else 
    return 0;
}
