#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr) == 1)
    {
        printf("Stack Overflow ! Cannot push %d to Stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        printf("Stack Underflow ! Cannot pop from Stack.\n");
        return -1;
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *ptr,int i){
    if(ptr->top-i+1<0){
        printf("Invalid Position.");
        return -1;
    }
    else
    return ptr->arr[ptr->top-i+1];
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully.\n");

    printf("Bfore Pushing Full : %d\n", isFull(sp));
    printf("Bfore Pushing Empty : %d\n", isEmpty(sp));

    push(sp, 56);
    push(sp, 89);
    push(sp, 78);
    push(sp, 13);
    push(sp, 41);
    push(sp, 23);
    push(sp, 67);
    push(sp, 99);
    push(sp, 65);
    push(sp, 11);
    // push(sp, 90); //Stack Overflow
    // pop(sp);
    // pop(sp);
    // pop(sp);
    for(int j=1;j<=sp->top+1;j++){
    printf("The element at Position %d is %d\n",j,peek(sp,j));
    }

    printf("After Pushing Full : %d\n", isFull(sp));
    printf("After Pushing Empty : %d\n", isEmpty(sp));
    return 0;
}