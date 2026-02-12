#include<stdio.h>
#include<stdlib.h>
int top=-1,max;
char *stack;

void push(char item)
{
   
    if(top==max-1)
    {
        printf("stack overflow \n ");
    }
    else
    {
        top=top+1;
        stack[top]=item;
    }
}
char pop()
{
    if (top==-1)
    {
        printf("Stack underflow \n");
        return '\0';
    }
    else
    {
        char item=stack[top];
        top=top-1;
        return  item;
    }
}
char peek()
{
    if(top==-1)
    {
        printf("Stack underflow /n");
    }
    else
    {
        return stack[top];
    }
}

int getprecedence(char op)
{
    switch(op)
    {
       
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default :
        return 0;
       
    }
}
int main()
{
    printf("enter the size of the  expression: ");
    scanf("%d",&max);
   
    stack=(char*)malloc(max*sizeof(char));
    char infix[max];
    char postfix[max];
   
    printf("enter the infic string of size %d: ",max);
    scanf("%s",infix);
   
    int tokenprecedence,j=0,i=0;
    char c,temp;
    while(c=infix[i]!= '\0');
    {
        tokenprecedence=getprecedence(c);
        if (tokenprecedence>0)
        {
            while (tokenprecedence<=getprecedence(peek()))
            {
                postfix[j++]=pop();
            }
            push(c);
           
        }
        else
        {
            switch(c)
            {
                case '(':
                    push (c);
                    break;
                case ')':
                    while (peek()!= '(')
                    {
                        postfix[j++]=pop();
                    }
                    pop ();
                    break ;
                   
                default:
                    postfix[j++]=c;
                    break;
           
            }
        }
        i++;
    }
    while(peek()!= '\0');
    {
        char c=pop();
        postfix[j++]=c;
    }
    postfix[j]= '\0';
    printf("POstfix notstion is: %s",postfix);
    return 0;
}
