//sir..
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
char stack[MAX];
int top = -1;/* top of the stack*/

void push(char element)
{
	if(top >= MAX-1)
    {
		printf("Stack overflow\n");
		return;
	}
	stack[++top] = element;
}

char pop()
{
	if(top < 0)
    {
        	printf("Stack underflow");
        	return ' ';
	}
	return stack[top--];
}

int getpriority(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void infix_postfix(char in_exp[])
{
    char c;
    int i;
    for(i= 0; in_exp[i]!='\0';i++)
    {
        if(isalnum(in_exp[i]))		/*1.Operand: add to output*/
            printf("%c ",in_exp[i]);
        else if(in_exp[i] == '(')	/*2.Left parenthesis: push it onto the stack*/
            push(in_exp[i]);
        else if(in_exp[i] == ')')
        {	/*3.Right parenthesis: pop and place onto output*/
            while((c = pop()) != '(') 		/*untill you find Left parenthesis*/
                printf("%c ", c);
        }
        else
        {/*4. Operator o1:While(there is an operator o2 at the top of the stack,*/
			/*and o2 precedence >= o1 precedence)*/
            while(getpriority(stack[top]) >= getpriority(in_exp[i]))
                printf("%c ",pop());	/* pop o2 add to output*/
            push(in_exp[i]);		/* push o1 onto stack*/
        }
    }
    while(top >=0)			/*5. lefover tokens pop and add to output*/
        printf("%c ",pop());
}


int main()
{
    char in_exp[20];
	printf("enter infix expression\n");
	scanf("%s", in_exp );
	infix_postfix(in_exp);
	return 0;
}