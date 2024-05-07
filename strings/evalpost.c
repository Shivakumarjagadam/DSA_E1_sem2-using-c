#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
char  stack[20];//evaluation of post fix...
int top=-1;
void evalation();
void push(int ch);
int pop();
void display();
void main(){
    int res;
evalation();
//display();
// printf("the post evaluation is:%d\n",res);
}
void evalation(){
    char exp[20];
    printf("enter an expression");
    scanf("%s",exp);
    char ch;
    int i,a,b,res;
    for(i=0;i<strlen(exp);i++){
        ch=exp[i];
        if(isdigit(ch))
        push(ch-'0');
        else{
            a=pop();
            b=pop();
            switch(ch){
                case '+':res=b+a; break;
                case '-':res=b-a; break;
                case '*':res=b*a; break;
                case '/':res=b/a; break;
                  case '^':res=pow(b,a); break;
            }
        
        push(res);
        }
        display();

    }
     printf("the post evaluation is:%d\n",res);


}
void push(int ch){
    if(top>=20-1)
    printf("stack full");
    else{
        top++;
        stack[top]=ch;
    }

}
int pop(){
    if(top==-1)
    printf("stack empty");
    else{
        return stack[top--];
    }
}
void display(){
    int i;
    printf("stack elements:\n");
    for(i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
    printf("\n");
}