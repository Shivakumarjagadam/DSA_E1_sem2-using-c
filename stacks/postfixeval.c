#include<stdio.h>  //evaluation of postfix expression...
#include<stdlib.h>//fistly scanf all chars from left to right eg:123*^34-+*;
#include<string.h>
#include<ctype.h>
//#include<math.h>//check if it is didgit push into stack...if operator pop them..A&B by an operator..;
#define N 10
int stack[N];
int top=-1;
int val;

                //printf the result;
void push(int);
int pop();
void display();

void push(int ch)
{
    //int x;
   // printf("enter data to push\n");
  //  scanf("%d",&x);
if(top==N-1)
printf("stack is full\n");
else{
    top++;
stack[top]=ch;
}
}
int pop(){
    int val;
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
      val=stack[top];
       // printf("delete->%d\n",item);
        top--;
    }
    return val;
    // return val;
}
void display(){
    int i;
    printf("\nstack is\n");    
    for(i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
}

int main(){
//#define N 10;
char ex[N],ch;
int i,res,a,b;
printf("enter the expression\n");
scanf("%s",ex);
for(i=0;i<strlen(ex);i++){
    ch=ex[i];
    if(isdigit(ch)){
        push(ch-'0');
    }
    else{
        a = pop();
        b = pop();
        switch(ch){
            case '+':res=b+a;
            break;
            case '-':res=b-a;
            break;
            case '*':res=b*a;
            break;
            case '/':res=b/a;
            break;
            case '^':res=b^a;
            break;
        }
        push(res);
    }
    display();
}
//display();
    printf(" \nans is :  %d\n",res);
}

