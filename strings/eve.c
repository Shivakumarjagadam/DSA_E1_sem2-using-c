#include<stdio.h>//evaluation of postfix...
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
int stack[50];
int top=-1,i;
void evaluation();
void display();
int pop();
void push(int ch);
void main(){
evaluation();
}
void evaluation(){
    char exp[50];
    printf("'enter expression");
    scanf("%s",exp);
    char ch;
    int a,b,res;
    for(i=0;i<strlen(exp);i++){
        ch=exp[i];
        if(isdigit(ch)){
            push(ch-48);
        }
        else{
           a= pop();
           b=pop();
           switch(ch){
            case '+':res=b+a;break;
            case '-':res=b-a;break;
            case '*':res=b*a;break;
            case '/':res=b/a;break;
             case '^':res=pow(b,a);break;
           }
           push(res);
        }
        display();

    }
    printf("\nevaluation:%d\n",res);
}
void push(int ch){
    if(top>=50-1)
    printf("stack full\n");
    else{
        top++;
        stack[top]=ch;
    }
}
int pop(){
    if(top==-1){
        printf("stack empty\n");

    }
    else
    return stack[top--];
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
    printf("\n");
}