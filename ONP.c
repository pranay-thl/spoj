#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stack
{
    int top;
    int capacity;
    char *a;
};
typedef struct stack stack;
stack* createStack(int c)
{
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    s->capacity=c;
    s->a=(char*)malloc(s->capacity*sizeof(char));
    return s;
}
int isFull(stack *s)
{
    return s->top==s->capacity-1;
}
int isEmpty(stack *s)
{
    return s->top==-1;
}
void push(stack *s,char v)
{
    if(isFull(s))
    {
        printf("Overflow\n");
        return;
    }
    s->a[++s->top]=v;
}
char pop(stack *s)
{
    if(isEmpty(s))
    {
        printf("Underflow\n");
        return INT_MIN;
    }
    return s->a[s->top--];
}
char top(stack *s)
{
    if(isEmpty(s))
    {
        printf("Empty\n");
        return INT_MIN;
    }
    return s->a[s->top];
}
int isOperand(char s)
{
    return ((s>='a'&&s<='z')||(s>='A'&&s<='Z')||(s>='0'&&s<='9'));
}
int prefer(char c)
{
    switch(c)
    {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
void postfix(char *s,char *out)
{
    stack *st;
    st=createStack(100);
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(isOperand(s[i]))
        {
            out[j++]=s[i];
        }
        else if(s[i]=='(')
        {
            push(st,s[i]);
        }
        else if(s[i]==')')
        {
            while(!isEmpty(st)&&top(st)!='(')
            {
                out[j++]=pop(st);
            }
            if(top(st)=='(')
                pop(st);
        }
        else
        {
            while(!isEmpty(st)&&prefer(s[i])<=prefer(top(st)))
            {
                out[j++]=pop(st);
            }
            push(st,s[i]);
        }
    }
    while(!isEmpty(st))
        out[j++]=pop(st);
    out[j]='\0';
}
int main()
{
    int i,t;
    char s[500],out[500];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        postfix(s,out);
        printf("%s\n",out);
    }
    return 0;
}
