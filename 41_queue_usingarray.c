#include <stdio.h>
#include<stdlib.h>
struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};
int isFull(struct queue *q){
    if(q->r==q->size-1)
    return 1;
    else
    return 0;
}
int isEmpty(struct queue *q){
    if(q->r==q->f)
    return 1;
    else
    return 0;
}
void enqueue(struct queue *q, int value)
{
    if (isFull(q))
        printf("Queue Overflow!\n");
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
        printf("Queue Underflow!\n");
    else
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}
int main()
{
    struct queue q;
    q.f = q.r = -1;
    q.size = 100;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q,5);
    enqueue(&q,6);
    enqueue(&q,7);
    enqueue(&q,8);
    printf("Dequeuing Element %d from Queue.\n",dequeue(&q));
    printf("Dequeuing Element %d from Queue.\n",dequeue(&q));
    printf("Dequeuing Element %d from Queue.\n",dequeue(&q));
    printf("Dequeuing Element %d from Queue.\n",dequeue(&q));
    if(isEmpty(&q))
    printf("Queue Underflow!\n");
    // if(isFull(&q))
    // printf("Queue Overflow!\n");
    return 0;
}