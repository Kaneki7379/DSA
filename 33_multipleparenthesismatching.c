#include <stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isFull(struct stack *ptr)
{
    if (ptr->top == (*ptr).size - 1)
        return 1;
    else
        return 0;
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
        printf("Stack Overflow cannot push %d to stack!", val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
        printf("Stack Underflow cannot pop!");
    else
    {
        int val = (*ptr).arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(sp, exp[i]);
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
                return 0;
            pop(sp);
        }
    }
    if (isEmpty(sp))
        return 1;
    else
        return 0;
}
int main()
{
    char *exp = "((8)(*--$$9))";
    // Check if stack is empty
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}